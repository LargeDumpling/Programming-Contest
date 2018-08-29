/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
const int MAXN=150000;
int n;
int x[2][MAXN],y[2][MAXN],minx[2][MAXN],maxx[2][MAXN],miny[2][MAXN],maxy[2][MAXN];
int ansx,ansy;
void read1n(int &x)
{
	bool neg=false;
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch=='-') neg=true;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	if(neg) x=-x;
	return;
}
int main()
{
	read1n(n);
	for(int i=1;i<=n;i++)
	{
		read1n(x[0][i]);
		read1n(y[0][i]);
		read1n(x[1][i]);
		read1n(y[1][i]);
	}
	minx[0][1]=x[1][1];
	maxx[0][1]=x[0][1];
	miny[0][1]=y[1][1];
	maxy[0][1]=y[0][1];
	for(int i=2;i<=n;i++)
	{
		minx[0][i]=min(minx[0][i-1],x[1][i]);
		maxx[0][i]=max(maxx[0][i-1],x[0][i]);
		miny[0][i]=min(miny[0][i-1],y[1][i]);
		maxy[0][i]=max(maxy[0][i-1],y[0][i]);
	}
	minx[1][n]=x[1][n];
	maxx[1][n]=x[0][n];
	miny[1][n]=y[1][n];
	maxy[1][n]=y[0][n];
	for(int i=n-1;i;i--)
	{
		minx[1][i]=min(minx[1][i+1],x[1][i]);
		maxx[1][i]=max(maxx[1][i+1],x[0][i]);
		miny[1][i]=min(miny[1][i+1],y[1][i]);
		maxy[1][i]=max(maxy[1][i+1],y[0][i]);
	}
	if(maxx[1][2]<=minx[1][2]&&maxy[1][2]<=miny[1][2])
	{
		ansx=maxx[1][2];
		ansy=maxy[1][2];
	}
	else if(maxx[0][n-1]<=minx[0][n-1]&&maxy[0][n-1]<=miny[0][n-1])
	{
		ansx=maxx[0][n-1];
		ansy=maxy[0][n-1];
	}
	else
	{
		for(int i=2;i<n;i++) if(max(maxx[0][i-1],maxx[1][i+1])<=min(minx[0][i-1],minx[1][i+1])
			&&max(maxy[0][i-1],maxy[1][i+1])<=min(miny[0][i-1],miny[1][i+1]))
		{
			ansx=max(maxx[0][i-1],maxx[1][i+1]);
			ansy=max(maxy[0][i-1],maxy[1][i+1]);
			break;
		}
	}
	printf("%d %d",ansx,ansy);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

