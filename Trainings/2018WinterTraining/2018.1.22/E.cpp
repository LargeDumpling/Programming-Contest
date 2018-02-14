/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
//U R D L
int move[4][2]={{-1,0},{0,1},{0,1},{0,-1}}
char map[550][550];
struct jp
{
	int op,x;
	jp* next;
}*head,*tail;
int main()
{
	freopen("reduce.in","r",stdin);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

