#include <cstdio>
#include <algorithm>

using namespace std;

int n; // number of requirements
int m; // number of proposals

char buf[128];

struct Proposal
{
  char name[81];
  int  count;
  double price;
} p[1000];

bool operator< (const Proposal &a, const Proposal &b)
{
  if ( a.count != b.count )
    return a.count > b.count;
  else
    return a.price < b.price;
}

int main()
{
  int t = 0;
  while ( true ) {
    gets(buf);
    sscanf(buf, "%d %d", &n, &m);
    if ( n==0 && m==0 ) break;
    else {
      char requirement[81];
      for ( int i=0; i<n; ++i ) {
	gets(requirement);
      }

      for ( int i=0; i<m; ++i ) {
	gets(p[i].name);
	gets(buf);
	sscanf(buf, "%lf %d", &p[i].price, &p[i].count);
	for ( int j=0; j<p[i].count; ++j )
	  gets(requirement);
      }

      sort(p, p+m);

      ++t;
      if ( t>1 ) putchar('\n');
      printf("RFP #%d\n%s\n", t, p[0].name);
    }
  }
}
