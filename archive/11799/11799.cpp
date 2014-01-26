#include <cstdio>
#include <climits>

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    int n, max = INT_MIN;
    scanf("%d", &n);
    for ( int i=0; i<n; ++i ) {
      int x;
      scanf("%d", &x);
      if ( x>max ) max = x;
    }
    printf("Case %d: %d\n", t, max);
  }
}
