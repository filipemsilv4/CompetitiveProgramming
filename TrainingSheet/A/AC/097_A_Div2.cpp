#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> gave_to_who(n+1);
    vector<int> who_gave(n+1);

    for (int i = 1, tmp; i <= n; i++){
        cin >> tmp;
        who_gave[tmp] = i;
    }

    for (int i = 1; i <= n; i++){
        cout << who_gave[i] << " ";
    }
    cout << endl;
}
