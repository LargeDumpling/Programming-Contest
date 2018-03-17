/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=100050;
struct jp
{
	long long x;
	jp(const long long &X=0):x(X) { }
	bool operator<(const jp &X)const { return x>X.x; }
};
int n;
long long v[MAXN],t[MAXN],alr=0;
int main()
{
	long long cnt=0;
	priority_queue<jp> q;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&v[i]);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&t[i]);
	for(int i=1;i<=n;i++)
	{
		q.push(jp(v[i]+alr));
		cnt=0;
		while(q.size()&&q.top().x<=t[i]+alr)
		{
			cnt+=(q.top().x-alr);
			q.pop();
		}
		cnt+=t[i]*q.size();
		printf("%I64d ",cnt);
		alr+=t[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

