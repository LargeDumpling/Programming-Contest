#include<iostream>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int r[300050]={0},c[300050];
//typedef complex<double>cp;
struct cp
{
	double r,i;
	cp(double a=0,double b=0):r(a),i(b){}
	cp operator+(const cp x){return cp(r+x.r,i+x.i);}
	cp operator-(const cp x){return cp(r-x.r,i-x.i);}
	cp operator*(const cp x){return cp(r*x.r-i*x.i,r*x.i+i*x.r);}
};
cp /*W[2][300050],*/a[300050],b[300050];
inline void fft_init(int &n)
{
	int tem=1;while(1<<tem<n)++tem;n=1<<tem;
//	double temp=acos(-1.)*2./n;
	/*W[0][0]=W[0][n]=cp(1.,0.);*/
//	cp g=cp(cos(temp),sin(temp));
	for(int i=1;i<n;i++)r[i]=(r[i>>1]>>1)|((i&1)<<(tem-1));/*
	for(int i=1;i<n;i++)W[0][i]=W[0][i-1]*g;
	for(int i=0;i<=n;i++)W[1][i]=W[0][n-i];*/
	return;
}
inline void fft(cp x[],int n,int t)
{
	double PI=t?-1*acos(-1.)*2.:acos(-1.)*2.;
	cp temp,g,cur;
	for(int i=1;i<n;i++)if(r[i]<i)swap(x[i],x[r[i]]);
	for(int i=2;i<=n;i<<=1)
	{
		g=cp(cos(PI/i),sin(PI/i)),cur=cp(1,0);
		for(int k=0;k<(i>>1);k++)
		{
			for(int j=0;j<n;j+=i)
			{
				temp=/*W[t][k*n/i]*/cur*x[j+k+(i>>1)];
				x[j+k+(i>>1)]=x[j+k]-temp;
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
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n;
	char tex[60050];
	scanf("%d",&n);
//	printf("%d\n",n);
	scanf("%s",tex);
	for(int i=0;i<n;i++)
		a[i]=tex[n-i-1]-'0';
	scanf("%s",tex);
	for(int i=0;i<n;i++)
		b[i]=tex[n-i-1]-'0';
	n*=2;
	fft_init(n);
	fft(a,n,0);
	fft(b,n,0);
	for(int i=0;i<=n;i++)
		a[i]=a[i]*b[i];
	fft(a,n,1);
	for(int i=0;i<=n;i++)
		c[i]=(int)(a[i].r+0.5);
	for(int i=0;i<=n;i++)
		if(c[i]>=10)
		{
			c[i+1]+=c[i]/10;
			c[i]=c[i]%10;
			if(i==n)
				n++;
		}
	while(!c[n])n--;
	for(int i=n;i>=0;i--)
		printf("%d",c[i]);
//	printf("\n");
//	for(int i=m-1;i>=0;i--)
//		printf("%.0lf",b[i].r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

