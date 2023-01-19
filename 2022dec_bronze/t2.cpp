#include<iostream>
#include<cstring>
using namespace std;
const int N=1e5+5;

void solve() {
        int n,k,cnt=0;
        cin >> n >> k;
        string s;
        cin >> s;
        char c[N];
        bool b[N]; // cover
        memset(c,'.',sizeof(c));
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++) {
                if(b[i]) continue;
                int pos = min(i+k,n-1);
                if(c[pos]!='.') {
                        pos--;
                }
                cnt++;
                c[pos] = s[i]; 
                for(int j=i;j<=min(i+2*k,n-1);j++) {
                        if (s[j]==s[i]) 
                                b[j] = true;
                }
        }
        cout << cnt << endl;
        for(int i=0;i<n;i++) 
                cout << c[i];
        cout << endl;
        return ;
}
        

int main() {
        int t;
        cin >> t;
        while(t--) {
                solve(); 
        }
        return 0;
}
