#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
int main()
{
  char ttt[9]; // for the array
  char x[20]; //first player name
  char y[20]; // second player name
  char fst[20]; // name(who'll play first)
  int count=0 ; // counting index filled in array
  int pos; // position to enter the move
  char tem ; //temporary variable
  int mx = 1; // temporary variable
  int my = 1; // temporary variable
  
  cout<<"\nEnter name of first player(who use SYMBOL X) : ";
  cin>>x;
  //   while(( getchar() ) != '\n') ;

  cout<<"\nEnter name of second player(who use SYMBOL O) : ";
  cin>>y;
  //  while(( getchar() ) != '\n') ;

  /*   Initialising each position of the array with ' '   */

  for(int i=0 ; i<9 ; i++)          
    ttt[i] =' ';

 
 /* Name of one of the 2 registered players who will start the game . */

    cout<<"Enter who will play first : ";  
    cin>>fst;
    //while(( getchar() ) != '\n') ;


  /* Tic Tac Toe board */

    while(count<9)
    {
      

        cout<<"\n\n";
                cout<<"\t\t\t  "<<ttt[0]<<" | "<<ttt[1]<<"  | "<<ttt[2]<<"  \n"; 
                cout<<"\t\t\t----+----+----\n";
                cout<<"\t\t\t  "<<ttt[3]<<" | "<<ttt[4]<<"  | "<<ttt[5]<<"  \n"; 
                cout<<"\t\t\t----+----+---\n";
                cout<<"\t\t\t  "<<ttt[6]<<" | "<<ttt[7]<<"  | "<<ttt[8]<<"  \n"; 
       if(count==0)
       {
          mx = strcmp(x,fst);
          my = strcmp(y,fst); 
           
        }

     
     
      if(my!=0 )
      {
         my=-10;
          if(mx%2 == 0 )
            {  cout<<"\n"<<x<<" !!!!!Enter ur move (1-9) ";  
               mx++;
             }

          else
             { cout<<"\n"<<y<<" !!!!!Enter ur move (1-9) ";  
               mx++ ;
              }

      }
      else if(mx!=0)
      {    mx=-10;
           if(my%2 == 0 )
            {  cout<<"\n"<<y<<" !!!!!Enter ur move (1-9) ";  
                my++; }

          else
             { cout<<"\n"<<x<<" !!!!!Enter ur move (1-9) ";  
               my++ ; }

      }
     
     /* If the player who wants to play first does not match any of the registered players */

        else if(mx == my)
         {
          cout<<"No such person is playing !!!!";
          exit(0);
         }
      
       cin>>pos;
       pos = pos-1 ;

  system("clear");

       if(count==0)

       {                        //1
       
         if(!(strcmp(x,fst)))
         {
            
             ttt[pos]='X' ;
             tem ='X';
              
         }
         else if(!(strcmp(y,fst)))
               {  ttt[pos]='O' ;   
                 tem = 'O' ;
                 }
         
        }                                                //-1

      else
          {                                              //a
            if(tem=='X' && ttt[pos]==' ')
               {
                 ttt[pos] = 'O';
                 tem = 'O';
               }
            else if(tem=='O' && ttt[pos]==' ')
              {
                  ttt[pos] = 'X' ;
                  tem = 'X' ;
               }

               /* If the position in which a player wants to mark his symbol was already filled !!!!!!*/

               else{
                cout<<"\nWRONG MOVE ( position already filled ) !!!! \n PLAY AGAIN ------>>>>>\n";
                if(mx>my)
                  mx--;
                else
                  my--;

                count--;
               }
          }        
                                             //-a
         
       int flag=10 ;
   for(int i=0 ; i<7 ; i++)
   {  
      if(i==4 || i==5);
        

      else if( ttt[0]!=' ' && ((ttt[0]==ttt[1] && ttt[1] == ttt[2]) || (ttt[0]==ttt[3] && ttt[3] == ttt[6]) || (ttt[0]==ttt[4] && ttt[4] == ttt[8]) ))
      {
        flag = 0 ;
        break;
      }
      
      else if(ttt[1]!=' ' &&  (ttt[1]==ttt[4] && ttt[4] == ttt[7])  )
             {
              flag =1 ;
               break;
             }
         
      else if(ttt[2]!=' ' && ( (ttt[2]==ttt[5] && ttt[5] == ttt[8]) || (ttt[2]==ttt[4] && ttt[4] == ttt[6]) ) )
                { 
                  
                  flag = 2;
                   break;
                }

      else if(ttt[i]!=' ' && (i==3 || i==6) )
          {
            if(  ttt[i] == ttt[i+1] && ttt[i+1] == ttt[i+2] )
            {
              flag = i ;
               break;
            }
          }
   }

 
      if(flag<10)
      {           
                cout<<"\t\t\t  "<<ttt[0]<<" | "<<ttt[1]<<"  | "<<ttt[2]<<"  \n"; 
                cout<<"\t\t\t----+----+----\n";
                cout<<"\t\t\t  "<<ttt[3]<<" | "<<ttt[4]<<"  | "<<ttt[5]<<"  \n"; 
                cout<<"\t\t\t----+----+---\n";
                cout<<"\t\t\t  "<<ttt[6]<<" | "<<ttt[7]<<"  | "<<ttt[8]<<"  \n"; 
        
    /* Displaying the WINNER !!!!! */

     if(ttt[flag] == 'X')
      cout<<"\n"<<x<<" is winner !!!!\n\n";

    else if(ttt[flag] == 'O')
       cout<<"\n"<<y<<" is winner !!!!\n\n"; 

     exit(0);

     }
  
   /* If both player failed to make the wining combination , the game results to a tie !!!!! */

  if(count==8)
      cout<<"\nDRAW :)   , better luck next time !!!!!!!!!!";

      count++ ;
    }//-while
   

   
  return 0 ;
}