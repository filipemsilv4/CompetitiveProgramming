#include <iostream>
#include <vector>

using namespace std;

const vector<int> coins = {100, 50, 25, 10, 5, 1};

int main() {
  int N;
  cin >> N;

  int ans = 0;
  for (int i = 0; N > 0 && i < coins.size(); i++) {
    while (N >= coins[i]) {
      N -= coins[i];
      ans++;
    }
  }

  cout << ans << endl;
}
