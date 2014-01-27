#include <cstdio>
#include <cstring>

const int MAX_N = 3650;
const int MAX_P = 100;

int  N, P;
bool lose[MAX_N+1];

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    scanf("%d %d", &N, &P);
    memset(lose, 0, sizeof(lose));
    int ans = 0;
    for ( int i=0; i<P; ++i ) {
      int hartal;
      scanf("%d", &hartal);
      for ( int j=hartal; j<=N; j+=hartal ) {
	if ( (j+1)%7!=0 && j%7!=0 && !lose[j] ) {
	  //printf("  j = %d, N = %d\n", j, N);
	  ++ans;
	  lose[j] = true;
	}
      }
    }
    printf("%d\n", ans);
  }
}
