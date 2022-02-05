#include<iostream>
typedef long long ll;
using namespace std;
const int N = 1e5+5;
ll a[N];
ll find(const ll x[],int size, int height) {  
	ll sum = 0;
	ll b[size+1] ;
	b[0] = 0;
	for(int i=1;i<=size;i++) {
		b[i] = x[i] - x[i-1];
	}
	ll d;
	d = b[1] - height;
	b[1] -= d;
	b[3] += d;
	sum += 2*d;
	for (int i=2;i<=size-1;i++) {
		if (b[i] < 0) 
			return -1;
		d = b[i];
		b[i] -= d;
		b[i+2] += d;
		sum += 2*d;
	}
	if (b[size]!=0) 
		return -1;
	return sum;
}

ll solve() {
	int n;
	ll tmin = 1e9;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		tmin = min(tmin,a[i]);
	}
	if (n==1) 
		return 0;
	if (n==2)  {
		if ( a[1]==a[2] ) 
			return 0;
		else 
			return -1;
	}
	ll ans =-1;
	for (int i=tmin;i>=0;i--) {
		ans = find(a,n,i);
		if (ans!=-1) 
			return ans;
	}
	return ans;
}

int main() {
	freopen("t3_1.in","r",stdin);
	int t;
	cin >> t;
	for(int i=1;i<=t;i++) {
		cout << solve() << endl;
	}
	return 0;
}
