package com.socialnetwork.app.domain;

import com.socialnetwork.app.utils.Constants;

import java.time.LocalDateTime;
import java.util.Objects;

public class Friendship extends Entity<Integer>{
    private User user1;
    private User user2;

    private LocalDateTime friendsFrom=null;

    private String status;
    /**
     * @param other
     */
    @Override
    public void set(Entity other) {

    }

    public String getStatus() {
        return status;
    }

    public Friendship(User user1, User user2) {
        this.user1 = user1;
        this.user2 = user2;
        status="PENDING";
    }

    public void acceptFriend() {
        this.status = "ACCEPTED";
        friendsFrom=LocalDateTime.now();
    }

    public void setFriendsFrom(String time){
        if (!time.isEmpty())
            friendsFrom=LocalDateTime.parse(time,Constants.FORMATTER);
        else friendsFrom=null;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public String getFriendsFrom(){
        if (friendsFrom==null)
            return "";
        return friendsFrom.format(Constants.FORMATTER);
    }
    public User getUser1() {
        return user1;
    }

    public User getUser2() {
        return user2;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
       // if (!super.equals(o)) return false;
        Friendship that = (Friendship) o;
        return Objects.equals(user1, that.user1) && Objects.equals(user2, that.user2) ||
                Objects.equals(user1,that.user2) &&  Objects.equals(user2,that.user1);
    }

    @Override
    public int hashCode() {
        return Objects.hash(user1, user2);
    }

    @Override
    public String fileCsvPatternString() {
        return getId()+";"+user1.getId()+";"+user2.getId()+";"+getFriendsFrom()+"\n";

    }
}
