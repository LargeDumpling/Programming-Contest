#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

double x[15],y[15],z[15],r[15];
double X1,Y1,Z1,X2,Y2,Z2,maxV;
int n,sel[15];
bool vis[15];
const double pi=acos(-1.0);


double getside(int i)
{
    double dis1,dis2,dis3;
    dis1=min(fabs(x[i]-X1),fabs(x[i]-X2));
    dis2=min(fabs(y[i]-Y1),fabs(y[i]-Y2));
    dis3=min(fabs(z[i]-Z1),fabs(z[i]-Z2));
    return min(dis1,min(dis2,dis3));
}

double distances(int a,int b)
{
    return sqrt((x[a]-x[b])*(x[a]-x[b])+
                (y[a]-y[b])*(y[a]-y[b])+
                (z[a]-z[b])*(z[a]-z[b]));
}

void getV()
{
    double a,v=0;
    for(int i=0;i<n;i++)
    {
        a=getside(sel[i]);
        for(int j=0;j<i;j++)
            a=min(a,distances(sel[i],sel[j])-r[sel[j]]);
        r[sel[i]]=(a<0)?0:a;
        if(a<=0) continue;
        v+=(4.0/3*pi*r[sel[i]]*r[sel[i]]*r[sel[i]]);
    }
    maxV=max(maxV,v);
}

void dfs(int cnt)
{
    if(cnt==n)
        getV();
    else
    {
        for(int i=0;i<n;i++)
        {
            if(vis[i]) continue;
            sel[cnt]=i;
            vis[i]=1;
            dfs(cnt+1);
            vis[i]=0;
        }
    }
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("other.out","w",stdout);
    int te=1;
    while(~scanf("%d",&n)&&n)
    {
        scanf("%lf%lf%lf",&X1,&Y1,&Z1);
        scanf("%lf%lf%lf",&X2,&Y2,&Z2);
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf",&x[i],&y[i],&z[i]);
        maxV=0;
        memset(vis,0,sizeof(vis));
        dfs(0);
        printf("Box %d: %.0lf\n\n",te++,((fabs((X1-X2)*(Y1-Y2)*(Z1-Z2)))-maxV));

    }
    return 0;
}

