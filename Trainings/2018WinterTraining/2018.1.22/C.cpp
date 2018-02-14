/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,k,cnt[15],ans;
bool exist[15];
int main()
{
	freopen("scoreboard.in","r",stdin);
	char str[15];
	scanf("%d",&T_T);
	while(T_T-->0)
	{
		memset(exist,true,sizeof(exist));
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&k);
		scanf("%s",str);
		for(int i=0;i<k;i++)
			exist[str[i]-'A']=false;
		for(int i=0;i<13;i++)
			scanf("%d",&cnt[i]);
		ans=-1;
		for(int i=0;i<13;i++) if(exist[i])
		{
			if(ans==-1)
				ans=i;
			else if(cnt[ans]<cnt[i])
				ans=i;
		}
		printf("%c\n",'A'+ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

