#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define lli unsigned long long int

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<int> a;

    for (int i = 0, tmp; i < n; i++) {
      cin >> tmp;
      a.push_back(tmp);
    }

    lli ans = 0;

    map<pair<pair<int, int>, int>, int> gen; // [[val, val], val], ammount
    map<pair<int, int>, int> mp0;            // [val1, val2]
    map<pair<int, int>, int> mp1;            // [val0, val2]
    map<pair<int, int>, int> mp2;            // [val0, val1]

    for (int i = 0; i < a.size() - 2; i++) {
      int val = gen[{{a[i], a[i + 1]}, a[i + 2]}];
      ans += mp0[{a[i + 1], a[i + 2]}] - val;
      ans += mp1[{a[i + 0], a[i + 2]}] - val;
      ans += mp2[{a[i + 0], a[i + 1]}] - val;

      gen[{{a[i], a[i + 1]}, a[i + 2]}]++;
      mp0[{a[i + 1], a[i + 2]}]++;
      mp1[{a[i + 0], a[i + 2]}]++;
      mp2[{a[i + 0], a[i + 1]}]++;
    }

    // cout << "---> ";
    cout << ans << endl;
  }
}
