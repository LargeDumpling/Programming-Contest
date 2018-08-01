/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-31	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int T_T;
	char ch;
	bool neg;
	unsigned long long x;
	scanf("%d",&T_T);
	while(T_T--)
	{
		neg=false;
		for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
			if(ch=='-')
				neg=true;
		for(x=0;'0'<=ch&&ch<='9';ch=getchar())
			x=(x<<1)+(x<<3)+ch-'0';
		if(!neg&&x) putchar('-');
		cout<<x<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

