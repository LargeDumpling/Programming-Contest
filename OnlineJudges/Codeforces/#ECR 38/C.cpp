/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T;
long long X;
int main()
{
	long long x,y,n,m;
	scanf("%d",&T_T);
	while(T_T--)
	{
		cin>>X;
		n=m=-1;
		for(x=1;x*x<X;x++) if(X%x==0)
		{
			y=X/x;
			if(((y-x)&1)==0)
			{
				m=(y-x)/2;
				n=(y+x)/2;
				m=n/m;
				if(X==n*n-(n/m)*(n/m)) break;
				else n=m=-1;
			}
		}
		if(X==0) n=m=1;
		if(n==-1) puts("-1");
		else //printf("%d %d\n",n,m);
		cout<<n<<" "<<m<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

