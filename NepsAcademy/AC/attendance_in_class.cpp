// Source: OBI 2012 - First Phase
#include <iostream>
#include <set>

using namespace std;

int main() {
  int N;
  cin >> N;

  set<int> present;

  int tmp;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    present.insert(tmp);
  }

  int ans = 0;
  for (auto &u : present) {
    ans++;
  }

  cout << ans << endl;
}
