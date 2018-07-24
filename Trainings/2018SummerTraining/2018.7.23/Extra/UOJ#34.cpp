/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
struct comp
{
	long double r,i;
	comp(const double &R=0,const double &I=0):r(R),i(I) { }
	comp operator+(const comp &X) { return comp(r+X.r,i+X.i); }
	comp operator-(const comp &X) { return comp(r-X.r,i-X.i); }
	comp operator*(const comp &X) { return comp(r*X.r-i*X.i,r*X.i+i*X.r); }
	comp operator*(const double &P) { return comp(r/P,i/P); }
}a[MAXN<<2],b[MAXN<<2];
int rev[MAXN<<2],c[MAXN<<2];
void fft_init(int &n)
{
	int tem=1;
	while((1<<tem)<n)
		tem++;
	n=1<<tem;
	rev[0]=0;
	for(int i=1;i<n;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(tem-1));
	return;
}
void fft(comp x[],int n,int t)
{
	double Pi=t?-1*acos(-1.)*2.:acos(-1.)*2.;
	comp temp,g,cur;
	for(int i=0;i<n;i++)
		if(rev[i]<i)
			swap(x[i],x[rev[i]]);
	for(int i=2;i<=n;i<<=1)
	{
		int step=i>>1;
		g=comp(cos(Pi/i),sin(Pi/i)),cur=comp(1.,0.);
		for(int k=0;k<step;k++)
		{
			for(int j=0;j<n;j+=i)
			{
				temp=cur*x[j+k+step];
				x[j+k+step]=x[j+k]-temp;
				x[j+k]=x[j+k]+temp;
			}
			cur=cur*g;
		}
	}
	if(t)
		for(int i=0;i<n;i++)
			x[i].r=x[i].r/n;
	return;
}
int main()
{
	int n,m,x,lenth;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
	{
		scanf("%d",&x);
		a[i].r=x;
	}
	for(int i=0;i<=m;i++)
	{
		scanf("%d",&x);
		b[i].r=x;
	}
	n++; m++;
	n=lenth=n+m-1;
	fft_init(n);
	fft(a,n,0);
	fft(b,n,0);
	for(int i=0;i<n;i++)
		a[i]=a[i]*b[i];
	fft(a,n,1);
	for(int i=0;i<lenth;i++)
		printf("%d ",(int)(a[i].r+0.5));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

