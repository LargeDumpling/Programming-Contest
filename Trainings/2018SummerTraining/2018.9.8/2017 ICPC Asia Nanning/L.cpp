/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-18	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long s[250];
int main()
{
	for(int i=1,t;i<=200;i++)
	{
		s[i]=(long long)i*(i+1LL);
		t=lower_bound(s+1,s+i+1,(s[i]>>1))-s;
		while((s[t]*2LL)<=s[i])
		{
			if(s[t]*2==s[i])
				printf("%d\n",i);
			t++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

