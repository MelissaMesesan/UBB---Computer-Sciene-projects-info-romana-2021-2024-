package com.example.holidaysappsemester;

import com.example.holidaysappsemester.controller.LogInController;
import com.example.holidaysappsemester.domain.Trip;
import com.example.holidaysappsemester.repo.ResDBRepo;
import com.example.holidaysappsemester.repo.TripDBRepo;
import com.example.holidaysappsemester.repo.UserDBRepo;
import com.example.holidaysappsemester.service.Service;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.io.FileReader;
import java.io.IOException;
import java.util.Properties;

public class HelloApplication extends Application {
    Service service;

    @Override
    public void start(Stage stage) throws IOException {

        Properties props = new Properties();
        try {
            props.load(new FileReader("bd.config"));
        } catch (IOException e) {
            System.out.println("Cannot find bd.config " + e);
        }

        TripDBRepo trepo =  new TripDBRepo(props);
        UserDBRepo usrrepo =  new UserDBRepo(props);
        ResDBRepo rrepo =  new ResDBRepo(props);

        service = new Service(usrrepo, trepo, rrepo);
        String ab="16:00";
        Integer x=ab.charAt(0)-48;
        Integer y=ab.charAt(1)-48;
        initView(stage);
        stage.show();

    }

    public static void main(String[] args) {
        launch(args);
    }

    private void initView(Stage primaryStage) throws IOException {

        // FXMLLoader fxmlLoader = new FXMLLoader();
        //fxmlLoader.setLocation(getClass().getResource("com/example/guiex1/views/UtilizatorView.fxml"));
        FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("firstpage.fxml"));
        VBox userLayout = fxmlLoader.load();
        primaryStage.setScene(new Scene(userLayout));

        LogInController userController = fxmlLoader.getController();
        userController.setService(service);

    }
}