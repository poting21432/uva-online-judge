#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

typedef unsigned long long ull;

const int MAX_MONEY = 300000;

const int N = 11; // number of coins
const int coins[N] = {5, 10, 20, 50, 100, 200,
		      500, 1000, 2000, 5000, 10000};

ull f[MAX_MONEY+1];

void prepare()
{
  f[0] = 1;
  for ( int i=0; i<N; ++i )
    for ( int j=coins[i]; j<=MAX_MONEY; ++j )
      f[j] += f[j-coins[i]];
}

void test()
{
  string input;
  while ( cin >> input ) {
    int m = 0;
    for ( int i=0; i<input.length(); ++i )
      if ( isdigit(input[i]) )
	m = m*10 + int(input[i]-'0');
    if ( m==0 ) break;
    cout << right << setw(6)  << input;
    cout << right << setw(17) << f[m] <<endl;
  }
}

int main()
{
  prepare();
  test();
}
