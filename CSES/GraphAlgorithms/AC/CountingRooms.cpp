/*
g++ -std=c++17 -Wall -pedantic -o bin/out CountingRooms.cpp && ./bin/out
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <string>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"

using namespace std;



int main(){
    int n, m; // lines, columns
    cin >> n >> m;

    vector<string> grid(n); // '.' -> floor | '#' -> wall
    for (int i = 0; i < n; i++){
        cin >> grid[i];
    }

    queue<pair<int,int>> q;

    int ans = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == '!') continue; // ! -> explored floor
            if (grid[i][j] == '#') continue; // wall
            q.push({i, j});
            ans++;

            // for (auto s : grid){
            //     cout << s << "\n";
            // } cout << "\n";
            
            while (!q.empty()){
                // explore neighbours
                pair<int, int> curr = q.front();
                q.pop();
                
                if (grid[curr.first][curr.second] == '!') continue; // ! -> explored floor
                if (grid[curr.first][curr.second] == '#') continue; // wall
                grid[curr.first][curr.second] = '!';
                
                // up
                pair<int, int> up = {curr.first - 1, curr.second};
                if (up.first >= 0) q.push(up);

                // down
                pair<int, int> down = {curr.first + 1, curr.second};
                if (down.first < n) q.push(down);

                // left
                pair<int, int> left = {curr.first, curr.second - 1};
                if (left.second >= 0) q.push(left);

                // right
                pair<int, int> right = {curr.first, curr.second + 1};
                if (right.second < m) q.push(right);
            }
        }
    }

    cout << ans << "\n";

}
