package com.example.holidaysappsemester.controller;

import com.example.holidaysappsemester.domain.Trip;
import com.example.holidaysappsemester.domain.User;
import com.example.holidaysappsemester.service.Service;
import com.example.holidaysappsemester.utils.events.ResEntityChangeEvent;
import com.example.holidaysappsemester.utils.observer.Observer;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.Node;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;
import javafx.util.Callback;

import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

public class ManagementController implements Observer<ResEntityChangeEvent> {

    Service service;

    User loggedInUser;

    ObservableList<Trip> Tmodel = FXCollections.observableArrayList();
    ObservableList<Trip> T2model = FXCollections.observableArrayList();

    @FXML
    Text userLabel;

    @FXML
    private TableView<Trip> allTrips;
    @FXML
    private TableView<Trip> selectedTrips;

    @FXML
    private TableColumn ob;

    @FXML
    private TableColumn tc;

    @FXML
    private TableColumn hr;

    @FXML
    private TableColumn pr;

    @FXML
    private TableColumn as;

    @FXML
    private TableColumn tc1;

    @FXML
    private TableColumn dh1;

    @FXML
    private TableColumn pc1;

    @FXML
    private TableColumn as1;

    @FXML
    private TextField objectiveField;

    @FXML
    private TextField hourField;

    @FXML
    private TextField hourToField;

    @FXML
    private TextField clientField;

    @FXML
    private TextField phoneField;

    @FXML
    private TextField ticketsField;


    public void setService(Service service) {
        this.service = service;
        service.addObserver(this);
        initModel();
    }

    void initialize() {


        allTrips.setRowFactory(tv -> new TableRow<Trip>() {
            @Override
            protected void updateItem(Trip item, boolean empty) {
                super.updateItem(item, empty);
                if (item!=null){
                    if(item.getAvailableSpots().equals(0))
                        setStyle("-fx-text-background-color: RED;");
                    else
                        setStyle("-fx-text-background-color: BLACK;");
                }

            }
        });

        ob.setCellValueFactory(new PropertyValueFactory<Trip, String>("objective"));
        tc.setCellValueFactory(new PropertyValueFactory<Trip, String>("transportCompany"));
        hr.setCellValueFactory(new PropertyValueFactory<Trip, String>("hour"));
        pr.setCellValueFactory(new PropertyValueFactory<Trip, Double>("price"));
        as.setCellValueFactory(new PropertyValueFactory<Trip, Integer>("availableSpots"));
        allTrips.setItems(Tmodel);

        tc1.setCellValueFactory(new PropertyValueFactory<Trip, String>("transportCompany"));
        dh1.setCellValueFactory(new PropertyValueFactory<Trip, String>("hour"));
        pc1.setCellValueFactory(new PropertyValueFactory<Trip, Double>("price"));
        as1.setCellValueFactory(new PropertyValueFactory<Trip, Integer>("availableSpots"));
        selectedTrips.setItems(T2model);

    }

    void initData(User user) {
        userLabel.setText(user.getUsername());
        initialize();
        this.loggedInUser = user;
    }

    private void initModel() {
        List<Trip> messages = service.getAllTrips();
        List<Trip> trips = StreamSupport.stream(messages.spliterator(), false)
                .collect(Collectors.toList());
        Tmodel.setAll(trips);
    }



    @Override
    public void update(ResEntityChangeEvent resEntityChangeEvent) {
        initModel();
    }

    @FXML
    public void onLogOut(ActionEvent actionEvent) {
        ((Node)(actionEvent.getSource())).getScene().getWindow().hide();
    }

    @FXML
    public void search(ActionEvent actionEvent) {
        String obj = objectiveField.getText();
        String hr1 = hourField.getText();
        String hr2 = hourToField.getText();
        List<Trip> trs=service.getFilteredTrips(obj, Integer.valueOf(hr1), Integer.valueOf(hr2));
        List<Trip> trips = StreamSupport.stream(trs.spliterator(), false)
                .collect(Collectors.toList());
        T2model.setAll(trips);

    }

    @FXML
    public void book(ActionEvent actionEvent) {

        Trip fr = selectedTrips.getSelectionModel().getSelectedItem();

        String clf = clientField.getText();
        String phf = phoneField.getText();
        Integer tick = Integer.valueOf(ticketsField.getText());

        if (fr != null) {
            service.book(fr.getIdTrip(), clf, phf, tick);
            initModel();
            String obj = objectiveField.getText();
            String hr1 = hourField.getText();
            String hr2 = hourToField.getText();
            List<Trip> trs=service.getFilteredTrips(obj, Integer.valueOf(hr1), Integer.valueOf(hr2));
            List<Trip> trips = StreamSupport.stream(trs.spliterator(), false)
                    .collect(Collectors.toList());
            T2model.setAll(trips);

        }

    }
}