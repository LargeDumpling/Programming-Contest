/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int T_T,n,m;
int T[MAXN],r[MAXN],ans=0;
char str[5];
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		int p=-1;
		ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",str);
			if(str[0]=='W') T[p=i]=-1;
			else if(str[0]=='C') T[i]=0;
			else if(str[0]=='B') T[i]=1;
			else if(str[0]=='D') T[i]=2;
			if(str[0]!='W') scanf("%d",&r[i]);
		}
		if(n==1)
		{
			ans=3*m;
			printf("%d\n",ans);
			continue;
		}
		else if(n==2)
		{
			if(T[1]==-1) ans=T[2]*m+r[2]-1;
			else if(T[2]==-1) ans=3*m-T[1]*m-r[1]+1;//the write dragon can also be the first tile
			else if(T[1]<T[2]) ans=3*m-1;
			else if(T[1]==T[2]&&r[1]<r[2]) ans=3*m-1;
			else ans=1;
			printf("%d\n",ans);
			continue;
		}
		if(p==-1)
		{
			 if(T[1]*m+r[1]<T[2]*m+r[2]) ans=3*m-n+1;
			 else ans=1;
			 printf("%d\n",ans);
			 continue;
		}
		if(p==1)
		{
			ans=T[1]*m+r[1]-1;
			printf("%d\n",ans);
			continue;
		}
		else if(p==2)
		{
			if(T[1]*m+r[1]<T[3]*m+r[3]) ans=T[3]*m+r[3]-T[1]*m-r[1];
			else ans=1;
			printf("%d\n",ans);
			continue;
		}
		if(T[1]*m+r[1]<T[2]*m+r[2])
			ans=T[p+1]*m+r[p+1]-T[p-1]*m-r[p-1]-1;
		else ans=1;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
