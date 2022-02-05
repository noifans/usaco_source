#include<iostream>
using namespace std;

int a[4],b[4],c[4];

bool beat(const int x[],const int y[] )  { // x beat ? y
	int winx = 0;
	int winy = 0;
	for(int i=0;i<4;i++) {
		for (int j=0;j<4;j++) {
			if (x[i] > y[j]) winx++;
			if (x[i] < y[j]) winy++;
		}
	}
	return winx > winy;
}

bool best(const int x[],const int y[])  { // find z , x  y z best ? 
	int z[4];
	for(int i=1;i<=10;i++) {
		for(int j=1;j<=10;j++) {
			for(int k=1;k<=10;k++) {
				for(int l=1;l<=10;l++) {
					z[0]=i;
					z[1]=j;
					z[2]=k;
					z[3]=l;
					if(beat(x,y)&&beat(y,z)&&beat(z,x))  
						return true;
					if(beat(y,x)&&beat(x,z)&&beat(z,y)) 
						return true;
				}
			}
		}
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	for(int i=1;i<=t;i++) {
		for(int j=0;j<4;j++) 
			cin >> a[j];
		for(int j=0;j<4;j++) 
			cin >> b[j];

		if (best(a,b))  {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
	return 0;
}
