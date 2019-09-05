/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-09-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200050;
int n,cnt;
char str[MAXN];
int main()
{
	scanf("%d",&n);
	if(n%2) puts("NO");
	else
	{
		cnt=0;
		scanf("%s",str);
		for(int i=0;i<n;i++)
		{
			if(str[i]==')')
				cnt+=1;
			else if(str[i]=='(')
				cnt-=1;
			if(cnt>1)
				break;
		}
		if(cnt) puts("NO");
		else puts("YES");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

