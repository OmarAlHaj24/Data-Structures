/**
 * @author: Omar Al Haj
 * @date: 6/4/2021
 */


#ifndef MYQSTACK_H
#define MYQSTACK_H
#include "MyQueue.h"


class MyQStack : protected MyQueue<int> {
public:
    MyQStack();
    int top();
    void pop();
    void push(int);
};

int MyQStack::top() {
    return this->front();
}

void MyQStack::pop() {
    MyQueue::pop();
}

void MyQStack::push(int value) {
    this->insert(value, this->begin());
}

MyQStack::MyQStack() : MyQueue<int>(){}


#endif //MYQSTACK_H
