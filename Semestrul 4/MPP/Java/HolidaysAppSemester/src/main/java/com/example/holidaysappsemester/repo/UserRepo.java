package com.example.holidaysappsemester.repo;

import com.example.holidaysappsemester.domain.Entity;
import com.example.holidaysappsemester.domain.User;

import java.util.List;

public interface UserRepo <ID, E extends Entity<ID>> {
    E findOne (int id);

    E findLog(String user, String pass);

}
