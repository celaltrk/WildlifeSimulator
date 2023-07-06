/**
* Author : Celal Salih Türkmen
* ID: 22102498
* Section : 3
* Homework : 3
* Description : Food header
*/
#ifndef __FOOD_H
#define __FOOD_H
#include <iostream>
#include <iomanip>
using namespace std;

class Food {
    private:
        pair<double,double> loc;
        int id;
        int quality;
        int time;
        bool exist;
    public:
        Food();
        Food(pair<double,double> loc, int id, int quality, int time, bool exist);
        int getID() const;
        void setID(int ID);
        int getQuality() const;
        void setQuality(int quality);
        pair<double,double> getLocation() const;
        void setLocation(double x, double y);
        bool operator>(const Food& food) const;
        int getTime() const;
        void setTime(int time);
        void setIfExists(bool e);
        bool doesExist() const;
};
#endif