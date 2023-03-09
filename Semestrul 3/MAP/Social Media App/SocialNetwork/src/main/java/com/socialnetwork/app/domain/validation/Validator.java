package com.socialnetwork.app.domain.validation;

import com.socialnetwork.app.exceptions.ValidationException;

public interface Validator<T> {
    void validate(T Obj) throws ValidationException;
}
