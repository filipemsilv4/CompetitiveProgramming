#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }

int main() {
  vector<pair<int, int>> t(3);
  t[0].first = 1;
  t[1].first = 2;
  t[2].first = 3;
  cin >> t[0].second >> t[1].second >> t[2].second;

  sort(t.begin(), t.end(), compare);

  for (auto u : t) {
    cout << u.first << endl;
  }

  return 0;
}
