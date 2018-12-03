/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-11-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=1050;
struct jz
{
	int ws;
	short num[MAXN];
	jz() { memset(num,ws=0,sizeof(num)); }
	jz operator-(const jz &X)const
	{
		jz ans;
		ans.ws=max(ws,X.ws);
		for(int i=0;i<X.ws&&i<ws;i++)
			ans.num[i]=num[i]-X.num[i];
		if(X.ws<ws) for(int i=X.ws;i<ws;i++)
			ans.num[i]=num[i];
		if(ws<X.ws) for(int i=ws;i<X.ws;i++)
			ans.num[i]=0-X.num[i];
		for(int i=0;i<ans.ws-1;i++)
			while(ans.num[i]<0)
			{
				ans.num[i]+=10;
				ans.num[i+1]--;
			}
		while(ans.ws&&ans.num[ans.ws-1]==0) ans.ws--;
		return ans;
	}
}N;
char str[MAXN];
void print(const jz &X)
{
	for(int i=X.ws-1;0<=i;i--)
		putchar('0'+X.num[i]);
	return;
}
int main()
{
	int T_T;
	scanf("%d",&T_T);
	queue<jz> q;
	for(int T=1;T<=T_T;T++)
	{
		scanf("%s",str);
		N.ws=strlen(str);
		for(int i=0;i<N.ws;i++)
			N.num[i]=str[N.ws-1-i]-'0';
		while(N.ws)
		{
			if(N.ws==1)
			{
				q.push(N);
				break;
			}
			else
			{
				jz M;
				M.ws=N.ws;
				for(int i=(M.ws>>1);i<M.ws;i++)
					M.num[i]=N.num[i];
				M.num[M.ws>>1]--;
				for(int i=(M.ws>>1);i<M.ws-1;i++)
					while(M.num[i]<0)
					{
						M.num[i]+=10;
						M.num[i+1]--;
					}
				if(M.num[M.ws-1]<=0)
				{
					M.ws--;
					for(int i=M.ws-1;0<=i;i--)
						M.num[i]=9;
				}
				else for(int i=(M.ws>>1)-1;0<=i;i--)
					M.num[i]=M.num[M.ws-1-i];
				q.push(M);
				N=N-M;
			}
		}
		printf("Case #%d:\n%d\n",T,(int)q.size());
		while(q.size())
		{
			print(q.front()); q.pop();
			putchar('\n');
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

