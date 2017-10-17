/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct tIre
{
	long long ans;
	struct nOde
	{
		int data,cnt,word;
		nOde *son,*next;
		nOde() { data=cnt=word=0;son=next=NULL; }
	}pool[4000050],*pis,*root;
	int idx(char x)
	{
		if('a'<=x&&x<='z') return x-'a';
		else if('A'<=x&&x<='Z') return x-'A'+26;
		else if('0'<=x&&x<='9') return x-'0'+52;
		return -1;
	}
	tIre()
	{
		ans=0;
		pis=pool;
		root=new (pis++)nOde();
	}
	void init()
	{
		ans=0;
		pis=pool;
		root= new (pis++)nOde();
		return;
	}
	void insert(char *tex)
	{
		int k;
		nOde *u,*v;
		for(u=root;*tex!='\0';tex++)
		{
			k=idx(*tex);
			for(v=u->son;v!=NULL&&v->data!=k;v=v->next);
			if(v==NULL)
			{
				v=new (pis++)nOde();
				v->data=k;
				v->next=u->son;
				u->son=v;
				ans+=(u->cnt);
			}
			else ans+=u->cnt+v->cnt;
			u->cnt++;
			u=v;
		}
		//if(u->cnt&&)ans++;
		//if(!u->word) ans+=u->cnt;
		//else ans+=(u->word)<<1;
		ans+=((u->word)<<1)+(u->cnt-u->word);
		u->cnt++;
		u->word++;
		return;
	}
	long long query() { return ans; }
}T;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n;
	char tex[1050];
	for(int cAse=1;scanf("%d",&n)!=-1&&n;cAse++)
	{
		T.init();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",tex);
			T.insert(tex);
		}
		printf("Case %d: %lld\n",cAse,T.query());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

