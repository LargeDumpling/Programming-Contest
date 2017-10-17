/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
int T,n;
long long num[100050];
long long gCd(long long a,long long b)
{
	long long t;
	while(b)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	long long tem,ans,num;
	int pos;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		set<long long>exist;
		map<long long,long long>f;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&num);
			for(set<long long>::iterator it=exist.begin();it!=exist.end();)
			{
				//int k=*it;
				pos=f[*it];
				tem=gCd(*it,num);
				ans=max(ans,tem*(i-f[*it]+1));
				if(tem==*it)
				{
					it++;
					continue;
				}
				exist.erase(*(it++));
				if(exist.count(tem)==0)
				{
					exist.insert(tem);
					f[tem]=pos;
				}
			}
			if(!exist.count(num))
			{
				exist.insert(num);
				f[num]=i;
				ans=max(ans,num);
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

