#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int num[15];
bool check(int x)
{
	for(num[0]=0;x;x/=10)num[++num[0]]=x%10;
	if(num[1]==4)
		return false;
	for(int i=2;i<=num[0];i++)
		if(num[i]==4||(num[i-1]==2&&num[i]==6))
			return false;
	return true;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int a,b,ans;
	while(true)
	{
		scanf("%d%d",&a,&b);
		if(!a&&!b)
			break;
		ans=0;
		for(int i=a;i<=b;i++)
			if(check(i))
				ans++;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

