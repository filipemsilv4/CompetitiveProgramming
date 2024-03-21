#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> b(N + 2); // 1 extra position at beginning and other at the end so
                        // i dont neet to care about corner cases :)
  vector<int> ans(N + 2);

  for (int i = 1; i <= N; i++) {
    cin >> b[i];
    if (b[i] == 1) {
      ans[i]++;
      ans[i - 1]++;
      ans[i + 1]++;
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
