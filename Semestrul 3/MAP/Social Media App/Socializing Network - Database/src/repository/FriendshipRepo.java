package repository;

import domain.Friendship;
import domain.User;
import exceptions.RepoException;


import java.sql.*;
import java.util.ArrayList;
import java.util.List;


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
            try {
                User u1 = repoUser.findElement(id_user1);
                User u2 = repoUser.findElement(id_user2);
                Friendship friendship = new Friendship(u1, u2);
                friendship.setFriendsFrom(friendsFrom);
                friendship.setId(id);
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
        String sql = "INSERT INTO friendships (id,id_user1,id_user2,friends_from) VALUES (?,?,?,?)";
        PreparedStatement ps = connection.prepareStatement(sql);
        ps.setInt(1, entity.getId());
        ps.setInt(2, entity.getUser1().getId());
        ps.setInt(3, entity.getUser2().getId());
        ps.setString(4, entity.getFriendsFrom());
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
