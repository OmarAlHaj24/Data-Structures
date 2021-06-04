/**
 * @author: Omar Al Haj
 * @date: 6/4/2021
 */


#ifndef MYQUEUE_H
#define MYQUEUE_H
#include "MyList.h"
#include "MyList.cpp"

template <class T>
class MyQueue : protected MyList<T> {
public:
    MyQueue();
    MyQueue(T, int);
    T &front();
    void pop();
    void push(T);
    int size();
};

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
    return this->getSize();
}


#endif //MYQUEUE_H
