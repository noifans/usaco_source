#include<iostream>
#include<cstring>
#include<unordered_map> 
using namespace std;
const int N=1e5+5;
int a[N];
unordered_map<int,bool> m;

int check(int x,int y){
	for(int i=x;i<=y;i+=x) {
		if(!m[i])
			return false;
	}
	return true;
}

int solve(){
	int n,gnum=0,sum=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		gnum = max(gnum,a[i]);
		sum +=a[i];
		m[sum] = true;
	}
	if (gnum==0) 
		return 0;
	while(true) {
		if (sum%gnum==0 && check(gnum,sum)) {
			return n - sum/gnum;
		}
		gnum++;
	}
}
int main(){ 
	int t;
	cin >> t;
	while(t--){
		memset(a,0,sizeof(a));
		m.clear();
		cout << solve() << endl; 
	}
	return 0;
}


