/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int num[1000050],N,Q;
void cHange(int l,int r,int x)
{
	for(int i=l;i<=r;i++) num[i]+=x;
	return;
}
int qUery(int l,int r,int x)
{
	int ans=0;
	for(int i=l;i<=r;i++) if(num[i]>=x) ans++;
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	char ord[5];
	int a,b,c;
	scanf("%d%d",&N,&Q);
	for(int i=1;i<=N;i++) scanf("%d",&num[i]);
	for(int i=1;i<=Q;i++)
	{
		scanf("%s%d%d%d",ord,&a,&b,&c);
		switch(ord[0])
		{
			case 'M': cHange(a,b,c); break;
			case 'A': printf("%d\n",qUery(a,b,c)); break;
			default: break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

