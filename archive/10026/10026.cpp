#include <cstdio>
#include <algorithm>

using namespace std;

int N;

struct Job
{
  int pos;
  int time;
  int fine;
  double ratio() const { return double(time)/double(fine); }
} jobs[1000];

bool operator< (const Job &a, const Job &b)
{
  double a_ratio = a.ratio();
  double b_ratio = b.ratio();
  if ( a_ratio != b_ratio ) return a_ratio < b_ratio;
  else                      return a.pos < b.pos;
}

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    scanf("%d", &N);
    for ( int i=0; i<N; ++i ) {
      int time, fine;
      scanf("%d %d", &time, &fine);
      jobs[i].pos  = i+1;
      jobs[i].time = time;
      jobs[i].fine = fine;
    }
    sort(jobs, jobs+N);
    if ( t>1 ) putchar('\n');
    printf("%d", jobs[0].pos);
    for ( int i=1; i<N; ++i )
      printf(" %d", jobs[i].pos);
    putchar('\n');
  }
}
