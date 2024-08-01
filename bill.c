#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_NAME_LENGTH 30
#define MAX_ITEM 100

typedef struct {
char name[MAX_NAME_LENGTH];
int quantity;
float prise;
float total;
} item;
void printbill(item items[],int itemcount);
void printline(char ch,int length);

int main(){
 item items[MAX_ITEM];
 int itemcount = 0 ;
 printf("\n");
 printf("\nENTER THE NO OF ITEMS : ");
 scanf("%d",&itemcount);
 for(int i = 0 ; i < itemcount ;i++){

 printf("ENTER THE NAME OF ITEM %d : ",i+1);
 scanf("%s",&items[i].name);

 printf("ENTER THE QUENTITY OF ITEM %d : ", i+1);
 scanf("%d",&items[i].quantity);

 printf("ENTER THE PRISE OF THE ITEM %d : ",i+1 );
 scanf("%f",&items[i].prise);

 items[i].total = items[i].quantity * items[i].prise;
 }
 printbill(items,itemcount);
    return 0;
}
void printbill(item items[],int itemcount){
    float grandtotal = 0.0;
printf("\n");
printf("\n%-30s%-10s%-10s%-10s%\n","ITEM NAME","QUANTITY","PRISE","TOTAL");

printline('-',60);

for(int i =0 ; i <itemcount ; i++){
    printf("%-30s%-10d%-10.2f%-10.2f%\n",items[i].name,items[i].quantity,items[i].prise,items[i].total);
    grandtotal+=items[i].total;
}
printline('=',60);
printf("%-50s%-10.2f%\n","GRANDTOTAL",grandtotal);
printline('=',60);
}
void printline(char ch , int length){
    for(int i = 0 ; i< length ; i++){
        putchar(ch);
    }
    putchar('\n');
}