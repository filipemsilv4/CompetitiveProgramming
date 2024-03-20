#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> sq(N, vector<int>(N));
  vector<int> row_sum(N);
  vector<int> col_sum(N);
  int diag_sum1 = 0;
  int diag_sum2 = 0;

  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      cin >> sq[r][c];
      row_sum[r] += sq[r][c];
      col_sum[c] += sq[r][c];
    }
  }

  // diag1
  for (int i = 0, j = 0; i < N && j < N; i++, j++) {
    diag_sum1 += sq[i][j];
  }

  // diag2
  for (int r = 0, c = N - 1; r < N && c >= 0; r++, c--) {
    diag_sum2 += sq[r][c];
  }

  if (diag_sum1 != diag_sum2) {
    cout << -1 << endl;
    return 0;
  }

  for (auto r : row_sum) {
    if (r != diag_sum1) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (auto c : col_sum) {
    if (c != diag_sum1) {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << diag_sum1 << endl;
}
