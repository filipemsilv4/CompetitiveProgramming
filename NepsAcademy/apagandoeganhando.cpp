#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int N, D; // digits, digits to erase
    string s, ans;

    while (cin >> N >> D >> s){
        int erased = 0;
        
        for (auto c : s){
            while (ans.size() > 0 && c > ans.back() && erased < D){
                ans.pop_back();
                erased++;
            }

            if (ans.size() < N - D){
                ans.push_back(c);
            }
        }

        for (auto u : ans){
            cout << u;
        }
        cout << "\n";

        s.erase();
        ans.erase();
    }
}