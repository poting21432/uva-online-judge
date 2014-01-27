#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAX_N = 100;
const int MAX_VALUE = 50000;

int main()
{
  int  N;
  int  sum;
  int  A[MAX_N];
  bool f[MAX_VALUE+1];
  int  max_hit;
  int  T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    scanf("%d", &N);
    sum = 0;
    for ( int i=0; i<N; ++i ) {
      scanf("%d", &A[i]);
      sum += A[i];
    }
    max_hit = sum/2;

    f[0] = true;
    for ( int j=1; j<=max_hit; ++j ) f[j] = false;
    for ( int i=0; i<N; ++i )
      for ( int j=max_hit; j>=A[i]; --j )
	f[j] |= f[j-A[i]];

    int hit;
    for ( int j=max_hit; j>=0; --j )
      if ( f[j] )
	{ hit=j; break; }

    int half_a = hit;
    int half_b = sum - hit;
    printf("%d\n", abs(half_a-half_b));
  }
}
