#include<stdio.h>

void redColor() /// Print the message in redcolor
{
  printf("\x1B[31m");
}
void resetColor() /// reset the old color of console
{
  printf("\x1B[0m");
}