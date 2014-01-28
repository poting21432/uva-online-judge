#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAX_M = 100;
const int MAX_N = 50;

int  m; // number of sequences
int  n; // length of sequences

struct DNA
{
  int  order;
  char s[MAX_N+1];
  int  unsortedness;
  void read()
  {
    scanf("%s", s);
    unsortedness = 0;
    for ( int i=0; i<n; ++i )
      for ( int j=i+1; j<n; ++j )
	if ( s[i] > s[j] )
	  ++unsortedness;
    //printf("sequence(%s).unsortedness = %d\n", s, unsortedness);
  }
} dna[MAX_M];

bool operator< (const DNA &a, const DNA &b)
{
  if ( a.unsortedness != b.unsortedness ) 
    return a.unsortedness < b.unsortedness;
  else
    return a.order < b.order;
}

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    scanf("%d %d", &n, &m);
    //printf("[m=%d, n=%d]\n", m, n);
    for ( int i=0; i<m; ++i ) {
      dna[i].order = i;
      dna[i].read();
    }
    std::sort(dna, dna+m);
    if ( t>1 ) putchar('\n');
    for ( int i=0; i<m; ++i )
      puts(dna[i].s);
  }
}
