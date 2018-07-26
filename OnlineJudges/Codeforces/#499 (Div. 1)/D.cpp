/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-27	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1000050;
struct jz
{
	int id;
	bool ans;
	jz(const int &I=0,const bool &B=true):id(I),ans(B) { }
	bool operator<(const jz &X)const
	{
		return id<X.id;
	}
}num[MAXN];
int n,an,typ[MAXN],data[MAXN],ch[MAXN][2];
bool chan[MAXN];
//AND 0
//OR  1
//XOR 2
//NOT 3
void read1n(int &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void DFS1(int u)
{
	if(typ[u]==-1) return;
	DFS1(ch[u][0]);
	if(typ[u]!=3)
		DFS1(ch[u][1]);
	if(typ[u]!=3)
	{
		switch(typ[u])
		{
			case 0:
				data[u]=data[ch[u][0]]&data[ch[u][1]];
				break;
			case 1:
				data[u]=data[ch[u][0]]|data[ch[u][1]];
				break;
			case 2:
				data[u]=data[ch[u][0]]^data[ch[u][1]];
				break;
			default:
				break;
		}
	}
	else data[u]=!data[ch[u][0]];
}
void DFS2(int u)
{
	if(typ[u]==-1)
	{
		num[++an]=jz(u,chan[u]);
		return;
	}
	if(!chan[u])
	{
		chan[ch[u][0]]=false;
		DFS2(ch[u][0]);
		if(typ[u]!=3)
			DFS2(ch[u][1]);
	}
	else
	{
		if(typ[u]==0)
		{
			if(data[u]==1)
			{
				chan[ch[u][0]]=true;
				DFS2(ch[u][0]);
				chan[ch[u][1]]=true;
				DFS2(ch[u][1]);
			}
			else if(data[ch[u][0]]==0&&data[ch[u][1]]==0)
			{
				chan[ch[u][0]]=false;
				DFS2(ch[u][0]);
				chan[ch[u][1]]=false;
				DFS2(ch[u][1]);
			}
			else if(data[ch[u][0]]==1)
			{
				chan[ch[u][0]]=false;
				DFS2(ch[u][0]);
				chan[ch[u][1]]=true;
				DFS2(ch[u][1]);
			}
			else if(data[ch[u][1]]==1)
			{
				chan[ch[u][0]]=true;
				DFS2(ch[u][0]);
				chan[ch[u][1]]=false;
				DFS2(ch[u][1]);
			}
		}
		else if(typ[u]==1)
		{
			if(data[u]==0)
			{
				chan[ch[u][0]]=true;
				DFS2(ch[u][0]);
				chan[ch[u][1]]=true;
				DFS2(ch[u][1]);
			}
			else if(data[ch[u][0]]==1&&data[ch[u][1]]==1)
			{
				chan[ch[u][0]]=false;
				DFS2(ch[u][0]);
				chan[ch[u][1]]=false;
				DFS2(ch[u][1]);
			}
			else if(data[ch[u][0]]==1)
			{
				chan[ch[u][0]]=true;
				DFS2(ch[u][0]);
				chan[ch[u][1]]=false;
				DFS2(ch[u][1]);
			}
			else if(data[ch[u][1]]==1)
			{
				chan[ch[u][0]]=false;
				DFS2(ch[u][0]);
				chan[ch[u][1]]=true;
				DFS2(ch[u][1]);
			}
		}
		else if(typ[u]==2)
		{
			chan[ch[u][0]]=true;
			DFS2(ch[u][0]);
			chan[ch[u][1]]=true;
			DFS2(ch[u][1]);
		}
		else if(typ[u]==3)
		{
			chan[ch[u][0]]=true;
			DFS2(ch[u][0]);
		}
	}
	return;
}
int main()
{
	char str[5];
	read1n(n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str);
		switch(str[0])
		{
			case 'A':
				typ[i]=0;
				read1n(ch[i][0]);
				read1n(ch[i][1]);
				break;
			case 'I':
				typ[i]=-1;
				read1n(data[i]);
				break;
			case 'N':
				typ[i]=3;
				read1n(ch[i][0]);
				break;
			case 'O':
				typ[i]=1;
				read1n(ch[i][0]);
				read1n(ch[i][1]);
				break;
			case 'X':
				typ[i]=2;
				read1n(ch[i][0]);
				read1n(ch[i][1]);
				break;
			default:
				break;
		}
	}
	DFS1(1);
	chan[1]=true;
	an=0;
	DFS2(1);
	sort(num+1,num+an+1);
	for(int i=1;i<=an;i++)
		putchar('0'+(int)(num[i].ans^data[1]));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

