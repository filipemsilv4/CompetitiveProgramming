#include <iostream>

using namespace std;

int main() {
  int k, r; // shovel price, coin
  cin >> k >> r;

  int ans = 0;

  int min_price = k;
  while (true) {
    if (min_price % 10 == 0) {
      ans++;
      break;
    }
    if (min_price % 10 == r) {
      ans++;
      break;
    }
    ans++;
    min_price += k;
  }

  cout << ans << endl;
}
