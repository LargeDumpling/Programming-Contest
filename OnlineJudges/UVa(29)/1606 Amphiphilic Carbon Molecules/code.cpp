#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp
{
	int x,y;
	double rad;
	jp(int A=0,int B=0):x(A),y(B){}
	bool operator<(const jp X)const
	{
		return rad<X.rad;
	}
}star[1050],t[1050];
int n,type[1050];
bool cnmp(jp A,jp B)
{
	return (A.x*B.y-B.x*A.y)>=0;
}
int solve()
{
	if(n<=2)
		return 2;
	int k,ans=0,cnt=0,H,T;
	for(int i=1;i<=n;i++)
	{
		k=0;
		for(int j=1;j<=n;j++)
		{
			if(i==j)
				continue;
			t[k]=jp(star[j].x-star[i].x,star[j].y-star[i].y);
			if(type[j])t[k].x=-t[k].x,t[k].y=-t[k].y;
			t[k].rad=atan2(t[k].y,t[k].x);
			k++;
		}
		sort(t,t+k);
		H=T=0;
		cnt=2;
		while(T<k)
		{
			if(H==T)
			{
				H=(H+1)%k;
				cnt++;
			}
			while(H!=T&&cnmp(t[T],t[H]))
			{
				H=(H+1)%k;
				cnt++;
			}
			cnt--;
			T++;
			ans=max(ans,cnt);
		}
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(scanf("%d",&n)==1&&n)
	{
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&star[i].x,&star[i].y,&type[i]);
		printf("%d\n",solve());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

