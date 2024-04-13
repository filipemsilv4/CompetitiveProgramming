#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void testcase() {
  vector<int> a; // positions to kick
  vector<int> res;
  int k; // a's lenght
  int q; // number of players

  cin >> k >> q;

  int tmp;
  for (int i = 0; i < k; i++) {
    cin >> tmp;
    a.push_back(tmp);
  }

  int player_count = 0;
  // cout << "---> ";
  for (int i = 0; i < q; i++) {
    cin >> tmp;
    player_count = tmp;

    if (player_count >= a[0]) {
      player_count = a[0] - 1;
    }
    cout << player_count << " ";
  }

  cout << endl;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    testcase();
  }
}
