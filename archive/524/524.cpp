#include <cstdio>
#include <cstring>

const int MAX_P = 32;

bool is_prime[MAX_P+1];

int  n;
int  ring[16];
bool used[16+1];

void sieve()
{
  memset(is_prime, 1, sizeof(is_prime));
  is_prime[0] = false;
  is_prime[1] = false;
  for ( int i=4; i<=MAX_P; i+=2 ) is_prime[i] = false;
  for ( int i=3; i*i<=MAX_P; i+=2 )
    if ( is_prime[i] )
      for ( int j=i*i; j<=MAX_P; j+=i )
	is_prime[j] = false;

  //for ( int i=0; i<=MAX_P; ++i ) printf("is_prime[%d] = %d\n", i, is_prime[i]);
}

void search(int i)
{
  //printf("search(i=%d)\n", i);
  if ( i==n && is_prime[ring[0]+ring[n-1]] ) {
    printf("%d", ring[0]);
    for ( int i=1; i<n; ++i ) printf(" %d", ring[i]);
    putchar('\n');
  }
  else {
    for ( int j=1; j<=n; ++j ) {
      if ( !used[j] && is_prime[ring[i-1]+j] ) {
	ring[i] = j;
	used[j] = true;
	search(i+1);
	used[j] = false;
      }
    }
  }
}

int main()
{
  sieve();
  int t = 0;
  while ( ~scanf("%d", &n) ) {
    if ( t>0 ) putchar('\n');
    printf("Case %d:\n", ++t);
    memset(used, 0, sizeof(used));
    ring[0] = 1;
    used[1] = true;
    search(1);
  }
}
