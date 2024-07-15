#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

int main() {
  pair<int, int> start;
  pair<int, int> dest;

  while (true) {
    cin >> start.first >> start.second >> dest.first >> dest.second;

    if (start.first == 0)
      return 0;

    // cout << "---> ";
    if ((dest.first == start.first) && (dest.second == start.second)) {
      cout << 0 << endl;
      continue;
    }

    if ((dest.first == start.first) || (dest.second == start.second)) {
      cout << 1 << endl;
      continue;
    }

    vector<pair<int, int>> ops;
    ops.push_back({1, 1});
    ops.push_back({-1, -1});
    ops.push_back({-1, +1});
    ops.push_back({+1, -1});

    bool found = false;
    for (const auto &sig_pair : ops) {
      for (int x = start.first, y = start.second;
           x <= 8 && x >= 0 && y <= 8 && y >= 0;
           x += sig_pair.first, y += sig_pair.second) {
        if (x == dest.first && y == dest.second) {
          cout << 1 << endl;
          found = true;
          break;
        }
      }
      if (found) break;
    }
    if (found)
      continue;

    cout << 2 << endl;
  }
}
