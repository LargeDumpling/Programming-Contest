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
int main(int argc,char *argv[])
{
	int x; sscanf(argv[1],"%d",&x); srand(x);
	freopen("C.in","w",stdout);
	stack<int> st;
	int n=rand()+1,k=rand()%4+1;
	for(;n;n>>=1)
		st.push(n&1);
	for(;!st.empty();st.pop())
		printf("%d",st.top());
	putchar('\n');
	printf("%d",k);
	fclose(stdout);
	return 0;
}

