package old_versions;
import domain.User;
import exceptions.RepoException;
import repository.Repository;
import utils.Constants;

/*
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashSet;
import java.util.List;
import java.util.Optional;
import java.util.Vector;

public class UserFileRepo implements Repository<User> {
    private Vector<User> userList;
    private static String filepath;

    public UserFileRepo(String _filepath) {
        userList=new Vector<>();
        filepath=_filepath;
        loadData();
    }


    private User extractEntity(String line) {
        String[] words = line.split(";");
        User user = new User(words[1], words[2], words[3]);
        user.setId(Integer.parseInt(words[0]));
        return user;

    }





    public void loadData(){
        userList.clear();
        Path path= Paths.get(filepath);
        try {
            List<String> lines = Files.readAllLines(path);
            for (String line : lines) {
                String[] words = line.split(";");
                User user = new User(words[1], words[2], words[3]);
                user.setId(Integer.parseInt(words[0]));
                userList.add(user);
            }
        } catch (IOException e){
            e.printStackTrace();
        }
    }


    @Override
    public void storeData(){
        Path path=Paths.get(filepath);

        try{
            StringBuilder info= new StringBuilder();
            for (User user : userList) {
                info.append(user.getId())
                        .append(";")
                        .append(user.getLastName())
                        .append(";")
                        .append(user.getFirstName())
                        .append(";")
                        .append(user.getEmail())
                        .append("\n");

            }
            Files.writeString(path, info.toString());
        }
        catch (IOException e){
            e.printStackTrace();
        }
    }


    @Override
    public void add(User obj) {

        loadData();
        userList.add(obj);
        storeData();
    }


    @Override
    public User remove(int id) throws RepoException {
        loadData();
        User user=find(id);
        if (user!=null)
        {
            userList.remove(user);
            storeData();
            return user;
        }
        else throw new RepoException(Constants.REPO_REMOVE_USER);
    }


    @Override
    public User findElement(int id) throws RepoException{
        User user=find(id);
        if (user==null)
            throw new RepoException(Constants.REPO_NO_ELEMENT_FOUND);
        else return user;
    }


    private User find(int id) {
        loadData();
        Optional<User> usersWithGivenID=userList.stream().filter(user -> user.getId()==id).findFirst();
        if (usersWithGivenID.isPresent())
            return usersWithGivenID.get();
        else return null;
    }


    @Override
    public Vector<User> getAll() {
        return userList;
    }

}
*/