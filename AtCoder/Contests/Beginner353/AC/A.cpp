#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n; cin >> n;

    vector<int> buildings(n+1);
    cin >> buildings[1];

    for (int i = 2; i <= n; i++){
        cin >> buildings[i];
        if (buildings[i] > buildings[1]){
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
