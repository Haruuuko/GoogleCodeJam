#include <iostream>
using namespace std;

#define ll long long
const int maxn = 5100;
int n, mod;
ll A[maxn], num[maxn], dp[maxn], dp2[maxn];
int main(){
	freopen("D-large-practice.in.txt", "r", stdin);
	freopen("D-large-practice.out.txt", "w", stdout);
	int T;
	cin >> T;
	for(int count = 1; count < T + 1; count++){
		ll res;
		cin >> n >> mod;
		num[0] = dp[0] = dp2[0] = 0;
        A[0] = 1 % mod;
		//A[i] -> i!	number of permutations of size i  
        for(int i = 1; i <= n; i ++) {
            A[i] = A[i - 1] * i % mod;
        }
        for(int i = 1; i <= n; i++){
            num[i] = A[i];
            dp[i] = dp2[i] = 0;
			//num[i] -> SUM(1->i){i! - (i-k)! * num[k]}		number of primitive chunks of size i
            for(int k = 1; k < i; k++)
                num[i] = (num[i] - num[k] * A[i - k] % mod + mod) % mod;
			//dp[i] -> SUM(1->i){(dp[i-k] + (i-k)!) * num[k]}	sum of all max chunks of size i
			//dp2[i] -> SUM(1->i){(dp2[i-k] + 2*dp[i-k] + (i-k)!) * num[k]} sum of square of all max chunks of size i
            for(int k = 1; k <= i; k++){
                dp[i] = (dp[i] + num[k] * (dp[i - k] + A[i - k]) % mod) % mod;
                dp2[i] = (dp2[i] + num[k] * (dp2[i - k] + A[i - k] + 2 * dp[i-k]) % mod) % mod;
            }
        }		
		cout << "Case #" << count << ": " << dp2[n] << endl;
	}
	return 0;
}
