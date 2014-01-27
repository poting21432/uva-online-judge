#include <cstdio>
#include <cstring>

int answer[15] = {0, 2, 7, 5, 30, 169,
		  441, 1872, 7632, 1740, 93313,
		  459901, 1358657, 2504881};

int  n;
int  cur; // current
int  nxt[30]; // next
int  pre[30]; // previous
bool killed[30];

void init()
{
  for ( int i=1; i<n-1; ++i ) {
    nxt[i] = i+1;
    pre[i] = i-1;
  }
  nxt[0] = 1;
  pre[0] = n-1;
  nxt[n-1] = 0;
  pre[n-1] = n-2;

  memset(killed, 0, sizeof(killed));
  cur = n-1;
}

bool ok(int m)
{
  init();
  for ( int i=0; i<n/2; ++i ) {
    int current_alive = n - i;
    int move = m % current_alive;
    if ( move==0 ) move = current_alive;
    for ( int j=0; j<move; ++j ) cur = nxt[cur];
    if ( cur < n/2 ) return false;
    nxt[pre[cur]] = nxt[cur];
    pre[nxt[cur]] = pre[cur];
  }
  return true;
}

int solve(int k)
{
  if ( answer[k]!=0 )
    return answer[k];
  else {
    n = 2*k;
    for ( int m=1; ; ++m )
      if ( ok(m) )
	return answer[k] = m;
  }
}

int main()
{
  int k;
  //memset(answer, 0, sizeof(answer));
  while ( ~scanf("%d", &k) && k!=0 ) {
    printf("%d\n", solve(k));
  }
}
