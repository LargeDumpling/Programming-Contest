#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int inf=0x3f3f3f3f;  
const ll llinf=0x3f3f3f3f3f3f3f3f;   
const ld pi=acos(-1.0L);
int a[105],b[105];

int main() {
	int cas,i,j;
	scanf("%d",&cas);
	a[16]=13;b[16]=6;
	for (i=17;i<=100;i++) {
		if (i%4==0&&i!=100) a[i]=a[i-1]-2; else a[i]=a[i-1]-1;
		if (i%4==0&&i!=100) b[i]=b[i-1]-2; else b[i]=b[i-1]-1;
		if (a[i]<8) a[i]+=7;
		if (b[i]<1) b[i]+=7;
	}
	for (i=15;i>=2;i--) {
		if ((i+1)%4==0) a[i]=a[i+1]-5; else a[i]=a[i+1]-6;
		if ((i+1)%4==0) b[i]=b[i+1]-5; else b[i]=b[i+1]-6;
		if (a[i]<8) a[i]+=7;
		if (b[i]<1) b[i]+=7;
	}
	int cnt=0;
	string s,t;
	while (cas--) {
		cnt++;
		cin >> s >> t;
		printf("Case #%d: ",cnt);
		int m=s[6]-'0'+10*(s[5]-'0');
	//	if (m==3||m==11) {
			int y=s[3]-'0'+10*(s[2]-'0'),d=s[9]-'0'+10*(s[8]-'0');
			int h,mi,se;
			h=t[1]-'0'+10*(t[0]-'0');
			mi=t[4]-'0'+10*(t[3]-'0');
			se=t[7]-'0'+10*(t[6]-'0');
			int tt=h*10000+mi*100+se;
			if (y==0) y=100;
			if (m==3&&a[y]==d&&h==2) {
				printf("Neither\n");
			} else if (m==11&&b[y]==d&&h==1) {
				printf("Both\n");
			} else if ((m>3||(m==3&&d>a[y])||(m==3&&d==a[y]&&tt>=30000))
			&&(m<11||(m==11&&d<b[y])||(m==11&&d==b[y]&&tt<10000))) {
				printf("PDT\n");
			} else printf("PST\n");
	//	}
	}
	return 0;
}
