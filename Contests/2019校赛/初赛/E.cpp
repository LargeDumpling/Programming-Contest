/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-03-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,n;
char s[6][3]={"k","p","kk","pp","kp","pk"};
int cnt[6],ans=0;
int main()
{
	char str[3];
	scanf("%d",&T_T);
	while(T_T--)
	{
		memset(cnt,ans=0,sizeof(cnt));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",str);
			for(int j=0;j<6;j++)
				if(!strcmp(s[j],str))
					cnt[j]++;
		}
		if((!cnt[4])&&(!cnt[5]))
			ans+=max(0,cnt[0]+2*cnt[2]-1)+max(0,cnt[1]+2*cnt[3]-1);
		else if(cnt[4]&&cnt[5])
		{
			if(cnt[4]<cnt[5])
				ans+=cnt[4]*2;
			else if(cnt[5]<cnt[4])
				ans+=cnt[5]*2;
			else
				ans+=(cnt[4]+cnt[5]-1);
			ans+=cnt[0]+cnt[1]+2*cnt[2]+2*cnt[3];
		}
		else
			ans+=cnt[0]+cnt[1]+2*cnt[2]+2*cnt[3];
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

