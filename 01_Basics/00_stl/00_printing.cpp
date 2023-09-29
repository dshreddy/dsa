// Source : https://www.hackerrank.com/challenges/prettyprint/

#include <bits/stdc++.h>
using namespace std;

int main() {

  double A = 100.345;
  double B = 2006.008;
  double C = 2331.41592653498;

  cout << hex << left << showbase << nouppercase << (long long)A << endl;
  cout << setprecision(2) << setw(15) << right << showpos << fixed
       << setfill('_') << B << endl;
  cout << setprecision(9) << uppercase << scientific << noshowpos << C << endl;
}
