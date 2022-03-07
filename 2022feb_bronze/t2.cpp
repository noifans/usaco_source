#include<iostream>
#include<unordered_map> 
using namespace std;
const int N=1e5+5;
int a[N],b[N];
unordered_map<int,int> m;

int main(){ 
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
	}
	for(int i=1;i<=n;i++) {
		cin >> b[i];
		m[b[i]] = i;
	}
	int cnt=0;
	int tmax = m[a[1]];
	for(int i=2;i<=n;i++) {
		int key = m[a[i]];
		if (tmax > key ) {
			cnt++;
		} else {
			tmax = key;
		}
	}
	cout << cnt ;
	return 0;
}


