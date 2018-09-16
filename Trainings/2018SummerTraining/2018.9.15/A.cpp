/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,len;
char str[20],name[]="JESSIE";
bool check()
{
	len=strlen(str);
	if(len!=6) return false;
	for(int i=0;i<len;i++)
	{
		if('a'<=str[i]&&str[i]<='z')
			str[i]=str[i]-'a'+'A';
		if(str[i]!=name[i]) return false;
	}
	return true;
}
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%s",str);
		if(check()) puts("Good guy!");
		else puts("Dare you say that again?");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

