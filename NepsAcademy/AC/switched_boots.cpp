#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> e(31);
  vector<int> d(31);
  int N;
  cin >> N;

  int size;
  char foot;
  for (int i = 0; i < N; i++) {
    cin >> size >> foot;

    size -= 30;

    if (foot == 'E') {
      e[size]++;
    } else {
      d[size]++;
    }
  }

  int ans = 0;
  for (int i = 0; i < e.size(); i++) {
    ans += min(e[i], d[i]);
  }

  cout << ans << endl;
}
