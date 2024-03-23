// Source: OBI 2015 - Second Phase

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  // index 0 will be used for store the weight of its column and row
  vector<vector<int>> board(N + 1, vector<int>(N + 1));

  int tmp;
  for (int row = 1; row <= N; row++) {
    for (int col = 1; col <= N; col++) {
      cin >> tmp;
      board[row][col] = tmp;
      board[row][0] += tmp; // row sum
      board[0][col] += tmp; // col sum
    }
  }

  int ans = 0;
  for (int row = 1; row <= N; row++) {
    for (int col = 1; col <= N; col++) {
      // tmp = board[row][0] + board[0][col] - board[row][col];
      // I've spent so much time wondering why this wasn't working, turns out
      // that i forgot that board[row][col] is used in both the sum of the row
      // and the sum of the column, so we need to subtract it 2 times
      tmp = board[row][0] + board[0][col] - (2 * board[row][col]);
      if (tmp > ans) {
        ans = tmp;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
