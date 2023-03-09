import domain.Friendship;
import domain.User;
import domain.validation.FriendshipValidator;
import domain.validation.UserValidator;
import domain.validation.Validator;
import presentation.UI;
import repository.AbstractRepo;
import repository.FriendshipRepo;
import repository.UserRepo;
import service.Service;
import service.AppService;
import tests.Tests;



public class Main {
    public static void main(String[] args) {

        Tests.run();
        Validator validator=UserValidator.getInstance();
        FriendshipValidator validator2=FriendshipValidator.getInstance();
        AbstractRepo<User> repository_user=new UserRepo("jdbc:postgresql://localhost:5432/socialmedia","postgres","postgres");
        AbstractRepo<Friendship> repository_friendship=new FriendshipRepo("jdbc:postgresql://localhost:5432/socialmedia","postgres","postgres", (UserRepo) repository_user);
        Service service=new AppService((UserRepo) repository_user, (FriendshipRepo) repository_friendship,validator,validator2);
        UI ui = new UI(service);
        ui.run();


    }
}