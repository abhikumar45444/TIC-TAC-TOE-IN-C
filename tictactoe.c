#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include<conio.h>


int i = 0;
int turn = 1;
int markedPosition[9] = {0};
int playing = 1;



// user input function accepts only position between 1 to 9 and characters not allowed
int input()
{
   int player1pos = 0;
   int player2pos = 0;
   int check = 1;

   while (check)   //checking for the correct input
   {
      if (turn == 1)   //flag variable to check if turn is of player 1 or 2
      {
         printf("\nPlayer 1, enter a number: ");
         fflush(stdin);   //if player enters a input other than numbers using %d in scanf the characters persist in buffer it clears buffers
         scanf("%d", &player1pos);

         if ((player1pos > 9) || (player1pos < 1)) //to check input is between 1 to 9
         {
            printf("invalid choice!! please choose correct position\n");
         }
         else
         {
            check = 0;
         }
      }
      else
      {
         printf("\nPlayer 2, enter a number: ");
         fflush(stdin);
         scanf("%d", &player2pos);

         if ((player2pos > 9) || (player2pos < 1))
         {
            printf("invalid choice!! please choose correct position\n");
         }
         else
         {
            check = 0;
         }
      }
   }

   if (turn == 1)
   {
      return player1pos;  //position at which player wants to place symbol  
   }
   else
   {
      return player2pos;  //position at which player wants to place symbol
   }
}



// function to check WHO_WIN or DRAW
int checkForWin(char *position, int len_pos)
{
   if(position[0] == 'X' && position[1] == 'X' && position[2] == 'X' || 
   position[3] == 'X' && position[4] == 'X' && position[5] == 'X' ||
   position[6] == 'X' && position[7] == 'X' && position[8] == 'X' ||
   position[0] == 'X' && position[3] == 'X' && position[6] == 'X' || 
   position[1] == 'X' && position[4] == 'X' && position[7] == 'X' ||
   position[2] == 'X' && position[5] == 'X' && position[8] == 'X' ||
   position[0] == 'X' && position[4] == 'X' && position[8] == 'X' ||
   position[2] == 'X' && position[4] == 'X' && position[6] == 'X')
   {
      playing = 0;
      return 1;  //printf("Player 1 -> (X)  WINS !!!!\n");
   }
   else if(position[0] == 'O' && position[1] == 'O' && position[2] == 'O' || 
   position[3] == 'O' && position[4] == 'O' && position[5] == 'O' ||
   position[6] == 'O' && position[7] == 'O' && position[8] == 'O' ||
   position[0] == 'O' && position[3] == 'O' && position[6] == 'O' ||
   position[1] == 'O' && position[4] == 'O' && position[7] == 'O' ||
   position[2] == 'O' && position[5] == 'O' && position[8] == 'O' ||
   position[0] == 'O' && position[4] == 'O' && position[8] == 'O' ||
   position[2] == 'O' && position[4] == 'O' && position[6] == 'O')
   {
      playing = 0;
      return 0;  //printf("Player 2 -> (O)  WINS !!!!\n");
   }
   else if (i == 9)
   {
      playing = 0;
      return -1; //printf("DRAW !!!!\n");
   }
   
}





// function to print the board on screen
void drawBoard(char *positions)
{


   system("cls");
   printf("****************  TIC-TAC-TOE  ******************\n\n");
   printf("Player 1 -> (X)     -    Player 2 -> (O)\n\n");
   printf("     |     |     \n");
   printf("  %c  |  %c  |  %c \n", positions[0], positions[1], positions[2]);
   printf("_____|_____|_____\n");
   printf("     |     |     \n");
   printf("  %c  |  %c  |  %c \n", positions[3], positions[4], positions[5]);
   printf("_____|_____|_____\n");
   printf("     |     |     \n");
   printf("  %c  |  %c  |  %c \n", positions[6], positions[7], positions[8]);
   printf("     |     |     \n");


}


// function to put X's and O's on the board
void markBoard(char *position, int pos_len)
{


   int correctpos1 = 1;
   int correctpos2 = 1;

   if (turn == 1)  //for player1
   {
      int pos = input();   

         while (correctpos1)
         {
            if (markedPosition[pos - 1] != 1)
            {

               int pos1 = position[pos - 1];
               if ((pos + 48) == pos1)
               {
                  position[pos - 1] = 'X';
                  markedPosition[pos - 1] = 1;
                  turn = 0;
                  correctpos1 = 0;
                  break;
               }
               
            }
            else
            {
               printf("Invalid position!!\n");
               pos = input();
            }
         }
         
         if(correctpos1 == 0)
         {
            i++;
         }
   }
   else    //for player 2
   {

      int pos = input();

         while (correctpos2)
         {

            if (markedPosition[pos - 1] != 1)
            {

               int pos1 = position[pos - 1];
               if ((pos + 48) == pos1)
               {
                  position[pos - 1] = 'O';
                  markedPosition[pos - 1] = 1;
                  turn = 1;
                  correctpos2 = 0;

                  break;
               }
            }
            else
            {
               printf("Invalid position!!\n");
               pos = input();
            }
         }
         
         if (correctpos2 == 0)
         {
            i++;
         }
   }
   drawBoard(position);
}

//main function
int main()
{

   char symbol[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
   int pos_len = strlen(symbol);
   
   int win;
   while (playing)
   {
      drawBoard(symbol);
      markBoard(symbol, pos_len);
      win = checkForWin(symbol, pos_len);
   }
   if (win == 1)
   {
      printf("\n\n\t____ player 1 wins! ____\n");
   }
   else if (win == 0)
   {
      printf("\n\t____player 2 wins!____\n");
   }
   if (win == -1)
   {
      printf("\n\t____ draw!!! ____\n");
   }
   printf("\n\t    ____ done!! ____\n\n\n\n");

   printf("Press any key to exit....");
   getch();

   return 0;
}