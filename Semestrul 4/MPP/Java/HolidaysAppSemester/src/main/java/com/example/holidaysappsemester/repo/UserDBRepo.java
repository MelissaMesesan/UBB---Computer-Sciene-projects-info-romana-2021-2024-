package com.example.holidaysappsemester.repo;

import com.example.holidaysappsemester.domain.User;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Properties;

public class UserDBRepo implements UserRepo<Integer, User> {

    private JdbcUtils dbUtils;
    private static final Logger logger = LogManager.getLogger();

    public UserDBRepo(Properties props) {
        logger.info("Initializing TripDBRepo with properties: {} ", props);
        dbUtils = new JdbcUtils(props);
    }

    @Override
    public User findOne(int id) {
        logger.traceEntry();
        Connection con = dbUtils.getConnection();
        try (PreparedStatement preStmt = con.prepareStatement("select * from Users where id=id")) {
            try (ResultSet result = preStmt.executeQuery()) {
                while (result.next()) {
                    int id1 = result.getInt("id");
                    String username = result.getString("username");
                    String password = result.getString("password");

                    User us = new User(id1, username, password);
                    return us;

                }
            }
        } catch (SQLException e) {
            logger.error(e);
            System.err.println("Error DB" + e);
        }
        return null;
    }

    @Override
    public User findLog(String user, String pass) {
        logger.traceEntry();
        Connection con = dbUtils.getConnection();

        PreparedStatement prepared = null;
        try {
            prepared = con.prepareStatement("SELECT * FROM Users WHERE username = ? and password = ?;");
            prepared.setString(1, user);
            prepared.setString(2, pass);

            try (ResultSet result = prepared.executeQuery()) {
                while (result.next()) {
                    int id1 = result.getInt("id");
                    String username = result.getString("username");
                    String password = result.getString("password");

                    User us = new User(id1, username, password);
                    return us;

                }
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }

        } catch (SQLException e) {
            logger.error(e);
            System.err.println("Error DB" + e);

        }
        return null;
    }
}