/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1000050;
template<typename Ty> void read1n(Ty &x)
{
	char ch; bool flag=false;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar()) if(ch=='-') flag=true;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	if(flag) x=-x;
	return;
}
int n,q[MAXN],l,r;
long long a,b,c,S[MAXN],f[MAXN],x[MAXN],y[MAXN];
double Slope(int p1,int p2) { return (double)(y[p2]-y[p1])/(x[p2]-x[p1]); }
long long Cross(long long A,long long B,long long C,long long D)
{
	return A*D-B*C;
}
bool Cross(int A,int B,int C)
{
	return Cross(y[A]-y[B],x[A]-x[B],y[B]-y[C],x[B]-x[C])<=0;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	read1n(n);
	read1n(a); read1n(b); read1n(c);
	for(int i=1;i<=n;i++)
	{
		read1n(S[i]);
		S[i]+=S[i-1];
	}
	q[l=r=0]=0;
	for(int i=1;i<=n;i++)
	{
		while(l<r&&Slope(q[l],q[l+1])*-1.<=S[i]) l++;
		int t=q[l];
		f[i]=f[t]+(S[i]-S[t])*(a*(S[i]-S[t])+b)+c;
		x[i]=-2*a*S[i]; y[i]=f[i]+(a*S[i]-b)*S[i];
		while(l<r&&Slope(q[r],i)>=Slope(q[r-1],q[r])) r--;
		q[++r]=i;
	}
	printf("%lld",f[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

