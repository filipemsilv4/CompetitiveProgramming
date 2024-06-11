#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>

#define lli long long int
#define ulli unsigned long long int

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, m; // lines, characters per line
        cin >> n >> m;

        vector<string> board(n);

        pair<int,int> first = {-1,-1};
        bool found_first = false;
        pair<int,int> last = {-1,-1};

        for (int i = 0; i < n; i++){
            cin >> board[i];
            for (int j = 0; j < m; j++){
                if (board[i][j] == '#'){
                    if (!found_first){
                        first = {i, j};
                        found_first = true;
                    } else {
                        last = {i, j};
                    }
                }
            }
        }

        if (last.first == -1){
            last = first;
        }

        first.first++;
        first.second++;
        last.first++;
        last.second++;

        // cout << "----> ";
        cout << (int)(first.first + ((last.first - first.first) / 2)) << " ";
        cout << (int)(first.second + ((last.second - first.second) / 2)) << endl;
    }
}
