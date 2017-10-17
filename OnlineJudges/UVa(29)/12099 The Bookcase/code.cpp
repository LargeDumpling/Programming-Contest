/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int INF=0x7f7f7f7f;
struct jp
{
	int h,w;
	bool operator<(const jp &X)const { return h>X.h; }
}book[75];
int T_T,n,f[2150][2150];
int p(int pw,int h) { return pw?0:h; }
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int allw,ans;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d",&n);
		ans=INF;
		allw=0;
		for(int i=1;i<=n;i++)
			scanf("%d%d",&book[i].h,&book[i].w);
		sort(book+1,book+n+1);
		memset(f,127,sizeof(f));
		f[0][0]=0;
		for(int i=1;i<=n;i++)
		{
			allw+=book[i].w;
			for(int j=allw;j>=0;j--)
			{
				for(int k=allw;k>=0;k--)
				{
					if(allw<j+k) continue;
					if(allw-j-k+30<j) continue;
					if(j+30<k) continue;
					if(k+book[i].w<=allw) //放在第叁层
						f[j][k+book[i].w]=min(f[j][k+book[i].w]
								,f[j][k]+p(k,book[i].h));
					if(j+book[i].w<=allw) //放在第贰层
						f[j+book[i].w][k]=min(f[j+book[i].w][k]
								,f[j][k]+p(j,book[i].h));
				}
			}
		}
		for(int i=1;i<=allw;i++)
			for(int j=1;j<=allw;j++)
				if(f[i][j]!=INF&&i+j<=allw&&i<=allw-i-j+30&&j<=i+30)
					if(max(max(i,j),allw-i-j)*(f[i][j]+book[1].h)<ans)
						ans=min(ans,max(max(i,j),allw-i-j)*(f[i][j]+book[1].h));
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

