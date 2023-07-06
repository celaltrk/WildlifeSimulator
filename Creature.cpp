/**
* Author : Celal Salih Türkmen
* ID: 22102498
* Section : 3
* Homework : 3
* Description : Creature class with some functionalities
*/
#include "Creature.h"
Creature::Creature() : loc({0,0}), id(0), health(0) {}
Creature::Creature(pair<double,double> loc, int id, int health) : loc(loc), id(id), health(health) {}
int Creature::getID() const {
    return id;
}
void Creature::setID(int ID) {
    this->id = id;
}
int Creature::getHealth() const {
    return health;
}
void Creature::setHealth(int health) {
    this->health = health;
}
pair<double,double> Creature::getLocation() const {
    return loc;
}
void Creature::setLocation(double x, double y) {
    loc = {x,y};
}
void Creature::kill(Creature& c) const {
    if (isDead()) return; // dead creatures do not kill
    c.setHealth(0);
}
void Creature::move(const Food& food) {
    if (isDead()) return; // dead creatures do not move
    double t0 = food.getLocation().first - loc.first;
    double t1 = food.getLocation().second - loc.second;
    double len = sqrt(t0*t0 + t1*t1);
    if (len == 0) return;
    pair<double, double> u = {t0/len, t1/len};
    if (health <= 10.0) {
        loc.first += u.first;
        loc.second += u.second;
    } 
    else {
        double k = 10.0/health;
        loc.first += k*u.first;
        loc.second += k*u.second;
    }
}
void Creature::eat(const Food& food) {
    if (isDead()) return; // dead creatures do not eat
    health += food.getQuality();
}

bool Creature::isCreatureClose(const Creature& creature) const {
    double t0 = creature.getLocation().first - loc.first;
    double t1 = creature.getLocation().second - loc.second;
    return t0*t0 + t1*t1 < 4;
}
bool Creature::isFoodClose(const Food& food) const {
    double t0 = food.getLocation().first - loc.first;
    double t1 = food.getLocation().second - loc.second;
    return t0*t0 + t1*t1 < 1;
}
void Creature::loseHealth() {
    if (isDead()) return;
    health--;
    if (health < 0)
    health = 0;
}
ostream& operator<<(ostream& os, const Creature& obj) {
    os << "Creature " << obj.id << ": " << fixed << setprecision(2) << obj.getLocation().first << ", " << fixed << setprecision(2) << obj.getLocation().second;
    return os;
}
bool Creature::operator<(const Creature& cr) const {
    return id < cr.id;
}
bool Creature::isDead() const {
    return health <= 0;
}


