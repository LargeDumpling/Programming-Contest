/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,n;
char str[85];
unsigned long long f[85][10];
bool check()
{
	for(int i=1;i<n;i++)
		if(str[i+1]<str[i])
			return false;
	return true;
}
int main()
{
	unsigned long long sum;
	f[0][9]=1;
	for(int i=1;i<=80;i++)
	{
		sum=0;
		for(int j=9;0<=j;j--)
		{
			sum+=f[i-1][j];
			f[i][j]=sum;
		}
	}
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%s",str+1);
		n=strlen(str+1);
		for(int i=1;i<=n;i++)
			str[i]-='0';
		if(check())
		{
			sum=0;
			str[0]=0;
			for(int i=0;i<n;i++)
				for(int j=str[i];j<str[i+1];j++)
					sum+=f[n-i][j];
			cout<<sum<<endl;
		}
		else puts("-1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

