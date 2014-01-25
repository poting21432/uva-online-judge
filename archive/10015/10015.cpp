#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_N = 3501;
const int MAX_P = 32768;

bool is_prime[MAX_P+1];
vector<int> primes;

int n;
int m; // how many people are there now
int nxt[MAX_N+1];

void sieve()
{
  memset(is_prime, 1, sizeof(is_prime));
  is_prime[0] = false;
  is_prime[1] = false;
  is_prime[2] = true;
  for ( int i=4; i<=MAX_P; i+=2 )  is_prime[i] = false;
  for ( int i=3; i*i<=MAX_P; i+=2 )
    if ( is_prime[i] )
      for ( int j=i*i; j<=MAX_P; j+=i )
	is_prime[j] = false;

  primes.push_back(2);
  for ( int i=3; i<=MAX_P; i+=2 )
    if ( is_prime[i] )
      primes.push_back(i);
}

void init()
{
  for ( int i=1; i<=n-1; ++i ) nxt[i] = i+1;
  nxt[n] = 1;
  m = n;
}

int kill(int start, int offset)
{
  int pos = start;
  int count = offset % m;
  if ( count==0 ) count = m;
  for ( int i=0; i<count-1; ++i ) {
    pos = nxt[pos];
  }
  nxt[pos] = nxt[nxt[pos]];
  return pos;
}

int solve()
{
  init();
  int current = n;
  for ( int i=0; i<n-1; ++i ) {
    current = kill(current, primes[i]);
    --m;
  }
  return nxt[current];
}

void test()
{
  for ( n=1; n<=3501; ++n ) {
    printf("f(%d) = %d\n", n, solve());
  }
}

int main()
{
  sieve();
  while ( ~scanf("%d", &n) && n!=0 ) {
    printf("%d\n", solve());
  }

}
