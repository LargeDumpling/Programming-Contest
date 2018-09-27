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
/*
 * 1, M should be a power to two that is bigger than n;
 * 2, Operations are valid only in the interval [1,M-2], otherwise unexcepted errors may happen.
 */
const int M=131072;
int data[M<<1];
void change(int pos,int x)
{
	data[pos=pos+M]+=x;
	for(pos>>=1;pos;pos>>=1)
		data[pos]=data[pos<<1]+data[pos<<1|1];
	return;
}
int query(int L,int R)
{
	int sum=0;
	for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
	{
		if(!(L&1)) sum+=data[L^1];
		if(R&1) sum+=data[R^1];
	}
	return sum;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

