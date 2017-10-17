/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char tex[400050];
int lenth,d[400050];
void solve()
{
	int r,id;
	memset(d,0,sizeof(d));
	d[0]=r=id=0; lenth=lenth<<1|1;
	for(int i=1;i<lenth;i++)
	{
		d[i]=r>i?min(r-i,d[(id<<1)-i]):0;
		//if(r>i)
		//{
			//d[i]=r-i;
			//if(id*2>=i) d[i]=min(d[i],d[id*2-i]);
		//}
		//else d[i]=0;
		while(tex[i-d[i]-1]==tex[i+d[i]+1]) d[i]++;
		if(i+d[i]>r)
		{
			r=i+d[i];
			id=i;
		}
		//r=max(r,i+d[i]);
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int id,tot,ts;
	int cAse=0;
	while(scanf("%s",tex)!=-1)
	{
		//printf("%d",cAse++);
		lenth=strlen(tex);
		for(int i=lenth-1;i>=0;i--)
		{
			tex[i<<1|1]=tex[i];
			tex[i<<1]='[';
		}
		tex[lenth<<1]=']';
		tex[0]='^';
		solve();
		//for(int i=0;i<lenth;i++) printf("%d ",i); putchar('\n');
		//for(int i=0;i<lenth;i++) putchar(tex[i]),putchar(' '); putchar('\n');
		//for(int i=0;i<lenth;i++) printf("%d ",d[i]); putchar('\n');
		tot=2147483647;
		for(int i=0;i<lenth-1;i++) if(i+d[i]==lenth-2)
		{
			ts=i&1?(d[i]>>1)<<1|1:((d[i]+1)>>1)<<1;
			ts+=(i-d[i])>>1;
			if(ts<tot)
			{
				tot=ts;
				id=i;
			}
		}
		for(int i=1;i<lenth;i+=2) putchar(tex[i]);
		for(int i=id-d[id]-2;i>=1;i-=2) putchar(tex[i]);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

