package com.example.holidaysappsemester.domain;

public class Reservation extends Entity<Integer>{
    Integer excursionId;
    String clientName;
    String phoneNumber;
    Integer noTickets;


    public Reservation(Integer resID,Integer excursionId, String clientName, String phoneNumber, Integer noTickets) {
        setId(resID);
        this.excursionId = excursionId;
        this.clientName = clientName;
        this.phoneNumber = phoneNumber;
        this.noTickets = noTickets;
    }

    public Integer getIdRes(){
        return getId();
    }

    public void setId(Integer id){
        super.setId(id);
    }

    public Integer getExcursionId() {
        return excursionId;
    }

    public void setExcursionId(Integer excursionId) {
        this.excursionId = excursionId;
    }

    public String getClientName() {
        return clientName;
    }

    public void setClientName(String clientName) {
        this.clientName = clientName;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public Integer getNoTickets() {
        return noTickets;
    }

    public void setNoTickets(Integer noTickets) {
        this.noTickets = noTickets;
    }
}
