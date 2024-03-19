// AC
#include <iostream>

using namespace std;

int main(){
    int b[3];
    for (int i = 0; i < 3; i++) cin >> b[i];

    // 3
    if (b[0] == b[1] && b[1] == b[2]){
        cout << 3 << endl;
        return 3;
    }
    // 1
    if ((b[0] < b[1] && b[1] < b[2]) || (b[2] > b[0] + b[1])){
        cout << 1 << endl;
        return 1;
    }
    // 2
    cout << 2 << endl;

    return 2;

}