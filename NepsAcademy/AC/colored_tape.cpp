#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> t(N); // tape
  vector<int> ans(N);

  int last_zero_index = -1;

  for (int i = 0; i < N; i++) {
    cin >> t[i];
    ans[i] = t[i];

    if (ans[i] == 0) {
      last_zero_index = i;
      int d = 1; // distance
      for (int j = i - 1; j >= 0; j--) {
        if (ans[j] == 0)
          break;

        // se não tiver settado ou tiver settado pra uma distancia maior
        if (ans[j] == -1 || ans[j] > d) {
          d < 9 ? ans[j] = d : ans[j] = 9;
        }

        d++;
      }
    }
  }

  last_zero_index = -1;
  for (int i = 0; i < N; i++) {
    if (ans[i] == 0)
      last_zero_index = i;
    if (last_zero_index == -1)
      continue;

    int d = (i - last_zero_index);
    if (d < ans[i] || ans[i] == -1)
      d < 9 ? ans[i] = d : ans[i] = 9;
  }

  for (auto u : ans) {
    cout << u << " ";
  }

  cout << endl;
}
