#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> b(N + 2, -1);
  int ans = 0;

  for (int i = 2, j = 0; i < N + 2; i++, j = (j + 1) % 3) {
    cin >> b[i];
    if (b[i] == 0 && b[i - 1] == 0 && b[i - 2] == 1)
      ans++;
  }

  cout << ans << endl;
}
