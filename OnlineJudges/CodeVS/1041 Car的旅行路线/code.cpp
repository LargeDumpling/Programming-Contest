#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define calc(x1,x2,y1,y2) (sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)))
using namespace std;
int s,t,A,B,n;
int x[105][4],y[105][4];
double d[450][450];
void swap(int &a,int &b)
{
	a^=b;
	b=a^b;
	a^=b;
	return;
}
void sort(int &a,int &b,int &c)
{
	if(c<b)swap(b,c);
	if(b<a)swap(a,b);
	if(c<b)swap(b,c);
	return;
}
void disi(int X)
{
	double a=calc(x[X][0],x[X][1],y[X][0],y[X][1]),b=calc(x[X][0],x[X][2],y[X][0],y[X][2]),c=calc(x[X][1],x[X][2],y[X][1],y[X][2]),d;
	int p;
	d=a<b?(b<c?c:b):(a<c?c:a);
	if(d==c)
		p=0;
	else if(d==b)
		p=1;
	else if(d==a)
		p=2;
	x[X][3]=x[X][0]+x[X][1]+x[X][2]-x[X][p]-x[X][p];
	y[X][3]=y[X][0]+y[X][1]+y[X][2]-y[X][p]-y[X][p];
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,c,te;
	double ans;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%d%d",&s,&t,&A,&B);
		for(int i=1;i<=s;i++)
		{
			scanf("%d%d%d%d%d%d%d",&x[i][0],&y[i][0],&x[i][1],&y[i][1],&x[i][2],&y[i][2],&te);
			/*a=x[i][0];b=x[i][1];c=x[i][2];
			sort(a,b,c);
			x[i][3]=a+c-b;
			a=y[i][0];b=y[i][1];c=y[i][2];
			sort(a,b,c);
			y[i][3]=a+c-b;*/
			disi(i);
			d[4*i+1][4*i+2]=d[4*i+2][4*i+1]=calc(x[i][0],x[i][1],y[i][0],y[i][1])*te;
			d[4*i+1][4*i+3]=d[4*i+3][4*i+1]=calc(x[i][0],x[i][2],y[i][0],y[i][2])*te;
			d[4*i+1][4*i+4]=d[4*i+4][4*i+1]=calc(x[i][0],x[i][3],y[i][0],y[i][3])*te;
			d[4*i+2][4*i+3]=d[4*i+3][4*i+2]=calc(x[i][1],x[i][2],y[i][1],y[i][2])*te;
			d[4*i+2][4*i+4]=d[4*i+4][4*i+2]=calc(x[i][1],x[i][3],y[i][1],y[i][3])*te;
			d[4*i+3][4*i+4]=d[4*i+4][4*i+3]=calc(x[i][2],x[i][3],y[i][2],y[i][3])*te;
			for(int j=1;j<i;j++)
				for(int k=0;k<=3;k++)
					for(int l=0;l<=3;l++)
						d[4*i+k+1][4*j+l+1]=d[4*j+l+1][4*i+k+1]=calc(x[i][k],x[j][l],y[i][k],y[j][l])*t;
		}
		for(int k=5,i,j;k<=4*s+4;k++)
			for(i=5;i<=4*s+4;i++)
				for(j=5;j<=4*s+4;j++)
					if(i!=j&&i!=k&&j!=k&&d[i][k]+d[k][j]<d[i][j])
						d[i][j]=d[i][k]+d[k][j];
		ans=2147483647;
		for(int i=1;i<=4;i++)
			for(int j=1;j<=4;j++)
				if(d[4*A+i][4*B+j]<ans)
					ans=d[4*A+i][4*B+j];
		printf("%.1f\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

