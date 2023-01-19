#include <iostream>
using namespace std;
const int N=105;
 
int cnt[N][2][2];
int n,m,total,x,y; 
bool check[N];

void init() {
        total = m;
        for(int i=0;i<m;i++) {
                check[i]=false;
                for(int j=0;j<=1;j++) {
                        for(int k=0;k<=1;k++) {
                                cnt[i][j][k]=0;
                        }
                }
        }
}
void solve() {
        int c[N];
        string s[N];

        cin >> n >> m;
        for (int i = 0; i < m; i++) {
                cin >> s[i] >> c[i];
        }
        init();
        for (int i = 0; i < m; i++) {
                string b = s[i];
                for(int j= 0; j<n; j++) {
                        cnt[j][b[j]-'0'][c[i]]++;
                }
        }
        while(total){
                bool flag = false;
                for(int i=0;i<n;i++) {
                        for(int j=0;j<=1;j++){
                                for(int k=0;k<=1;k++){
                                        if(cnt[i][j][k]>0&&cnt[i][j][1-k]==0) {
                                                x=i;    
                                                y=j;  // y = f(x) 
                                                flag=true;
                                        }
                                }
                        }
                }
                if(!flag) break;
                for(int i=0;i<m;i++) {
                        string b=s[i];
                        if(!check[i]&&(b[x]-'0')==y){
                                check[i]=true;
                                total--;
                                for(int j=0;j<n;j++) {
                                        cnt[j][b[j]-'0'][c[i]]--;
                                }
                        }
                }

        }
        if (total) {
                cout << "LIE" << endl;
        } else {
                cout << "OK" << endl;
        }
}

int main() {
        int t; 
        cin >> t;
        while (t--) 
                solve();
        return 0;
}
