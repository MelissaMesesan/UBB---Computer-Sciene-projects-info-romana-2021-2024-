package com.example.holidaysappsemester.repo;

import com.example.holidaysappsemester.domain.Entity;
import com.example.holidaysappsemester.domain.Trip;

import java.util.List;

public interface TripRepo<ID, E extends Entity<ID>> {
    Trip findOne (int id);

    void save(Trip elem);
    void update(Integer id, Integer val);

    List<Trip> findAll();
}
