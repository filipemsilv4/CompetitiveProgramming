// AC
#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, d; // num of pieces, ammount u want
    cin >> n >> d;

    // 'Extending' the vector so i dont need to deal with circular logic
    vector<int> pieces(n*2);
    vector<int> prefix(n*2);

    int input;
    for (int i = 1; i <= n; i++){
        cin >> input;
        pieces[i] = input;
        pieces[n+i] = input; // So i dont neet to deal with circular logic
    }

    // Calculating prefix
    for (int i = 1; i < pieces.size(); i++){
        prefix[i] = prefix[i-1] + pieces[i];
    }

    // se o tamanho total do sanduíche for menor que d
	if(prefix[n] < d){
		
		// não há solução
		cout << "0" << endl;
		return 0;
	}

    // cout << "\npieces: ";
    // for (auto u : pieces){
    //     cout << u << " ";
    // }
    // cout << endl;

    // cout << "prefix: ";
    // for (auto u : prefix){
    //     cout << u << " ";
    // }
    // cout << endl;

    int ans = 0;

    int j = 1;
    for (int i = 1; i <= n; i++){
        //cout << i << "act: " << prefix[j] - prefix[i-1] << endl;
        while (prefix[j] - prefix[i-1] < d && j < prefix.size()){
            j++;
        }

        if (prefix[j] - prefix[i-1] == d) ans++;
    }

    cout << ans << endl;

    return 0;
}