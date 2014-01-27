#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

char A[1024];
char B[1024];

int A_len;
int B_len;

int A_freq[26];
int B_freq[26];

int main()
{
  while ( gets(A) && gets(B) ) {
    A_len = strlen(A);
    B_len = strlen(B);
    memset(A_freq, 0, sizeof(A_freq));
    memset(B_freq, 0, sizeof(B_freq));
    for ( int i=0; i<A_len; ++i ) if (islower(A[i])) ++A_freq[A[i]-'a'];
    for ( int i=0; i<B_len; ++i ) if (islower(B[i])) ++B_freq[B[i]-'a'];
    for ( int i=0; i<26; ++i ) {
      if ( A_freq[i]>0 && B_freq[i]>0 ) {
	int k = min(A_freq[i], B_freq[i]);
	while ( k-- ) putchar('a'+i);
      }
    }
    putchar('\n');
  }
}
