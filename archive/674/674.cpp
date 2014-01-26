#include <cstdio>

typedef unsigned long long ull;

int main()
{
  const int MAX_N = 10000;

  int coins[5] = {1, 5, 10, 25, 50};
  ull f[MAX_N+1];

  f[0] = 1;
  for ( int i=0; i<5; ++i )
    for ( int j=coins[i]; j<=MAX_N; ++j )
      f[j] += f[j-coins[i]];

  int c;
  while ( ~scanf("%d", &c) ) {
    printf("%llu\n", f[c]);
  }
}
