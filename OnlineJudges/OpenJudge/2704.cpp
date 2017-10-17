#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define low(x) (x&-x)
#define max(a,b) (a>b?a:b)
using namespace std;
struct jp
{
	int x,y;
	jp(int X=0,int Y=0):x(X),y(Y){}
	bool operator<(const jp A)const
	{
		return x==A.x?y<A.y:x<A.x;
	}
}poi[205];
int n,f[105],a[105];
void add(int x)
{
	for(;x;x-=low(x))f[x]++;
}
int query(int x)
{
	int ans=0;
	for(;x<105;x+=low(x))ans+=f[x];
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int amax,an=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&poi[i].x,&poi[i].y);
		poi[i].x++;
		poi[i].y++;
	}
	sort(poi+1,poi+n+1);
	for(int i=n;i;i--)
	{
		a[i]=query(poi[i].y);
		add(poi[i].y);
	}
	amax=a[1];
	an=1;
	for(int i=2;i<=n;i++)
		if(a[i]<amax)
			amax=a[i],an=1;
		else if(a[i]==amax)
			an++;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==amax)
		{
			printf("(%d,%d)",poi[i].x-1,poi[i].y-1);
			if(--an)
				printf(",");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

