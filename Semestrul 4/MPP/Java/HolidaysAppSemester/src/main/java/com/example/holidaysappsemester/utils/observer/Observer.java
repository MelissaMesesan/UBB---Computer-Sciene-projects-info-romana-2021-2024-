package com.example.holidaysappsemester.utils.observer;


import com.example.holidaysappsemester.utils.events.Event;

public interface Observer<E extends Event> {
    void update(E e);
}