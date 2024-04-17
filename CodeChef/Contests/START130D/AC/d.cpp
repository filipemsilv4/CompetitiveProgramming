#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

#define lli long long int

void testcase() {
  int n;
  cin >> n;
  vector<lli> a(n);

  lli min_v = LONG_LONG_MAX;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    min_v = min(min_v, a[i]);
  }

  if (a[0] == min_v && a[n - 1] == min_v) {
    cout << "YES" << endl;
    return;
  }

  cout << "NO" << endl;
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    testcase();
}
