package domain.validation;

import domain.Friendship;
import exceptions.ValidationException;
import utils.Constants;

public class FriendshipValidator implements Validator<Friendship> {
    private static final FriendshipValidator instance = new FriendshipValidator();
    private FriendshipValidator(){}

    public static FriendshipValidator getInstance() {
        return instance;
    }

    @Override
    public void validate(Friendship Obj) throws ValidationException {
        UserValidator validator=UserValidator.getInstance();
        try {
            validator.validate(Obj.getUser1());
            validator.validate(Obj.getUser2());
        }
        catch (ValidationException ex){
            throw new ValidationException(Constants.FRIENDSHIP_VALIDATION_EXCEPT);
        }

    }
}
