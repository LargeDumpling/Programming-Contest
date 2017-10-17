#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n,q,num[100050];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int L,R,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++)scanf("%d",&num[i]);
		sort(num+1,num+n+1);
		L=1;R=n;ans=0;
		while(L<R)
		{
			if(num[L]+num[R]<=q)L++,R--;
			else R--;
			ans++;
		}
		if(L==R)ans++;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

