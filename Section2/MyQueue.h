/**
 * @author: Omar Al Haj
 * @date: 6/4/2021
 */


#ifndef C___PRACTICING_MYQUEUE_H
#define C___PRACTICING_MYQUEUE_H
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


#endif //C___PRACTICING_MYQUEUE_H
