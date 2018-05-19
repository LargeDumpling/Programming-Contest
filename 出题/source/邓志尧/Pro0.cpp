#include<bits/stdc++.h>
#define mod 1000000007
#define MAXN 262144

const double pi = 3.14159265358979323846264338327950288419716939937510582;

using namespace std;

struct cp
{
  double x , y;
  cp( double x , double y ) : x( x ) , y( y ) {}
  cp() {}
} o[ MAXN ] , A1[ MAXN ] , A2[ MAXN ] , A3[ MAXN ] , B1[ MAXN ] , B2[ MAXN ] , B3[ MAXN ] , C[ MAXN ];

inline cp operator + ( const cp & a , const cp & b )
{
  return cp( a.x + b.x , a.y + b.y );
}

inline cp operator - ( const cp & a , const cp & b )
{
  return cp( a.x - b.x , a.y - b.y );
}

inline cp operator * ( const cp & a , const cp & b )
{
  return cp( a.x * b.x - a.y * b.y , a.x * b.y + a.y * b.x );
}

int n , m , t , rev[ MAXN ] , ans[ MAXN ] , x[ MAXN ] , y[ MAXN ];
char a[ MAXN ] , b[ MAXN ];
queue < int > q;

inline void fft( cp * a )
{
  for( register int i = 0 ; i < t ; i++ )
    if( rev[i] > i )
      swap( a[i] , a[ rev[i] ] );
  for( int i = 2 , mid = 1 , s = t / i ; i <= t ; mid = i , i <<= 1 , s >>= 1 )
    for( int j = 0 ; j < t ; j += i )
      for( register int k = j , now = 0 ; k < j + mid ; k++ , now += s )
      {
        cp x = a[ k + mid ] * o[ now ];
        a[ k + mid ] = a[k] - x , a[k] = a[k] + x;
      }
}

int main()
{
  scanf( "%s" , a ) , scanf( "%s" , b );
  n = strlen( a ) , m = strlen( b );
  for( t = 1 ; t <= n + m ; t <<= 1 );
  for( register int i = 0 ; i < n ; i++ ) x[i] = a[i] - 'a' + 1;
  for( register int i = 0 ; i < m ; i++ ) y[i] = b[m - i - 1] - 'a' + 1;
  for( register int i = 0 ; i < n ; i++ )
    if( x[i] < 0 ) x[i] = 0;
  for( register int i = 0 ; i < m ; i++ )
    if( y[i] < 0 ) y[i] = 0;
  for( register int i = 1 ; i < t ; i++ )
  {
    rev[i] = rev[i >> 1] >> 1;
    if( i & 1 ) rev[i] ^= t >> 1;
  }
  for( register int i = 0 ; i < n ; i++ )
    A1[i].x = x[i] , A2[i].x = x[i] * x[i] , A3[i].x = x[i] * x[i] * x[i];
  for( register int i = 0 ; i < m ; i++ )
    B1[i].x = y[i] , B2[i].x = y[i] * y[i] , B3[i].x = y[i] * y[i] * y[i];
  o[0] = cp( 1 , 0 ) , o[1] = cp( cos( 2 * pi / t ) , sin( 2 * pi / t ) );
  for( register int i = 2 ; i < t ; i++ ) o[i] = o[i - 1] * o[1];
  fft( A1 ) , fft( A2 ) , fft( A3 ) , fft( B1 ) , fft( B2 ) , fft( B3 );
  for( register int i = 0 ; i < t ; i++ )
    C[i] = C[i] + A3[i] * B1[i] + A1[i] * B3[i] - A2[i] * B2[i] - A2[i] * B2[i];
  for( register int i = 0 ; i < t ; i++ ) o[i].y = -o[i].y;
  fft( C );
  for( register int i = 0 ; i < t ; i++ ) ans[i] = ( C[i].x / t ) + 0.5;
  for( register int i = m - 1 ; i < n ; i++ )
    if( !ans[i] ) q.push( i );
  cout << q.size() << endl;
  while( !q.empty() ) printf( "%d\n" , q.front() - m + 2 ) , q.pop();
}
