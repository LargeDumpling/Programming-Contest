#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
int n,a[200050],pre[200050],next[200050],ans=0;
struct jp
{
	int a,p;
	jp(int A,int B):a(A),p(B){}
	bool operator<(const jp &X)const
	{
		return a<X.a;
	}
};
set<jp>s;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T;
	bool flag;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if(n==1){printf("1\n");continue;}
		ans=1;
		a[0]=0;
		pre[0]=0;
		for(int i=1;i<=n;i++)
			pre[i]=(a[i]>a[i-1]?pre[i-1]+1:1);
		a[n+1]=2147483647;
		next[n+1]=0;
		for(int i=n;i;i--)
			next[i]=(a[i]<a[i+1]?next[i+1]+1:1);
		s.clear();
		s.insert(jp(a[1],pre[1]));
		for(int i=2;i<=n;i++)
		{
			jp c(a[i],pre[i]);
			set<jp>::iterator it=s.lower_bound(c);
			flag=true;
			if(it!=s.begin())
			{
				jp last=*(--it);
				int lenth=last.p+next[i];
				ans=max(ans,lenth);
				if(c.p<=last.p)flag=false;
			}
			if(flag)
			{
				s.erase(c);
				s.insert(c);
				it=s.find(c);
				it++;
				while(it!=s.end()&&it->a>c.a&&c.p>=it->p)s.erase(it++);
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

