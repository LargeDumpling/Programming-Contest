/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-07-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k;
int num[35050],pos[35050],exist[35050];
int main()
{
	//freopen("code.in","r",stdin);
	memset(exist,-1,sizeof(exist));
	num[0]=pos[0]=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[num[0]+1]);
		if(2<=num[0]&&(num[num[0]-1]!=num[num[0]]||num[num[0]]!=num[num[0]+1]))
			num[0]++;
		else if(num[0]<2)
			num[0]++;
	}
	for(int i=1;i<=num[0];i++)
		if(num[i]==num[i+1])
			pos[++pos[0]]=i;
	int cnt=0,ans=0,cur=0;
	for(int i=1;i<=num[0]&&cnt<k-1;i++)
	{
		if(exist[num[i]]!=cnt)
		{
			cur++;
			exist[num[i]]=cnt;
		}
		if(num[i]==num[i+1])
		{
			ans+=cur;
			cur=0;
			cnt++;
			if(cnt==k-1)
				break;
		}
	}
	for(int i=cnt?pos[cnt]+1:1;i<=num[0];i++)
		if(exist[num[i]]!=cnt)
		{
			cur++;
			exist[num[i]]=cnt;
		}
	ans+=cur;
	cnt++;
	ans+=k-cnt;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

