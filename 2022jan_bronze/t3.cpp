#include<iostream>
typedef long long ll;
using namespace std;
const int N = 1e5+5;
ll a[N];
ll find(const ll x[],int size) {  
	ll sum = 0;
	ll b[size+1],a[size+1] ;
	b[0] = a[0] = 0;
	for(int i=1;i<=size;i++) {
		b[i] = x[i] - x[i-1];
	}
	ll d;
	for (int i=2;i<=size;i++) {
		d = abs(b[i]);
		if (b[i]>0) {
			b[i] -= d;
			if(i+2<=size)
				b[i+2] += d;
			sum += 2*d;
		} else if (b[i]<0) {
			if (i%2==0) 
				return -1;
			b[1] -=d;
			b[i] +=d;
			sum += (i-1)*d;
		}
	}
	if (b[1]<0) 
		return -1;
	return sum;
}

ll solve() {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
	}
	if (n==1) 
		return 0;
	if (n==2)  {
		if ( a[1]==a[2] ) 
			return 0;
		else 
			return -1;
	}
	return find(a,n);
}

int main() {
	int t;
	cin >> t;
	for(int i=1;i<=t;i++) {
		cout << solve() << endl;
	}
	return 0;
}
