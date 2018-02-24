#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	if(c<d)
	{
		c+=d;
		d=c-d;
		c-=d;
	}
	printf("%d\n%d\n%d",a+b,c-d,e*f);
	fclose(stdin);
	fclose(stdout);
    return 0;
}

