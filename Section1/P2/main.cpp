#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

template <typename t>
void insertionSort (vector<t> & a) {
  for (int i=1; i <= a.size(); ++i) {
    t tmp = a[i];
    int low = 0, high = i-1, mid;
    while (low < high) {
      mid = low + ((high - low) >> 1);
      if (a[mid] < a[i]) low = mid + 1;
      else high = mid;
    }
    for (int j = i; j > low; --j) {
      a[j] = a[j-1];
    }
    a[low] = tmp;
  }
}

int main() {

  vector<int> vect;
  srand (time(0));
  for(int i = 0 ; i < 500 ; i++){
    vect.push_back(rand()%10000);
  }
  insertionSort(vect);
  for (int i=0; i<vect.size(); ++i) {
    cout << vect[i] << " ";
  }

  return 0;
}
