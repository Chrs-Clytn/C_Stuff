#include <stdio.h>




int my_islower(char param_1)
{

  if (param_1 >= 96 && param_1 <= 122) {
      return 1;
  } else {
      return 0;
  }

}

int main() 
{
    
    my_islower('x');

    return 0;
}
