#include <bits/stdc++.h>
#include "Stack.h"
#define ll long long
#define _ ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;

bool checkValidity(string input, Stack <char> myStack){
    for(int i = 0; i < input.size(); ++i){
        if(!myStack.IsEmpty() && *myStack.Top() == '*'){
            if(input[i] != '*'){
                continue;
            }
        }
        if(input[i] == '(' || input[i] == '[' || input[i] == '{'){
            myStack.Push(input[i]);
        }else if(input[i] == '/' && input.size() - 1 > i && input[i + 1] == '*'){
            myStack.Push(input[i]);
            myStack.Push(input[i + 1]);
        }
        if(input[i] == ')'){
            if(*myStack.Top() == '('){
                myStack.Pop();
            }else{
                return false;
            }
        }
        if(input[i] == ']'){
            if(*myStack.Top() == '['){
                myStack.Pop();
            }else{
                return false;
            }
        }
        if(input[i] == '}'){
            if(*myStack.Top() == '{'){
                myStack.Pop();
            }else{
                return false;
            }
        }
        if(input[i] == '*' && input.size() - 1 > i && input[i + 1] == '/'){
            if(*myStack.Top() == '*'){
                myStack.Pop();
                myStack.Pop();
            }else{
                return false;
            }
        }
    }
    if(myStack.size() != 0){
        return false;
    }
    return true;
}

int main() { _
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin); //freopen("output.out", "w", stdout);
#endif
    string arr[] = {"([{}])(){}[]{[]}", "({)}", "({/*)}]]]]]]}*/})", "({/*[][[]]]]]})", "[{/*******/}]"};
    for(int i = 0; i < 5; ++i){
        Stack <char> myStack;
        if(checkValidity(arr[i], myStack)){
            cout << "Valid\n";
        }else{
            cout << "Invalid\n";
        }
    }
}