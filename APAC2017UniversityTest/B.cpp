#include <bitset>
#include <iostream>
using namespace std;

#define ll	long long
const int maxn = 100001;
const int mod = 1e9 + 7;

//同余幂的快速算法 a^b%m
int pow_mod(int n, int exp, int mode) {
	int r = 1 % mode;
	while(exp) {
		if(exp&1) r = (ll)r * n % mode;
		n = (ll)n * n % mode;
		exp >>= 1;
	}
	return r;
}

// 1 <= K <= 100000
// arr[i] -> repetition times of remainder i in N 
// Amod[i] -> i ^ A % K
// Bmod[i] -> i ^ B % K
// sumA[n] -> total numbers of digits that meet i ^ A % K = n
// sumB[n] -> total numbers of digits that meet i ^ B % K = n
ll arr[maxn], Amod[maxn], Bmod[maxn], sumA[maxn], sumB[maxn];
int main() {
	freopen("B-large-practice.in.txt", "r", stdin);
	freopen("B-large-practice.out.txt", "w", stdout);
	int T;
	cin >> T;
	for(int count = 1; count < T + 1; count++) {
		memset(arr, 0 , sizeof arr);
		memset(sumA, 0 , sizeof sumA);
		memset(sumB, 0 , sizeof sumB);
		int A, B, K;ll N;
		cin >> A >> B >> N >> K;
		arr[0]--; // i,j != 0
		for(int i = 0; i < K; ++i) {
			arr[i] += N/K;
			if(i <= (N%K)) arr[i]++;
			Amod[i] = pow_mod(i, A, K) % K;
			Bmod[i] = pow_mod(i, B, K) % K;
			sumA[Amod[i]] = (sumA[Amod[i]] + arr[i]) % mod;
			sumB[Bmod[i]] = (sumB[Bmod[i]] + arr[i]) % mod;
		}	
		// compute result using sumA and sumB
		ll res = 0;
		for(int i = 0; i < K; i++){
			if (i == 0){
				res = (res + sumA[0] * sumB[0]) % mod;
			}else{
				res = (res + sumA[i] * sumB[K - i]) % mod;
			}
			// i != j
			if((Amod[i] + Bmod[i])%K == 0){
				res = (res + mod - (arr[i]%mod)) % mod;
			}
		}
		cout << "Case #" << count << ": " << res << endl;
	}
	return 0;
}
