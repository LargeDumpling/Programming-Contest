#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp
{
	int l[2],h[2],an[2],id;
}kni[5050];
int n;
bool cnm_0(jp A,jp B)
{
	return A.l[0]==B.l[0]?A.h[0]<B.h[0]:A.l[0]<B.l[0];
}
bool cnm_1(jp A,jp B)
{
	return A.l[1]==B.l[1]?A.h[1]<B.h[1]:A.l[1]<B.l[1];
}
bool cnm_id(jp A,jp B)
{
	return A.id<B.id;
}
bool exist[5050];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(true)
	{
		scanf("%d",&n);
		if(!n)
			break;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d%d",&kni[i].l[0],&kni[i].l[1],&kni[i].h[0],&kni[i].h[1]);
			kni[i].id=i;
		}
		bool sEt,aNs=true;
		memset(exist,false,sizeof(exist));
		sort(kni+1,kni+n+1,cnm_0);
		for(int i=1;i<=n&&aNs;i++)
		{
			sEt=false;
			for(int j=kni[i].l[0];j<=kni[i].h[0];j++)
			{
				if(exist[j])continue;
				kni[i].an[0]=j;
				exist[j]=true;
				sEt=true;
				break;
			}
			if(!sEt)
			{
				printf("IMPOSSIBLE\n");
				aNs=false;
				break;
			}
		}
		if(!aNs)
			continue;
		memset(exist,false,sizeof(exist));
		sort(kni+1,kni+n+1,cnm_1);
		for(int i=1;i<=n;i++)
		{
			sEt=false;
			for(int j=kni[i].l[1];j<=kni[i].h[1];j++)
			{
				if(exist[j])continue;
				kni[i].an[1]=j;
				exist[j]=true;
				sEt=true;
				break;
			}
			if(!sEt)
			{
				printf("IMPOSSIBLE\n");
				aNs=false;
				break;
			}
		}
		if(!aNs)
			continue;
		sort(kni+1,kni+n+1,cnm_id);
		for(int i=1;i<=n;i++)
			printf("%d %d\n",kni[i].an[0],kni[i].an[1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

