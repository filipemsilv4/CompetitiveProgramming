/*
g++ -std=c++17 -o bin/out 956_B_Div2.cpp && ./bin/out
*/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>

#define lli long long int
#define ulli unsigned long long int
#define endl "\n"
#define bi 1000000000

using namespace std;

int main(){
    lli t;
    cin >> t;
    while (t--){
        lli row, col;
        cin >> row >> col;

        vector<vector<int> > a(row);
        vector<vector<int> > b(row);

        for (lli i = 0; i < row; i++){
            string tmp;
            cin >> tmp;
            for (lli j = 0; j < tmp.length(); j++){
                a[i].push_back(tmp[j] - '0');
            }
        }

        for (lli i = 0; i < row; i++){
            string tmp;
            cin >> tmp;
            for (lli j = 0; j < tmp.length(); j++){
                b[i].push_back(tmp[j] - '0');
            }
        }

        bool no = false;
        lli sum_row_a = 0, sum_col_a = 0;
        lli sum_row_b = 0, sum_col_b = 0;
        for (lli i = 0; i < row; i++){
            for (lli j = 0; j < col; j++){
                sum_row_a += a[i][j];
                sum_row_b += b[i][j];
            }
            if ((sum_row_a % 3) != (sum_row_b % 3)){
                no = true;
                break;
            }
            sum_row_a = sum_row_b = 0;
        }

        for (lli i = 0; i < col; i++){ // set the column
            for (lli j = 0; j < row; j++){ // track column between rows
                sum_col_a += a[j][i];
                sum_col_b += b[j][i];
            }
            if ((sum_col_a % 3) != (sum_col_b % 3)){
                no = true;
                break;
            }
            sum_col_a = sum_col_b = 0;
        }

        // cout << "---------------------------> ";
        if (no){
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }
}
