#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

const int MAX_LEN = 2000;
char line[MAX_LEN+1];

struct Freq
{
  char ch;
  int  count;
  Freq(): count(0) {}
};

bool operator< (const Freq &a, const Freq &b)
{
  if ( a.count != b.count ) return a.count < b.count;
  else                      return a.ch > b.ch;
}

int main()
{
  bool first_case = true;
  while ( fgets(line, sizeof(line), stdin) ) {
    if ( first_case )  first_case = false;
    else               putchar('\n');

    Freq freq[128];
    char *ptr;
    for ( ptr=line; *ptr; ++ptr ) {
      int ascii = (int)*ptr;
      freq[ascii].ch = *ptr;
      freq[ascii].count++;
    }
    std::sort(freq, freq+128);
    for ( int i=0; i<128; ++i )
      if ( freq[i].count > 0 && freq[i].ch>=32 )
	printf("%d %d\n", (int)freq[i].ch, freq[i].count);
  }
}
