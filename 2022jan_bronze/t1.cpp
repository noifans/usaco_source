#include<iostream>
#include<unordered_map>
using namespace std;
char a[3][3],b[3][3];
unordered_map<char,int> ma,mb;
int green,yellow;
int main(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
			ma[a[i][j]]++;
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>b[i][j];
			mb[b[i][j]]++;
			if(b[i][j]==a[i][j])
				green++;
		}
	}
	for(int i='A';i<='Z';i++){
		yellow += min(ma[i],mb[i]);
	}
	cout << green << endl;
	cout << yellow - green <<endl;
	return 0;
}





