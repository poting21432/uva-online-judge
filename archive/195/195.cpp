#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

#define MAX_LEN 5000

int  N;
char str[MAX_LEN+1];
char pre[MAX_LEN+1];

bool compare(const char &a, const char &b)
{
  char a_lower = tolower(a);
  char b_lower = tolower(b);
  if ( a_lower != b_lower )
    return a_lower < b_lower;
  else
    return a < b;
}

int main()
{
  int T;
  gets(pre);
  sscanf(pre, "%d", &T);
  while ( gets(pre) ) {
    N = strlen(pre);
    char *ptr = str;
    for ( int i=0; i<N; ++i ) {
      if ( isalpha(pre[i]) ) {
	*ptr++ = pre[i];
      }
      else {
	while(1);
      }
    }
    *ptr = '\0';

    N = strlen(str);
    sort(str, str+N, compare);
    //printf("sorted = %s\n", str);
    pre[0] = '\0';
    do {
      if ( strcmp(str, pre)!=0 ) puts(str);
      else                       strcpy(pre, str);
    } while ( next_permutation(str, str+N, compare) );
  }
}
