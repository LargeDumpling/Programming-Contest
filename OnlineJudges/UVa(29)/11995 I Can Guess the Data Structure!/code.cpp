/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,x1,x2;
queue<int>q;
priority_queue<int>Q;
stack<int>s;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	bool a,b,c;
	while(scanf("%d",&n)!=-1)
	{
		a=b=c=true;
		while(!q.empty())q.pop();
		while(!Q.empty())Q.pop();
		while(!s.empty())s.pop();
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&x1,&x2);
			if(x1==1)
			{
				if(a)q.push(x2);
				if(b)Q.push(x2);
				if(c)s.push(x2);
			}
			else if(x1==2)
			{
				if(a)
				{
					if(!q.empty()&&q.front()==x2)q.pop();
					else a=false;
				}
				if(b)
				{
					if(!Q.empty()&&Q.top()==x2)Q.pop();
					else b=false;
				}
				if(c)
				{
					if(!s.empty()&&s.top()==x2)s.pop();
					else c=false;
				}
			}
		}
		if(!a&&!b&&!c)puts("impossible");
		else if(a&&!b&&!c)puts("queue");
		else if(!a&&b&&!c)puts("priority queue");
		else if(!a&&!b&&c)puts("stack");
		else puts("not sure");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

