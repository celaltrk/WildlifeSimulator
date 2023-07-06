/**
* Author : Celal Salih Türkmen
* ID: 22102498
* Section : 3
* Homework : 3
* Description : Wildlife simulation game. Creatures kill each other to eat the spawned foods.
*/
#include <iostream>
#include "Food.h"
#include "Creature.h"
#include "Heap.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
void game(vector<Creature>& creatures, Heap<Food>& futureFoods);
void initialize(const string& inputFile, vector<Creature>& creatures, Heap<Food>& foods) {
    ifstream ifs(inputFile); 
    if (ifs.is_open()) { 
        int N;
        string line;
        getline(ifs, line);
        N = stoi(line);
        for (int i = 0; i < N; i++) {
            int id, h;
            double x, y;
            getline(ifs, line);
            stringstream ss(line);
            getline(ss, line, ',');
            id = stoi(line);
            getline(ss, line, ',');
            x = stod(line);
            getline(ss, line, ',');
            y = stod(line);
            getline(ss, line, ',');
            h = stoi(line);
            Creature c({x,y}, id, h);
            creatures.push_back(c);
        }
        while (getline(ifs, line)) {  
            int id, q, t;
            double x, y;
            stringstream ss(line);
            getline(ss, line, ',');
            id = stoi(line);
            getline(ss, line, ',');
            x = stod(line);
            getline(ss, line, ',');
            y = stod(line);
            getline(ss, line, ',');
            q = stoi(line);
            getline(ss, line, ',');
            t = stoi(line);
            Food f({x,y}, id, q, t, 0);
            foods.insert(f);
        }
        ifs.close();
        sort(creatures.begin(), creatures.end());
    } 
    else {
        throw runtime_error("Failed to open input file: " + inputFile);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Incorrect args" << endl;
        return 1;
    }
    vector<Creature> creatures;
    Heap<Food> foods;
    try {
        initialize(argv[1], creatures, foods);
        game(creatures, foods);
    } 
    catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
        return 1;
    }
    return 0;
}
void foodExchange(Heap<Food>& futureFoods, Heap<Food>& currentFoods, int t) {
    if (futureFoods.empty() || futureFoods.peek().getTime() != t) return;
    Food f = futureFoods.peek();
    do {
        f = futureFoods.peek(); 
        futureFoods.remove();
        f.setIfExists(1); 
        currentFoods.insert(f);
    }
    while(!futureFoods.empty() && futureFoods.peek().getTime() == f.getTime());
}
void fight(vector<Creature>& creatures) {
    for (int i = 0; i < creatures.size(); i++) {
        if (creatures[i].isDead()) continue;
        for (int j = 0; j < creatures.size(); j++) {
            if (i == j) continue;
            if (creatures[j].isDead()) continue;
            if (creatures[i].isCreatureClose(creatures[j]) && creatures[i].getHealth() >= creatures[j].getHealth())
                creatures[i].kill(creatures[j]);
        }
    }
}
void foodConsume(vector<Creature>& creatures, Heap<Food>& currentFoods) {
    for (int i = 0; i < creatures.size() && !currentFoods.empty(); i++) {
        if (creatures[i].isDead()) continue;
        if (creatures[i].isFoodClose(currentFoods.peek())) {
            creatures[i].eat(currentFoods.peek());
            currentFoods.remove();
        }
    }
    if (currentFoods.empty()) return;
    for (int i = 0; i < creatures.size(); i++) {
        if (creatures[i].isDead()) continue;
            creatures[i].move(currentFoods.peek());
    }
}
void game(vector<Creature>& creatures, Heap<Food>& futureFoods) {
    Heap<Food> currentFoods;
    int t = 0;
    bool allDead = false;
    while(!allDead) {
        // STEP 1
        for (int i = 0; i < creatures.size(); i++)
            cout << creatures[i] << endl;
        // STEP 2
        foodExchange(futureFoods, currentFoods, t);
        // STEP 3
        fight(creatures);
        // STEP 4
        foodConsume(creatures, currentFoods);
        // STEP 5
        allDead = true;
        for (int i = 0; i < creatures.size(); i++) {
            creatures[i].loseHealth();
            if (!creatures[i].isDead())
                allDead = false;
        }
        t++;
    }
}

