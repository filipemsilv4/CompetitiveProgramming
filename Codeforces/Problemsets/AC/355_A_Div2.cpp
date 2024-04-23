// https://codeforces.com/contest/677/problem/A
#include <iostream>

using namespace std;

#define lli long long int

int main() {
  int n, h;
  cin >> n >> h;

  int ans = 0;

  for (int i = 0, a; i < n; i++) {
    cin >> a;
    if (a > h) {
      ans += 2;
    } else {
      ans += 1;
    }
  }

  cout << ans << endl;
}
