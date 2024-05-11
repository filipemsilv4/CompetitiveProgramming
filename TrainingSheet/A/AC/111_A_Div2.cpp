#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  deque<int> coins;

  int twin_sum = 0;
  int my_sum = 0;

  for (int i = 0, tmp; i < n; i++) {
    cin >> tmp;
    coins.push_back(tmp);
    twin_sum += tmp;
  }

  sort(coins.rbegin(), coins.rend());

  int ans = 0;
  while (my_sum <= twin_sum){
      my_sum += coins.front();
      twin_sum -= coins.front();
      coins.pop_front();
      ++ans;
  }

  cout << ans << endl;
}
