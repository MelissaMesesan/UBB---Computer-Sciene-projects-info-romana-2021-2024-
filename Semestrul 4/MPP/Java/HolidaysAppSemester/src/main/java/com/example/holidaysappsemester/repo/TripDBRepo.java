package com.example.holidaysappsemester.repo;

import com.example.holidaysappsemester.domain.Trip;
import com.example.holidaysappsemester.domain.User;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;


public class TripDBRepo implements TripRepo<Integer, Trip> {
    private JdbcUtils dbUtils;


    private static final Logger logger = LogManager.getLogger();

    public TripDBRepo(Properties props) {
        logger.info("Initializing TripDBRepo with properties: {} ", props);
        dbUtils = new JdbcUtils(props);
    }

    @Override
    public Trip findOne(int id) {
        logger.traceEntry();
        Connection con = dbUtils.getConnection();
        try (PreparedStatement preStmt = con.prepareStatement("select * from Trips where id=id")) {
            try (ResultSet result = preStmt.executeQuery()) {
                while (result.next()) {
                    int id1 = result.getInt("id");
                    String ob = result.getString("objective");
                    String transp = result.getString("transport");
                    String hr = result.getString("hour");
                    Double price = result.getDouble("price");
                    Integer avl = result.getInt("availablespots");

                    Trip us = new Trip(id1, ob, transp, hr, price, avl);
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
    public void save(Trip elem) {
        logger.traceEntry("saving task {} ", elem);
        Connection con = dbUtils.getConnection();
        try (PreparedStatement preStm = con.prepareStatement("insert into Trips(id, objective, transport, hour, price, availablespots) values (?,?,?,?,?,?)")) {
            preStm.setInt(1, elem.getIdTrip());
            preStm.setString(2, elem.getObjective());
            preStm.setString(3, elem.getTransportCompany());
            preStm.setString(4, elem.getHour());
            preStm.setDouble(5, elem.getPrice());
            preStm.setInt(6, elem.getAvailableSpots());
            int result = preStm.executeUpdate();
            logger.trace("Saved {} instances", result);

        } catch (SQLException ex) {
            logger.error(ex);
            System.err.println("Error DB " + ex);
        }
    }


    @Override
    public List<Trip> findAll() {
        logger.traceEntry();
        Connection con = dbUtils.getConnection();
        List<Trip> cars = new ArrayList<>();
        try (PreparedStatement preStmt = con.prepareStatement("select * from Trips")) {
            try (ResultSet result = preStmt.executeQuery()) {
                while (result.next()) {
                    int id = result.getInt("id");
                    String objective = result.getString("objective");
                    String transportCompany = result.getString("transport");
                    String hour = result.getString("hour");
                    Double price = result.getDouble("price");
                    int availableSpots = result.getInt("availablespots");

                    Trip car = new Trip(id, objective, transportCompany, hour, price, availableSpots);
                    car.setId(id);
                    cars.add(car);
                }
            }
        } catch (SQLException e) {
            logger.error(e);
            System.err.println("Error DB" + e);
        }
        logger.traceExit(cars);
        return cars;

    }


    @Override
    public void update(Integer idTr, Integer howManyOut) {
        logger.traceEntry();
        Connection con = dbUtils.getConnection();

        String query = "UPDATE Trips SET availablespots=availablespots-? WHERE id=?";
        PreparedStatement statement = null;
        try {
            statement = con.prepareStatement(query);
            statement.setInt(1, howManyOut);
            statement.setInt(2, idTr);
            statement.executeUpdate();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        logger.traceExit();



    }


}