#include <stdio.h>

void my_initializer(int * param_1)
{
  *param_1 = 0;
 }

int main() 
{
  int variable_a = 12;

  printf("%d\n", variable_a); // will print 12
  my_initializer(&variable_a);
  printf("%d\n", variable_a); // will print 0
  return 0;
}