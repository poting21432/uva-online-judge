#include <cstdio>
#include <climits>

int digit_cost[36]; // 0..35
int base_cost [37]; // 2..36

int getBaseCost(int A, const int base)
{
  int cost = 0;
  while ( A != 0 ) {
    int digit = A % base;
    cost += digit_cost[digit];
    A /= base;
  }
  return cost;
}

int main()
{
  int T, Q, A;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    if ( t>1 ) putchar('\n');
    printf("Case %d:\n", t);
    for ( int d=0; d<36; ++d ) scanf("%d", &digit_cost[d]);
    scanf("%d", &Q);
    for ( int q=0; q<Q; ++q ) {
      scanf("%d", &A);
      printf("Cheapest base(s) for number %d:", A);
      int min_cost = INT_MAX;
      for ( int base=2; base<=36; ++base ) {
	base_cost[base] = getBaseCost(A, base);
	if ( base_cost[base] < min_cost )
	  min_cost = base_cost[base];
      }
      for ( int base=2; base<=36; ++base )
	if ( base_cost[base] == min_cost )
	  printf(" %d", base);
      putchar('\n');
    }
  }
}
