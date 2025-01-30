#include<bits/stdc++.h>
using namespace std;

int main() {
    string binary = "1100";
    int decimal = 0;
    int n = binary.length();

    int power = n - 1;
    for (int i = 0; i < n; i++) {
      if (binary[i] == '1') {
        decimal = decimal + pow(2, power);
      }
      power--;
    }

    cout << decimal;
}