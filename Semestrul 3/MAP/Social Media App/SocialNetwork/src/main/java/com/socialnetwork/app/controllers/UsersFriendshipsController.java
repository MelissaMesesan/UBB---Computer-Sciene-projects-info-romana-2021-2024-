package com.socialnetwork.app.controllers;

import com.socialnetwork.app.domain.Friendship;
import com.socialnetwork.app.domain.User;
import com.socialnetwork.app.service.AppService;
import com.socialnetwork.app.service.Service;
import com.socialnetwork.app.utils.Observer.Observable;
import com.socialnetwork.app.utils.Observer.Observer;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;

public class UsersFriendshipsController implements Observer{

    AppService service;
    ObservableList<User>usersList= FXCollections.observableArrayList();
    ObservableList<Friendship>friendshipsList= FXCollections.observableArrayList();

    @FXML
    TableView<User>usersTableView;
    @FXML
    TableView<User>friendshipsTableView;
    @FXML
    TableColumn<User,String>firstNameColumn;
    @FXML
    TableColumn<User,String>lastNameColumn;
    @FXML
    TableColumn<User,String>emailColumn;

    @FXML
    TableColumn<Friendship,String>user1Column;
    @FXML
    TableColumn<Friendship,String>user2Column;
    @FXML
    TableColumn<Friendship,String>sinceColumn;


    @Override
    public void update() {

    }

    public void setService(AppService service) {
        this.service = service;
        this.service.addObserver(this);
        usersList.setAll(service.getAllUsers());
        //friendshipsList.setAll(service.getAllFriendships());
    }
    @FXML
    public void initialize(){
        System.out.println("SAL");
        firstNameColumn.setCellValueFactory(new PropertyValueFactory<User,String>("firstName"));
        lastNameColumn.setCellValueFactory(new PropertyValueFactory<User,String>("lastName"));
        emailColumn.setCellValueFactory(new PropertyValueFactory<User,String>("email"));

        usersTableView.setItems(usersList);
    }
}
