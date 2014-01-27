#include <cstdio>

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    int n, h[50];
    scanf("%d", &n);
    for ( int i=0; i<n; ++i ) scanf("%d", &h[i]);
    int low_count=0, high_count=0;
    for ( int i=1; i<n; ++i ) {
      if      ( h[i-1] < h[i] ) ++high_count;
      else if ( h[i-1] > h[i] ) ++low_count;
    }
    printf("Case %d: %d %d\n", t, high_count, low_count);
  }
}
