/**
* Author : Celal Salih Türkmen
* ID: 22102498
* Section : 3
* Homework : 3
* Description : Food class
*/
#include "Food.h"
Food::Food() : loc({0,0}), id(0), quality(0), time(0), exist(0) {}
Food::Food(pair<double,double> loc, int id, int quality, int time, bool exist) : loc(loc), id(id), quality(quality), time(time), exist(exist) {}
int Food::getID() const {
    return id;
}
void Food::setID(int ID) {
    this->id = id;
}
int Food::getQuality() const {
    return quality;
}
void Food::setQuality(int quality) {
    this->quality = quality;
}
pair<double,double> Food::getLocation() const {
    return loc;
}
void Food::setLocation(double x, double y) {
    loc = {x,y};
}
bool Food::operator>(const Food& food) const {
    if (!exist) {
        if (time != food.time)
            return time < food.time;
        else
            return id < food.id;
    }
    if (quality != food.quality)
        return quality > food.quality;
    else
        return id < food.id; 
}
int Food::getTime() const {
    return time;
}
void Food::setTime(int time) {
    this->time = time;
}
void Food::setIfExists(bool e) {
    exist = e;
}
bool Food::doesExist() const {
    return exist;
}