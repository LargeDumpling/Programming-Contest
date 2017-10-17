#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp
{
	int x,y,rate;
	jp(int a=0,int b=0,int c=0):x(a),y(b),rate(c){}
	bool operator<(const jp X)const
	{
		return rate<X.rate;
	}
}edge[5050];
int n,m,s,t,f[505];
long long ansa,ansb;
int find(int x)
{
	while(f[f[x]]!=f[x])
		f[x]=f[f[x]];
	return f[x];
}
void JP(int a,int b)
{
	a=find(a);
	b=find(b);
	f[b]=a;
	return;
}
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].rate);
	sort(edge+1,edge+m+1);
	scanf("%d%d",&s,&t);
	for(int i=1,j;i<=m;i++)
	{
		for(j=1;j<=n;j++)f[j]=j;
		for(j=i;j<=m&&find(s)!=find(t);j++)
		{
			if(find(edge[j].x)==find(edge[j].y))
				continue;
			JP(edge[j].x,edge[j].y);
			if(find(s)==find(t))
				break;
		}
		if(find(s)!=find(t))
			break;
		if((ansa==0&&ansb==0)||(ansa*edge[i].rate>ansb*edge[j].rate))
		{
			ansa=edge[j].rate;
			ansb=edge[i].rate;
		}
	}
	if(ansa==0&&ansb==0)
		printf("IMPOSSIBLE");
	else
	{
		int t=gcd(ansa,ansb);
		ansa/=t;
		ansb/=t;
		if(ansb==1)
			printf("%lld",ansa);
		else
			printf("%lld/%lld",ansa,ansb);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

