#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  int n, tmp;
  for (int i = 0; i < t; i++) {
    cin >> n;

    if (n == 1) {
      cout << "YES" << endl;
      continue;
    }

    vector<int> a;

    for (int i = 0; i < n; i++) {
      cin >> tmp;
      a.push_back(tmp);
    }

    if (n == 2) {
      if (a[0] == a[1])
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
      continue;
    }

    if (a[0] > a[1] || a[n - 1] > a[n - 2]) {
      cout << "NO" << endl;
      continue;
    }

    for (int i = 1; i < n - 1; i++) {
      if (a[i] < a[i - 1] || a[i] < a[i + 1])
        continue;
      int m = max(a[i - 1], a[i + 1]);
      a[i] = m;
    }
  }
}
