/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-07	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ch (int)str[i]
using namespace std;
const int MAXN=100050;
int T_T,n,ansn,ansl,ansr;
int f1[MAXN],f2[MAXN],f3[MAXN][10],pre[MAXN],longa[10];
char str[MAXN];
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%s",&n,str+1);
		for(int i=1;i<=n;i++)
			str[i]-='0';
		ansn=0;
		for(int fl=0;fl<10;fl++)
		{
			for(int c=fl;c<10;c++)
			{
				//step 1
				memset(f1,0,sizeof(f1));
				memset(longa,0,sizeof(longa));
				for(int i=1;i<=n;i++)
				{
					if(c<str[i]) continue;
					for(int j=0;j<=str[i];j++)
						if(f1[i]<f1[longa[j]]+1)
							f1[i]=f1[longa[j]]+1;
					if(f1[longa[ch]]<f1[i])
						longa[ch]=i;
				}
				//step 2
				memset(f3[n+1],0,sizeof(f3[n+1]));
				for(int i=0;i<10;i++)
					longa[i]=n+1;
				for(int i=n;i;i--)
				{
					memcpy(f3[i],f3[i+1],sizeof(f3[i+1]));
					if(str[i]<fl) continue;
					for(int j=str[i];j<10;j++)
						if(f3[i][ch]<f3[longa[j]][j]+1)
							f3[i][ch]=f3[longa[j]][j]+1;
					if(f3[longa[ch]][ch]<f3[i][ch])
						longa[ch]=i;
					for(int j=8;0<=j;j--)
						f3[i][j]=max(f3[i][j],f3[i][j+1]);
				}
				//step 3
				memset(f2,0,sizeof(f2));
				memset(longa,0,sizeof(longa));
				memset(pre,0,sizeof(pre));
				for(int i=1;i<=n;i++)
				{
					f2[i]=f1[i];
					if(str[i]<fl||c<str[i]);
					else
					{
						for(int j=str[i];j<=c;j++)
						{
							if(f2[i]<f2[longa[j]]+1)
							{
								f2[i]=f2[longa[j]]+1;
								pre[i]=pre[longa[j]]?pre[longa[j]]:longa[j];
							}
						}
						if(f2[longa[ch]]<f2[i])
							longa[ch]=i;
					}
					if(ansn<f2[i]+f3[i+1][c])
					{
						ansn=f2[i]+f3[i+1][c];
						ansl=pre[i];
						ansr=i;
					}
				}
			}
		}
		printf("%d %d %d\n",ansn,ansl,ansr);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

