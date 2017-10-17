#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct fraction
{
	int fz,fm;
	fraction(int a=0,int b=1):fz(a),fm(b){}
	int gcd(int m,int n)
	{
		int t;
		while(n)
		{
			t=m%n;
			m=n;
			n=t;
		}
		return m;
	}
	bool operator<(const fraction& A)const{return fz*A.fm<A.fz*fm;}
}shot,rota;
int lenth;
char tex[105];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int zn,a,b;
	while(scanf("%s",tex)!=-1)
	{
		zn=a=b=0;
		lenth=strlen(tex);
		for(int i=1;i<lenth;i++)
		{
			if(tex[i]=='0')
			{
				zn++;
				if(tex[i-1]=='0')a++;
			}
			if(tex[i]=='1'&&tex[i-1]=='0')b++;
		}
		if(tex[0]=='0')
		{
			zn++;
			if(tex[lenth-1]=='0')a++;
		}
		if(tex[0]=='1'&&tex[lenth-1]=='0')b++;
		shot=fraction(a,a+b);
		rota=fraction(zn,lenth);
		if(shot<rota)
			printf("ROTATE\n");
		else if(rota<shot)
			printf("SHOOT\n");
		else
			printf("EQUAL\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

