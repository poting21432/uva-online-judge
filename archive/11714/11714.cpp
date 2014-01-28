#include <cstdio>
#include <cmath>

int main()
{
  int n;
  while ( ~scanf("%d", &n) ) {
    int ans = n + (int)ceil(log2(n)) - 2;
    printf("%d\n", ans);
  }
}
