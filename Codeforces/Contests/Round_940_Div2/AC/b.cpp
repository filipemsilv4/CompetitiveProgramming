#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> ans(n);

    // cout << "---> ";

    if (n == 1) {
      cout << k << endl;
      continue;
    }

    int most = 0; // most significant bit of k
    for (int i = 0; i < sizeof(int) * 8; i++) {
      if ((1 << i) & k) {
        most = i;
      }
    }

    // (1 << most) <= k < (1 << most + 1)
    // cout << "most: " << most << " | ";
    ans[0] = (1 << most) - 1; // -1 so the binary representation will be all 1s
    ans[1] = k - ans[0];

    for (int i = 2; i < n; i++) {
      ans[i] = 0;
    }

    for (const auto &val : ans) {
      cout << val << " ";
    }

    cout << endl;
  }
}
