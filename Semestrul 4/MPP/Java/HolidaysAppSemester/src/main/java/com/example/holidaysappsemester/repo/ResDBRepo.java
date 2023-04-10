package com.example.holidaysappsemester.repo;

import com.example.holidaysappsemester.domain.Reservation;
import com.example.holidaysappsemester.domain.Trip;
import com.example.holidaysappsemester.domain.User;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;

public class ResDBRepo implements ResRepo<Integer, Reservation>{

    private JdbcUtils dbUtils;
    private static final Logger logger = LogManager.getLogger();

    public ResDBRepo(Properties props) {
        logger.info("Initializing TripDBRepo with properties: {} ", props);
        dbUtils = new JdbcUtils(props);
    }


    @Override
    public List<Reservation> findAll() {
        logger.traceEntry();
        Connection con = dbUtils.getConnection();
        List<Reservation> res = new ArrayList<>();
        try (PreparedStatement preStmt = con.prepareStatement("select * from Reservations")) {
            try (ResultSet result = preStmt.executeQuery()) {
                while (result.next()) {
                    int id = result.getInt("id");
                    int ide = result.getInt("excursionid");
                    String client = result.getString("client");
                    String phone = result.getString("phone");
                    int notickets = result.getInt("notickets");


                    Reservation r=new Reservation(id, ide, client, phone, notickets);
                    res.add(r);
                }
            }
        } catch (SQLException e) {
            logger.error(e);
            System.err.println("Error DB" + e);
        }
        logger.traceExit(res);
        return res;
    }

    @Override
    public Reservation save(Reservation elem) {
        logger.traceEntry("saving task {} ", elem);
        Connection con = dbUtils.getConnection();
        try (PreparedStatement preStm = con.prepareStatement("insert into Reservations(id, excursionid, client, phone, notickets) values (?,?,?,?,?)")) {
            preStm.setInt(1, elem.getIdRes());
            preStm.setInt(2, elem.getExcursionId());
            preStm.setString(3, elem.getClientName());
            preStm.setString(4, elem.getPhoneNumber());
            preStm.setDouble(5, elem.getNoTickets());
            int result = preStm.executeUpdate();
            logger.trace("Saved {} instances", result);

        } catch (SQLException ex) {
            logger.error(ex);
            System.err.println("Error DB " + ex);
        }
        return elem;
    }
}
