module com.example.holidaysappsemester {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;
    requires com.dlsc.formsfx;
    requires org.kordamp.bootstrapfx.core;
    requires java.sql;
    requires org.apache.logging.log4j;

    opens com.example.holidaysappsemester to javafx.fxml;
    opens com.example.holidaysappsemester.domain to javafx.base;
    exports com.example.holidaysappsemester;
    exports com.example.holidaysappsemester.controller;
    opens com.example.holidaysappsemester.controller to javafx.fxml;
}