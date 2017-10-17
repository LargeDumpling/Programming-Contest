#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,a[27],d[28],d2[27];
int p;
bool flag,exist[27];
void read1n()
{
	char ch;
	for(ch=getchar();ch<'A'||'Z'<ch;ch=getchar());
	for(int i=0;i<26;i++,ch=getchar())a[i]=ch-'A';
	return;
}
bool check()
{
	memset(exist,true,sizeof(exist));
	memset(d2,0,sizeof(d2));
	for(int i=d[0]=0;i<26;i++)
	{
		if(!exist[i])
			continue;
		d[++d[0]]=1;
		p=a[i];
		exist[i]=false;
		while(exist[p])
		{
			d[d[0]]++;
			exist[p]=false;
			p=a[p];
		}
		d2[d[d[0]]]++;
	}
	flag=false;
	for(int i=2;i<=26;i+=2)
		if(d2[i]&1)
			flag=true;
	return flag;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		read1n();
		if(check())
			printf("No\n");
		else
			printf("Yes\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

