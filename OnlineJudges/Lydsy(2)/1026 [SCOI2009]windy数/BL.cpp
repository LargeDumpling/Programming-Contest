#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int A,B,ans=0;
bool check(int x)
{
	int pre=99;
	for(;x;x/=10)
	{
		if(abs((x%10)-pre)<2)
			return false;
		pre=(x%10);
	}
	return true;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	scanf("%d%d",&A,&B);
	for(int i=A;i<=B;i++)
		if(check(i))
			ans++;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

