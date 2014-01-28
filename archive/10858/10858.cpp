#include <cstdio>
#include <vector>
#include <deque>
#include <cstring>

using namespace std;

const int MAX_P = 2000000;

bool is_prime[MAX_P+1];

deque<int> fac;
vector< deque<int> > output;

void sieve()
{
  memset(is_prime, 1, sizeof(is_prime));
  is_prime[0] = false;
  is_prime[1] = false;
  for ( int i=4; i<=MAX_P; i+=2 )
    is_prime[i] = false;
  for ( int i=3; i*i<=MAX_P; i+=2 )
    if ( is_prime[i] )
      for ( int j=i*i; j<=MAX_P; j+=i )
	is_prime[j] = false;
}

void printFac( const deque<int> D )
{
  printf("%d", D[0]);
  for ( int i=1; i<D.size(); ++i )
    printf(" %d", D[i]);
  putchar('\n');
}

void factorize(int N, int start)
{
  //printf("factorize(%d)\n", N);

  if ( N==1 ) {
    if ( fac.size() >= 2 )
      output.push_back( fac );
  }
  else {
    for ( int x=start; x<=N; ++x ) {
      if ( N % x==0 ) {
	fac.push_back(x);
	factorize(N/x, x);
	fac.pop_back();
      }
    }
  }
}

int main()
{
  sieve();
  int N;
  while ( ~scanf("%d", &N) && N!=0 ) {
    if ( N==1 ) puts("0");
    else {
      output.clear();
      factorize(N, 2);
      printf("%zd\n", output.size());
      for ( int i=0; i<output.size(); ++i )
	printFac( output[i] );
    }
  }
}
