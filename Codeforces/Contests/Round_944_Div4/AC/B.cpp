#include <iostream>

using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        string s;
        cin >> s;

        bool flag = false;
        for (int i = 0; i < s.size(); i++){
            if (s[i] != s[0]){
                cout << "YES" << endl;
                swap(s[i], s[0]);
                cout << s << endl;
                flag = true;
                break;
            }
        }

        if (!flag){
            cout << "NO" << endl;
        }

    }
}
