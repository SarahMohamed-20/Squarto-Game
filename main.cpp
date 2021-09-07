#include <iostream>
#include<stdlib.h>
//2-D array stated GLOBALLY
int b[6][6] = {{1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30},{31,32,33,34,35,36}};
int i,j;
void theBoard(); //function to draw the board
void Intro(); //function to introduce the game
void Input(); //function to take the input and check its validity
void PlayerSwap(); //swap between the 2 players
int checkWin(); // check if a player DID complete a square and return his playing number
int player=0; //define the player as an integer and set the initial value with the first player's playing number
int count=0; // count to keep track of the filled slots
using namespace std;
int main()
{
    Intro();
    theBoard();

    while (1) // a loop to keep displaying the board,taking the input,swapping players until a player is announced
    {
        Input();  // keep taking input until a winner is announced
        theBoard(); // board keeps showing until a winner is announced

//checking if a player actually won
        if(checkWin()==0) //checking to see which player won
        {
            cout<<"\n\n\n\n\n\n\t\t\t\t\t\tPlayer 1 --> '0' symbol WINS\n\n\t\t\t\t\t\t\tGOOD JOB!!\n\n"<<endl;
            break;  //if indeed a player won by completing a square, break out of the loop/program
        }
        else if(checkWin()==100)
        {
            cout<<"\n\n\n\n\n\n\t\t\t\t\t\tPlayer 2 --> '100' symbol WINS\n\n\t\t\t\t\t\t\tGOOD JOB!!\n\n"<<endl;
            break;
        }


        PlayerSwap(); //players swap if there is no winner yet
        if(count==36) // check if all the playing cells are filled
        {
            if (checkWin()!=0 || checkWin()!=100) //check that filled cells did not form a square, no winner was announced
            {
                cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t  ITS A TIE.\n\n\t\t\t\t\t\t\tTRY AGAIN LATER!!\n\n"<<endl; // a tie
                break;
            }

        }


    }


    return 0;
}
void Intro ()
{
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tWelcome to S Q U A R T O GAME\t\t"<<endl<<endl;
    cout<<"\t\t\t\t\t\tA WINNER IS ANNOUNCED WHEN HE COMPLETES A SQUARE OUT OF HIS MARKS"<<endl;
    cout<<"\n\t\t\tPlayer 1 is assigned '0' as symbol\n\t\t\tplayer 2 is assigned '100' as symbol"<<endl;
    cout<<"\n\t\t\t\t\t\t\tL E T   T H E   G A M E   S T A R T !!\n\n"<<endl;
    system("pause"); // use the function system with parameter "pause", to pause the screen as it works as an introduction to the game
}
void theBoard()
{
    system("cls"); // called function system with parameter "cls", so that it clears the screen and show only the recent changes, helps keep it one board with all the plays
    cout<<"\n\n\n\t\t";
    cout<<" _______________________________________________________________________________________________\n";

    for(i=0;i<6;i++)
    {
        cout<<"\t\t";
        for(j=0;j<6;j++)
        {
            cout<<"|\t"<<b[i][j]<<"\t" ;
            if(b[i][j]==6 || b[i][j]==12 || b[i][j]==18 || b[i][j]==24 || b[i][j]==30 || b[i][j] ==36)
                cout<<"|";
        }

       cout<<endl;
      cout<<"\t\t|_______________|_______________|_______________|_______________|_______________|_______________|\t\t"<<endl;

    }

}
void Input()
{
    int play;
    cout<<"\nEnter your Playing Cell Number"<<endl;  // take the wanted cell number from the player
    cin>>play;

// a switch cases to check if the playing slot the player has chosen matches his input and if it is actually empty and has never been played in
 //if a condition out of these does not come true then he had entered a wrong/unavailable slot number
    switch(play)
{
case 1:
    {if(play==1 && b[0][0]!=0 && b[0][0]!=8)  //checking if the slot is free and matches the chosen number
       {b[0][0]= player;
       count++;  // accrement the count of the filling cells with every successful play
       break;         // if the slot is free rewrite it with the input then break out of the condition
       }
       else
            cout<<"invalid move. Next Player!\n"; // if not, let the player know that this move is invalid, and switch to the other player's turn
             system("pause");break; // called function system with parameter "pause" to keep the window with the "invalid move" until a key is pressed to make sure the player has read it
    }

case 2:
    {if(play==2 && b[0][1]!=0 && b[0][1]!=100)
       {b[0][1]=player;
       count++;
       break;
       }
        else
           cout<<"invalid move. Next Player!\n";
           system("pause");break;
            ;}
case 3:
     {if(play==3 && b[0][2]!=0 && b[0][2]!=100)
        {b[0][2]=player;
        count ++;
        break;}
        else
            cout<<"invalid move. Next Player!\n";
             system("pause");break;}
case 4:
    {if(play==4 && b[0][3]!=0 && b[0][3]!=100)
        {b[0][3]=player;
        count++;
        break;}
        else
            cout<<"invalid move. Next Player!\n";
             system("pause");break;}
case 5:
      {if(play==5 && b[0][4]!=0 && b[0][4]!=100)
        {b[0][4]=player;
        count++;
        break;}
        else
            cout<<"invalid move. Next Player!\n";
             system("pause");break;;}
case 6:

      {if (play==6 && b[0][5]!=0 && b[0][5]!=100)
        {b[0][5]=player;
        count++;
        break;}
        else
            cout<<"invalid move. Next Player!\n";
            system("pause");break;;
}
case 7:

     {if(play==7 && b[1][0]!=0 && b[1][0]!=100)
        {b[1][0]= player;
        count++;
        break;}
        else
            cout<<"invalid move. Next Player!\n";
            system("pause");break;}
case 8:

     {if (play==8 && b[1][1]!=0 && b[1][1]!=100)
       {
           b[1][1]=player;
           count++;
           break;}
        else
           cout<<"invalid move. Next Player!\n";
            system("pause");break;
}
case 9:

      {if (play==9&& b[1][2]!=0 && b[1][2]!=100)
        {b[1][2]=player;
        count++;
        break;}
        else
           cout<<"invalid move. Next Player!\n";
            system("pause");break;
}
case 10:

      {if (play==10 && b[1][3]!=0 && b[1][3]!=100)
        {b[1][3]=player;
        count++;
        break;}
        else
           cout<<"invalid move. Next Player!\n";
            system("pause");break;}
case 11:
{
    if (play==11 && b[1][4]!=0 && b[1][4]!=100)
       {

        b[1][4]=player;
        count++;
        break;}
        else
            cout<<"invalid move. Next Player!\n";
             system("pause");break;}
case 12:
{
      if (play==12 && b[1][5]!=0 && b[1][5]!=100)
  {

     b[1][5]=player;
     count++;
     break;
 }
 else
            cout<<"invalid move. Next Player!\n";
             system("pause");break;
}
case 13:
{
    if(play==13 && b[2][0]!=0 && b[2][0]!=100)
   {

     b[2][0]= player;
     count++;
     break;}
        else
  cout<<"invalid move. Next Player!\n";
   system("pause");break;
}
case 14:
{
     if (play==14 && b[2][1]!=0 && b[2][1]!=100)
        {b[2][1]=player;
        count++;
        break;
 }       else
          cout<<"invalid move. Next Player!\n";
           system("pause");break;
}
case 15:
    {
      if (play==15 && b[2][2]!=0 && b[2][2]!=100)
        {b[2][2]=player;
        count++;
        break;}
     else
           cout<<"invalid move. Next Player!\n";
           system("pause");break;
    }
case 16:
{
      if (play==16 && b[2][3]!=0 && b[2][3]!=100)
       {
           b[2][3]=player;
           count++;
        break;}
     else
           cout<<"invalid move. Next Player!\n";
            system("pause");break;
}
case 17:
{      if (play==17&& b[2][4]!=0 && b[2][4]!=100)
        {b[2][4]=player;
        count++;
        break;}
    else
           cout<<"invalid move. Next Player!\n";
           system("pause");break;
}
case 18:
{
      if (play==18 && b[2][5]!=0 && b[2][5]!=100)
       {b[2][5]=player;
       count++;
       break;}
      else
            cout<<"invalid move. Next Player!\n";
            system("pause");break;
}
case 19:
{
     if(play==19 && b[3][0]!=0 && b[3][0]!=100)
        {b[3][0]= player;
        count++;
        break;}
     else
            cout<<"invalid move. Next Player!\n";
             system("pause");break;
}
case 20:
{
     if (play==20  && b[3][1]!=0 && b[3][1]!=100)
        {b[3][1]=player;
        count++;
        break;}
      else
            cout<<"invalid move. Next Player!\n";
             system("pause");break;
}
case 21:
{
      if (play==21 && b[3][2]!=0 && b[3][2]!=100)
        {b[3][2]=player;
        count++;
        break;}
     else
            cout<<"invalid move. Next Player!\n";
             system("pause");break;
}
case 22:
{
    if (play==22 && b[3][3]!=0 && b[3][3]!=100)
        {b[3][3]=player;
        count++;
        break;}
    else
            cout<<"invalid move. Next Player!\n";
             system("pause");break;
}
case 23:
{
    if (play==23 && b[3][4]!=0 && b[3][4]!=100)
        {b[3][4]=player;
        count++;
         break;}
    else
           cout<<"invalid move. Next Player!\n";
           system("pause");break;
}
case 24:
{
     if (play==24 && b[3][5]!=0 && b[3][5]!=100)
        {b[3][5]=player;
        count++;
        break;}
    else
           cout<<"invalid move. Next Player!\n";
           system("pause");break;
}
case 25:
{
    if(play==25 && b[4][0]!=0 && b[4][0]!=100)
    {
        b[4][0]= player;
        count++;
        break;}
     else
            cout<<"invalid move. Next Player!\n";
            system("pause");break;
}
case 26:
{
     if (play==26 && b[4][1]!=0 && b[4][1]!=100)
        {b[4][1]=player;
        count++;
        break;}
     else
          cout<<"invalid move. Next Player!\n";
           system("pause");break;
}
case 27:
{
      if (play==27 && b[4][2]!=0 && b[4][2]!=100)
        {b[4][2]=player;
        count++;
        break;}
     else
            cout<<"invalid move. Next Player!\n";
             system("pause");break;
}
case 28:
{
     if (play==28 && b[4][3]!=0 && b[4][3]!=100)
        {b[4][3]=player;
        count++;
        break;}
     else
          cout<<"invalid move. Next Player!\n";
          system("pause");break;
}
case 29:
{
     if (play==29 && b[4][4]!=0 && b[4][4]!=100)
        {b[4][4]=player;
        count++;
        break;}
     else
           cout<<"invalid move. Next Player!\n";
           system("pause");break;
}
case 30:
{
    if (play==30&& b[4][5]!=0 && b[4][5]!=100)
        {b[4][5]=player;
        count++;
        break;}
    else
           cout<<"invalid move. Next Player!\n";
           system("pause");break;
}
case 31:
{
     if(play==31 && b[5][0]!=0 && b[5][0]!=100)
        {b[5][0]= player;
        count++;
        break;}
    else
            cout<<"invalid move. Next Player!\n";
             system("pause");break;
}
case 32:
{
     if (play==32 && b[5][1]!=0 && b[5][1]!=100)
        {b[5][1]=player;
        count++;
        break;}
     else
            cout<<"invalid move. Next Player!\n";
             system("pause");break;
}
case 33:
{
    if (play==33 && b[5][2]!=0 && b[5][2]!=100)
        {b[5][2]=player;
        count++;
        break;}
    else
           cout<<"invalid move. Next Player!\n";
           system("pause");break;
}
case 34:
{
    if (play==34 && b[5][3]!=0 && b[5][3]!=100)
        {b[5][3]=player;
        count++;
        break;}
   else
            cout<<"invalid move. Next Player!\n";
            system("pause");break;
}
case 35:
{
    if (play==35 && b[5][4]!=0 && b[5][4]!=100)
        {b[5][4]=player;
        count++;
        break;}
    else
           cout<<"invalid move. Next Player!\n";
            system("pause");break;
}
case 36:
{
    if (play==36 && b[5][5]!=0 && b[5][5]!=100)
        {b[5][5]=player;
        count++;
        break;}
    else
            cout<<"invalid move. Next Player!\n";
             system("pause");break;
}
default:        // so that if the player entered a number out of the game board range
    cout<<"Out of Range Move. Next Player!\n";
     system("pause");break;
}
}
void PlayerSwap()
{
    if (player==0) // initialized as a global variable

           player=100; // swap to other player

       else
    player = 0;    //alternate
}

int checkWin()
{
   for(i=0;i<6;i++)  //  nested loops that work to run over the 2-D array elements to check if the player indeed did form a square out of his number
   {
       for(j=0;j<6;j++)
            {
                if(b[i][j]==b[i][j+1] && b[i][j]==b[i+1][j] && b[i][j]==b[i+1][j+1])
                        return b[i][j];                    // if yes, return the number inside the elements so the winning player is declared
            }
   }
}
