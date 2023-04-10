package com.example.holidaysappsemester.repo;

import com.example.holidaysappsemester.domain.Entity;
import com.example.holidaysappsemester.domain.Reservation;

import java.util.List;

public interface ResRepo <ID, E extends Entity<ID>> {

    Iterable<E> findAll();

    E save(E entity);

}
