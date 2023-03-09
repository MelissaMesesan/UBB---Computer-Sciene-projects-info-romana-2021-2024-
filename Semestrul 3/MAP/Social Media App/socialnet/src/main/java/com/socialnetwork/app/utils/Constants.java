package com.socialnetwork.app.utils;

import java.time.format.DateTimeFormatter;

public class Constants {
    public static final String REPO_REMOVE_ENTITY ="The removal could not be initiated!\n";
    public static final String REPO_NO_ELEMENT_FOUND="The entity does not exist!\n";
    public static final String REPO_ALREADY_EXISTS="The entity already exists!\n";
    public static final String NETWORK_EXISTS_FRIENDSHIP="The users are already friends!\n";
    public static final String NETWORK_NO_FRIENDSHIP="The users are not friends!\n";
    public static final String FRIENDSHIP_VALIDATION_EXCEPT="The friendship is not valid!\n";
    public static final String REPO_DATABASE_ERROR="We encountered a database error!\n";

    public static DateTimeFormatter FORMATTER =DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm");


}
