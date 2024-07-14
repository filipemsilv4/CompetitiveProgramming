#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <ostream>
#include <queue>
#include <vector>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    lli n, k;
    cin >> n >> k;
    vector<lli> a(k);

    lli bp = LONG_LONG_MIN;
    lli bpi = -1;
    for (int i = 0; i < k; i++) {
      cin >> a[i];
      if (a[i] > bp) {
        bp = a[i];
        bpi = i;
      }
    }

    if (bp == 1) {
      cout << n - 1 << endl;
      continue;
    }

    // cout << "bp: " << bp << "bpi: " << bpi << endl;
    lli ans = 0;
    for (int i = 0; i < k; i++) {
      if (i == bpi) continue;
      ans += (2 * a[i] - 1);
    }

    // cout << "----> ";
    cout << ans << endl;
  }
}
