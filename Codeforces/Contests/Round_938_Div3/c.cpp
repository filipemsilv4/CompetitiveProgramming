#include <deque>
#include <iostream>
#include <ostream>

using namespace std;

void testcase() {
  int n, k;
  cin >> n >> k;
  deque<int> ships;

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    ships.push_back(tmp);
  }

  int ans = 0;
  while (k / 2 > 0) {
    int weaker = min(ships.front(), ships.back());
    weaker = min(weaker, k / 2);

    if (ships.size() < 1)
      break;

    // attack the first
    k -= weaker;
    ships.front() -= weaker;
    if (ships.front() <= 0) {
      ships.pop_front();
      ans++;
    }

    if (ships.size() < 1)
      break;

    // attack the last
    k -= weaker;
    ships.back() -= weaker;
    if (ships.back() <= 0) {
      ships.pop_back();
      ans++;
    }
  }

  while (k > 0) {
    if (ships.size() < 1)
      break;

    // attack the first
    k -= 1;
    ships.front() -= 1;
    if (ships.front() <= 0) {
      ships.pop_front();
      ans++;
    }

    if (k < 1 || ships.size() < 1)
      break;

    // attack the last
    k -= 1;
    ships.back() -= 1;
    if (ships.back() <= 0) {
      ships.pop_back();
      ans++;
    }
  }

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    testcase();
  }
}
