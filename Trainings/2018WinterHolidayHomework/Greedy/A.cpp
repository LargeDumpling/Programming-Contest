/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-07	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,p;
int den[10]={1,5,10,20,50,100,200,500,1000,2000},num[10],cnt[10];
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int main()
{
	int ans=0;
	read1n(T_T);
	while(T_T--)
	{
		read1n(p);
		for(int i=0;i<10;i++)
		{
			read1n(num[i]);
			cnt[i]=0;
		}
		for(int i=9;0<=i;i--)
		{
			cnt[i]=min(p/den[i],num[i]);
			p-=cnt[i]*den[i];
			num[i]-=cnt[i];
		}
		if(p)
		{
			for(int i=0;i<9;i++)
				for(int j=1;j<10;j++) if(cnt[j]&&den[j]%dend[i]==0&&)
				{
					int tem= 
				}
		}
		else puts("-1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

