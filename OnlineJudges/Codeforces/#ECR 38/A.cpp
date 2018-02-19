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
char str[105];
int len;
bool check(char x)
{
	return x=='a'||x=='e'||x=='i'||x=='o'||x=='u'||x=='y';
}
int main()
{
	scanf("%d%s",&len,str);
	for(int i=0;i<len;i++)
	{
		putchar(str[i]);
		if(check(str[i]))
			while(i+1<len&&check(str[i+1])) i++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

