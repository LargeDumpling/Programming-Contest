/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-07-13	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char A[30],B[30],str[1050];
int idx[30];
int lenth;
int main()
{
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	scanf("%s%s%s",A,B,str);
	lenth=strlen(str);
	for(int i=0;i<26;i++)
		idx[A[i]-'a']=B[i]-'a';
	for(int i=0;i<lenth;i++)
		if('a'<=str[i]&&str[i]<='z')
			putchar(idx[str[i]-'a']+'a');
		else if('A'<=str[i]&&str[i]<='Z')
			putchar(idx[str[i]-'A']+'A');
		else putchar(str[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

