/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,v[200050],be[200050],next[200050],take[200050],BLOCK;
int query(int x)
{
	int ans=take[x];
	for(x=next[x];x<=n;x=next[x])
		ans+=take[x];
	return ans;
}
void change(int pos,int x)
{
	//if(v[pos]==x) return;
	int lowlimit=(be[pos]-1)*BLOCK+1;
	v[pos]=x;
	for(int i=pos;i>=lowlimit;i--)
	{
		next[i]=i+v[i];
		take[i]=1;
		while(next[i]<=n&&be[next[i]]==be[i])
		{
			take[i]+=take[next[i]];
			next[i]=next[next[i]];
		}
	}
	return;
}
int read1n()
{
	int x;
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	return x;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int order,a,b;
	//scanf("%d",&n);
	n=read1n();
	BLOCK=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		//scanf("%d",&v[i]);
		v[i]=read1n();
		next[i]=i+v[i];
		take[i]=1;
		be[i]=(i-1)/BLOCK+1;
	}
	for(int i=n;i;i--)
		while(next[i]<=n&&be[next[i]]==be[i])
		{
			take[i]+=take[next[i]];
			next[i]=next[next[i]];
		}
	//scanf("%d",&m);
	m=read1n();
	//fprintf(stderr,"%d %d\n",n,m);
	while(m--)
	{
		//scanf("%d%d",&order,&a); a++;
		order=read1n();
		a=read1n();a++;
		//fprintf(stderr,"%d %d",order,a);
		if(order==1) printf("%d\n",query(a));
		else if(order==2)
		{
			//scanf("%d",&b);
			b=read1n();
			//fprintf(stderr," %d",b);
			change(a,b);
		}
		//fprintf(stderr,"\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

