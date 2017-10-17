#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
char tex[4001][1005];
unsigned long long ans;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("BL.out","w",stdout);
	for(int k=1;;k++)
	{
		scanf("%d",&n);
		if(!n)
			break;
		for(int i=1;i<=n;i++)
			scanf("%s",tex[i]);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=0;tex[i][l]==tex[j][l];l++)
				{
					ans+=2;
					if(tex[i][l]=='\0'||tex[j][l]=='\0')
						break;
				}
		ans+=((unsigned long long)n*(n-1))/2;
		printf("Case %d: %I64d\n",k,ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

