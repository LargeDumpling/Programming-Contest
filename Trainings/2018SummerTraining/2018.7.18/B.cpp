#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,q,p,all=0;
set<int> s;
int main()
{
	scanf("%d%d%d",&n,&q,&p);
	int x,op;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		s.insert(x);
	}
	while(q-->0)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&x);
			set<int>::iterator it=s.lower_bound(x+all);
			if((it==s.end()||x+all+1<=*it)&&x<=p-all-1)
				s.insert(x+all);
		}
		else if(s.size())
		{
			all++;
			s.erase(s.begin());
		}
	}
	for(set<int>::iterator it=s.begin();it!=s.end();it++)
		printf("%d ",*it-all);
	while(all)
		printf("%d ",p-(all--));
	return 0;
}

