#include<cstdio>
#include<cstring>
#include<algorithm>

#define MAXN 1000
#define MAXW 10000
#define MAX 10000000
#define INF 1000000000000000000L

typedef long long int lli;

lli weights[MAXN];
lli values[MAXN];
lli n, w;

lli bestset[MAX][2];
int numset;
lli bestsett[MAX][2];
int numsett;
int Z;

void push(lli weight, lli val){
  //printf("Pushing! %lld %lld\n", val, weight);
  bestsett[numsett][0] = weight;
  bestsett[numsett][1] = val;
  numsett++;
}

void consider(lli weight, lli val){
  if (numsett > 0 && bestsett[numsett-1][0] > weight){
    printf("WTF?\n");
    bestsett[23123211][0]  = 0;
  }
  //printf("Considering %lld %lld\n", val, weight);
  if (weight > w)
    return;
  else if (numsett == 0)
    push(weight, val);
  else if (bestsett[numsett-1][0] == weight){
    if (bestsett[numsett-1][1] < val)
      bestsett[numsett-1][1] = val;
  } else if (bestsett[numsett-1][1] < val) {
    push(weight, val);
  }
}

int main(){
  scanf("%lld %lld", &n, &w);
  for(int i = 0; i < n; i++){
    scanf("%lld %lld", &weights[i], &values[i]);
  }
  bestset[0][0] = bestset[0][1] = 0;
  numset = 1;
  for(int i = 0; i < n; i++){
    numsett = 0;
    int k = 0;
    for(int j = 0; j < numset; j++){
      while(k < numset && bestset[k][0] + weights[i] <= bestset[j][0]){
        consider(bestset[k][0] + weights[i], bestset[k][1] + values[i]);
        k++;
      }
      consider(bestset[j][0], bestset[j][1]);
    }
    for(; k < numset; k++)
      consider(bestset[k][0] + weights[i], bestset[k][1] + values[i]);
    memcpy(bestset, bestsett, numsett*sizeof(bestsett[0]));
    numset = numsett;
    //printf("Pareto optimal after %d:\n", i);
    //for(int j = 0; j < numset; j++)
    //  printf("%lld %lld\n", bestset[j][0], bestset[j][1]);
  }
  int j;
  for(j = 0; j < numset && bestset[j][0] <= w; j++);
  printf("%lld\n", bestset[j-1][1]);
}