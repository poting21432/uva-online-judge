#include <cstdio>
#include <set>
#include <string>
#include <map>

using namespace std;

char buf[128];
map<string, set<string> > beauties;

int main()
{
  int n;
  gets(buf);
  sscanf(buf, "%d", &n);
  for ( int i=0; i<n; ++i ) {
    gets(buf);
    char *ptr = buf;
    while ( *ptr++ != ' ' );
    ptr[-1] = '\0';
    char *country = buf;
    char *beauty  = ptr;
    //printf("country=%s, beauty=%s\n", country, beauty);
    beauties[country].insert(beauty);
  }
  for ( map<string, set<string> >::iterator it=beauties.begin();
	it != beauties.end(); ++it ) {
    printf("%s %zd\n", it->first.c_str(), it->second.size());
  }
}
