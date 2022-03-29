#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "bst.c"
#include "login.c"

BSTR *root = NULL;
int getCost(BSTR *r);                         // calculates costs
void getStatus();                             // shows bus and seats getStatus
void getBusList();                            // shows buslist and do booking seat and return customer ID
void displaySeats(int bus[33]);               // Display the seats of buses
void cancelBooking(int x);                    // cancelBooking the booking
BSTR *getReservationInfo(BSTR *, int, int *); // Display Reservation Info
BSTR *insertNode(BSTR **r, int custID);       // inserting a node

int busSeats[32][9] = {0};

BSTR *getReservationInfo(BSTR *r, int s, int *custIDmatched) // find function
{
  if (r == NULL)
    return NULL;
  BSTR *current = r;
  while (current)
  {
    // --------------------

    if (current->passengerNumber == s)
    {
      *custIDmatched = 1;
      colorRed();
      printf("\n-----------------------------------------------------------------");
      printf("\n||              NAME: %10s                               ||", (current->name));
      printf("\n||              CUSTOMER ID: %d                              ||", current->passengerNumber);
      printf("\n||              BUS NUMBER: %d                                  ||", (current->passengerNumber) / 1000);
      printf("\n||              SEAT NUMBER: %d                                 ||", (current->passengerNumber) % 100);
      printf("\n||              TICKET COST: Rs.%d                             ||", getCost(current));
      printf("\n-----------------------------------------------------------------");
      colorReset();
      getch();
      return r;
    }
    else if (current->passengerNumber > s)
      current = current->left;
    else
      current = current->right;
  }

  return NULL;
}
BSTR *insertNode(BSTR **r, int custId)
{
  if (*r == NULL)
  {

    *r = (BSTR *)malloc(sizeof(BSTR));
    (*r)->passengerNumber = custId;
    if (*r == NULL)
    {
      printf("No memory…");
      return NULL;
    }
    else
    {
      (*r)->left = (*r)->right = NULL;
      printf("\n   ENTER THE PERSON NAME: ");
      scanf("%s", &((*r)->name));
    }
  }
  else
  {
    if ((*r)->passengerNumber > custId)
    {
      (*r)->left = insertNode(&((*r)->left), custId);
    }
    else if ((*r)->passengerNumber < custId)
    {
      (*r)->right = insertNode(&((*r)->right), custId);
    }
  }
  return *r;
}

void displaySeats(int bus[33])
{
  for (int i = 1; i <= 32; i++)
  {
    colorRed();
    if (i < 10 && i > 0)
    {
      printf("0%d .", i);
    }
    else
    {
      printf("%d .", i);
    }

    colorReset();
    {
      if (bus[i] == 0)
        printf("EMPTY ");
      else
        printf("BOOKED"); // reserved
    }
    printf("         ");
    if (i % 4 == 0)
      printf("\n");
  }
}
int getCost(BSTR *r)
{
  int getCost, buscost;
  buscost = (r->passengerNumber) / 1000;
  switch (buscost % 3)
  {
  case 1:
    return 70;
    break;
  case 2:
    return 55;
    break;
  case 0:
    return 40;
    break;
  default:
    return 0;
    break;
  }
}
void getStatus()
{
  int busNum;
  getBusList();
busInput:
  printf("\n\nENTER YOUR BUS NUMBER : ");
  scanf("%d", &busNum);
  if (busNum <= 0 || busNum >= 10)
  {
    colorRed();
    printf("\n  PLEASE ENTER CORRECT BUS NUMBER !!\n");
    colorReset();
    goto busInput;
  }
  printf("\n");
  displaySeats(busSeats[busNum]);
  getch();
}
void getBusList()
{
  colorRed();
  printf("-----------------------------------------------------------------------------------------");
  printf("\nBus.No\tName\t\t\tDestinations  \t\tCharges  \t\tTime\n");
  printf("-----------------------------------------------------------------------------------------");
  colorReset();
  printf("\n1\tGangaTravels         \tDharan to Kavre       \tRs.70   \t\t07:00  AM");
  printf("\n2\tPhaphara Travels     \tKavre To Dharan       \tRs.55    \t\t01:30  PM");
  printf("\n3\tShiv Ganga Travels   \tAllahabad To Gorakhpur\tRs.40    \t\t03:50  PM");
  printf("\n4\tSuper Deluxe         \tPokhara To Benigha    \tRs.70    \t\t01:00  AM");
  printf("\n5\tSai Baba Travels     \tMaitidevi To Janakpur \tRs.55    \t\t12:05  AM");
  printf("\n6\tShine On Travels     \tMadhubani to Patna    \tRs.40    \t\t09:30  AM");
  printf("\n7\tMayur Travels        \tPatna To Gaya         \tRs.70   \t\t11:00  PM");
  printf("\n8\tRajjo Travels       \tBegusarai To Patna     \tRs.55    \t\t08:15  AM");
  printf("\n9\tShree Travels        \tGaya To Chhapra       \tRs.40    \t\t04:00  PM");
  printf("\n");
  printf("\n   PRESS 'ENTER' KEY TO CONTINUE ");
  getch();
}
void cancelBooking(int randomNum)
{
  int reservationNo;
  int seat;
  int choice;
  char c;
  int seatCancel;

aa:
{
  printf("\nENTER YOUR RESERVATION NUMBER : ");
  scanf("%d", &reservationNo);
  if (reservationNo == randomNum)
  {
    printf("\nRESERVATION NUMBER IS IT CORRECT ? %d \nENTER (Y/N) : ", reservationNo);
    scanf("%s", &c);
    if (c == 'y' || c == 'Y')
    {
      printf("\n\n============================================\n\n");
      printf("   ENTER THE BUS NUMBER: ");
      scanf("%d", &choice);

      printf("\n HOW MANY SEATS DO WANT TO CANCEL : ");
      scanf("%d", &seatCancel);
      for (int i = 0; i < seatCancel; i++)
      {
        printf("   \nENTER THE SEAT NUMBER: ");
        scanf("%d", &seat);

        busSeats[choice][seat] = 0;
      }
      printf("\n\nYOUR RESERVATION HAS BEEN CANCEL !!\n\n");
      printf("\n  PRESS 'ENTER' KEY TO CONTINUE \n");
      getch();
      displaySeats(busSeats[choice]);
    }

    else if (c == 'n' || c == 'N')
    {
      printf("\nYOUR RESERVATION CANCELATION HAS BEEN DENIED\n");
    }
  }
  else
  {
    printf("\nNOT FOUND!! ENTER THE CORRECT RESERVATION NUMBER\n");
    goto aa;
  }
}
}

int main()
{
  srand(time(0));
  int randomNum = rand();
  int num, i, custID, reservationNo;
  BSTR *root1;
  loginCred();
main:
{
  do
  {
    system("cls");
    printf("\n\n====================================================================\n\n");
    printf("\t\t\t\033[1;31mBUS RESERVATION\033[0m\t\t");
    printf("\n\n=====================================================================\n");
    printf("\n====================");
    colorRed();
    printf("  MAIN MENU ");
    colorReset();
    printf("=====================\n\n");
    printf("   \033[1;31m[1]\033[0m VIEW BUS LIST \n\n");
    printf("   \033[1;31m[2]\033[0m BOOK TICKETS\n\n");
    printf("   \033[1;31m[3]\033[0m CANCEL BOOKING\n\n");
    printf("   \033[1;31m[4]\033[0m BUSES SEATS INFO\n\n");
    printf("   \033[1;31m[5]\033[0m RESERVATION INFO\n\n");
    printf("   \033[1;31m[6]\033[0m EXIT\n");
    printf("\n=====================================================\n");
    printf("\n   ENTER YOUR CHOICE: ");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
      getBusList(); // for list of bus
      break;
    case 2:
      getBusList(); // for booking the tickets

      int customerID, choice, seats;

    busChoice:
      printf("\n\nCHOOSE YOUR BUS  : ");
      scanf("%d", &choice);
      if (choice <= 0 || choice > 9)
      {
        colorRed();
        printf("\nENTER VALID BUS NUMBER !! \n");
        colorReset();
        getch();
        goto busChoice;
      }
      printf("\n");
      displaySeats(busSeats[choice]);
    busSeatChoice:
      printf("\n\nNO. OF SEATS YOU NEED TO BOOK : ");
      scanf("%d", &seats);
      if (seats <= 0)
      {
        colorRed();
        printf("\nENTER VALID SEAT NUMBER!!\n");
        colorReset();
        goto busSeatChoice;
      }
      else if (seats > 32)
      {
        colorRed();
        printf("\nENTER VALID SEAT NUMBER WE HAVE ONLY 32 SEATS IN A BUS !!\n");
        colorReset();
        goto busSeatChoice;
      }
      int seat;
      for (int i = 1; i <= seats; i++)
      {
        printf("\n\n==================================================================================\n\n");
      seat:
        printf("   ENTER THE SEAT NUMBER: ");
        scanf("%d", &seat);
        if (seat <= 0)
        {
          colorRed();
          printf("\n   ENTER VALID SEAT NUMBER!!\n\n");
          colorReset();
          goto seat;
        }
        else if (seat > 32)
        {
          colorRed();
          printf("\n   ENTER VALID SEAT NUMBER WE HAVE ONLY 32 SEATS IN A BUS !!\n\n");
          colorReset();
          goto seat;
        }
        customerID = choice * 1000 + seat; // CustumerId
        busSeats[choice][seat] = 1;
        root = insertNode(&root, customerID);
        colorRed();
        printf("\n   YOUR CUSTOMER ID IS : %d", customerID);
        colorReset();
        printf("\n\n==================================================================================\n\n");
      }
      printf("\nYOUR RESERVATION NUMBER IS : ");
      colorRed();
      printf("%d\n", randomNum);
      printf("\nPLEASE NOTE DOWN YOUR RESERVATION NUMBER FOR CANCEL BOOKING TICKETS!!\n");
      colorReset();
      printf("PRESS 'ENTER' KEY TO CONTINUE ");
      getch();
      break;

    case 3:
      cancelBooking(randomNum);
      break;
    case 4:
      getStatus(randomNum);
      break;
    case 5:
    takingReservationNo:
      printf("\n   ENTER YOUR RESERVATION NUMBER :");
      scanf("%d", &reservationNo);

      if (randomNum == reservationNo)
      {
      cust:
        printf("\n   ENTER YOUR CUSTOMER ID :");
        scanf("%d", &custID);
        int custIDmatched = 0;
        root1 = getReservationInfo(root, custID, &custIDmatched);
        if (custIDmatched == 0)
        {
          colorRed();
          printf("\n   ENTER CORRECT CUSTOMER ID!!\n");
          colorReset();
          goto cust;
        }
      }
      else
      {
        colorRed();
        printf("\n INVALID RESERVATION NUMBER PLEASE ENTER CORRECT RESERVATION NUMBER !!\n");
        colorReset();
        goto takingReservationNo;
      }
      break;
    default:
      colorRed();
      printf("\n\n   INVALID INPUT CHOOSE CORRECT OPTION\n");
      colorReset();
      break;
    }
  } while (num != 6);
  printf("\n\n=====================================================================\n\n");
  printf("THANK YOU FOR USING THIS BUS RESERVATION SYSTEM");
  printf("\n\nPRESS ANY KEY TO EXIT THE END PROGRAM !! \n");
  printf("\n\n");
  getch();
  return 0;
}
}
