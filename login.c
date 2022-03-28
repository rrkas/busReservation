#include<stdio.h>
#include "colors.c"

void login()
{
  char userName[20] = "demo";
  char passWord[10] = "password";
  char matchPass[10];
  char matchUser[10];
  int value;
  redColor();
  printf("\n\n=========================================================================================\n");
  printf("\n\t\t\tWELCOME TO ONLINE BUS RESERVATION");
  printf("\n\n=========================================================================================\n\n");
  resetColor();
login:
{
  printf("\n\nUserName: ");
  gets(matchUser);

  printf("\nPassWord: ");
  gets(matchPass);
}

  value = strcmp(passWord, matchPass); /// string compare is function defined in headerfile i.e string.h
  if (value != 0)
  {
    redColor();
    printf("\nINVALID DETAILS TRY AGAIN...\n");
    resetColor();
    goto login;
  }
  else
  {
    printf("\nLOGED IN SUCCESFULLY...\n");
  }
}
