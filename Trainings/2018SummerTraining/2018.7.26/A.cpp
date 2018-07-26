/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-26	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=40;
int n,c[MAXN][5],C[4];
int f[2][MAXN][MAXN][MAXN][MAXN],St[2][MAXN][MAXN][MAXN][MAXN];
int d[MAXN];
void calc(int t,int l,int r)
{
	if(r<l) return;
	int limit=1<<(r-l+1),num=r-l+1,cnt[5];
	bool flag;
	for(int S=0;S<limit;S++)
	{
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<num;i++) if((S>>i)&1)
			for(int j=0;j<5;j++)
				cnt[j]+=c[l+i][j];
		flag=true;
		for(int i=0;i<4&&flag;i++)
			if(C[i]<cnt[i])
				flag=false;
		if(flag&&f[t][cnt[0]][cnt[1]][cnt[2]][cnt[3]]<cnt[4])
		{
			f[t][cnt[0]][cnt[1]][cnt[2]][cnt[3]]=cnt[4];
			St[t][cnt[0]][cnt[1]][cnt[2]][cnt[3]]=S;
		}
	}
	return;
}
void cOunt(int mid)
{
	int ans=0,ansS[2];
	for(int i=0;i<=C[0];i++)
		for(int j=0;j<=C[1];j++)
			for(int k=0;k<=C[2];k++)
				for(int l=0;l<=C[3];l++)
					for(int p=0;p<2;p++)
					{
						if(i&&f[p][i][j][k][l]<f[p][i-1][j][k][l])
						{
							f[p][i][j][k][l]=f[p][i-1][j][k][l];
							St[p][i][j][k][l]=St[p][i-1][j][k][l];
						}
						if(j&&f[p][i][j][k][l]<f[p][i][j-1][k][l])
						{
							f[p][i][j][k][l]=f[p][i][j-1][k][l];
							St[p][i][j][k][l]=St[p][i][j-1][k][l];
						}
						if(k&&f[p][i][j][k][l]<f[p][i][j][k-1][l])
						{
							f[p][i][j][k][l]=f[p][i][j][k-1][l];
							St[p][i][j][k][l]=St[p][i][j][k-1][l];
						}
						if(l&&f[p][i][j][k][l]<f[p][i][j][k][l-1])
						{
							f[p][i][j][k][l]=f[p][i][j][k][l-1];
							St[p][i][j][k][l]=St[p][i][j][k][l-1];
						}
					}
	for(int i=0;i<=C[0];i++)
		for(int j=0;j<=C[1];j++)
			for(int k=0;k<=C[2];k++)
				for(int l=0;l<=C[3];l++)
					if(ans<f[0][i][j][k][l]+f[1][C[0]-i][C[1]-j][C[2]-k][C[3]-l])
					{
						ans=f[0][i][j][k][l]+f[1][C[0]-i][C[1]-j][C[2]-k][C[3]-l];
						ansS[0]=St[0][i][j][k][l];
						ansS[1]=St[1][C[0]-i][C[1]-j][C[2]-k][C[3]-l];
					}
	//printf("%d\n",ans);
	d[0]=0;
	for(int i=0;i<=mid;i++) if((ansS[0]>>i)&1)
		//printf("%d ",i);
		d[++d[0]]=i;
	int num=n-mid-1;
	for(int i=0;i<num;i++) if((ansS[1]>>i)&1)
		//printf("%d ",mid+1+i);
		d[++d[0]]=mid+1+i;
	/*printf("%d\n",d[0]);
	for(int i=1;i<=d[0];i++)
		printf("%d ",d[i]);
	putchar('\n');*/
	printf("%d",ans);
	return;
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	memset(f,0,sizeof(f));
	int mid;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<5;j++)
			scanf("%d",&c[i][j]);
	for(int i=0;i<4;i++)
		scanf("%d",&C[i]);
	mid=n>>1;
	calc(0,0,mid);
	calc(1,mid+1,n-1);
	cOunt(mid);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

