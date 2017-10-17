#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
struct jp
{
	int c,v,nu;
	jp(int a=0,int b=0,int d=0):c(a),v(b),nu(d){}
}item[1050];
int N,V,f[200050],in=0,ans=0;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,c;
	scanf("%d%d",&N,&V);
	for(int i=1;i<=N;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(c==1)
			for(int j=V;j>=a;j--)
				f[j]=max(f[j],f[j-a]+b);
		else if(c>0)
		{
			for(int j=1;j<=c;j<<=1)
			{
				for(int k=V;k>=a*j;k--)
					f[k]=max(f[k],f[k-a*j]+b*j);
				c-=j;
			}
			if(c)
				for(int k=V;k>=c*a;k--)
					f[k]=max(f[k],f[k-c*a]+b*c);
		}
		else if(c==-1)
			for(int j=1;j*a<=V;j<<=1)
				for(int k=V;k>=a*j;k--)
					f[k]=max(f[k],f[k-a*j]+b*j);
	}
	for(int i=0;i<=V;i++)
		ans=max(ans,f[i]);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

