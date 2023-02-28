#include<bits/stdc++.h>
using namespace std;

char space[3][3]={
                    {'1' , '2' , '3' },
                    {'4' , '5' , '6' },
                    {'7' , '8' , '9' }
          };

int row,column;
string n1,n2;
int p=0;
char token='X';
char replay='y';

int checker(){
    for(int i=0;i<3;i++){
      if(space[i][0]==space[i][1] && space[i][2]==space[i][1])
         return true;
    }
   for(int i=0;i<3;i++){
      if(space[0][i]==space[1][i] && space[2][i]==space[1][i])
         return true;
    }
   if((space[0][0]==space[1][1] && space[0][0]==space[2][2])||(space[0][2]==space[1][1] && space[1][1]==space[2][0]))
      return true;

    return false;
}

void functionOne(){
   cout<<"   |    |\n";
   cout<<" "<<space[0][0]<<" | "<<space[0][1]<<"  | "<<space[0][2]<<" \n";
   cout<<"___|____|___\n";
   cout<<"   |    |\n";
   cout<<" "<<space[1][0]<<" | "<<space[1][1]<<"  | "<<space[1][2]<<" \n";   
   cout<<"___|____|___\n";
   cout<<"   |    |\n";
   cout<<" "<<space[2][0]<<" | "<<space[2][1]<<"  | "<<space[2][2]<<" \n";
   cout<<"   |    |\n";
 
 }

void functionTwo(){
 int digit;
if(token=='X'){
   cout<<n1<<" please enter \n";
   cin>>digit;
}
if(token=='O'){
   cout<<n2<<" please enter \n";
   cin>>digit;
}

if(digit==1)
   row=0,column=0;
else if(digit==2)
   row=0,column=1;
else if(digit==3)
   row=0,column=2;
else if(digit==4)
   row=1,column=0;
else if(digit==5)
   row=1,column=1;
else if(digit==6)
   row=1,column=2;
else if(digit==7)
   row=2,column=0;
else if(digit==8)
   row=2,column=1;
else if(digit==9)
   row=2,column=2;

space[row][column]=token;
p++;
 if(checker() && p<=9){
   functionOne();
   if(token=='X')
   cout<<"Player "<<n2<<" win the game\n";
   else
   cout<<"Player "<<n1<<" win the game\n";
   replay='n';
   return ;
  }
}

int main()
{
   cout<<"Enter the name of first player\n";           
   cin>>n1;
   cout<<"Enter the name of second player\n";           
   cin>>n2;
   cout<<n1<<" is player 1 so he/she will play first\n";
   cout<<n2<<" is player 1 so he/she will play second\n";

   int pp=0;
   do{
     do{
       if(p%2==0)
        token='X';
       else
       token='O';
      functionOne();
      functionTwo();

      if(replay=='y')
      system("cls");

      if(p==9){
       cout<<"NO One win the game\n";
      replay='n';
     }
   }while(replay=='y'||replay=='Y');
     cout<<"GOOD LUCK NEXT TIME, Enter any letter to break\n";
     cin>>pp;
 }while(pp==-1);

  return 0;
}; 
   