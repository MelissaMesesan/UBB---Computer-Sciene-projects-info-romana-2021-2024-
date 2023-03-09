package com.socialnetwork.app.domain;

public class UserDTOFriend {
    private String friendsSince;
    private String name_user;
    private int UID;

    public UserDTOFriend(User user,String friendsSince) {
        this.friendsSince = friendsSince;
        String name=user.getFirstName()+" "+ user.getLastName();
        this.name_user = name;
        UID= user.getId();
    }

    public int getUID() {
        return UID;
    }

    public String getFriendsSince() {
        return friendsSince;
    }

    public String getName_user() {
        return name_user;
    }
}
