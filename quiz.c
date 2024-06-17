#include<stdio.h>
#include<windows.h>

void gotoXY(int x, int y){

   COORD c;
    c.X=x;
    c.Y=y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
int main(){

   int ans1,ans2,ans3,ans4,ans5;
    int p1=0,p2=0,p3=0,p4=0,p5=0;
    int p01=0,p02=0,p03=0,p04=0,p05=0;
    int i ,total= 0;
   
    gotoXY(15,8);
printf("WELCOME TO QUIZE\n");
printf("\n");
    printf(" > PRESS 1 to start the game .\n");
    printf(" > PRESS 0 TO QUIT THE GAME .\n");
    scanf("%d",&i);
    if(i==1){
       printf("\n");
        printf(" \t \t \t  THE GAME HAS BEEN STARTED .\n");
    }
    else if(i == 0){
     printf("\n");
        printf("\t\t\t\tEXITTING THE GAME .....");
        return 1;
    }
    else{
       printf("\n");
        printf("INVALID INPUT .");
        printf("\n");
    }
    //question 1. 
   
if(i==1){
    printf("\n");
    printf("\n1 ] Who is the father of c language .\n");
    printf("\t1) VYOM\n\t2) james Gosling \n\t3) Dennis Ritchie\n\t4) Rasmus Lerdorf \n");
    scanf("%d",&ans1);
    if(ans1== 3){
        p1=5;
        printf("Your answer is correct .\n");
        printf("you scored %d points.",p1);
    }
    else{
        p01=0;
        printf("Your answer is wrong .\n");
        printf("You scored %d pointd ",p01);
    }
}
// question 2.
printf("\n");
if(i==1){
    printf("\n");
    printf("2 ] Which is valid c expression .\n");
    printf("\t1) int n = 100,000\n\t2) int my n = 100000;\n\t3) int n = 1000;\n\t4) int $n = 10000;\n");
    scanf("%d",&ans2);
    if(ans2== 3){
        p2=5;
        printf("Your answer is correct .\n");
        printf("you scored %d points.",p2);
    }
    else{
        p02=0;
        printf("Your answer is wrong .\n");
        printf("You scored %d pointd ",p02);
    }
}
//question 3.
printf("\n");
if(i==1){
    printf("\n");
    printf("3 ] Which is an example of iteration in c .\n");
    printf("\t1) for \n\t2) while \n\t3) do while \n\t4) all of the above \n");
    scanf("%d",&ans3);
    if(ans3== 4){
        p3=5;
        printf("Your answer is correct .\n");
        printf("you scored %d points.",p3);
    }
    else{
        p03=0;
        printf("Your answer is wrong .\n");
        printf("You scored %d pointd ",p03);
    }
}
//question 4
printf("\n");
if(i==1){
    printf("\n");
    printf("4 ] The c preprocessors are specified with _________ symbol.\n");
    printf("\t1) # \n\t2) $ \n\t3) " " \n\t4) & \n");
    scanf("%d",&ans4);
    if(ans4== 1){
        p4=5;
        printf("Your answer is correct .\n");
        printf("you scored %d points.",p4);
    }
    else{
        p04=0;
        printf("Your answer is wrong .\n");
        printf("You scored %d pointd ",p04);
    }
}
//question 5.
printf("\n");
if(i==1){
    printf("\n");
    printf("5 ] Which of the following return type cannot be used for a function ? \n");
    printf("\t1) char* \n\t2) struct \n\t3) void \n\t4) none of the mentioned \n");
    scanf("%d",&ans5);
    if(ans5== 4){
        p5=5;
        printf("Your answer is correct .\n");
        printf("you scored %d points.",p5);
    }
    else{
        p05=0;
        printf("Your answer is wrong .\n");
        printf("You scored %d pointd ",p05);
    }
}

printf("\n \n ");
total=p1+p2+p3+p4+p5;
printf("\nYOU HAVE SCORED  %d POINTS IN QUIZ . ",total);

    return 0;
}