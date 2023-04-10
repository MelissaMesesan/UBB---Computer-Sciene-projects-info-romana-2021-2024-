package com.example.holidaysappsemester.utils.observer;


import com.example.holidaysappsemester.utils.events.Event;

public interface Observable<E extends Event> {
    void addObserver(Observer<E> e);
    void removeObserver(Observer<E> e);
    void notifyObservers(E t);
}
