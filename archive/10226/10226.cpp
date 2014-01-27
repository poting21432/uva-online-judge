#include <cstdio>
#include <string>
#include <map>

using namespace std;

char buf[64];
map<string,int> freq;

int main()
{
  int T;
  gets(buf);
  sscanf(buf, "%d", &T);
  gets(buf);

  for ( int t=1; t<=T; ++t ) {
    freq.clear();
    int total_trees = 0;
    while ( gets(buf) ) {
      if ( buf[0]=='\0' )
	break;
      else {
	++freq[buf];
	++total_trees;
      }
    }
    if ( t>1 ) putchar('\n');
    for ( map<string,int>::iterator it=freq.begin(); it!=freq.end(); ++it ) {
      printf("%s %.4f\n", it->first.c_str(), (double)it->second/(double)total_trees*100.0);
    }
  }
}
