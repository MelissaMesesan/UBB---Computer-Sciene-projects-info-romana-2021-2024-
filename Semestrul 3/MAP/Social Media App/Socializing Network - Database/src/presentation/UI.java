package presentation;

import domain.Friendship;
import domain.User;
import exceptions.NetworkException;
import exceptions.RepoException;
import exceptions.ValidationException;
import service.Service;

import java.util.HashMap;
import java.util.Scanner;

public class UI {
    private Service service;
    private Scanner in = new Scanner(System.in);

    public UI(Service service) {
        this.service = service;
        showMenu();
    }

    public void run() {

        while (true) {
            System.out.println(">>>");
            String input = in.nextLine();
            if (input.equals("7")) showMenu();
            else if (input.equals("99")) System.exit(0);
            else if (input.equals("1")) add();
            else if (input.equals("2")) remove();
            else if (input.equals("3")) update();
            else if (input.equals("4")) addFriendship();
            else if (input.equals("5")) removeFriendship();
            else if (input.equals("6")) showUsers();
            else if (input.equals("8")) numberOfCommunities();
            else if (input.equals("9")) mostSociableCommunity();
            else if (input.equals("10")) friendList();
            else if (input.equals("11")) showFriendships();
        }
    }

    private void showFriendships() {
        var friendships=service.getAllFriendships();
        for (Friendship friendship : friendships)
            System.out.print(friendship.fileCsvPatternString());

    }

    private void update() {
        showUsers();
        System.out.println("Select the id of the user you want to update information for");
        System.out.print("ID: ");

        String idString=in.nextLine();
        System.out.print("New First Name: ");
        String firstName = in.nextLine();
        System.out.print("New Last Name: ");
        String lastName = in.nextLine();
        System.out.print("New Email Name: ");
        String email = in.nextLine();

        try{
            int id=Integer.parseInt(idString);
            service.update(id,firstName,lastName,email);
            System.out.println("Update successfully");
        }
        catch (NumberFormatException ex){
            System.out.println("ID invalid!");
        }
        catch (ValidationException ex){
            System.out.println(ex.getMessage());
        }
        catch (RepoException ex){
            System.out.println(ex.getMessage());
        }
    }

    private void showMenu() {
        System.out.println("1 - Add a user to the system");
        System.out.println("2 - Remove a user to the system");
        System.out.println("3 - Update a user from the system");
        System.out.println("4 - Add a friendship to the system");
        System.out.println("5 - Remove a friendship from the system");
        System.out.println("6 - Show all users");
        System.out.println("7 - Show menu");
        System.out.println("8 - Number of communities");
        System.out.println("9 - Most sociable community");
        System.out.println("10 - See friend list of a user");
        System.out.println("11 - See all friendships");
        System.out.println();
        System.out.println("There are "+service.sizeUsers()+" users in the system!");
        System.out.println("There are "+service.sizeFriendships()+" friendships in the system!");
        System.out.println("99 - Exit");



    }
    private void friendList(){
        showUsers();
        System.out.println("Select the user you want to see the friend list of");
        System.out.print("ID: ");
        String idString=in.nextLine();
        try{
            int id=Integer.parseInt(idString);
            HashMap<User,String> list=service.getFriends(id);
            System.out.println("\tFriend list:");
            for (User user : list.keySet())
                System.out.println(user.printPatternString()+" \t\tFriends since: "+list.get(user));

        }
        catch (NumberFormatException ex){
            System.out.println("ID invalid!");
        }
    }
    private void addFriendship(){
        showUsers();
        System.out.println("Select two users you want to have a friendship between by using their ids: ");
        System.out.println("ID 1: ");
        String id1String=in.nextLine();
        System.out.println("ID 2: ");
        String id2String=in.nextLine();

        try{
            int id1=Integer.parseInt(id1String);
            int id2=Integer.parseInt(id2String);
            service.addFriendship(id1,id2);
            System.out.println("Added friendship!");

        }
        catch (NumberFormatException nex){
            System.out.println("ID invalid!");
        }
        catch (NetworkException ex){
            System.out.println(ex.getMessage());
        }
        catch (RepoException ex){
            System.out.println(ex.getMessage());
        }
        catch (ValidationException ex){
            System.out.println(ex.getMessage());
        }
    }
    private void removeFriendship(){
        System.out.println("Select two users you want to remove a friendship between by using their ids: ");
        System.out.println("ID 1: ");
        String id1String=in.nextLine();
        System.out.println("ID 2: ");
        String id2String=in.nextLine();
        try{
            int id1=Integer.parseInt(id1String);
            int id2=Integer.parseInt(id2String);
            service.removeFriendship(id1,id2);
            System.out.println("Removed friendship!");

        }
        catch (NumberFormatException nex){
            System.out.println("ID invalid!");
        }
        catch (Exception ex){
            System.out.println(ex.getMessage());
        }

    }
    private void numberOfCommunities(){
        System.out.println("There are "+Integer.toString(service.numberOfCommunities()) + " communities!");
    }
    private void mostSociableCommunity(){
        var community=service.mostSociableCommunity();
        System.out.println("Most sociable community is made of the following users:");
        for (User user : community)
            System.out.println(user.printPatternString());

    }
    private void showUsers() {
        for (User user : service.getAllUsers())
            System.out.println(user.printPatternString());

    }
    private void remove(){
        showUsers();
        System.out.print("Input the ID of the user you want to remove: ");
        String idString = in.nextLine();

        try {
            int id=Integer.parseInt(idString);
            service.remove(id);
            System.out.println("Successfully removed!");
        }
        catch(NumberFormatException nex){
            System.out.println("ID invalid!");
        }
        catch (Exception ex){
            System.out.println(ex.getMessage());
        }
    }
    private void add() {
        System.out.print("First Name: ");
        String firstName = in.nextLine();
        System.out.print("Last Name: ");
        String lastName = in.nextLine();
        System.out.print("Email Name: ");
        String email = in.nextLine();

        try {
            service.add(firstName, lastName, email);
        } catch (Exception ex) {
            System.out.println(ex.getMessage());
        }
    }
}