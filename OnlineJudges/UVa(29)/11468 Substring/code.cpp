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
struct jp
{
	//private:
		int ch[450][62],pre[450],sz;
		double pro[62],dp[450][105];
		int q[100050];
		bool word[450];
		int inc(int &x){return ++x>100048?x-100048:x;}
		int idx(char x)
		{
			if('A'<=x&&x<='Z')return x-'A';
			else if('a'<=x&&x<='z')return x-'a'+26;
			else if('0'<=x&&x<='9')return x-'0'+52;
			return -1;
		}
	//public:
		void init()
		{
			memset(ch,sz=0,sizeof ch);
			memset(word,false,sizeof word);
			for(int i=0;i<62;i++) pro[i]=0;
			for(int i=0;i<450;i++) for(int j=0;j<105;j++) dp[i][j]=-1;
			return;
		}
		void insert(char *tex)
		{
			int u;
			for(u=0;*tex!='\0';u=ch[u][idx(*(tex++))])
				if(!ch[u][idx(*tex)])
					ch[u][idx(*tex)]=++sz;
			word[u]=true;
			return;
		}
		#define head q[0]
		#define tail q[100049]
		void get_fail()
		{
			int u,v,f;
			memset(pre,head=tail=0,sizeof pre);
			for(int i=0;i<62;i++) if(ch[0][i]) q[inc(tail)]=ch[0][i];
			while(head!=tail)
			{
				u=q[inc(head)];
				for(int i=0;i<62;i++)
				{
					if(!ch[u][i]) { ch[u][i]=ch[pre[u]][i]; continue; }
					v=ch[u][i];
					q[inc(tail)]=v;
					f=pre[u];
					while(f&&!ch[f][i])f=pre[f];
					pre[v]=ch[f][i];
					word[v]|=word[pre[v]];
				}
			}
			return;
		}
		#undef head
		#undef tail
		void def_pro(char x,double p) { pro[idx(x)]=p; return; }
		double query(int u,int L)
		{
			if(word[u]) return 0.;
			if(!L) return 1.;
			if(dp[u][L]!=-1) return dp[u][L];
			dp[u][L]=0;
			for(int i=0;i<62;i++) if(pro[i]>1e-6)
				dp[u][L]+=pro[i]*query(ch[u][i],L-1);
			return dp[u][L];
		}
}AC;
int T,n,L;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char tex[25];
	double p;
	scanf("%d",&T);
	for(int cAse=1;cAse<=T;cAse++)
	{
		AC.init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",tex);
			AC.insert(tex);
		}
		scanf("%d",&L);
		AC.get_fail();
		for(int i=1;i<=L;i++)
		{
			scanf("%s%lf",tex,&p);
			AC.def_pro(tex[0],p);
		}
		scanf("%d",&L);
		printf("Case #%d: %.6f\n",cAse,AC.query(0,L));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

