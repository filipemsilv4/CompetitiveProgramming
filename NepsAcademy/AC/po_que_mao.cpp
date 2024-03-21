#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v(3);
  int candies;
  cin >> candies >> v[0] >> v[1] >> v[2];

  sort(v.begin(), v.end());

  if (v[0] > candies) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 0;
  for (int i = 0; i < v.size(); i++) {
    candies = candies - v[i];
    if (candies < 0) {
      break;
    }
    ans++;
  }

  cout << ans << endl;

  return 0;
}
