#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n,m;
int his[100050],lAst[100050],laSt=-2000000;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	bool exist;
	scanf("%d",&T);
	while(T--)
	{
		memset(lAst,0,sizeof(lAst));
		exist=true;
		laSt=-200000;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)scanf("%d",&his[i]);
		for(int i=1;i<=m&&exist;i++)
		{
			if(lAst[his[i]]&&i-lAst[his[i]]<n)
			{
				if(i-laSt<n)
					exist=false;
				else
					laSt=i;
			}
			else if(!lAst[his[i]]||i-lAst[his[i]]>=n)
				lAst[his[i]]=i;
		}
		if(!exist)
			printf("0\n");
		else
			printf("%d\n",m+1-laSt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

