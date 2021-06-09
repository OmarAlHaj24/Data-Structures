#include <iostream>
#include "MyList1.h"

using namespace std;

int main()
{
    
        MyList<int> list1;
        MyList<int>::iterator it = list1.begin();
        MyList<int> list2;
        MyList<int>::iterator it2 = list2.begin();
        it = list1.insert(1, it);
        ++it;
        it = list1.insert(2, it);
        ++it;
        it = list1.insert(3, it);
        ++it;
        it = list1.insert(5, it);
        ++it;
        it = list1.insert(7, it);
        ++it;
        it = list1.insert(9, it);

        it2 = list2.insert(2, it2);
        ++it2;
        it2 = list2.insert(4, it2);
        ++it2;
        it2 = list2.insert(6, it2);
        ++it2;
        it2 = list2.insert(8, it2);
        ++it2;
        it2 = list2.insert(10, it2);

        cout << "list1: ";
        for (it = list1.begin(); it != list1.end(); ++it)
            cout << *it << " ";
        cout << endl;

        cout << "List2: ";
        for (it2 = list2.begin(); it2 != list2.end(); ++it2)
            cout << *it2 << " ";
        cout << endl;

        it = list1.begin();
        it2 = list2.begin();

        while (it != list1.end() && it2 != list2.end()) {
            if (*it2 < *it) {
                it = list1.insert(*it2, it);
                ++it;
                it2 = list2.erase(it2);
            }
            else if (*it < *it2) {
                ++it;
            }
            else {
                it2 = list2.erase(it2);
            }
        }

        while (it2 != list2.end()) {
            list1.insert(*it2, list1.end());
            it2 = list2.erase(it2);
        }

        cout << "After merging List1 and List2: ";
        for (it = list1.begin(); it != list1.end(); ++it)
            cout << *it << " ";
        cout << endl;
        
    //cout << *it;
    return 0;
}

