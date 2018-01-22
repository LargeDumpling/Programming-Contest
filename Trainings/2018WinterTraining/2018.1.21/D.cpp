/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	stack<bool> s;
	scanf("%d",&n);
	while(n)
	{
		if(n&1)
		{
			s.push(true);
			n=(n-1)>>1;
		}
		else
		{
			s.push(false);
			n=(n-2)>>1;
		}
	}
	for(;!s.empty();s.pop())
		putchar(s.top()?'A':'B');
	fclose(stdin);
	fclose(stdout);
	return 0;
}

