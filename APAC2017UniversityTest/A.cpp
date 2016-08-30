#include <iostream>
using namespace std;

#define ll long long

int main(){
	freopen("A-large-practice.in.txt", "r", stdin);
	freopen("A-large-practice.out.txt", "w", stdout);
	int T;
	cin >> T;
	for(int count = 1; count < T + 1; count++){
		ll L, R, res, MIN;
		cin >> L >> R;
		MIN = min(L, R);
		res = (MIN + 1) * MIN / 2; // sum = n + n-1 + n-2 + ... + 1
		cout << "Case #" << count << ": " << res << endl;
	}
	return 0;
}
