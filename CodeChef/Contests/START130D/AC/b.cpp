#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  string a, b;
  string a_r, b_r;
  for (int i = 0; i < t; i++) {
    cin >> a >> b;
    a_r = a;
    b_r = b;
    reverse(a_r.begin(), a_r.end());
    reverse(b_r.begin(), b_r.end());

    // cout << "a_r: " << a_r << endl;
    // cout << "b_r: " << b_r << endl;

    if (a > b || a > b_r || a_r > b || a_r > b_r) {
      cout << "Yes" << endl;
      continue;
    }
    cout << "No" << endl;
  }
}
