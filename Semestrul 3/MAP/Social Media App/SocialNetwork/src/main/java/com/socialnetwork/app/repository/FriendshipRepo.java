package com.socialnetwork.app.repository;

import com.socialnetwork.app.domain.Friendship;
import com.socialnetwork.app.domain.User;
import com.socialnetwork.app.exceptions.RepoException;
import com.socialnetwork.app.utils.Constants;


import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;


public class FriendshipRepo extends AbstractRepo<Friendship> {
    private UserRepo repoUser;

    @Override
    protected Friendship extractEntity(String line) {
        String[] words = line.split(";");
        try {
            Friendship friendship = new Friendship(repoUser.findElement(Integer.parseInt(words[1])),
                    repoUser.findElement(Integer.parseInt(words[2])));
            friendship.setId(Integer.parseInt(words[0]));
            friendship.setFriendsFrom(words[3]);
            return friendship;
        } catch (RepoException ex) {
            ex.printStackTrace();
        }
        return null;
    }



    public void acceptFriendshipInDB(Friendship f1) throws RepoException{
        try{
            Connection connection=DriverManager.getConnection(super.url, super.userName, super.password);
            String sql="UPDATE friendships SET status=?,friends_from=? WHERE id=?";
            PreparedStatement ps=connection.prepareStatement(sql);
            f1.acceptFriend();
            ps.setString(1,f1.getStatus());
            ps.setString(2,f1.getFriendsFrom());
            ps.setInt(3,f1.getId());
            ps.executeUpdate();
            connection.close();
            super.loadData();
        }
        catch (SQLException ex){
            ex.printStackTrace();
            throw new RepoException(Constants.REPO_DATABASE_ERROR);
        }
    }
    public FriendshipRepo(String url, String userName, String password, UserRepo repoUser) {
        super(url, userName, password);
        this.repoUser = repoUser;
        loadData();
    }

    /**
     * @param entity
     * @param connection
     * @throws SQLException
     */
    @Override
    protected void updateEntity(Friendship entity, Connection connection) throws SQLException {

    }

    /**
     * Removes all the friendships that involve current users
     *
     * @param user
     */
    public void removeAllFriendshipsByUser(User user) {
        List<Friendship> friendships = super.getAll();

        try {
            Connection connection = DriverManager.getConnection(super.url, super.userName, super.password);

            for (int i = 0; i < friendships.size(); i++) {
                if (friendships.get(i).getUser1().getId() == user.getId() ||
                        friendships.get(i).getUser2().getId() == user.getId()) {
                    deleteEntity(friendships.get(i), connection);
                    friendships.remove(i);
                    i--;
                }
            }
            connection.close();

        } catch (SQLException ex) {
            ex.printStackTrace();
        }

    }

    /**
     * @param set
     * @return
     * @throws SQLException
     */
    @Override
    protected List<Friendship> extractEntity(ResultSet set) throws SQLException {
        List<Friendship> friendships = new ArrayList<>();
        while (set.next()) {
            Integer id = set.getInt("id");
            Integer id_user1 = set.getInt("id_user1");
            Integer id_user2 = set.getInt("id_user2");
            String friendsFrom = set.getString("friends_from");
            String status=set.getString("status");

            try {
                User u1 = repoUser.findElement(id_user1);
                User u2 = repoUser.findElement(id_user2);
                Friendship friendship = new Friendship(u1, u2);
                friendship.setFriendsFrom(friendsFrom);
                friendship.setId(id);
                friendship.setStatus(status);
                friendships.add(friendship);
            } catch (RepoException ex) {
                ex.printStackTrace();
            }
        }
        return friendships;
    }

    /**
     * @return
     * @throws SQLException
     */
    @Override
    protected PreparedStatement ps_getAll(Connection connection) throws SQLException {
        return connection.prepareStatement("SELECT * FROM friendships");
    }

    /**
     * @param entity
     * @param connection
     * @throws SQLException
     */
    @Override
    protected void storeEntity(Friendship entity, Connection connection) throws SQLException {
        String sql = "INSERT INTO friendships (id,id_user1,id_user2,friends_from,status) VALUES (?,?,?,?,?)";
        PreparedStatement ps = connection.prepareStatement(sql);
        ps.setInt(1, entity.getId());
        ps.setInt(2, entity.getUser1().getId());
        ps.setInt(3, entity.getUser2().getId());
        ps.setString(4, entity.getFriendsFrom());
        ps.setString(5, entity.getStatus());
        ps.executeUpdate();
    }

    /**
     * @param entity
     * @param connection
     * @throws SQLException
     */
    @Override
    protected void deleteEntity(Friendship entity, Connection connection) throws SQLException {
        String sql = "DELETE FROM friendships WHERE id=?";
        PreparedStatement ps = connection.prepareStatement(sql);
        ps.setInt(1, entity.getId());
        ps.executeUpdate();
    }
}
