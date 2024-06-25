#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

int n, m; // row column

// Neighbours:
//         [-1, 0]
// [0,-1], [0, 0], [0,+1]
//         [+1, 0]
vector<pair<int, int>> fronteira = {{-1, 0}, {0, -1}, {0, +1}, {+1, 0}};

int find_vizinho_anao(vector<vector<int>> &mat, int n_at, int m_at) {
  // max = biggest neighbour smaller than mat[n_at][m_at]
  int max = INT_MIN, n_min = n_at, m_min = m_at;
  for (auto const &p : fronteira) {
    int curr_n = n_at + p.first;
    int curr_m = m_at + p.second;
    if (curr_n < 0 || curr_n >= n)
      continue;
    if (curr_m < 0 || curr_m >= m)
      continue;

    if (mat[curr_n][curr_m] >= mat[n_at][m_at]) {
      max = mat[n_at][m_at];
      break;
    }

    if (mat[curr_n][curr_m] > max) {
      max = mat[curr_n][curr_m];
      n_min = curr_n;
      m_min = curr_m;
    }
  }

  return max;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<vector<int>> mat(n, (vector<int>(m)));

    for (int row = 0; row < n; row++) {
      for (int col = 0; col < m; col++) {
        cin >> mat[row][col];
      }
    }

    for (int row = 0; row < n; row++) {
      for (int col = 0; col < m; col++) {
        mat[row][col] = find_vizinho_anao(mat, row, col);
      }
    }

    for (int row = 0; row < n; row++) {
      for (int col = 0; col < m; col++) {
        cout << mat[row][col] << " ";
      }
      cout << endl;
    }
  }
}
