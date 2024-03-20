#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];

  int tmp;
  int ans;
  // 1 floor
  tmp = a[1] + a[2] * 2;
  ans = tmp;
  // 2 floor
  tmp = a[0] + a[2];
  if (tmp < ans)
    ans = tmp;
  // 3 floor
  tmp = a[0] * 2 + a[1];
  if (tmp < ans)
    ans = tmp;

  cout << ans * 2 << endl;

  return 0;
}
