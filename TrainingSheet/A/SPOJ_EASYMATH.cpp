#include <iostream>

using namespace std;

#define lli long long int

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m, a, d;
    cin >> n >> m >> a >> d;

    // find count of numbers between n and m (inclusive) not divisible by (a) or
    // (a+d) or (a+2d) or (a+3d) or (a+4d).

    int ans = 0;
    for (int i = n; i <= m; i++) {
      if (i % a != 0 && i % (a + d) != 0 && i % (a + 2 * d) != 0 &&
          i % (a + 3 * d) != 0 && i % (a + 4 * d) != 0) {
        ans++;
      }
    }

    cout << ans << endl;
  }
}
