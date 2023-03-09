package domain.validation;
import domain.User;
import exceptions.ValidationException;

public class UserValidator implements Validator<User>{
    private static final UserValidator instance=new UserValidator();
    public static UserValidator getInstance(){
        return instance;
    }
    private UserValidator(){}

    /**
     * Validates the user
     * @param Obj
     * @throws ValidationException if it is not valid
     */
    @Override
    public void validate(User Obj) throws ValidationException {
        String errors="";
        if (Obj.getLastName().length()<3)
            errors+="Last name is too short!\n";
        if (Obj.getFirstName().length()<3)
            errors+="First name is too short!\n";
        if (!Obj.getEmail().matches(".{6,}[@].{2,}[.].{2,}"))
            errors+="Email is invalid!\n";

        if (errors.length()>0)
            throw new ValidationException(errors);
    }
}
