/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=1000000007;
long long C[1050][1050],ans=0;
int cnt[1050];
char n[1050];
int k;
int calc(int x)
{
	int num=0;
	for(int i=0;i<=10;i++)
		if((x>>i)&1)
			num++;
	return num;
}
void pre_calc()
{
	for(int i=0;i<=1000;i++)
	{
		if(1<i)
			cnt[i]=cnt[calc(i)]+1;
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	return;
}
int main()
{
	//freopen("C.in","r",stdin);
	//freopen("C.out","w",stdout);
	int x,len;
	pre_calc();
	scanf("%s%d",n,&k);
	len=strlen(n);
	x=0;
	for(int i=0;i<len;i++)
		if(n[i]=='1')
			x++;
	if(cnt[x]==k-1) ans=1;
	for(int i=1;i<=1000;i++)
	{
		if(cnt[i]==k-1)
		{
			x=i;
			for(int j=0;j<len;j++) if(n[j]=='1')
				ans=(ans+C[len-j-1][x--])%mod;
			if(i==1) ans--;
		}
	}
	if(len==1&&n[0]=='1'&&k==0) ans=1;
	printf("%I64d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

