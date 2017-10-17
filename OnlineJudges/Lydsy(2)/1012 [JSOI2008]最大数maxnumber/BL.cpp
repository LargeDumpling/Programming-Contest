#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int num[200050],n,D,m;
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int x,ans=0;
	char ch[2];
	scanf("%d%d",&m,&D);
	for(int i=1;i<=m;i++)
	{
		scanf("%s%d",ch,&x);
		if(ch[0]=='A')
			num[++n]=(x+ans)%D;
		else if(ch[0]=='Q')
		{
			ans=0;
			for(int j=0;j<x;j++)
				ans=max(ans,num[n-j]);
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

