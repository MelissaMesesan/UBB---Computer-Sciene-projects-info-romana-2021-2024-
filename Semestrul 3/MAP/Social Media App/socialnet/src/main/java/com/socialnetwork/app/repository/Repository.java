package com.socialnetwork.app.repository;

import com.socialnetwork.app.domain.Entity;
import com.socialnetwork.app.exceptions.RepoException;


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
