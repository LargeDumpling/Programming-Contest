/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-07	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
int T,n,m,len[3050];
unsigned long long h[3050],P[25];
char tex[15];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int tot;
	set<unsigned long long>s;
	scanf("%d",&T);
	P[0]=1;
	for(int i=1;i<=20;i++) P[i]=P[i-1]*317;
	for(int cAse=1;cAse<=T;cAse++)
	{
		memset(h,0,sizeof(h));
		s.clear();
		scanf("%d%d",&n,&m);
		getchar();
		tot=n+m;
		for(int i=1;i<=tot;i++)
		{
			gets(tex);
			len[i]=strlen(tex);
			for(int j=len[i]-1;j>=0;j--) h[i]=h[i]*317+tex[j]-'a'+1;
		}
		for(int i=1;i<=n;i++)
			for(int j=1+n;j<=tot;j++)
				s.insert(h[i]+h[j]*P[len[i]]);
		printf("Case %d: %d\n",cAse,(int)s.size());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

