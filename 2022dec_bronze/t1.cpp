#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e5+5;
int a[N];  // cow 

int main() {
        //freopen("t1_data/6.in","r",stdin);
        int n;
        cin >> n;
        for(int i=0;i<n;i++) {
                cin >> a[i];
        }
        sort(a,a+n);
        int ans; // set money
        long long total=0; // total 
        for(int i=0;i<n;i++) {
                long long t = 1LL*a[i]*(n-i);
                if (t > total) {
                        ans = a[i];
                        total = t;
                }
        }
        cout << total << " " << ans ;

        return 0;
}
