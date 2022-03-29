#include<stdio.h>
#include "colors.c"

void loginCred()
{
  char username[20] = "demo";
  char password[10] = "password";
  char passMatch[10];
  char userMatch[10];
  int value;
  colorRed();
  printf("\n\n=========================================================================================\n");
  printf("\n\t\t\tWELCOME TO ONLINE BUS RESERVATION");
  printf("\n\n=========================================================================================\n\n");
  colorReset();
loginCred:
{
  printf("\n\nusername: ");
  gets(userMatch);

  printf("\npassword: ");
  gets(passMatch);
}

  value = strcmp(password, passMatch); /// string compare is function defined in headerfile i.e string.h
  if (value != 0)
  {
    colorRed();
    printf("\nINVALID USERNAME/ PASSWORD TRY AGAIN...\n");
    colorReset();
    goto loginCred;
  }
  else
  {
    printf("\nLOGGING IN SUCCESSFULLY...\n");
  }
}
