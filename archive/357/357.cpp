#include <cstdio>

typedef unsigned long long ull;

const int MAX_MONEY = 50000;

const int N = 5; // number of coins
const int coins[N] = {1, 5, 10, 25, 50};

ull f[MAX_MONEY+1];

void prepare()
{
  f[0] = 1;
  for ( int i=0; i<N; ++i )
    for ( int j=coins[i]; j<=MAX_MONEY; ++j )
      f[j] += f[j-coins[i]];
}

void test()
{
  int n;
  while ( ~scanf("%d", &n) ) {
    if ( f[n]==1 )
      printf("There is only 1 way to produce %d cents change.\n", n);
    else
      printf("There are %llu ways to produce %d cents change.\n", f[n], n);
  }
}

int main()
{
  prepare();
  test();
}
