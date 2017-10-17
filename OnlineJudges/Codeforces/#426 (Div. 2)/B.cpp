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
char str[1000050];
int len,k,beg[26],endd[26];
int B[1000050],E[1000050];
bool check()
{
	int cnt=0;
	for(int i=0;i<len;i++)
	{
		cnt+=B[i];
		if(k<cnt) return true;
		cnt-=E[i];
	}
	return false;
}
int main()
{
	memset(beg,-1,sizeof(beg));
	memset(endd,-1,sizeof(endd));
	memset(B,0,sizeof(B));
	memset(E,0,sizeof(E));
	scanf("%d%d",&len,&k);
	scanf("%s",str);
	for(int i=0;i<len;i++)
		if(beg[str[i]-'A']==-1) beg[str[i]-'A']=endd[str[i]-'A']=i;
		else endd[str[i]-'A']=max(endd[str[i]-'A'],i);
	for(int i=0;i<26;i++)
		if(beg[i]!=-1)
		{
			B[beg[i]]++;
			E[endd[i]]++;
		}
	if(check()) printf("YES");
	else printf("NO");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

