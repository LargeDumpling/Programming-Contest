#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int k,x,y;
int ans[1050][2],an=0;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(true)
	{
		if(scanf("%d",&k)==-1)
			break;
		an=0;
		for(y=k+1;y<=k+k;y++)
		{
			x=k*y/(y-k);
			if(x*(y-k)==k*y)
			{
				an++;
				ans[an][0]=x;
				ans[an][1]=y;
			}
		}
		printf("%d\n",an);
		for(int i=1;i<=an;i++)
			printf("1/%d = 1/%d + 1/%d\n",k,ans[i][0],ans[i][1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

