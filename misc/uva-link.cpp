#include <cstdio>
#include <cstring>

char buf[1024];

int main()
{
  while ( gets(buf) ) {
    if ( buf[0]=='*' ) {
      char problem_id[16];
      sscanf(buf, "* %s", problem_id);
      char problem_dir[16];
      strcpy(problem_dir, problem_id);
      problem_dir[strlen(problem_id)-2] = '\0';
      printf("[%s](http://uva.onlinejudge.org/external/%s/%s.html)\n", buf, problem_dir, problem_id);
    }
    else {
      puts(buf);
    }
  }
}
