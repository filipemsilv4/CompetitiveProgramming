#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> c(n + 1);

  cin >> c[1];
  int compensate = abs(c[1]);
  c[1] += compensate;

  for (int i = 2; i <= n; i++) {
    cin >> c[i];
    c[i] += compensate;
  }

  int min_d, max_d;

  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      min_d = c[2] - c[i];
      max_d = c[i] - c[n];
    } else if (i == n) {
      min_d = c[i] - c[i - 1];
      max_d = c[i] - c[1];
    } else {
      max_d = max(c[i] - c[1], c[n] - c[i]);
      min_d = min(c[i] - c[i - 1], c[i + 1] - c[i]);
    }

    cout << abs(min_d) << " " << abs(max_d) << endl;
  }
}
