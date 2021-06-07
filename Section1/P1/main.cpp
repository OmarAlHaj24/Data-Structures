#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

/**
 Merge Sort
 */
template <typename t>
void merge (vector<t>& a, vector<t>& tmp, int low, int mid, int high) {
  int lst = low, rst = mid + 1, pos = low - 1;
  while (lst <= mid && rst <= high) {
    if (a[lst] < a[rst]) tmp[++pos] = a[lst++];
    else tmp[++pos] = a[rst++];
  }
  while (lst <= mid) tmp[++pos] = a[lst++];
  while (rst <= high) tmp[++pos] = a[rst++];
  while (low <= high) {
    a[low] = tmp[low];
    ++low;
  }
}

template <typename t>
void mergeSort (vector<t>& a, vector<t>& tmp, int low, int high) {
  if (low >= high) return;
  int mid = (low + high) >> 1;
  mergeSort(a, tmp, low, mid);
  mergeSort(a, tmp, mid+1, high);
  merge(a, tmp, low, mid, high);
}

template <typename t>
void mergeSort (vector<t>& a) {
  vector<t> tmp (a.size());
  mergeSort (a, tmp, 0, (int)a.size() - 1);
}

/**
 Quick Sort
 */

template <typename t>
void insertionSort (vector<t>& a, int low, int high) {
  int j;
  t tmp;
  for (int i=low+1; i <= high; ++i) {
    tmp = a[i];
    for (j = i; j > low && tmp < a[j-1]; --j)
      a[j] = a[j-1];
    a[j] = tmp;
  }
}

template <typename t>
const t& median3 (vector<t>& a, int low, int high) {
  int mid = (low + high) >> 1;
  if (a[mid] < a[low]) swap(a[low], a[mid]);
  if (a[high] < a[low]) swap(a[low], a[high]);
  if (a[high] < a[mid]) swap(a[mid], a[high]);
  swap(a[mid], a[high-1]);
  return a[high-1];
}

template <typename t>
void quickSort (vector<t>& a, int low, int high) {
  if (low + 10 > high) {
    insertionSort(a, low, high);
    return;
  }
  const t& povit = median3 (a, low ,high);
  int l = low, r = high - 1;
  while (true) {
    while (a[++l] < povit);
    while (a[--r] > povit);
    if (l < r) swap(a[l], a[r]);
    else break;
  }
  swap (a[l], a[high - 1]);
  quickSort (a, low, l-1);
  quickSort(a, l+1, high);
}

template <typename t>
void quickSort (vector<t>& a) {
  quickSort(a, 0, (int) a.size() - 1);
}

/**
 Main
 */
int main() {

  vector<int> vect;
  srand (time(0));
  for(int i = 0 ; i < 5000 ; i++){
    vect.push_back(rand()%10000);
  }
  auto start = high_resolution_clock::now();
  quickSort(vect);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
  return 0;
}
