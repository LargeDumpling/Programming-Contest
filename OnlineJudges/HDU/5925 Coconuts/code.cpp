/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-10-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=205;
int T_T,R,C,n;
int x[MAXN],y[MAXN],hx[MAXN],hy[MAXN],fx[MAXN<<1],fy[MAXN<<1],hxn,hYn,xn,Yn;
int mOve[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int nn;
long long lenx[MAXN<<1],leny[MAXN<<1],num[MAXN*MAXN<<2];
bool vis[MAXN<<1][MAXN<<1],exist[MAXN<<1][MAXN<<1];
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
long long DFS(int X,int Y)
{
	long long sum=lenx[X]*leny[Y];
	vis[X][Y]=true;
	int xx,yy;
	for(int i=0;i<4;i++)
	{
		xx=X+mOve[i][0];
		yy=Y+mOve[i][1];
		if(xx<1||xn<xx||yy<1||Yn<yy||vis[xx][yy]||!exist[xx][yy]) continue;
		sum+=DFS(xx,yy);
	}
	return sum;
}
int main()
{
	read1n(T_T);
	for(int T=1;T<=T_T;T++)
	{
		memset(vis,false,sizeof(vis));
		memset(exist,true,sizeof(exist));
		hxn=hYn=xn=Yn=0;
		read1n(R);
		read1n(C);
		read1n(n);
		for(int i=1;i<=n;i++)
		{
			read1n(x[i]);
			hx[++hxn]=x[i];
			read1n(y[i]);
			hy[++hYn]=y[i];
		}
		hx[0]=0;
		sort(hx+1,hx+hxn+1);
		hx[hxn=unique(hx+1,hx+hxn+1)-hx]=R;
		for(int i=1;i<=hxn;i++)
		{
			if(hx[i-1]+1<hx[i])
				lenx[++xn]=hx[i]-hx[i-1]-1;
			lenx[++xn]=1;
			fx[i]=xn;
		}
		hy[0]=0;
		sort(hy+1,hy+hYn+1);
		hy[hYn=unique(hy+1,hy+hYn+1)-hy]=C;
		for(int i=1;i<=hYn;i++)
		{
			if(hy[i-1]+1<hy[i])
				leny[++Yn]=hy[i]-hy[i-1]-1;
			leny[++Yn]=1;
			fy[i]=Yn;
		}
		for(int i=1;i<=n;i++)
		{
			x[i]=fx[lower_bound(hx+1,hx+hxn+1,x[i])-hx];
			y[i]=fy[lower_bound(hy+1,hy+hYn+1,y[i])-hy];
			exist[x[i]][y[i]]=false;
		}
		nn=0;
		for(int i=1;i<=xn;i++)
			for(int j=1;j<=Yn;j++) if(!vis[i][j]&&exist[i][j])
				num[++nn]=DFS(i,j);
		sort(num+1,num+nn+1);
		printf("Case #%d:\n%d\n",T,nn);
		for(int i=1;i<=nn;i++)
			printf("%lld ",num[i]);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

