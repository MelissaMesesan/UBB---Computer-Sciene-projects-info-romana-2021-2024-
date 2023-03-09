package repository;

import domain.Friendship;
import domain.User;
import exceptions.NetworkException;
import utils.Constants;

import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;

public class Network {
    private Map<Integer, List<Integer>> network = new HashMap();

    public Network(List<Friendship> friendships) {
        createNetwork(friendships);
    }

    private void createNetwork(List<Friendship> friendships) {
        for (Friendship friendship : friendships)
            addFriendship(friendship.getUser1(), friendship.getUser2());
    }

    private void addUserToNetwork(User user) {
        network.put(user.getId(), new LinkedList<Integer>());
    }

    /**
     * Tests if there is a friendship between 2 users
     *
     * @param u1 User
     * @param u2 User
     * @return True/False
     */
    private boolean isThereFriendship(User u1, User u2) {
        boolean sw = false;
        for (int identificator : network.get(u1.getId()))
            if (identificator == u2.getId())
                sw = true;

        return sw;

    }

    /**
     * Removes a friendship from the network
     * @param u1 User
     * @param u2 User
     * @throws NetworkException if there is already no friendship
     */
    /*
    public void removeFriendship(User u1, User u2) throws NetworkException{
        if (network.containsKey(u1.getId()) && network.containsKey(u2.getId())) {
            if (isThereFriendship(u1, u2)) {
                var list=network.get(u1.getId());
                list.removeIf(integer -> integer==u2.getId());
                list=network.get(u2.getId());
                list.removeIf(integer -> integer==u1.getId());

            }
            else throw new NetworkException(Constants.NETWORK_NO_FRIENDSHIP);
        }

    }
    public void removeFriendship(Friendship f1) throws NetworkException{
        User u1=f1.getUser1();
        User u2=f1.getUser2();
        if (network.containsKey(u1.getId()) && network.containsKey(u2.getId())) {
            if (isThereFriendship(u1, u2)) {
                var list=network.get(u1.getId());
                list.removeIf(integer -> integer==u2.getId());
                list=network.get(u2.getId());
                list.removeIf(integer -> integer==u1.getId());

            }
            else throw new NetworkException(Constants.NETWORK_NO_FRIENDSHIP);
        }

    }
    */


    /**
     * Adds a friendship to the network
     *
     * @param u1
     * @param u2
     * @throws NetworkException if the friendship already exists
     */
    public void addFriendship(User u1, User u2) {


        if (!network.containsKey(u1.getId()))
            addUserToNetwork(u1);

        if (!network.containsKey(u2.getId()))
            addUserToNetwork(u2);

        //if (!isThereFriendship(u1, u2))
        network.get(u1.getId()).add(u2.getId());
        network.get(u2.getId()).add(u1.getId());


    }

    /**
     * @return List with ids of users from the most sociable community
     */
    public List<Integer> mostSociableCommunity() {
        AtomicInteger maxLevel = new AtomicInteger(0);
        var community_indexes = getCommunities();
        int[] visited = new int[maxNode() + 1];
        Arrays.fill(visited, 0);
        int highestLevel = 0;
        int indexOfSociableCom = 0;
        int node;
        for (int communityIndex : community_indexes.keySet()) {
            for (int index : community_indexes.get(communityIndex)) {
                node = index;
                maxLevel.set(0);
                longest_road(node, visited, 0, maxLevel);

                if (highestLevel < maxLevel.get()) {
                    highestLevel = maxLevel.get();
                    indexOfSociableCom = communityIndex;
                }
            }


        }

        return community_indexes.get(indexOfSociableCom);
    }

    /**
     * @return The number of communities
     */
    public int getNumberOfCommunities() {
        int community_number = 0;
        var indexes = getCommunityIndexes();
        for (int number : indexes) {
            if (Arrays.stream(indexes).filter(value -> value == number).count() > 1)
                community_number = Math.max(community_number, number);
        }
        return community_number;

    }

    /**
     * Calculates the intest road on a network where the starting position is given as parameter node
     *
     * @param node     int
     * @param visited  int[]
     * @param level    int
     * @param maxLevel AtomicInteger
     */
    private void longest_road(int node, int[] visited, int level, AtomicInteger maxLevel) {
        visited[node] = 1;
        maxLevel.set(Math.max(level, maxLevel.get()));
        for (int neighbor : network.get(node))
            if (visited[neighbor] == 0)
                longest_road(neighbor, visited, level + 1, maxLevel);

    }

    /**
     * DFS on a given network
     *
     * @param node    int
     * @param visited int[]
     * @param number  int
     */
    private void dfs_util(int node, int[] visited, int number) {
        visited[node] = number;
        for (int neighbor : network.get(node))
            if (visited[neighbor] == 0)
                dfs_util(neighbor, visited, number);
    }

    /**
     * @return the maximum id in the network
     */
    private int maxNode() {
        int size = 1;
        for (int key : network.keySet())
            size = Math.max(size, key);
        return size;
    }

    /**
     * @return community indexes for every id of user, where the index of the vector is user id
     */
    private int[] getCommunityIndexes() {

        int visited[] = new int[maxNode() + 1];
        Arrays.fill(visited, 0);
        int community_number = 0;
        for (int user : network.keySet())
            if (visited[user] == 0) {
                community_number++;
                dfs_util(user, visited, community_number);
            }
        return visited;
    }

    /**
     * @return Map<UserID ( Integer ), List < UserID ( Integer )>  all the communities
     */
    public HashMap<Integer, List<Integer>> getCommunities() {

        int[] comm_indexes = getCommunityIndexes();

        HashMap<Integer, List<Integer>> communities = new HashMap<>();
        for (int userId = 1; userId < comm_indexes.length; userId++) {
            if (comm_indexes[userId] != 0) {
                if (!communities.containsKey(comm_indexes[userId]))
                    communities.put(comm_indexes[userId], new LinkedList<Integer>());
                communities.get(comm_indexes[userId]).add(userId);
            }
        }
        return communities;
    }


}
