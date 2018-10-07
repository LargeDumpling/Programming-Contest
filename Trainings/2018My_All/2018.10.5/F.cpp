/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-10;
int T_T,n,m,a,b;
inline void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
inline double Pow(double x,int N)
{
	double ans;
	for(ans=1.;N;N>>=1,x=x*x)
		if(N&1)
			ans=ans*x;
	return ans;
}
double Peak()
{
	double l,mid[2],r,p[2],q[2],res[2];
	l=0; r=1;
	while(l<r-eps)
	{
		mid[0]=(r-l)/3.;
		if(mid[0]<eps) break;
		mid[1]=r-mid[0];
		mid[0]+=l;
		p[0]=mid[0];
		q[0]=min(1.,2*mid[0]);
		p[1]=mid[1];
		q[1]=min(1.,2*mid[1]);
		res[0]=Pow(p[0],a)*Pow(1-p[0],n-a)*Pow(q[0],b)*Pow(1-q[0],m-b);
		res[1]=Pow(p[1],a)*Pow(1-p[1],n-a)*Pow(q[1],b)*Pow(1-q[1],m-b);
		if(res[0]>res[1]) r=mid[1];
		else l=mid[0];
	}
	return l;
}
int main()
{
	read1n(T_T);
	while(T_T--)
	{
		read1n(n);
		read1n(m);
		read1n(a);
		read1n(b);
		printf("%.10lf\n",Peak());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

