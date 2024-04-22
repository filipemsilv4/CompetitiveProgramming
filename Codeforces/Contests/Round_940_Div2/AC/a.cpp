#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define lli long long int

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> sticks;

    for (int i = 0, tmp; i < n; i++) {
      cin >> tmp;
      sticks.push_back(tmp);
    }

    sort(sticks.begin(), sticks.end());

    int lastv = sticks[0];
    int lastq = 1;
    int ans = 0;

    for (int i = 1; i < n; i++) {
      if (sticks[i] == lastv) {
        lastq++;
      } else {
        ans += lastq / 3;
        lastq = 1;
        lastv = sticks[i];
      }
    }

    ans += lastq / 3;

    // cout << "---> ";
    cout << ans << endl;
  }
}
