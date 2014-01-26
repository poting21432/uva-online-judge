#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int n; // number of courses
int m; // number of categories

set<int> courses_taken;
vector<int> require[100];
int low[100];

int main()
{
  while ( ~scanf("%d", &n) && n!=0 ) {
    scanf("%d", &m);
    courses_taken.clear();
    for ( int i=0; i<n; ++i ) {
      int x;
      scanf("%d", &x);
      courses_taken.insert(x);
    }
    for ( int i=0; i<m; ++i ) {
      require[i].clear();
      int count;
      scanf("%d %d", &count, &low[i]);
      while ( count-- ) {
	int x;
	scanf("%d", &x);
	require[i].push_back(x);
      }
    }

    bool ok = true;
    for ( int i=0; i<m; ++i ) {
      int count = 0;
      for ( int j=0; j<require[i].size(); ++j ) {
	if ( courses_taken.count(require[i][j]) ) {
	  ++count;
	}
      }
      if ( count < low[i] ) {
	ok = false;
	break;
      }
    }
    puts(ok?"yes":"no");
  }
}
