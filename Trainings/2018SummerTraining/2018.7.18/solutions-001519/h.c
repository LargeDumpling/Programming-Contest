#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 24
#define NN (1 << MAXN)
#define INF 1000

int c[MAXN];   // size of the pieces
int bins[NN];  // number of bins used by this subset
int used[NN];  // the space used in the least used bin
int n, nn;
int bound;

int main () {
    int i, s, s1, m, d, e, j, nb, nu;
    scanf(" %d %d ", &n, &bound);
    for (i=0; i<n; i++) {
	scanf(" %d ", &c[i]);
    };
    
    nn = 1 << n;
    
    for (i=0; i<nn; i++) {
	bins[i] = INF;
	used[i] = 0;
    }
    
    bins[0] = 0;
    used[0] = bound;
    
    for (s=1; s<nn; s++) {
	for (j=0; j<n; j++) {
	    e = 1 << j;
	    if ((s & e) != 0) {
		s1 = s-e;
		if (used[s1] + c[j] <= bound) {
		    nb = bins[s1];
		    nu = used[s1] + c[j];
		} else {
		    nb = bins[s1] + 1;
		    nu = c[j];
		}
		if (nb < bins[s] || (nb == bins[s] && nu < used[s])) {
		    bins[s] = nb;
		    used[s] = nu;
		}
	    }
	}
    }
    
    printf("%d\n", bins[nn-1]);
}
