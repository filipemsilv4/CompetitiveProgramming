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
  lli n, l;
  cin >> n >> l;

  vector<lli> ot(n);

  for (lli i = 0; i < n; i++) {
    cin >> ot[i];
  }

  sort(ot.rbegin(), ot.rend());

  lli ans = 0;
  for (lli i = 0; i < n; i++) {
    if (l < (100ll - ot[i])) {
      break;
    }

    l = l - (100ll - ot[i]);
    ++ans;
  }

  cout << ans << endl;
}
