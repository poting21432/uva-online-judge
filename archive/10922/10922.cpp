#include <iostream>
#include <string>

using namespace std;

int sumOfDigits(const string &S)
{
  int N = S.length();
  int sum = 0;
  for ( int i=0; i<N; ++i )
    sum += S[i]-'0';
  return sum;
}

int sumOfDigits(int n)
{
  int sum = 0;
  while ( n>0 ) {
    sum += n%10;
    n /= 10;
  }
  return sum;
}

int main()
{
  string S;
  while ( cin >> S && S != "0" ) {
    int sum = sumOfDigits(S);
    if ( sum%9 != 0 )
      cout << S << " is not a multiple of 9." << endl;
    else {
      int degree = 1;
      while ( sum != 9 ) {
	sum = sumOfDigits(sum);
	++degree;
      }
      cout << S << " is a multiple of 9 and has 9-degree " << degree << "." << endl;
    }
  }
}
