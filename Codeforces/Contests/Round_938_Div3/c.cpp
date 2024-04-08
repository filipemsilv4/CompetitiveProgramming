#include <iostream>
#include <vector>

using namespace std;

void testcase() {
  int n, k;
  cin >> n >> k;
  vector<int> ships(n);
  int fs = 0, ls = n - 1; // first ship index, last ship index

  for (int i = 0; i < n; i++) {
    cin >> ships[i];
  }

  int ans = 0;

  bool first_turn = false;
  while (k > 0 && fs <= ls) {
    first_turn = !first_turn;
    if (ships[fs] < 1) {
      fs++;
      ans++;
    }
    if (ships[ls] < 1) {
      ls--;
      ans++;
    }

    // who is weaker?
    int weaker;
    ships[ls] < ships[fs] ? weaker = ls : weaker = fs;

    if (k / 2 > ships[weaker]) {
      k -= ships[weaker] * 2;
      if (weaker == fs) {
        fs++;
        ans++;
        ships[ls] -= ships[weaker];
        continue;
      }
      ls--;
      ans++;
      ships[fs] -= ships[weaker];
      continue;
    }

    if (first_turn) {
      ships[fs]--;
      if (ships[fs] < 1) {
        fs++;
        ans++;
      }
    } else {
      ships[ls]--;
      if (ships[ls] < 1) {
        ls--;
        ans++;
      }
    }

    k--;
  }

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    testcase();
  }
}
