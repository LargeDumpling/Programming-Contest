//LargeDumpling
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=505;
const int MAXC=100050;
struct jz
{
	int d,s,id;
	bool operator<(const jz &X)const
	{
		return s-d<=X.s-X.d;
	}
}soft[MAXN];
int n,c,ans=-1,ansS=0;
int calc(int S)
{
	int k=0,cnt=0;
	for(int i=0;i<n;i++) if(S&(1<<i))
	{
		if(c<k+soft[i+1].d||c<k+soft[i+1].s)
		{
			cnt=-1;
			break;
		}
		else k+=soft[i+1].s,cnt++;
	}
	return cnt;
}
int num[MAXN];
int main()
{
	freopen("I.in","r",stdin);
	freopen("I_BL.out","w",stdout);
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&soft[i].d,&soft[i].s);
		soft[i].id=i;
	}
	sort(soft+1,soft+n+1);
	int limit=(1<<n),tem;
	for(int i=0;i<limit;i++)
		if(ans<(tem=calc(i)))
		{
			ans=tem;
			ansS=i;
		}
	printf("%d\n",ans);
	for(int i=0;i<n;i++) if(ansS&(1<<i))
		num[++num[0]]=soft[i+1].id;
	sort(num+1,num+num[0]+1);
	for(int i=1;i<=num[0];i++)
		printf("%d ",num[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


