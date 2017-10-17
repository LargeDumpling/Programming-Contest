/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-05-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,cnt;
bool exist[26];
char ch[30];
int main()
{
	scanf("%d",&n);
	if(n>26) puts("-1");
	else
	{
		scanf("%s",ch);
		for(int i=0;i<n;i++)
		{
			if(!exist[ch[i]-'a'])
			{
				cnt++;
				exist[ch[i]-'a']=true;
			}
		}
		printf("%d",n-cnt);
	}
	return 0;
}

