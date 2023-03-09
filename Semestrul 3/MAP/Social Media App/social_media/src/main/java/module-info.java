module com.example.social_media {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.social_media to javafx.fxml;
    exports com.example.social_media;
}