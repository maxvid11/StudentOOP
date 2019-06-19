#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

/*
 * A constructor for weather class.
 * */
Weather::Weather(std::string nm, GPS loc) :
station_nm(nm), my_loc(loc) {
}

ostream& operator<< (std::ostream& os, const Weather& w){
    os << "Name: " << w.station_nm << endl;
    os << "Latitude: " << w.my_loc.latitude << ", Longitude: " << w.my_loc.longitude << ", Rating: " << w.rating << endl;
    for(WReading reading: w.wreadings){
        os << reading << endl;
        }
    return os;
}
int Weather::get_rating() const {
    return rating;
}

void Weather::set_rating(int new_rating){
    rating = new_rating;
}

void Weather::add_reading(WReading w){
    wreadings.push_back(w);
}

string Weather::get_name() const {
    return station_nm;
}

std::ostream& operator<<(std::ostream& os, const WReading& wr){
    os << "Date: " << wr.date << "; Temp: " << wr.temperature << "; Humidity: " << wr.humidity << "; Windspeed: " << wr.windspeed;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Date& date){
    os << date.month << "/" << date.day << "/" << date.year;
    return os;
}

const double F_TO_C = 5 / 9;
const double C_TO_F = 9 / 5;

Image::Image(int w, int h, std::string flnm)
: width(w), height(h)
{
    filename = flnm;
    image_buf = new char[image_sz()];
}

// copy constructor:
Image::Image(const Image& img2) {
    copy_fields(img2);
}

Image::~Image() {
    delete[] image_buf;
}

Image& Image::operator=(const Image& img2) {
    if(&img2 == this){
        return *this;
        }
    width = 0;
    height = 0;
    filename = "";
    delete image_buf;

    copy_fields(img2);
    return *this;
}

int Image::image_sz() {
    return width * height;
}


void Image::copy_fields(const Image& img2) {
    width = img2.width;
    height = img2.height;
    filename = img2.filename;
    image_buf = new char(*img2.image_buf);
}


Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}


double WReading::get_tempF() {
    return (temperature * C_TO_F) + 32;
}

void Image::display(){
    cout << "Base" << endl;
}

void Jpeg::display(){
    cout << "Jpeg" << endl;
}

void Gif::display(){
    cout << "Gif" << endl;
}

void Png::display(){
    cout << "Png" << endl;
}

Image* WReading::get_image() const {
    return image;
}

void Weather::display_images() const{
    for(WReading reading: wreadings){
        Image* image = reading.get_image();
        image->display();
        }
}
