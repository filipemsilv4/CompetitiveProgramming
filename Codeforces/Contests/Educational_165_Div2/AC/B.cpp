#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

int main() {
  lli t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    if (is_sorted(s.begin(), s.end())) {
      cout << 0 << endl;
      continue;
    }

    lli ptr1 = 0;
    while (s[ptr1] == '0' && ptr1 < s.length())
      ++ptr1;

    lli ans = 0;
    lli ptr2 = ptr1 + 1;
    while (ptr2 < s.length()) {
      if (s[ptr2] == '0') {
          ans += ptr2 - ptr1 + 1;
          swap(s[ptr2], s[ptr1]);
          ptr1++;
      }
      ptr2++;
    }

    // cout << "----> ";
    cout << ans << endl;
  }
}
