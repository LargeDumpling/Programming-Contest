#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
int T,n,num[200050],pre[200050],next[200050];
bool check(int l,int r)
{
	if(l>=r)
		return true;
	for(int L=l,R=r;L<=R;L++,R--)
	{
		if(pre[L]<l&&r<next[L])
			return (check(l,L-1)&&check(L+1,r));
		if(L==R)
			break;
		if(pre[R]<l&&r<next[R])
			return (check(l,R-1)&&check(R+1,r));
	}
	return false;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	map<int,int>s;
	scanf("%d",&T);
	while(T--)
	{
		s.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
			if(!s.count(num[i]))
				pre[i]=0;
			else
				pre[i]=s[num[i]];
			s[num[i]]=i;
			next[i]=0;
		}
		for(int i=n;i;i--)
		{
			 if(pre[i])
				next[pre[i]]=i;
			 if(!next[i])
				next[i]=n+1;
		}
		if(check(1,n))
			printf("non-boring\n");
		else
			printf("boring\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

