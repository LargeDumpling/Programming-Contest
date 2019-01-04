/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-01-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int MAXL=500050;
int n,len;
int lef[MAXL],rig[MAXL],ans=0;
char str[MAXL];
int main()
{
	int num;
	bool mid=false;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str);
		len=strlen(str);
		num=0;
		for(int i=0;i<len;i++)
		{
			if(str[i]=='(') num++;
			if(str[i]==')') num--;
			if(num<0) break;
		}
		if(num==0)
		{
			if(mid) ans++;
			mid^=true;
			continue;
		}
		else if(num>0)
		{
			if(rig[num]>0)
			{
				rig[num]--;
				ans++;
			}
			else lef[num]++;
		}
		num=0;
		for(int i=len-1;0<=i;i--)
		{
			if(str[i]==')') num++;
			if(str[i]=='(') num--;
			if(num<0) break;
		}
		if(num>0)
		{
			if(lef[num]>0)
			{
				lef[num]--;
				ans++;
			}
			else rig[num]++;
		}
	}
	printf("%d",ans);
	return 0;
}

