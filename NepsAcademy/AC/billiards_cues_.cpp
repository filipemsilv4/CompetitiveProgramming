#include <iostream>
#include <set>

using namespace std;

int main() {
  set<int> stock;
  int N;
  cin >> N;

  int tmp;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    if (stock.erase(tmp) == 0) {
      stock.insert(tmp);
      ans += 2;
    }
  }

  cout << ans << endl;
}
