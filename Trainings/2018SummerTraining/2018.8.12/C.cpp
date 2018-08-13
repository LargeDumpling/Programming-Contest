/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-12	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int num[110],cnt,len,t[350],st[350];
long long ans[3629900];
char str[350];
bool calc()
{
	int cnt=0;
	long long j;
	memset(ans,-1,sizeof(ans));
	for(int i=0;i<10;i++)
		num[i]=i;
	do
	{
		j=0;
		memset(t,-1,sizeof(t));
		for(int i=0;i<len;i++)
			if(t[str[i]]==-1)
				t[str[i]]=num[j++];
		j=0;
		for(int i=1;i<len;i++)
		{
			if(t[str[i-1]]>t[str[i]])
				j=j*3LL;
			else if(t[str[i-1]]==t[str[i]])
				j=j*3LL+1LL;
			else if(t[str[i-1]]<t[str[i]])
				j=j*3LL+2LL;
		}
		ans[cnt++]=j;
	}while(next_permutation(num,num+10));
	sort(ans,ans+3628800);
	for(int i=0;i<3628800;i++)
		if(ans[i]!=-1)
		{
			if(0<i&&ans[i]==ans[i-1]) continue;
			if(i<3628799&&ans[i]==ans[i+1]) continue;
			st[0]=0;
			j=ans[i];
			for(int k=1;k<len;k++,j/=3LL)
				st[++st[0]]=j%3LL;
			for(int k=0;k<len;k++)
			{
				if(k!=0) putchar(' ');
				putchar('a'+str[k]);
				if(st[0])
				{
					putchar(' ');
					if(st[st[0]]==0)
						putchar('>');
					else if(st[st[0]]==1)
						putchar('=');
					else if(st[st[0]]==2)
						putchar('<');
					st[0]--;
				}
			}
			return true;
		}
	return false;
}
int main()
{
	scanf("%s",str);
	len=strlen(str);
	for(int i=0;i<len;i++)
		str[i]-='a';
	if(!calc()) puts("Impossible");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

