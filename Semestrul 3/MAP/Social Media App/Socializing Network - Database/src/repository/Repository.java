package repository;

import domain.Entity;
import exceptions.RepoException;


import java.util.List;


public interface Repository<E extends Entity<Integer>> {


    void add(E obj) throws RepoException;
    E remove(int id) throws Exception;
    E remove(E entity) throws Exception;
    void loadData();
    void storeData();
    void update(E obj) throws Exception;
    E findElement(int id) throws RepoException;
    List<E> getAll();
    int getLastID();
    int size();
}
