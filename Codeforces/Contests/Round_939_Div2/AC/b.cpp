#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void game() {
  int n;
  cin >> n;

  vector<int> ur_crds(n + 1); // <card, ammount>

  // Since u are the first to play, u can only get a point when there's 2 cards
  // of same number in ur hand. Stupid game.
  int ans = 0;
  for (int i = 1, tmp; i <= n; i++) {
    cin >> tmp;
    ur_crds[tmp] += 1;
    if (ur_crds[tmp] == 2)
      ans++;
  }

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--)
    game();
}
