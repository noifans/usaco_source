#include<iostream>
#include<algorithm>
using namespace std;
int a[100001];
int main() {
	int n,ans=0;
	long long cnt =0;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++) {
		long long t = 1LL*(n-i)*a[i];
		if( t > cnt)  {
			cnt = t;
			ans = a[i];	
		} 
	}
	cout << cnt <<" "<<ans;
	return 0;
}
