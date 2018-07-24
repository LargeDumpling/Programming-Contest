## Problem

Lawson is a magic swordman with $k$ kinds of magic attributes $v_1, v_2, v_3, \dots, v_k$. Now Lawson is faced with $n$ monsters and the $i$-th monster also has $k$ kinds of defensive attributes $a_{i,1}, a_{i,2}, a_{i,3}, \dots, a_{i, k}$. If $v_1\geq a_{i,1}$ and $v_2\geq a_{i,2}$ and $v_3\geq a_{i,3}$ and $\dots$ and $v_k\geq a_{i, k}$, Lawson can kill the $i$-th monster (each monster can be killed for at most one time) and get EXP from the battle, which means $v_j$ will increase $b_{i,j}$ for $j = 1, 2, 3, \dots, k$.
Now we want to know how many monsters Lawson can kill at most and how much Lawson's magic attributes can be maximized.

## Input

There are multiple test cases. The first line of input contains an integer $T$, indicating the number of test cases. For each test case:
The first line has two integers $n$ and $k$ ($1\leq n \leq 10^5, 1\leq k \leq 5$).
The second line has $k$ non-negative integers (initial magic attributes) $v_1, v_2, v_3, \dots, v_k$.
For the next $n$ lines, the $i$-th line contains $2k$ non-negative integers $a_{i,1}, a_{i,2}, a_{i,3}, \dots, a_{i, k}, b_{i,1}, b_{i,2}, b_{i,3}, \dots, b_{i, k}$.
It's guaranteed that all input integers are no more than $10^9$ and $v_j + \sum_{i=1}^n b_{i,j} \leq 10^9$ for $j = 1, 2, 3, \dots, k$.

It is guaranteed that the sum of all n $\leq 5 \times 10 ^ 5$.
The input data is very large so that fast IO (like `fread`) is recommended.

## Output

For each test case:
The first line has one integer which means maximum number of monsters that can be killed by Lawson.
The second line has $k$ integers $v_1', v_2', v_3', \dots, v_k'$ and the $i$-th integer means maximum of the $i$-th magic attibute.

## Sample Input

1
4 3
7 1 1
5 5 2 6 3 1
24 1 1 1 2 1
0 4 1 5 1 1
6 0 1 5 3 1

## Sample Output

3
23 8 4

## Note

For the sample, initial $V = [7, 1, 1]$
① kill monster #4 $(6, 0, 1)$, $V + [5, 3, 1] = [12, 4, 2]$
② kill monster #3 $(0, 4, 1)$, $V + [5, 1, 1] = [17, 5, 3]$
③ kill monster #1 $(5, 5, 2)$, $V + [6, 3, 1] = [23, 8, 4]$
After three battles, Lawson are still not able to kill monster #2 $(24, 1, 1)$ because $23 < 24$.
