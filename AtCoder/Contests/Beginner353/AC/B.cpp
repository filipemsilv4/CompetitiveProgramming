#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n, k; // groups, empty seats
  cin >> n >> k;
  const int og_k = k;

  queue<int> a;

  for (int i = 0, tmp; i < n; i++) {
    cin >> tmp;
    a.push(tmp);
  }

  int ans = 0;
  while (!a.empty()) {
      if (k < a.front()){
          ans++;
          k = og_k;
      } else {
          k -= a.front();
          a.pop();
      }
  }

  cout << ans + 1 << endl;
}
