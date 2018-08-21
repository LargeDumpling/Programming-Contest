/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXL=1000050;
int T_T;
int nex[MAXL][26],n,len,m;
char S[MAXL],str[MAXL];
void merge()
{
	int i,x=0;
	char ch;
	for(i=0;i<m;i++)
	{
		if(nex[x][str[i]-'a']==-1)
			break;
		x=nex[x][str[i]-'a']+1;
	}
	for(int j=0;j<m-i;j++)
	{
		ch=S[len+j]=str[i+j];
		for(int k=len+j;0<=k&&nex[k][ch-'a']==-1;k--)
			nex[k][ch-'a']=len+j;
	}
	len+=(m-i);
	return;
}
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		memset(nex,-1,sizeof(nex));
		scanf("%d",&n);
		scanf("%s",S);
		len=strlen(S);
		for(int i=len-1;0<=i;i--)
		{
			memcpy(nex[i],nex[i+1],sizeof(nex[i]));
			nex[i][S[i]-'a']=i;
		}
		for(int i=1;i<n;i++)
		{
			scanf("%s",str);
			m=strlen(str);
			merge();
		}
		S[len]='\0';
		puts(S);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

