/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct Tire
{
	static const int MAXS=400050;
	int ch[MAXS][26],sz,c[26];
	bool word[MAXS];
	Tire()
	{
		memset(ch[0],sz=0,sizeof(ch[0]));
		memset(c,0,sizeof(c));
		word[0]=false;
	}
	void clear()
	{
		memset(ch[0],sz=0,sizeof(ch[0]));
		memset(c,0,sizeof(c));
		word[0]=false;
		return;
	}
	bool insert(char tex[],int lenth)
	{
		int u=0;
		bool flag;
		for(int i=0;i<lenth;u=ch[u][tex[i++]-97])
		{
			if(!ch[u][tex[i]-97])
			{
				ch[u][tex[i]-97]=++sz;
				memset(ch[sz],0,sizeof(ch[sz]));
				word[sz]=false;
				if(i) c[tex[i]-97]++;
			}
		}
		flag=word[u];
		word[u]=true;
		return !flag;
	}
	int size() { return sz; }
}pre,suf;
int n;
long long ans;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int lenth;
	char wo[50];
	bool exist[26];
	while(scanf("%d",&n)!=-1&&n)
	{
		pre.clear(); suf.clear(); ans=0;
		memset(exist,false,sizeof(exist));
		for(int i=1;i<=n;i++)
		{
			scanf("%s",wo);
			lenth=strlen(wo);
			if(lenth==1)exist[wo[0]-97]=true;
			pre.insert(wo,lenth);
			for(int j=((lenth-1)>>1);j>=0;j--) swap(wo[j],wo[lenth-j-1]);
			suf.insert(wo,lenth);
		}
		ans=(long long)pre.size()*suf.size();
		for(int i=0;i<26;i++) ans-=((long long)pre.c[i]*suf.c[i]-exist[i]);
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

