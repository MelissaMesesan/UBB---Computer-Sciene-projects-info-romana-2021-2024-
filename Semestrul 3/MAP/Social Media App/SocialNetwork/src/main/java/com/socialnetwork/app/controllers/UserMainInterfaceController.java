package com.socialnetwork.app.controllers;

import com.socialnetwork.app.Main;
import com.socialnetwork.app.domain.Friendship;
import com.socialnetwork.app.domain.User;
import com.socialnetwork.app.domain.UserDTOFriend;
import com.socialnetwork.app.service.AppService;
import com.socialnetwork.app.utils.Observer.Observer;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;


import java.util.*;
import java.util.stream.Collectors;

public class UserMainInterfaceController implements Observer {

    private ObservableList<User> usersList = FXCollections.observableArrayList();
    private ObservableList<UserDTOFriend> friendList = FXCollections.observableArrayList();

    private ObservableList<User> friendRequestsList = FXCollections.observableArrayList();
    private User loggedUser = null;
    @FXML
    public AnchorPane friendRequestsPane;
    @FXML
    public Button acceptFriendButton;
    @FXML
    public Button rejectFriendButton;

    @FXML
    public Button removeFriendButton;

    @FXML
    public Button addFriendshipButton;
    @FXML
    public TextField searchUserTextField;

    @FXML
    public Label connectedUserLabel;
    @FXML
    public Label emailUserLabel;
    @FXML
    public TableView<UserDTOFriend> friendsTableView;
    @FXML
    public ListView<User> friendRequestsListView;
    @FXML
    public TableView<User> usersTable;
    @FXML
    public TableColumn<UserDTOFriend, String> friendNameColumn;
    @FXML
    public TableColumn<UserDTOFriend, String> friendsSinceColumn;
    @FXML
    public TableColumn<User, String> firstNameColumn;
    @FXML
    public TableColumn<User, String> lastNameColumn;
    @FXML
    public TableColumn<User, String> emailColumn;

    @FXML
    public Button refreshButton;
    @FXML
    public Button showFriendRequestsButton;

    @FXML
    public Button removeAccountButton;

    @FXML
    public Button logoutButton;

    @FXML
    public ImageView profileImageView;
    private AppService service;



    @FXML
    public void onLogoutButtonAction(){
        FXMLLoader loader = new FXMLLoader(Main.class.getResource("LoginInterfaceView.fxml"));
        Scene scene;
        try{
            scene = new Scene(loader.load(), 286, 400);
        }
        catch (Exception ex){
            ex.printStackTrace();
            return;
        }
        LoginInterfaceController controller=loader.getController();
        controller.setService(service);
        Stage currentStage= (Stage) removeAccountButton.getScene().getWindow();

        Stage newStage = new Stage();
        newStage.setScene(scene);
        newStage.setResizable(false);
        newStage.setTitle("HI6");
        currentStage.close();
        newStage.show();
    }
    @FXML
    public void onRemoveAccountAction(){
        try {
            service.remove(loggedUser.getId());

            FXMLLoader loader = new FXMLLoader(Main.class.getResource("LoginInterfaceView.fxml"));
            Scene scene;
            try{
                scene = new Scene(loader.load(), 286, 400);
            }
            catch (Exception ex){
                ex.printStackTrace();
                return;
            }
            LoginInterfaceController controller=loader.getController();
            controller.setService(service);
            Stage currentStage= (Stage) removeAccountButton.getScene().getWindow();

            Stage newStage = new Stage();
            newStage.setScene(scene);
            newStage.setResizable(false);
            newStage.setTitle("HI6");
            currentStage.close();
            newStage.show();
        }
        catch(Exception ex){
            ex.printStackTrace();
            Alert alert=new Alert(Alert.AlertType.ERROR,"No action finished!",ButtonType.OK);
        }
    }
    public void setService(AppService service, User user) {


        friendRequestsPane.setVisible(visibleFriendrequestsPane);
        this.service = service;
        this.service.addObserver(this);
        this.loggedUser = user;

        connectedUserLabel.setText(loggedUser.getFirstName() + " " + loggedUser.getLastName());
        emailUserLabel.setText(loggedUser.getEmail());
        profileImageView.setImage(new Image("https://www.kindpng.com/picc/m/24-248253_user-profile-default-image-png-clipart-png-download.png"));
        initLists();
    }

    private void initLists() {
        HashMap<User, String> friendsOfUser = service.getFriends(loggedUser.getId());

        List<UserDTOFriend> friendsTemp = new ArrayList<>();

        for (User user : friendsOfUser.keySet()) {
            UserDTOFriend friend = new UserDTOFriend(user, friendsOfUser.get(user));
            friendsTemp.add(friend);
        }
        List<User> friendReqTemp = new ArrayList<>();
        List<User> friendReqOfUsers = service.getFriendRequests(loggedUser.getId());
        for (User user : friendReqOfUsers) {
            friendReqTemp.add(user);
        }
        friendList.setAll(friendsTemp);
        friendRequestsList.setAll(friendReqTemp);

        List<User> allUsers = service.getAllUsers();
        List<User> allUsersTempList = allUsers.stream()
                .filter(user -> user.getId() != loggedUser.getId())
                .collect(Collectors.toList());

        usersList.setAll(allUsersTempList);

    }

    @FXML
    public void onAcceptButton() {

        try {
            int id = friendRequestsListView.getSelectionModel().getSelectedItem().getId();
            service.addFriendship(loggedUser.getId(), id);
        } catch (NullPointerException npe) {
            Alert alert = new Alert(Alert.AlertType.WARNING, "No user selected!", ButtonType.OK);
            alert.show();
        } catch (Exception ex) {
            Alert alert = new Alert(Alert.AlertType.ERROR, ex.getMessage(), ButtonType.OK);
            alert.show();
        }
    }


    @FXML
    public void onRejectFriendrequestButton() {
        try {
            int userID = friendRequestsListView.getSelectionModel().getSelectedItem().getId();
            service.removeFriendship(loggedUser.getId(), userID);
        } catch (NullPointerException npe) {
            Alert alert = new Alert(Alert.AlertType.WARNING, "No user selected!", ButtonType.OK);
            alert.show();
        } catch (Exception ex) {
            Alert alert = new Alert(Alert.AlertType.ERROR, ex.getMessage(), ButtonType.OK);
            alert.show();
        }
    }

    @FXML
    public void onAddFriendButton() {
        try {
            User userToAskFriendship = usersTable.getSelectionModel().getSelectedItem();
            service.addFriendship(loggedUser.getId(), userToAskFriendship.getId());
            Alert alert = new Alert(Alert.AlertType.INFORMATION, "Sent friendrequest", ButtonType.OK);
            alert.show();

        } catch (NullPointerException npe) {
            Alert alert = new Alert(Alert.AlertType.WARNING, "No user selected!", ButtonType.OK);
            alert.show();
        } catch (Exception ex) {
            Alert alert = new Alert(Alert.AlertType.ERROR, ex.getMessage(), ButtonType.OK);
            alert.show();
        }

    }

    private boolean visibleFriendrequestsPane = false;

    @FXML
    public void onShowFriendrequestsButton() {
        if (visibleFriendrequestsPane == false) {
            visibleFriendrequestsPane = true;
            showFriendRequestsButton.setText("Hide friendrequests");

        } else {
            visibleFriendrequestsPane = false;
            showFriendRequestsButton.setText("Show friendrequests");
        }
        friendRequestsPane.setVisible(visibleFriendrequestsPane);
    }

    @FXML
    public void onRemoveFriendButton() {

        try {
            int friendID = friendsTableView.getSelectionModel().getSelectedItem().getUID();
            service.removeFriendship(friendID, loggedUser.getId());
        } catch (NullPointerException npe) {
            Alert alert = new Alert(Alert.AlertType.WARNING, "No friend selected!", ButtonType.OK);
            alert.show();
        } catch (Exception ex) {
            ex.printStackTrace();
            Alert alert = new Alert(Alert.AlertType.ERROR, ex.getMessage(), ButtonType.OK);
            alert.show();
        }
    }

    @FXML
    public void onSearchUserTextField() {
        List<User> users = service.getAllUsers();
        List<User> usersTemp = new ArrayList<>();
        for (User user : users) {
            String name = user.getFirstName() + " " + user.getLastName();
            if (name.startsWith(searchUserTextField.getText()) && user.getId() != loggedUser.getId())
                usersTemp.add(user);
        }
        usersList.setAll(usersTemp);
        usersTable.setItems(usersList);
    }

    @FXML
    public void initialize() {
        friendNameColumn.setCellValueFactory(new PropertyValueFactory<UserDTOFriend, String>("name_user"));
        friendsSinceColumn.setCellValueFactory(new PropertyValueFactory<UserDTOFriend, String>("friendsSince"));


        firstNameColumn.setCellValueFactory(new PropertyValueFactory<User, String>("firstName"));
        lastNameColumn.setCellValueFactory(new PropertyValueFactory<User, String>("lastName"));
        emailColumn.setCellValueFactory(new PropertyValueFactory<User, String>("email"));
        usersTable.setItems(usersList);

        friendRequestsListView.setItems(friendRequestsList);
        friendsTableView.setItems(friendList);


        searchUserTextField.textProperty().addListener(o -> onSearchUserTextField());
    }

    @Override
    public void update() {
        initLists();
    }

}
