package com.example.holidaysappsemester.domain;

public class Trip extends Entity<Integer>{
    String objective;
    String transportCompany;
    String hour;
    Double price;
    Integer availableSpots;

    public Trip(Integer tripID, String objective, String transportCompany, String hour, Double price, Integer availableSpots) {
        setId(tripID);
        this.objective = objective;
        this.transportCompany = transportCompany;
        this.hour = hour;
        this.price = price;
        this.availableSpots = availableSpots;
    }

    public Integer getIdTrip(){
        return getId();
    }
    public void setId(Integer id){
        super.setId(id);
    }

    public String getObjective() {
        return objective;
    }

    public void setObjective(String objective) {
        this.objective = objective;
    }

    public String getTransportCompany() {
        return transportCompany;
    }

    public void setTransportCompany(String transportCompany) {
        this.transportCompany = transportCompany;
    }

    public String getHour() {
        return hour;
    }

    public void setHour(String hour) {
        this.hour = hour;
    }

    public Double getPrice() {
        return price;
    }

    public void setPrice(Double price) {
        this.price = price;
    }

    public Integer getAvailableSpots() {
        return availableSpots;
    }

    public void setAvailableSpots(Integer availableSpots) {
        this.availableSpots = availableSpots;
    }
}
