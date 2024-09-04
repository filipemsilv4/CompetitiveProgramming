/*
g++ -std=c++17 -o bin/out 849_E_Div4.cpp && ./bin/out
*/

#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;

int main() {
  lli t;
  cin >> t;
  while (t--) {
    lli n;
    cin >> n;
    lli abs_sum = 0, neg_cnt = 0, smallest_abs = LONG_MAX;
    for (lli i = 0, tmp; i < n; i++) {
      cin >> tmp;
      abs_sum += abs(tmp);
      if (tmp < 0)
        neg_cnt++;
      if (abs(tmp) < smallest_abs)
        smallest_abs = abs(tmp);
    }

    // cout << "-----> ";
    if (neg_cnt % 2ll == 0ll || smallest_abs == 0ll){
        cout << abs_sum << endl;
        continue;
    }

    cout << abs_sum - (2ll * smallest_abs) << endl;

  }
}
