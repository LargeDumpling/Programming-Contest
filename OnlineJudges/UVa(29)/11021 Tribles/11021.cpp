#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T;
void readln(int &x)
{
	bool a=false;
	char ch=getchar();
	x=0;
	while(ch<'0'||'9'<ch)
	{
		if(ch=='-')
			a^=1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	if(a)
		x=-x;
	return;
}
double qpow(double x,int n)
{
	double ans=1;
	while(n)
	{
		if(n&1)
			ans*=x;
		x*=x;
		n>>=1;
	}
	return ans;
}
int main()
{
	int n,k,m;
	double p[1050],f[1050];
	readln(T);
	for(int l=1;l<=T;l++)
	{
		readln(n);
		readln(k);
		readln(m);
		for(int i=0;i<n;i++)
			scanf("%lf",&p[i]);
		f[0]=0;
		f[1]=p[0];
		for(int i=2;i<=m;i++)
		{
			f[i]=0;
			for(int j=0;j<n;j++)
				f[i]+=p[j]*qpow(f[i-1],j);
		}
		printf("Case #%d: %.7lf\n",l,qpow(f[m],k));
	}
}

