#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool compare_pair(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second > b.second;
}

void game() {
  int n;
  cin >> n;

  vector<int> all_cards(n + 1, 2); // there are 2 of each card

  unordered_map<int, int> ur_crds; // <card, ammount>
  vector<int> ur_pref;

  unordered_map<int, int> ne_crds; // <card, ammount>
  vector<int> ne_pref;

  unordered_map<int, int> tab_crds; // <card, ammount>

  int tmp;
  for (int i = 1; i <= n; i++) {
    cin >> tmp;
    all_cards[tmp]--;

    if (ur_crds.count(tmp)) {
      ur_crds[tmp] = 2;
      ur_pref.push_back(tmp);
    } else
      ur_crds[tmp] = 1;
  }

  for (int i = 1; i <= n; i++) {
    if (all_cards[i] != 0) {
      ne_crds[i] = all_cards[i];
      if (ne_crds[i] == 2)
        ne_pref.push_back(i);
    }
  }

  int ur_points = 0;
  int ne_points = 0;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    game();
  }
}
