#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

vector<int> factors(int n) {
  vector<int> f;
  for (int x = 2; x * x <= n; x++) {
    while (n % x == 0) {
      f.push_back(x);
      n /= x;
    }
  }

  if (n > 1)
    f.push_back(n);
  return f;
}

bool between(ulli is_between, ulli a, ulli b) {
  if (is_between >= a && is_between <= b)
    return true;
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ulli l, r;
    cin >> l >> r;

    ulli before = 1;
    while (before * 2 <= l) {
      before *= 2;
    }

    bool found = false;

    ulli after = before * 2;
    while (after <= r) {
      if (after * 2 > r) {
        // cout << "after: " << after << " | factors: ";
        cout << factors(after).size() << endl;
        found = true;
        break;
      }
      after *= 2;
    }

    if (found)
      continue;

    // binary search
    ulli sl = before, sr = after, mid;
    ulli ans = 1;
    while (!found) {
      mid = sl + ((sr - sl) / 2);
      if (between(mid, l, r)) {
        ans = mid;
        break;
      } else if (mid < l) {
        sl = mid;
      } else {
        sr = mid;
      }
    }

    // cout << "ans: " << ans << " | factors: ";
    cout << factors(mid).size() << endl;
  }
}
