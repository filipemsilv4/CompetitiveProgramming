#include <iostream>
#include <vector>

using namespace std;

#define lli long long int

// void print_grid(vector<vector<int>> g, int n) {
//   for (auto v : g) {
//     for (auto i : v) {
//       cout << i << " ";
//     }
//     cout << endl;
//   }
// }

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> grid(n + 1, vector<int>(n + 1));

  cout << m * n << endl;

  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y;
    grid[x][y] = 1;
    grid[x][0]++;
    grid[0][y]++;
  }

  // print_grid(grid, n);

  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= n; y++) {
      if (x != y && grid[x][0] < m && grid[0][y] < m) {

        grid[x][y] = 1;
        grid[x][0]++;
        grid[0][y]++;
      }
      if (grid[x][y] == 1) {
        // cout << "---> ";
        cout << x << " " << y << endl;
      }
    }
  }

  for (int x = 1, y = 1; x <= n && y <= n; x++, y++) {
    if (grid[x][0] < m && grid[0][y] < m) {
      grid[x][y] = 1;
      grid[x][0]++;
      grid[0][y]++;
    }
    if (grid[x][y] == 1) {
      // cout << "---> ";
      cout << x << " " << y << endl;
    }
  }

  // print_grid(grid, n);
}
