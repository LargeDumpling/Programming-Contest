#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,q;
int sum[4050][4050];
void readln(int &x)
{
	char ch;x=0;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(;'0'<=ch&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void build_2(int rx,int root,int l,int r)
{
	if(l==r)
	{
		readln(sum[rx][root],
	}
}
void build(int root,int l,int r)
{
	if(l==r)
	{
		build_2(root,1,1,m);
		return;
	}
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	build(1,1,n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

