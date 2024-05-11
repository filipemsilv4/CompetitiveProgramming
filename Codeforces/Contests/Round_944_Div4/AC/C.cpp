#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (c > d)
      swap(c, d);
    if (a > b)
      swap(a, b);

    if ((a > c && a < d) && (b < c || b > d)) {
      cout << "YES" << endl;
      continue;
    } else if ((b > c && b < d) && (a < c || a > d)) {
      cout << "YES" << endl;
      continue;
    }

    cout << "NO" << endl;
  }
}
