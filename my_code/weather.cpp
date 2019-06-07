#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

ostream& operator<<(ostream& os, const GPS& gps) {
    os << "latitude: " << gps.latitude << "; longitude: " << gps.longitude << endl;
    return os;
}

Weather::Weather(std::string nm, GPS loc) :
    station_nm(nm), my_loc(loc) {
}

string Weather::get_name() const{
    return station_nm;
}

int Weather::get_rating() const{
    return rating;
}

void Weather::set_rating(int new_rating) {
    rating = new_rating;
}

void Weather::add_reading(WReading wr){
    wreadings.push_back(wr);
}


ostream& operator<<(ostream& os, const Weather& w) {
    os << w.get_name() << ": rating" << w.get_rating() << " " << w.my_loc <<endl;
    return os;
}

ostream& operator<<(ostream& os, const WReading& wr) {
    os << "Date: " << wr.date << ", Temperature: " <<wr.temperature << ", Humidity: " << wr.humidity << ", Windspeed: " <<wr.windspeed <<endl;
    return os;
}

ostream& operator<<(ostream& os, const Date& date) {
    os << "Date: " << date.month << "/" << date.day << "/" << date.year << endl;
    return os;
}
