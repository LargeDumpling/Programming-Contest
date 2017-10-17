#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int h,w,n,m,k,offset[25][25][2],cnt[25];
bool star[25][105][105],sky[1050][1050],flag;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char tex[1050];
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&h,&w);
		cnt[i]=0;
		for(int j=1;j<=h;j++)
		{
			scanf("%s",tex);
			for(int l=1;l<=w;l++)
				if(tex[l]=='#')
				{
					cnt[i]++;
					offset[i][cnt[i]][0]=j;
					offset[i][cnt[i]][1]=l;
				}
		}
		for(int j=cnt[i];j;j--)
		{
			offset[i][j][0]-=offset[i][1][0];
			offset[i][j][1]-=offset[i][1][1];
		}
	}
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",tex);
		for(int j=1;j<=m;j++)
			sky[i][j]=(tex[j]=='#');
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int l=1;l<=m;l++)
			{
				flag=true;
				for(int p=1;p<=cnt[i];p++)
				{
					if(!sky[j+offset[i][p][0]][l+offset[i][p][1]])
					{
						flag=false;
						break;
					}
				}
				if(flag)
				{
					j=n+1;
					l=m+1;
				}
			}
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

