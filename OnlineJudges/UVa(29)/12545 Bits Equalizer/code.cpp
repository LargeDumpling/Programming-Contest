/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History: 
    2015-11-26    File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,lenth;
char A[105],B[105];
int main()
{
    freopen("code.in","r",stdin);
    freopen("code.out","w",stdout);
	int cnt,ans=0;
	scanf("%d",&T);
	for(int cAse=1;cAse<=T;cAse++)
	{
		printf("Case %d: ",cAse);
		scanf("%s%s",A,B);
		lenth=strlen(A);
		ans=0;
		for(int i=cnt=0;i<lenth;i++)if(B[i]=='1')cnt++;
		for(int i=0;i<lenth;i++)if(A[i]=='1')cnt--;
		if(cnt<0)
		{
			printf("-1\n");
			continue;
		}
		for(int i=0;i<lenth;i++)
			if(A[i]=='?'&&cnt&&B[i]=='1')
			{
				cnt--;
				ans++;
				A[i]='1';
			}
		for(int i=0;i<lenth;i++)
			if(A[i]=='0'&&cnt&&B[i]=='1')
			{
				cnt--;
				ans++;
				A[i]='1';
			}
		for(int i=0;i<lenth;i++)
			if(A[i]=='?')
			{
				ans++;
				if(cnt) A[i]='1';
				else A[i]='0';
			}
		for(int i=0;i<lenth;i++)
			if(A[i]=='0'&&cnt)
			{
				ans++;
				A[i]='1';
			}
		for(int i=0;i<lenth;i++)if(A[i]=='1'&&B[i]=='0')ans++;
		printf("%d\n",ans);
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

