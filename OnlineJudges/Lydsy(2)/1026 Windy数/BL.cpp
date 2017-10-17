#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
bool check(int x)
{
	int num[15];
	for(num[0]=0;x;x/=10)num[++num[0]]=x%10;
	for(int i=2;i<=num[0];i++)
		if(abs(num[i]-num[i-1])<2)
			return false;
	return true;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int a,b,ans=0;
	scanf("%d%d",&a,&b);
	for(int i=a;i<=b;i++)
		if(check(i))
			ans++;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

