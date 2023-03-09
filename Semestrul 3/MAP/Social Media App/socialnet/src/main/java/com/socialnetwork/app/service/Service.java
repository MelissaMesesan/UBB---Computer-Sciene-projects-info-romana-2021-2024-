package com.socialnetwork.app.service;

import com.socialnetwork.app.domain.Friendship;
import com.socialnetwork.app.domain.User;
import com.socialnetwork.app.exceptions.NetworkException;
import com.socialnetwork.app.exceptions.RepoException;
import com.socialnetwork.app.exceptions.ValidationException;

import java.util.HashMap;
import java.util.List;


public interface Service {

    void add(String firstName, String lastName, String email) throws Exception;
    void remove (int id) throws Exception;
    void addFriendship(int id1, int id2) throws NetworkException, RepoException, ValidationException;
    void removeFriendship(int id1, int id2) throws Exception;
    HashMap<User,String> getFriends(int id);
    List<User> getFriendRequests(int id);
    int numberOfCommunities();
    List<User> mostSociableCommunity();
    List<User> getAllUsers();

    List<Friendship> getAllFriendships();
    int sizeFriendships();
    int sizeUsers();
    void update(int idToChange, String firstName, String lastName, String email) throws RepoException, ValidationException;

    User findUserByEmail(String email) throws RepoException;
    User findUserById(int id);
}
