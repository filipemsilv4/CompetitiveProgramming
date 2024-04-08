#include <iostream>

using namespace std;

void testcase() {
  int n, a, b;
  cin >> n >> a >> b;

  if (b > 2 * a) {
    cout << n * a << endl;
    return;
  }

  int ans = 0;
  if (n % 2 != 0) {
    if (n == 1) {
      cout << n * a << endl;
      return;
    }
    n--;
    ans += a;
  }

  cout << ans + ((n / 2) * b) << endl;
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    testcase();
  }
}
