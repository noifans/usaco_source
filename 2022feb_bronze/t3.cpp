#include<iostream>
#include<cstring>
using namespace std;
char a[7],b[7],c[7],d[7];
int w[26];
bool check(int a[],string s) {
	for(int i=0;i<s.size();i++) {
		int t = s[i] - 'A';
		if (a[t] > 0 ) {
			a[t]--;
		} else {
			return false;
		}
	}
	return true;
}
string solve(string s) {
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			for(int k=0;k<6;k++){
				for(int l=0;l<6;l++){
					memset(w,0,sizeof(w));
					w[a[i]-'A']++;
					w[b[j]-'A']++;;
					w[c[k]-'A']++;
					w[d[l]-'A']++;
					if(check(w,s)) {
						return "YES";
					}
				}
			}
		}

	}
	return "NO";
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<6;i++) cin >> a[i];
	for(int i=0;i<6;i++) cin >> b[i];
	for(int i=0;i<6;i++) cin >> c[i];
	for(int i=0;i<6;i++) cin >> d[i];
	for(int i=0;i<n;i++) {
		string s;
		cin >> s;
		cout<< solve(s)<<endl;
	}
	return 0;
}
