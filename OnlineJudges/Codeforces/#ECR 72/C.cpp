/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-09-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200050;
char str[MAXN];
int T_T,len,lz[MAXN],tlen[MAXN],pz[MAXN];
long long ans;
void pre_calc()
{
	for(int i=1;i<MAXN;i++)
	{
		tlen[i]=0;
		for(int j=i;j;tlen[i]++,j>>=1);
		lz[i]=i-tlen[i];
	}
	return;
}
int main()
{
	int cnt;
	pre_calc();
	memset(pz,0,sizeof(pz));
	scanf("%d",&T_T);
	while(T_T--)
	{
		ans=0;
		scanf("%s",str);
		len=strlen(str);
		for(int i=0;i<len;i++)
		{
			if((!i)||str[i-1]=='1') pz[i]=0;
			else pz[i]=pz[i-1]+1;
			cnt=0;
			for(int j=i;str[i]=='1'&&j<len;j++)
			{
				cnt=(cnt<<1)+str[j]-'0';
				if(cnt<MAXN&&lz[cnt]<=pz[i]) ans++;
				else break;
			}
		}
		cout<<ans<<endl;

		for(int i=0;i<len;i++) pz[i]=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

