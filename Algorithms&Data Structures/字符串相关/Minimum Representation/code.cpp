/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int minP(char s[])
{
	int l=strlen(s);
	int i=0,j=1,k=0;
	while(true)
	{
		if(i+k>=l||j+k>=l) break;
		if(s[i+k]==s[j+k])
		{
			k++;
			continue;
		}
		else
		{
			if(s[j+k]>s[i+k]) j+=k+1;
			else i+=k+1;
			k=0;
			if(i==j) j++;
		}
	}
	return min(i,j);
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

