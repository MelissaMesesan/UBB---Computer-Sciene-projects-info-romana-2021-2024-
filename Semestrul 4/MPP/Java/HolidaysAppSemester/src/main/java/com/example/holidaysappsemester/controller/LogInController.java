package com.example.holidaysappsemester.controller;

import com.example.holidaysappsemester.HelloApplication;
import com.example.holidaysappsemester.domain.User;
import com.example.holidaysappsemester.service.Service;
import com.example.holidaysappsemester.utils.events.ResEntityChangeEvent;
import com.example.holidaysappsemester.utils.observer.Observer;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

import java.io.IOException;
import java.util.List;

public class LogInController implements Observer<ResEntityChangeEvent> {

    Service service;

    @FXML
    public TextField usernameField;
    @FXML
    public TextField passwordField;
    @FXML
    private Button loginButton;



    public void setService(Service service) {
        this.service = service;
        service.addObserver(this);
    }

    public Stage showPage(User user) {
        FXMLLoader loader = new FXMLLoader(HelloApplication.class.getResource("secondpage.fxml"));
        Stage stage = new Stage(StageStyle.DECORATED);
        try {
            stage.setScene(
                    new Scene(loader.load())
            );
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        ManagementController controller = loader.getController();
        controller.initData(user);
        controller.setService(service);
        stage.show();
        return stage;
    }

    @FXML
    protected void onLog() {

        boolean found = false;
        boolean valid = false;
        String username = usernameField.getText();
        String password = passwordField.getText();

        if (!username.isEmpty() && !password.isEmpty()) {
            valid = true;
            User us = service.getLoggerOb(username, password);

            if (us!=null) {
                System.out.println(us.getUsername());
                //deschid fereastra noua cu user
                showPage(us);
                found = true;
            }
        }
        if (!valid || !found) {
            System.out.println(0);
            MessageAlert.showMessage(null, Alert.AlertType.INFORMATION, "Info", "Invalid username or password!");

        }
    }


    @Override
    public void update(ResEntityChangeEvent userEntityChangeEvent) {

    }
}
