package com.socialnetwork.app;

import com.socialnetwork.app.controllers.LoginInterfaceController;
import com.socialnetwork.app.controllers.UserMainInterfaceController;
import com.socialnetwork.app.controllers.UsersFriendshipsController;
import com.socialnetwork.app.domain.Friendship;
import com.socialnetwork.app.domain.User;
import com.socialnetwork.app.domain.validation.FriendshipValidator;
import com.socialnetwork.app.domain.validation.UserValidator;
import com.socialnetwork.app.domain.validation.Validator;
import com.socialnetwork.app.presentation.UI;
import com.socialnetwork.app.repository.AbstractRepo;
import com.socialnetwork.app.repository.FriendshipRepo;
import com.socialnetwork.app.repository.Repository;
import com.socialnetwork.app.repository.UserRepo;
import com.socialnetwork.app.service.AppService;
import com.socialnetwork.app.service.Service;
import javafx.application.Application;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.stage.Stage;

import java.io.IOException;

public class Main extends Application {
    private final static String url="jdbc:postgresql://localhost:5432/socialmedia";
    private final static String username="postgres";
    private final static String password="postgres";

    private static Validator<User> userValidator=UserValidator.getInstance();
    private static Validator<Friendship> friendshipValidator=FriendshipValidator.getInstance();
    private static AbstractRepo<User> userRepository=new UserRepo(url,username,password);
    private static AbstractRepo<Friendship> friendshipRepo =new FriendshipRepo(url,username,password, (UserRepo) userRepository);
    private static Service service=new AppService((UserRepo) userRepository, (FriendshipRepo) friendshipRepo,userValidator,friendshipValidator);







    @Override
    public void start(Stage stage) throws IOException {

        FXMLLoader fxmlLoader = new FXMLLoader(Main.class.getResource("LoginInterfaceView.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 286, 400);
        LoginInterfaceController controller = fxmlLoader.getController();
        controller.setService((AppService) service);
        stage.setScene(scene);
        stage.setTitle("HI6");
        stage.setResizable(false);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}