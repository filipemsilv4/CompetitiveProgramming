#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v(4);

  for (int i = 0; i < 4; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  int t1 = v[0] + v[3];
  int t2 = v[1] + v[2];

  int ans = t1 - t2;
  if (ans < 0)
    ans = t2 - t1;

  cout << ans << endl;

  return 0;
}
