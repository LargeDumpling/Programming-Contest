#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int f[10050],n;
bool vis[10050];
int find(int x)
{
	while(f[x]!=f[f[x]])
		f[x]=f[f[x]];
	return f[x];
}
void swap(int &a,int &b)
{
	a^=b;
	b=a^b;
	a^=b;
	return;
}
void JP(int a,int b)
{
	if(a<b)swap(a,b);
	vis[b]=true;
	f[b]=a;
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("union.out","w",stdout);
	int a,b;
	for(int i=1;i<=10000;i++)f[i]=i;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		a=find(a);
		b=find(b);
		if(a==b)vis[a]=true;
		else JP(a,b);
	}
	for(a=1;vis[a]&&a<=10000;a++);
	printf("%d",a-1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

