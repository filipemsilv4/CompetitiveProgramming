#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y; // 1x1, 2x2
    cin >> x >> y;

    int ans = 0;

    int desktops_with_max_2x2 = y / 2;
    y = y % 2;
    x -= desktops_with_max_2x2 * 7;

    ans += desktops_with_max_2x2;

    if (y == 1) {
      y--;
      x -= 11;

      ans++;
    }

    if (x > 0) {
      ans += x / 15;
      x = x % 15;
      if (x > 0) {
        ans++;
      }
    }

    // cout << "---> ";
    cout << ans << endl;
  }
}
