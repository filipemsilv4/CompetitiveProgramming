#include <climits>
#include <iostream>

using namespace std;

// Euclid's algorithm
int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int x;
    cin >> x;

    int max_v = INT_MIN;
    int ans = x - 1;
    for (int y = x - 1; y >= x / 2; y--) {
      int val = gcd(x, y) + y;

      if (val > max_v) {
        max_v = val;
        ans = y;
      }
    }

    cout << ans << endl;
  }
}
