/**
* Author : Celal Salih Türkmen
* ID: 22102498
* Section : 3
* Homework : 3
* Description :  General maxheap implementation
*/
#include "Heap.h"
template <class T>
void Heap<T>::heapRebuild(int i) {
    int child = 2*i+1;
    if (child < size) {
        if (child+1<size && arr[child+1] > arr[child]) {
            child++;
        }
        if (arr[child] > arr[i]) {
            swap(arr[child], arr[i]);
            heapRebuild(child);
        }
    } 
}
template <class T>
Heap<T>::Heap() : size(0) {
    arr = new T[MAX_SIZE];
}
template <class T>
Heap<T>::~Heap() {
    delete[] arr;
}
template <class T>
void Heap<T>::insert(T item) {
    if (size == MAX_SIZE) {
        throw runtime_error("Heap is full");
    }
    arr[size] = item;
    int i = size;
    int parent = (i-1)/2;
    while (i > 0 && arr[i] > arr[parent]) {
        swap(arr[i], arr[parent]);
        i = parent;
        parent = (i-1)/2;
    }
    size++;
}
template <class T>
void Heap<T>::remove() {
    if (!size) {
        throw runtime_error("Heap is empty");
    }
    arr[0] = arr[size - 1];
    size--;
    heapRebuild(0);
}
template <class T>
bool Heap<T>::empty() const {
    return !size;
}
template <class T>
T Heap<T>::peek() const {
    if (size) {
        return arr[0];
    }
    else {
        throw runtime_error("Heap is empty");
    }
}
template <class T>
int Heap<T>::getSize() const {
    return size;
}
template class Heap<Food>;
