package com.socialnetwork.app.repository;

import com.socialnetwork.app.domain.Entity;
import com.socialnetwork.app.exceptions.RepoException;
import com.socialnetwork.app.utils.Constants;

import java.sql.*;
import java.util.LinkedList;
import java.util.List;
import java.util.Optional;


public abstract class AbstractRepo<E extends Entity<Integer>> implements Repository<E> {
    private List<E> entities;
    protected String url;
    protected String userName;
    protected String password;


    public AbstractRepo(String url, String userName, String password) {
        entities = new LinkedList<>();
        this.url = url;
        this.userName = userName;
        this.password = password;
    }

    protected abstract E extractEntity(String line);

    protected abstract List<E> extractEntity(ResultSet set) throws SQLException;

    protected abstract PreparedStatement ps_getAll(Connection connection) throws SQLException;

    /**
     * Loads data from database
     */
    @Override
    public void loadData() {
        entities.clear();
        try {
            Connection connection = DriverManager.getConnection(url, userName, password);
            PreparedStatement ps = ps_getAll(connection);
            ResultSet resultSet = ps.executeQuery();

            List<E> list = extractEntity(resultSet);
            connection.close();
            list.forEach(entity -> entities.add(entity));
        } catch (SQLException ex) {
            ex.printStackTrace();
        }
    }

    /**
     * Updates an entity
     *
     * @param obj Entity
     * @throws RepoException if the entity does not exist
     */
    @Override
    public void update(E obj) throws RepoException {
        loadData();
        try {
            Connection connection = DriverManager.getConnection(url, userName, password);
            E entity = findElement(obj.getId());
            updateEntity(obj, connection);
            entity.set(obj);

            connection.close();

        } catch (SQLException ex) {
            throw new RepoException(Constants.REPO_DATABASE_ERROR);
        }
    }

    @Override
    public void storeData() {
    }

    /**
     * Must create a prepared statement that stores the given entitiy and executes it
     * @param entity Entity
     * @param connection Connect
     * @throws SQLException if the prepared statement throws an error
     */
    protected abstract void storeEntity(E entity, Connection connection) throws SQLException, RepoException;

    /**
     * Must create a prepared statement that delete the given entity and executes it
     * @param entity Entity
     * @param connection Connect
     * @throws SQLException if the prepared statement throws an error
     */
    protected abstract void deleteEntity(E entity, Connection connection) throws SQLException;

    /**
     * Must create a prepared statement that updates the given entity and executes it
     * @param entity Entity
     * @param connection Connect
     * @throws SQLException if the prepared statement throws an error
     */
    protected abstract void updateEntity(E entity, Connection connection) throws SQLException;

    /**
     * Adds an entity to the entity list
     *
     * @param obj Entity
     * @throws RepoException if the entity already exists
     */
    @Override
    public void add(E obj) throws RepoException {
        loadData();
        Optional<E> optionalE = entities.stream().filter(entity -> entity.equals(obj)).findFirst();
        if (optionalE.isEmpty()) {
            try {
                Connection connection = DriverManager.getConnection(url, userName, password);
                storeEntity(obj, connection);
                entities.add(obj);
                connection.close();

            } catch (SQLException ex) {
                ex.getStackTrace();
                throw new RepoException(Constants.REPO_DATABASE_ERROR);
            }

        } else throw new RepoException(Constants.REPO_ALREADY_EXISTS);
    }

    private E find(int id) {
//poate trb comentat
       // loadData();
        Optional<E> optionalEntities = entities.stream()
                .filter(entity -> entity.getId() == id)
                .findFirst();
        if (optionalEntities.isPresent())
            return optionalEntities.get();
        else return null;
    }

    /**
     * Removes an entity by id
     *
     * @param id int
     * @return E entity
     * @throws Exception if there is no entity to delete
     */
    @Override
    public E remove(int id) throws Exception {
        loadData();
        E entity = find(id);
        if (entity != null) {
            try {
                Connection connection = DriverManager.getConnection(url, userName, password);
                deleteEntity(entity, connection);
                entities.remove(entity);
                connection.close();

            } catch (SQLException ex) {
                ex.printStackTrace();
                throw new RepoException(Constants.REPO_DATABASE_ERROR);
            }
            return entity;
        } else throw new RepoException(Constants.REPO_REMOVE_ENTITY);
    }

    /**
     * Removes an entity if it is found in the entity list
     *
     * @param entity Entity
     * @return Entity removed
     * @throws Exception if there is no entity to delete
     */
    @Override
    public E remove(E entity) throws Exception {

        loadData();
        Optional<E> optionalE = entities.stream().filter(_entity -> _entity.equals(entity)).findFirst();
        if (!optionalE.isPresent())
            throw new RepoException(Constants.REPO_REMOVE_ENTITY);

        try {
            Connection connection = DriverManager.getConnection(url, userName, password);
            deleteEntity(optionalE.get(), connection);
            entities.remove(optionalE.get());
            connection.close();
        } catch (SQLException ex) {
            ex.printStackTrace();
            throw new RepoException(Constants.REPO_DATABASE_ERROR);
        }

        return optionalE.get();

    }

    /**
     * Finds an entity by given id
     *
     * @param id int
     * @return Entity
     * @throws RepoException
     */
    @Override
    public E findElement(int id) throws RepoException {
        loadData();
        E entity = find(id);
        if (entity == null)
            throw new RepoException(Constants.REPO_NO_ELEMENT_FOUND);
        return entity;
    }

    @Override
    public List<E> getAll() {
        loadData();
        return entities;
    }

    /**
     * @return maximum found id
     */
    @Override
    public int getLastID() {

        int ID = -1;
        for (Entity entity : entities)
            ID = Math.max(ID, (Integer) entity.getId());
        if (ID == -1) return 1;
        else return ID;
    }

    /**
     * @return size of repo
     */
    @Override
    public int size() {
        return entities.size();
    }
}
