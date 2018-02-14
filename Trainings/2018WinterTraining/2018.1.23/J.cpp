/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
char str[30][30];
int rcnt[30][26],ccnt[30][26],cnt[26],tar;
int main()
{
	while(scanf("%d",&n)!=-1)
	{
		memset(rcnt,0,sizeof(rcnt));
		memset(ccnt,0,sizeof(ccnt));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
			scanf("%s",str[i]+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				rcnt[i][str[i][j]-'A']++;
				ccnt[j][str[i][j]-'A']++;
				cnt[str[i][j]-'A']++;
			}
		for(int i=0;i<26;i++)
			if(cnt[i]==n-1)
			{
				tar=i;
				break;
			}
		for(int i=1;i<=n;i++)
			if(!rcnt[i][tar])
			{
				printf("%d",i);
				break;
			}
		for(int i=1;i<=n;i++)
			if(!ccnt[i][tar])
			{
				printf(" %d",i);
				break;
			}
		printf(" %c\n",tar+'A');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

