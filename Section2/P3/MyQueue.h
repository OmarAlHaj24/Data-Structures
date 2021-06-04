/**
 * @author: Omar Al Haj
 * @date: 6/4/2021
 */


#ifndef MYQUEUE_H
#define MYQUEUE_H
#include "MyList.h"

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
    try{
        if(this->size() == 0){
            throw "The Queue Is Empty";
        }
        return *(this->begin());
    }
    catch(const char * arr){
        std::cout << arr << std::endl;
        exit(0);
    }
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
