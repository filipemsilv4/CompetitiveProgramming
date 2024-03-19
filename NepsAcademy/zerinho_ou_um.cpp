//AC
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> zero;
    vector<int> um;

    int jogada;
    for (int i = 0; i < 3; i++){
        cin >> jogada;
        if (jogada == 0) zero.push_back(i);
        else um.push_back(i);
    }

    if (zero.size() == 1) printf("%c\n", zero[0] + 'A');
    else if (um.size() == 1) printf("%c\n", um[0] + 'A');
    else cout << '*' << endl;

}