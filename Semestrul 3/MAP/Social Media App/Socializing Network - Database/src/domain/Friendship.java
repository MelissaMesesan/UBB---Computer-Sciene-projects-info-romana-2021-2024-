package domain;

import utils.Constants;

import java.time.LocalDateTime;
import java.util.Objects;

public class Friendship extends Entity<Integer>{
    User user1;
    User user2;

    LocalDateTime friendsFrom;

    /**
     * @param other
     */
    @Override
    public void set(Entity other) {

    }

    public Friendship(User user1, User user2) {
        this.user1 = user1;
        this.user2 = user2;
        friendsFrom=LocalDateTime.now();



    }

    public void setFriendsFrom(String time){
        friendsFrom=LocalDateTime.parse(time,Constants.FORMATTER);
    }
    public String getFriendsFrom(){
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
        return Objects.equals(user1, that.user1) && Objects.equals(user2, that.user2);
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
