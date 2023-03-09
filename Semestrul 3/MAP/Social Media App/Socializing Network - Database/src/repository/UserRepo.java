package repository;

import domain.User;
import exceptions.RepoException;
import utils.Constants;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class UserRepo extends AbstractRepo<User>{

    public UserRepo(String url, String userName, String password) {
        super(url, userName, password);
        loadData();
    }

    @Override
    protected User extractEntity(String line) {
        String[] words=line.split(";");
        User user=new User(words[1],words[2],words[3]);
        user.setId(Integer.parseInt(words[0]));
        return user;
    }

    @Override
    protected List<User> extractEntity(ResultSet set) throws SQLException {
        List<User> users=new ArrayList<>();
        while(set.next()) {
            Integer id = set.getInt("id");
            String firstName = set.getString("first_name");
            String lastName = set.getString("last_name");
            String email = set.getString("email");
            User u = new User(lastName, firstName, email);
            u.setId(id);
            users.add(u);
        }
        return users;
    }

    /**
     * @param connection
     * @return
     * @throws SQLException
     */
    @Override
    protected PreparedStatement ps_getAll(Connection connection) throws SQLException {
       return connection.prepareStatement("SELECT * FROM users");
    }



    /**
     * @param entity
     */
    @Override
    protected void storeEntity(User entity,Connection connection) throws SQLException{
        String sql="INSERT INTO users (first_name,last_name,email,id) VALUES (?,?,?,?)";
        PreparedStatement ps=connection.prepareStatement(sql);
        ps.setString(1,entity.getFirstName());
        ps.setString(2,entity.getLastName());
        ps.setString(3,entity.getEmail());
        ps.setInt(4,entity.getId());
        ps.executeUpdate();

    }

    /**
     * @param entity
     * @param connection
     * @throws SQLException
     */
    @Override
    protected void updateEntity(User entity, Connection connection) throws SQLException {
        String sql="UPDATE users SET first_name=?, last_name=?, email=? WHERE id=?";
        PreparedStatement ps=connection.prepareStatement(sql);
        ps.setString(1,entity.getFirstName());
        ps.setString(2,entity.getLastName());
        ps.setString(3,entity.getEmail());
        ps.setInt(4,entity.getId());
        ps.executeUpdate();
    }

    /**
     * @param entity
     * @param connection
     * @throws SQLException
     */
    @Override
    protected void deleteEntity(User entity, Connection connection) throws SQLException {
        String sql="DELETE FROM users WHERE id=?";
        PreparedStatement ps=connection.prepareStatement(sql);
        ps.setInt(1,entity.getId());
        ps.executeUpdate();

    }


}
