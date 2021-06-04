/**
 * @author: Omar Al Haj
 * @date: 6/4/2021
 */


#include "MyQueue.h"


template<class T>
MyQueue<T>::MyQueue() : MyList<T>() {}

template<class T>
MyQueue<T>::MyQueue(T data, int size): MyList<T>(data, size){}

template<class T>
T &MyQueue<T>::front() {
    return *(this->begin());
}

template<class T>
void MyQueue<T>::pop(){
    this->erase(this->begin());
}

template<class T>
void MyQueue<T>::push(T data) {
    this->insert(data, this->end());
}

template<class T>
int MyQueue<T>::size() {
    this->getSize();
}
