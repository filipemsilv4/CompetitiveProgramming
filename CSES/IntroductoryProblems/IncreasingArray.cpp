// g++ -std=c++17 -o bin/out IncreasingArray.cpp && ./bin/out
#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

int main() {
  lli t;
  cin >> t;

  vector<lli> v(t + 1);
  for (lli i = 0; i < t; i++)
    cin >> v[i];

  lli ans = 0;
  for (lli i = 1; i < t; i++) {
    if (v[i] < v[i - 1]) {
      lli diff = v[i - 1] - v[i];
      ans += diff;
      v[i] += diff;
    }
  }

  cout << ans << endl;
}
