#include <bits/stdc++.h>
#include "MyList.h"
#include "MyQueue.h"
#include "MyQStack.h"
using namespace std;

int main() {
    MyQueue <string> queue;
    queue.push("Five");
    cout << queue.front() << endl;
    queue.pop();
    cout << queue.size() << endl;
    cout << "-------------\n";
    MyQStack qStack;
    qStack.push(5);
    qStack.push(10);
    cout << qStack.top() << endl;
    qStack.pop();
    cout << qStack.top() << endl;
    qStack.pop();
    cout << qStack.top() << endl;
}