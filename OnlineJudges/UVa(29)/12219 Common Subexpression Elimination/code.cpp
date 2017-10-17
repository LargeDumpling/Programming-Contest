/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
struct jp
{
	string data;
	int lch,rch,sl,sr;
	bool leaf;
	jp()
	{
		lch=rch=sl=sr=0;
		leaf=false;
	}
	bool operator<(const jp &X)const
	{
		if(data==X.data)return lch==X.lch?rch<X.rch:lch<X.lch;
		return data<X.data;
	}
}node[50050];
map<jp,int>s;
char tex[1000050],temp[1000050];
int lenth,sz,exist[1000050],cAse;
int get_ID(jp X,int x)
{
	if(!s.count(X))return s[X]=x;
	return s[X];
}
bool isis(char ch){return ('a'<=ch&&ch<='z')||('A'<=ch&&ch<='Z');}
int bUild(char* &p)
{
	int id,len=0;
	node[id=++sz]=jp();
	while(isis(*p))temp[len++]=*(p++);
	temp[len]='\0';
	node[id].data=string(temp);
	node[id].lch=node[sz].rch=0;
	if(*p=='(')
	{
		p++;
		node[id].lch=bUild(p);
		p++;
		node[id].rch=bUild(p);
		p++;
	}
	if(s.count(node[id])!=0)
		return sz--,s[node[id]];
	return s[node[id]]=id;
}
void pRint(int root)
{
	if(exist[root]==cAse)
	{
		printf("%d",s[node[root]]);
		return;
	}
	exist[root]=cAse;
	cout<<node[root].data;
	if(!node[root].lch)return;
	putchar('(');
	pRint(node[root].lch);
	putchar(',');
	pRint(node[root].rch);
	putchar(')');
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(cAse=1;cAse<=T;cAse++)
	{
		scanf("%s",tex);
		lenth=strlen(tex);
		sz=0;
		s.clear();
		char *start=tex;
		pRint(bUild(start));
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

