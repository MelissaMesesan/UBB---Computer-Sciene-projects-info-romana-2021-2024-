package com.example.holidaysappsemester.utils.events;


import com.example.holidaysappsemester.domain.Reservation;
import com.example.holidaysappsemester.domain.Trip;

public class ResEntityChangeEvent implements Event {
    private com.example.holidaysappsemester.utils.events.ChangeEventType type;
    private Trip data, oldData;

    public ResEntityChangeEvent(ChangeEventType type, Trip data) {
        this.type = type;
        this.data = data;
    }
    public ResEntityChangeEvent(com.example.holidaysappsemester.utils.events.ChangeEventType type, Trip data, Trip oldData) {
        this.type = type;
        this.data = data;
        this.oldData=oldData;
    }

    public com.example.holidaysappsemester.utils.events.ChangeEventType getType() {
        return type;
    }

    public Trip getData() {
        return data;
    }

    public Trip getOldData() {
        return oldData;
    }
}