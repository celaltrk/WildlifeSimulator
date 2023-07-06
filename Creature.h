/**
* Author : Celal Salih Türkmen
* ID: 22102498
* Section : 3
* Homework : 3
* Description : Creature header with some functionalities
*/
#ifndef __CREATURE_H
#define __CREATURE_H
#include <iostream>
#include <math.h>
#include <iomanip>
#include "Food.h"
using namespace std;
class Creature {
    private:
        pair<double,double> loc;
        int id;
        int health;
    public:
        Creature();
        Creature(pair<double,double> loc, int id, int health);
        int getID() const;
        void setID(int ID);
        int getHealth() const;
        void setHealth(int health);
        pair<double,double> getLocation() const;
        void setLocation(double x, double y);
        void kill(Creature& c) const;
        void move(const Food& food);
        void eat(const Food& food);
        bool isCreatureClose(const Creature& creature) const;
        bool isFoodClose(const Food& food) const;
        void loseHealth();
        friend ostream& operator<<(ostream& os, const Creature& obj);
        bool operator<(const Creature& cr) const;
        bool isDead() const;
};
#endif
