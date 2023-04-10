package com.example.holidaysappsemester.service;

import com.example.holidaysappsemester.domain.Reservation;
import com.example.holidaysappsemester.domain.Trip;
import com.example.holidaysappsemester.domain.User;
import com.example.holidaysappsemester.repo.ResRepo;
import com.example.holidaysappsemester.repo.TripRepo;
import com.example.holidaysappsemester.repo.UserRepo;
import com.example.holidaysappsemester.utils.events.ChangeEventType;
import com.example.holidaysappsemester.utils.events.ResEntityChangeEvent;
import com.example.holidaysappsemester.utils.observer.Observable;
import com.example.holidaysappsemester.utils.observer.Observer;

import java.util.*;
import java.util.stream.Collectors;

import static java.lang.Integer.valueOf;

public class Service<ID> implements Observable<ResEntityChangeEvent> {


    private UserRepo<Integer, User> usrepo;
    private TripRepo<Integer, Trip> trepo;
    private ResRepo<Integer, Reservation> resrepo;
    private List<Observer<ResEntityChangeEvent>> observers = new ArrayList<>();

    public Service(UserRepo<Integer, User> usrepo, TripRepo<Integer, Trip> trepo, ResRepo<Integer, Reservation> resrepo) {
        this.usrepo = usrepo;
        this.trepo = trepo;
        this.resrepo = resrepo;
    }

    @Override
    public void addObserver(Observer<ResEntityChangeEvent> e) {
        observers.add(e);

    }

    @Override
    public void removeObserver(Observer<ResEntityChangeEvent> e) {
        observers.remove(e);
    }

    @Override
    public void notifyObservers(ResEntityChangeEvent t) {
        observers.stream().forEach(x -> x.update(t));
    }

//----------------------------- user functions ------------------------------------------

    public User getLoggerOb(String user, String password) {
        return usrepo.findLog(user, password);
    }

//------------------------------ trips functions -----------------------------------------


    public List<Trip> getAllTrips() {
        List<Trip> mess = new ArrayList((Collection) trepo.findAll());
        List<Trip> sortedList = mess.stream()
                .sorted(Comparator.comparing(Trip::getObjective))
                .collect(Collectors.toList());
        return sortedList;
    }

    public Integer hourToInt(Trip tr) {
        String hr = tr.getHour();
        Integer z = hr.charAt(0) - 48;
        Integer u = hr.charAt(1) - 48;
        return z * 10 + u;
    }

    public List<Trip> getFilteredTrips(String objective, Integer from, Integer to) {
        Trip ttt = new Trip(222, "asdsad", "asdasd", "16:00", 1234.6, 2);
        System.out.println(hourToInt(ttt) + " ora tripului");
        List<Trip> mess = new ArrayList((Collection) trepo.findAll());
        List<Trip> sortedList = mess.stream()
                .filter(c -> c.getObjective().equals(objective) && hourToInt(c) >= from && hourToInt(c) <= to)
                .collect(Collectors.toList());

        for (Trip t : sortedList) {
            System.out.println(t.getObjective());
        }
        return sortedList;
    }

    public Trip getTripByID(Integer id) {
        return trepo.findOne(id);
    }

//------------------------------ reservation functions -------------------------------------------


    public void book(Integer idTrip, String client, String phone, Integer tickets) {
        Random rand = new Random(); //instance of random class
        int upperbound = 10000;
        int id = rand.nextInt(upperbound);
        Reservation rs = new Reservation(id, idTrip, client, phone, tickets);
        resrepo.save(rs);
        trepo.update(idTrip, tickets);
        notifyObservers(new ResEntityChangeEvent(ChangeEventType.UPDATE, getTripByID(idTrip)));

    }


}
