#include<stdio.h>

void colorRed() /// Print the message in colorRed
{
  printf("\x1B[31m");
}
void colorReset() /// reset the old color of console
{
  printf("\x1B[0m");
}