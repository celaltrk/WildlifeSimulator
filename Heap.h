/**
* Author : Celal Salih Türkmen
* ID: 22102498
* Section : 3
* Homework : 3
* Description :  General maxheap header
*/
#ifndef __HEAP_H
#define __HEAP_H
#include <iostream>
#include "Food.h"
#include <stdexcept> 
using namespace std;
template <class T>
class Heap {
    private:
        static int const MAX_SIZE = 100;
        int size;
        T* arr;
        void heapRebuild(int i);
    public:
        Heap();
        ~Heap();
        void insert(T item);
        void remove();
        bool empty() const;
        T peek() const;
        int getSize() const;
};
#endif
