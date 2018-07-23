/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
struct jz
{
	int x,y,id;
	bool operator<(const jz &X)const { return x==X.x?y>X.y:x>X.x; }
};
int T_T,n;
void read1n(int &x)
{
	char ch; bool neg=false;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar()) if(ch=='-') neg=true;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	if(neg) x=-x;
	return;
}
int main()
{
	int a,b;
	//scanf("%d",&T_T);
	read1n(T_T);
	priority_queue<jz> q;
	while(T_T-->0)
	{
		//scanf("%d",&n);
		read1n(n);
		n*=3;
		for(int i=1;i<=n;i++)
		{
			//scanf("%d%d",&P[i].x,&P[i].y);
			read1n(a); read1n(b);
			jz tem;
			tem.x=a;
			tem.y=b;
			tem.id=i;
			q.push(tem);
		}
		for(int i=1;i<=n;i++)
		{
			printf("%d%c",q.top().id,i%3?' ':'\n');
			q.pop();
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

