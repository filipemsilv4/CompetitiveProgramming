// TLE
#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, d; // num of pieces, ammount u want
    cin >> n >> d;

    vector<int> pieces;

    int piece;
    for (int i = 0; i < n; i++){
        cin >> piece;
        pieces.push_back(piece);
    }

    int ans = 0;

    int ptr2;
    for (int ptr1 = 0; ptr1 < n; ptr1++){
        if (pieces[ptr1] == d) {
            ans++;
            continue;
        }

        int sum = pieces[ptr1];

        for (ptr2 = (ptr1 + 1) % n; ptr2 != ptr1; ptr2 = (ptr2 + 1) % n){
            sum += pieces[ptr2];
            if (sum < d) continue;
            if (sum == d) ans++;
            break;
        }
    }

    cout << ans << endl;
}