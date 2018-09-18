/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
const int zero=350;
int map[2][700][700];
char str[350];
int T_T,n,m,h[2][2],w[2][2],cnt,ans,num,a,b,c;
int neib[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int main()
{
	int x,y;
	scanf("%d",&T_T);
	while(T_T--)
	{
		ans=cnt=a=b=0;
		memset(map,0,sizeof(map));
		scanf("%d%d",&n,&m);
		h[0][0]=h[0][1]=w[0][0]=w[0][1]=1000;
		//cerr<<"0:"<<endl;
		for(int i=0;i<n;i++)
		{
			scanf("%s",str);
			for(int j=0;j<m;j++) if(str[j]=='#')
			{
				//cerr<<i<<" "<<j<<endl;
				if(h[0][0]==1000)
				{
					h[0][0]=h[0][1]=zero+i;
					w[0][0]=w[0][1]=zero+j;
				}
				else
				{
					h[0][0]=min(h[0][0],zero+i);
					h[0][1]=max(h[0][1],zero+i);
					w[0][0]=min(w[0][0],zero+j);
					w[0][1]=max(w[0][1],zero+j);
				}
				map[0][zero+i][zero+j]=1;
				b++;
			}
		}
		for(int T=1;T<=321;T++)
		{
			cnt=0;
#define pre map[!(T&1)]
#define now map[T&1]
			//cerr<<T<<":"<<endl;
			h[T&1][0]=h[T&1][1]=w[T&1][0]=w[T&1][1]=1000;
			for(int i=h[!(T&1)][0]-1;i<=h[!(T&1)][1]+1;i++)
			{
				for(int j=w[!(T&1)][0]-1;j<=w[!(T&1)][1]+1;j++)
				{
					num=0;
					for(int k=0;k<8;k++)
					{
						x=i+neib[k][0];
						y=j+neib[k][1];
						if(pre[x][y]==T)
							num++;
					}
					if(pre[i][j]==T)
					{
						if(num<2||3<num) now[i][j]=T;
						else
						{
							now[i][j]=T+1;
							if(h[T&1][0]==1000)
							{
								h[T&1][0]=h[T&1][1]=i;
								w[T&1][0]=w[T&1][1]=j;
							}
							else
							{
								h[T&1][0]=min(h[T&1][0],i);
								h[T&1][1]=max(h[T&1][1],i);
								w[T&1][0]=min(w[T&1][0],j);
								w[T&1][1]=max(w[T&1][1],j);
							}
							cnt++;
							//cerr<<i-zero<<" "<<j-zero<<endl;
						}
					}
					else if(num==3)
					{
						now[i][j]=T+1;
						if(h[T&1][0]==1000)
						{
							h[T&1][0]=h[T&1][1]=i;
							w[T&1][0]=w[T&1][1]=j;
						}
						else
						{
							h[T&1][0]=min(h[T&1][0],i);
							h[T&1][1]=max(h[T&1][1],i);
							w[T&1][0]=min(w[T&1][0],j);
							w[T&1][1]=max(w[T&1][1],j);
						}
						cnt++;
						//cerr<<i-zero<<" "<<j-zero<<endl;
					}
				}
			}
#undef pre
#undef now
			if(b<cnt)
			{
				a=T;
				b=cnt;
			}
			if(!cnt)
				break;
		}
		printf("%d %d %d\n",a,b,cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

