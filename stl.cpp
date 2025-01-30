#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// data types-> int, float, char, boolean
int main() {
    // set, map
      set<int> s;
      s.insert(4);
      s.insert(5);
      s.insert(4);
       s.insert(6);
      s.insert(0);
       s.insert(8);
      s.insert(9);

      cout << *(s.upper_bound(4)) << endl;

      for (auto it : s){
        cout << it << " ";
      }
}