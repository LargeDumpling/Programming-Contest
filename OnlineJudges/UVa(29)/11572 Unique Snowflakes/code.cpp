#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
int T,n,a[1000050];
set<int>s;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int l,r,ans=0;
	scanf("%d",&T);
	while(T--)
	{
		s.clear();
		scanf("%d",&n);
		l=1;
		r=ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[++r]);
			if(s.count(a[r]))
			{
				while(a[l]!=a[r])
					s.erase(a[l++]);
				l++;
			}
			else
				s.insert(a[r]);
			ans=max(ans,r-l+1);
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

