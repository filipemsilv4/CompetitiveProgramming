#include <deque>
#include <iostream>
#include <ostream>

using namespace std;

void testcase() {
  long long int n, k;
  cin >> n >> k;
  deque<long long int> ships;

  for (long long int i = 0; i < n; i++) {
    long long int tmp;
    cin >> tmp;
    ships.push_back(tmp);
  }

  long long int ans = 0;
  while (k / 2 > 0) {
    long long int weaker = min(ships.front(), ships.back());
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

  // cout << "k:" << k << ", sobreviventes: ";
  // for (auto const &n : ships) {
  //   cout << n << " ";
  // }
  // cout << endl;

  cout << ans << endl;
}

int main() {
  long long int t;
  cin >> t;

  for (long long int i = 0; i < t; i++) {
    testcase();
  }
}
