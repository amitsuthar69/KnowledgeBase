#include <bits/stdc++.h>
using namespace std;

struct MaxHeap {
  vector<int>h;
  MaxHeap(): h(1) {} // reserve 0th index for 1-based indexing

  // insert: lead->root, worst O(logn)
  void insert(int elem) {
    h.push_back(elem);         // put the new element in the valid complete tree position
    int i = (int)h.size() - 1; // get its index
    while (i > 1 && h[i] > h[i/2]) {
      swap(h[i], h[i/2]);
      i /= 2;
    }
  }

  // heapify at i: shift-down O(logn)
  void heapify(int i) {
    int n = (int)h.size()-1;
    while (true) {
      int l_c = 2*i, r_c = 2*i+1, maxi = i;
      if (l_c <= n && h[l_c] > h[maxi]) maxi = l_c;
      if (r_c <= n && h[r_c] > h[maxi]) maxi = r_c;
      if (maxi == i) break;
      swap(h[i], h[maxi]);
      i = maxi;
    }
  }

  // Build heap by inserting. (nlogn)
  void buildByInsert(vector<int> &a) {
    h.assign(1, 0);
    for (auto e : a) insert(e);
  }

  // Build heap by heapifying (bottom-up) (log n)
  void buildHeap(vector<int>& a) {
    h = {0}; // reset
    h.insert(h.end(), a.begin(), a.end()); // Copy elements
    
    int n = (int)h.size()-1;
    for (int i = n/2; i >= 1; i--) {
      heapify(i);
    }
  }

  int popMax() {
    int mx = h[1];   // in maxheap, root is always max
    h[1] = h.back(); // bring the last element at root
    h.pop_back();    // get rid of the last value
    heapify(1);      // heapify again to get max on top
    return mx;
  }

  vector<int> heapSort() {
    vector<int>sorted;
    int n = (int)h.size()-1;
    for (int i = 0; i < n; i++) {
      sorted.push_back(popMax());
    }
    return sorted;
  }

};

int main() {
  MaxHeap H;
  vector<int>a = {3,1,4,1,5,9,2,6};
  H.buildHeap(a);
  for (auto i : H.h) {
    cout << i << " ";
  }
  H.insert(7);
  cout << endl;
  for (auto i : H.h) {
    cout << i << " ";
  }
  cout<<endl;
  auto s = H.heapSort();
  for (auto i : s) {
    cout << i << " ";
  }
}