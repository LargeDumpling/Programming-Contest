/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
const int M=16384;
int T_T,d[M<<1],n,m;
set<int> p[M];
int main()
{
	int x;
	scanf("%d",&T_T);
	for(int T=1;T<=T_T;T++)
	{
		scanf("%d",&n);
		memset(d,-1,sizeof(d));
		m=1<<n;
		for(int i=0;i<m;i++)
		{
			p[i].clear();
			for(int j=0;j<n;j++)
			{
				scanf("%d",&x);
				p[i].insert(x);
			}
			d[i+M]=i;
		}
		for(int i=M-1;i;i--)
		{
			if(d[i<<1]==-1) d[i]=d[i<<1|1];
			else if(d[i<<1|1]==-1) d[i]=d[i<<1];
			else
			{
				set<int>::iterator it1=p[d[i<<1]].end(),it2=p[d[i<<1|1]].end();
				it1--; it2--;
				if(*it1<*it2)
				{
					it2=lower_bound(p[d[i<<1|1]].begin(),p[d[i<<1|1]].end(),*it1);
					p[d[i<<1|1]].erase(it2);
					d[i]=d[i<<1|1];
				}
				else if(*it2<*it1)
				{
					it1=lower_bound(p[d[i<<1]].begin(),p[d[i<<1]].end(),*it2);
					p[d[i<<1]].erase(it1);
					d[i]=d[i<<1];
				}
			}
		}
		printf("Case #%d: %d\n",T,d[1]+1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

