#include <iostream>
#include <cstdio>

using namespace std;

typedef unsigned long long ull;

const int _10_7 = 10000000;
const int _10_5 = 100000;
const int _10_3 = 1000;
const int _10_2 = 100;

void display(ull n)
{
  if ( n < _10_7 ) {
    int lakh   = n / _10_5; if ( lakh  >0 ) printf(" %d lakh",   lakh);  n %= _10_5;
    int hajar  = n / _10_3; if ( hajar >0 ) printf(" %d hajar",  hajar); n %= _10_3;
    int shata  = n / _10_2; if ( shata >0 ) printf(" %d shata",  shata); n %= _10_2;
    int remain = n % _10_2; if ( remain>0 ) printf(" %d",        remain);
  }
  else {
    display( n / _10_7 );
    printf(" kuti");
    display( n % _10_7 );
  }
}

int main()
{
  ull n;
  int case_count = 0;
  while ( cin >> n ) {
    printf("%4d.", ++case_count);
    if ( n==0 ) puts(" 0");
    else {
      display(n);
      putchar('\n');
    }
  }
}
