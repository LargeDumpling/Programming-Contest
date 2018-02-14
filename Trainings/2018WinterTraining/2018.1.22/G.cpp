/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,n,limit;
int L[25],cnt[100050][25];
bool check(int l,int r)
{
	for(int i=20;0<=i;i--)
		if((bool)L[i]>(bool)(cnt[r][i]-cnt[l][i]))
			return true;
		else if((bool)L[i]<(bool)(cnt[r][i]-cnt[l][i]))
			return false;
	return true;
}
int main()
{
	freopen("wifi.in","r",stdin);
	int x,l,r,mid,ans;
	scanf("%d",&T_T);
	while(T_T-->0)
	{
		memset(cnt,0,sizeof(cnt));
		memset(L,0,sizeof(L));
		ans=0;
		scanf("%d%d",&n,&limit);
		for(int i=0;i<=20;i++,limit>>=1)
			L[i]=limit&1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			for(int j=0;j<=20;j++,x>>=1)
				cnt[i][j]=cnt[i-1][j]+(x&1);
		}
		for(int i=1;i<=n;i++)
		{
			l=0; r=i-1;
			while(l<r-1)
			{
				mid=(l+r)>>1;
				if(check(mid,i))
					r=mid;
				else l=mid;
			}
			if(check(l,i)) ans=max(ans,i-l);
			else if(check(r,i)) ans=max(ans,i-r);
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

