#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
/*
��������������ɣ���һ�����ĸ�������n��1��n��50����m��1��m��n*n����s��1��s��n����e��1��e��n����
n��ʾ��������m��ʾ��·����s��e��ʾ������͵���㡣
�� 2��m+1����m ���ߵ� ��Ϣ��ÿ������������Ϊ�ߵ������յ㡣 
*/
int fir[55],next[255],end[255],dis[55],root=0,ed=0,n,m,s,t;
bool exist[55];
void addedge(int u,int v)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	return;
}
int merge(int A,int B)
{
	if(A==0)
		return B;
	if(B==0)
		return A;
	if(dis[B]<dis[A])
	{
		A+=B;
		B=A-B;
		A=A-B;
	}
	r[A]=merge(r[A],B);
	l[A]+=r[A];
	r[A]=l[A]-r[A];
	l[A]=l[A]-r[A];
	return A;
}
/*
void Dijkstra()
{
    memset(d,0x3f,sizeof d);
    memset(flag,0,sizeof flag);
    d[1]=0;
    ll MN;
    int u;
    for(int T=n;T--;){
        MN=INF;
        for(int i=1;i<=n;i++) if(!flag[i] && d[i]<MN) {
            MN=d[i]; u=i;
        }
        flag[u]=1;
        for(int i=1;i<=n;i++){
            d[i]=min(d[i],d[u]+g[u][i]);
        }
    }
}
*/
void Dijkstra()
{
	int u,v;
	dis[0]=2147483647;
	dis[s]=1;
	root=merge(root,s);
	for(int i=fir[s];i;i=next[i])
	{
		dis[end[i]]=2;
		root=merge(root,end[i]);
	}
	exist[s]=true;
	for(int cnt=1;cnt<n;cnt++)
	{
		u=root;
		root=merge(l[root],r[root]);
		exist[u]=true;//������� 
		for(int i=fir[u];i;i=next[i])
		{//������ 
			if(exist[end[i]]||dis[end[i]]<dis[u]+1)
				continue;
			dis[end[i]]=dis[u]+1;
			root=merge(root,end[i]);
		}
	}
}
int main()
{
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	int a,b;
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		addedge(a,b);
	}
	Dijkstra();
	printf("%d",dis[t]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

