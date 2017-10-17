#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
bool dot[100050],flag=true;
int main()
{
	freopen("code.out","r",stdin);
	int a,b;
	memset(dot,false,sizeof(dot));
	while(true)
	{
		if(scanf("%d%d",&a,&b)==-1)
			break;
		dot[a]^=true;
		dot[b]^=true;
	}
	for(int i=0;i<100050;i++)
		if(dot[i])
		{
			flag=false;
			break;
		}
	fclose(stdin);
	if(!flag)
		return 1;
	return 0;
}

