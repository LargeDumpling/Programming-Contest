/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-03	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXL=1001*100+50;
//char T[MAXL];
int sa[MAXL],height[MAXL],a[MAXL],b[MAXL],c[MAXL],belong[MAXL],lenth,n,T[MAXL];
void build_sa(int m)
{
	int *x=a,*y=b,p;
	memset(c,0,sizeof(c));
	for(int i=0;i<lenth;i++) c[x[i]=T[i]]++;
	for(int i=1;i<m;i++) c[i]+=c[i-1];
	for(int i=lenth-1;i>=0;i--) sa[--c[x[i]]]=i;
	for(int k=1;k<=lenth;k<<=1)
	{
		p=0;
		for(int i=lenth-k;i<lenth;i++) y[p++]=i;
		for(int i=0;i<lenth;i++) if(sa[i]>=k) y[p++]=sa[i]-k;
		memset(c,0,sizeof(c));
		for(int i=0;i<lenth;i++) c[x[y[i]]]++;
		for(int i=1;i<m;i++) c[i]+=c[i-1];
		for(int i=lenth-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		x[sa[0]]=0;
		for(int i=p=1;i<lenth;i++)
			x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]?p-1:p++;
		if(p>=lenth)break;
		m=p;
	}
	return;
}
void build_height()
{
	int rank[MAXL];
	for(int i=0;i<lenth;i++) rank[sa[i]]=i;
	height[rank[0]]=0;
	for(int i=0,k=0,j;i<lenth;i++)
	{
		if(k)k--;
		if(!rank[i])continue;
		j=sa[rank[i]-1];
		while(T[i+k]==T[j+k]) k++;
		height[rank[i]]=k;
	}
	return;
}
void print_sub(int L, int R) {
  for(int i = L; i < R; i++)
    printf("%c", T[i]-1+'a');
  printf("\n");
}
bool flag[110];
bool check(int L, int R) {
  memset(flag, 0, sizeof(flag));
  if(R - L <= n/2) return false;
  int cnt = 0;
  for(int i = L; i < R; i++) {
    int x = belong[sa[i]];
    if(x != n && !flag[x]) { flag[x] = 1; cnt++; }
  }
  return cnt > n/2;
}
bool print(int len, bool prin) {
  int L = 0;
  for(int R = 1; R <= lenth; R++) {
    if(R == lenth || height[R] < len) { // ÐÂ¿ªÒ»¶Î
      if(check(L, R)) {
        if(prin) print_sub(sa[L], sa[L] + len); else return true;
      }
      L = R;
    }
  }
  return false;
}
void solve(int maxlen) {
  if(!print(1, false))
    printf("?\n");
  else {
    int L = 1, R = maxlen, M;
    while(L < R) {
      M = L + (R-L+1)/2;
      if(print(M, false)) L = M;
      else R = M-1;
    }
    print(L, true);
  }
}
void add(int ch, int i) {
  belong[lenth] = i;
  T[lenth++] = ch;
}
char word[1050];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int r,maxl;
	for(int cAse=0;scanf("%d",&n)!=-1&&n;cAse++)
	{
		if(cAse) putchar('\n');
		memset(sa,0,sizeof(sa));
		maxl=lenth=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",word);
			r=strlen(word);
			maxl=max(maxl,r);
			for(int j=0;j<r;j++) add(word[j]-'a'+1,i);
			add(100+i,n);
		}
		if(n==1) puts(word);
		else
		{
			build_sa(100+n);
			build_height();
			solve(maxl);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

