package domain.validation;

import exceptions.ValidationException;

public interface Validator<T> {
    void validate(T Obj) throws ValidationException;
}
