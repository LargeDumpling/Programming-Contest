/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-27	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int num,x,n;
	long long ans;
	while(scanf("%d",&n)!=-1&&n)
	{
		multiset<int>s;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num);
			while(num--)
			{
				scanf("%d",&x);
				s.insert(x);
			}
			multiset<int>::iterator mAx=s.end(),mIn=s.begin();
			mAx--;
			ans+=((*mAx)-(*mIn));
			s.erase(mAx); s.erase(mIn);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

