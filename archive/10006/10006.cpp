#include <cstdio>
#include <cstring>

typedef unsigned long long ull;

const int MAX_P = 65000;

bool is_prime[MAX_P+1];
bool checked [MAX_P+1];
bool answer  [MAX_P+1];

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
}

int bigMod(int a, int b, int c)
{
  if ( b==1 ) {
    return a % c;
  }
  else if ( b%2==0 ) {
    int t = bigMod(a, b/2, c);
    return (ull)t*(ull)t%c;
  }
  else {
    return (ull)a*(ull)bigMod(a,b-1,c)%c;
  }
}

bool fermatTest(int n)
{
  for ( int a=2; a<n; ++a )
    if ( bigMod(a,n,n) != a )
      return false;
  return true;
}

bool isCarmichael(int n)
{
  if ( checked[n] ) {
    return answer[n];
  }
  else {
    answer [n] = !is_prime[n] && fermatTest(n);
    checked[n] = true;
    return answer[n];
  }
}

int main()
{
  int n;
  sieve();
  memset(checked, 0, sizeof(checked));
  while ( ~scanf("%d", &n) && n!=0 ) {
    if ( isCarmichael(n) )
      printf("The number %d is a Carmichael number.\n", n);
    else
      printf("%d is normal.\n", n);
  }
}
