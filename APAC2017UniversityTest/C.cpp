#include <unordered_set>
#include <iostream>
using namespace std;

#define ll long long
#define mpr make_pair
const int maxn = 501000;
pair <int, int> event[maxn * 2];
int le;
int n, l1, r1, a, b, c1, c2, m;
int ncase;
unordered_set <int> us;
int cnt = 0;
int ans[maxn];

int main(){
	freopen("C-large-practice.in.txt", "r", stdin);
	freopen("C-large-practice.out.txt", "w", stdout);
	int T;
	cin >> T;
	for(int count = 1; count < T + 1; count++){
		le = 0;
		cin >> n >> l1 >> r1 >> a >> b >> c1 >> c2 >> m;
		ll rx = l1, ry = r1;
		//caculate n pairs L&R (event)
		for(int i = 0; i <= n;i++) ans[i] = 0;
		event[le++] = mpr(l1, 1);
		event[le++] = mpr(r1 + 1, -1);
		for(int i = 1; i < n; i ++) {
			ll rrx = rx, rry = ry;
			rx = (1ll * a * rrx + 1ll * b * rry + c1) % m;
			ry = (1ll * a * rry + 1ll * b * rrx + c2) % m;
			event[le++] = mpr(min(rx, ry), i + 1);
			event[le++] = mpr(max(rx, ry) + 1, -(i + 1));
		}
		sort(event, event + le);
		cnt = 0;
		ll sum = 0;
		us.clear();
		for(int i = 0; i < le; i++) {
			if(cnt == 1)
				//cnt -> overlap interval numbers
				//ans -> length of interval without overlap
				ans[*us.begin()] += event[i].first - event[i - 1].first;
			if(cnt)
				//sum -> total intervals in n pairs
				sum += event[i].first - event[i - 1].first;
			int no = event[i].second;
			no = abs(no) - 1;
			if(event[i].second < 0) {
				cnt--;
				us.erase(no);
			} else {
				cnt++;
				us.insert(no);
			}
		}

		int rans = 0;
		for(int i = 0; i < n; i++)
			rans = max(rans, ans[i]);
		cout << "Case #" << count << ": " << sum - rans << endl;
	}
	return 0;
}
