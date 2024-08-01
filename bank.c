


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// defining colours by ANSI VALUES .
#define MAX_EMPLOYEE 100
#define RESET "\033[om"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define WHITE "\033[37m"
#define CYAN "\033[0;36m"

#define MAX_ACCOUNT 10

typedef struct
{
    int accountnumber;
    char name[30];
    float balance;
    char pass[21];
} Account;

Account accounts[MAX_ACCOUNT];
int Numaccounts = 0;
int lastaccno = 0;

void addaccount();
void deposit();
void withdraw();
void checkbalance();
void send_money();
void saveaccount();
void loadaccount();
void save_new_acc();
void load_new_acc();
bool check_pass(int accountno, const char *pass);
void bar(int percentage);

int main()
{
    loadaccount();
    load_new_acc();

    int choice;
    int pass;
    while (1)
    { // printf("%d",Numaccounts);
        printf("\n");
        printf(WHITE"\n\tBANK \n");
        printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _\n ");
        printf("\n");
        printf(CYAN"1. ADD ACCOUNT  \n");
        printf("2. DEPOSIT MONEY \n");
        printf("3. WITHDRAW MONEY  \n");
        printf("4. CHECK BALANCE \n");
        printf("5. SEND MONEY \n");
        printf("6. EXIT \n");
        printf("\nENTER YOUR CHOICE : ");
        scanf("%d", &choice);
        if (choice <= 0 || choice >= 7)
        {
            printf(RED"\n INVALID INPUT ");
            return 1;
        }
        switch (choice)
        {
        case 1:
            addaccount();
            break;

        case 2:
            deposit();
            break;

        case 3:
            withdraw();
            break;

        case 4:
            checkbalance();
            break;

        case 5:

            send_money();
            break;

        case 6:

            saveaccount();
            save_new_acc();
            printf("\nEXIT");
            return 0;
        }
    }
    return 0;
}
void addaccount()
{
    if (Numaccounts >= MAX_ACCOUNT)
    {
        printf(RED"\nMAX ACCOUNT REACHED .\n");
        return;
    }
    printf("\nEnter account holder name(DO NOT GIVE SPACE IF NEEDED GIVE'.'OR'_') : ");
    scanf("%s", accounts[Numaccounts].name);

    accounts[Numaccounts].accountnumber = lastaccno + 1;

    accounts[Numaccounts].balance = 0.0;
    printf(GREEN"SET YOUR PASSWORD (IT SHOULD BE OF ONLY 20 CHARACTES): ");
    scanf("%20s", accounts[Numaccounts].pass);
    lastaccno++;

    printf(CYAN"\nACCOUNT CREATED SUCCESFULLY . \n");
    printf("YOUR ACCOUNT NUMBER IS %d\n", accounts[Numaccounts].accountnumber);
    Numaccounts++;
}
void deposit()
{
    int accountno;
    float amount;
    char pass[21];
    printf("\nENTER ACCOUNT NUMBER :");
    scanf("%d", &accountno);

    getchar();
    printf(GREEN"\nENTER THE PASSWORD : ");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = '\0';

    if (!check_pass(accountno, pass))
    {
        printf(RED"WRONG PASSWORD OR ACCOUNT NUMBER .");
        return;
    }
    printf(GREEN" ACCESS GRANTED .\n");
    if (accountno < 1 || accountno > Numaccounts)
    {
        printf(RED"INVALID ACCOUNT NO %d\n", accountno);
        return;
    }
    printf(CYAN"\n ENTER AMOUNT :");
    scanf("%f", &amount);

    accounts[accountno - 1].balance += amount;
    printf("AMOUNT DEPOSITED SUCCEFULLY \n");
    printf("NEW BALANCE : %.2f \n", accounts[accountno - 1].balance);
}
void withdraw()
{
    int accountno;
    float amount;
    char pass[21];
    printf("\nENTER ACCOUNT NUMBER : ");
    scanf("%d", &accountno);
    if (accountno < 1 || accountno > Numaccounts)
    {
        printf(RED"\n INVALID ACCOUNT NUMBER %d\n", accountno);
        return;
    }
         getchar();

        printf(GREEN"\nENTER THE PASSWORD : ");
        fgets(pass, sizeof(pass), stdin);
        pass[strcspn(pass, "\n")] = '\0';

        if (!check_pass(accountno, pass))
        {
            printf(RED"WRONG PASSWORD OR ACCOUNT NUMBER .");
            return;
        }
        printf(GREEN"ACCESS GRANTED .\n");
    
    printf(CYAN"ENTER AMOUNT TO BE WITHDRAW : ");
    scanf("%f", &amount);

    if (amount < 0)
    {
        printf(RED"AMOUNT IS INVALID .\n");
        return;
    }
    if (amount > accounts[accountno - 1].balance)
    {
        printf("AMOUNT IS MORE THEN BALANCE IN YOUR ACCOUNT .\n");
        return;
    }
    accounts[accountno - 1].balance -= amount;
    printf(CYAN"\n AMOUNT WITHDRAWED SUCCESFULLY \n");
    printf("PRESENT BALANCE : %f\n", accounts[accountno - 1].balance);
}

void checkbalance()
{
    int accountno;
    char pass[21];

    printf("\n ENTER ACCOUNT NO :");
    scanf("%d", &accountno);
    if (accountno < 1 || accountno > Numaccounts)
    {
        printf(RED"INVALID ACCOUNT NUMBER .\n");
        return;
    }
    getchar();
    printf(GREEN"\nENTER THE PASSWORD : ");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = '\0';

    if (!check_pass(accountno, pass))
    {
        printf(RED"WRONG PASSWORD OR ACCOUNT NUMBER .");
        return;
    }

    printf(GREEN" ACCESS GRANTED .\n");
    
            for (int i = 0; i <= 100; i++)
            {
                bar(i);
                usleep(100000);
            }
    printf(CYAN"\n ACCOUNT HOLDER NAME : %s\n", accounts[accountno - 1].name);
    printf("CURRENT BALANCE : %2f\n", accounts[accountno - 1].balance);
}

void send_money()
{
    int sender, reciver, amount;
    char pass[21];
    printf("\nENTER YOUR ACCOUNT NUMBER : ");
    scanf("%d", &sender);
    if (sender < 1 || sender > Numaccounts)
    {
        printf(RED"INVALID ACCOUNT NUMBER .\n");
        return;
    }

    printf("ENTER RECIPIENT ACCOUNT NUMBER : ");
    scanf("%d", &reciver);

    if (reciver < 1 || reciver > Numaccounts)
    {
        printf("INVALID ACCOUNT NUMBER .\n");
        return;
    }

    printf(CYAN"\n ENTER THE AMOUNT TO SEND : ");
    scanf("%d", &amount);
    if (amount < 0)
    {
        printf(RED"\nNEGATIVE AMMOUNT CANNOT BE SEND .\n");
        return;
    }
    if (amount > accounts[sender - 1].balance)
    {
        printf(RED"INSIFICIENT AMOUNT IN YOUR ACCOUNT .");
        return ; 
    }
    getchar();
    printf(GREEN"\nENTER THE PASSWORD : ");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = '\0';

    if (!check_pass(sender, pass))
    {
        printf(RED"WRONG PASSWORD OR ACCOUNT NUMBER .");
        return;
    }

    accounts[sender - 1].balance -= amount;
    accounts[reciver - 1].balance += amount;
    
            for (int i = 0; i <= 100; i++)
            {
                bar(i);
                usleep(100000);
            }
    printf(CYAN"\nAMOUNT TRANSFERED SUCCESFULLEY .");
}

void saveaccount()
{
    FILE *fp;
    fp = fopen("bank.txt", "w"); // Open in write mode
    if (fp == NULL)
    {
        printf(RED"FAILED TO ACCESS OUR DATABASE .");
        return;
    }
    for (int i = 0; i < Numaccounts; i++)
    {
        fprintf(fp, "%d,%s,%.2f,%20s\n", accounts[i].accountnumber, accounts[i].name, accounts[i].balance, accounts[i].pass);
    }
    // printf("ACCOUNTS SAVED SUCCESSFULLY .\n");
    fclose(fp);
}

void loadaccount()
{
    FILE *fp;
    fp = fopen("bank.txt", "r");
    if (fp == NULL)
    {
        printf(RED"\nFAILED TO ACCESS OUR DATABASE. TRY AGAIN LATER.\n");
        return;
    }

    Numaccounts = 0; // Reset Numaccounts before loading
    while (Numaccounts < MAX_ACCOUNT && fscanf(fp, "%d,%s,%f,%20s", &accounts[Numaccounts].accountnumber, accounts[Numaccounts].name, &accounts[Numaccounts].balance, &accounts[Numaccounts].pass) == 3)
    {
        Numaccounts++;
    }

    fclose(fp);
    //  printf("\nDATA LOADED SUCCESSFULLY.\n");
}

void save_new_acc()
{
    FILE *fp;
    fp = fopen("new_acc.txt", "w"); // Open in write mode
    if (fp == NULL)
    {
        printf(RED"FAILED TO SAVE NEW ACCOUNT ");
        return;
    }
    fprintf(fp, "%d\n", Numaccounts);
    printf(CYAN"ACCOUNT NUMBER SAVED SUCCESSFULLY !!!\n");
    fclose(fp);
}

void load_new_acc()
{
    FILE *fp;
    fp = fopen("new_acc.txt", "r");
    if (fp == NULL)
    {
        printf(RED"FAILED TO LOAD SOME FILES. TRY AGAIN.\n");
        return;
    }
    fscanf(fp, "%d", &Numaccounts);
    fclose(fp);
}
bool check_pass(int accountno, const char *pass)
{
    if (accountno < 1 || accountno > Numaccounts)
    {
        return false;
    }
    if (strcmp(accounts[accountno - 1].pass, pass) != 0)
    {
        return false;
    }
    return true;
}
void bar(int percentage)
{
    int bar_width = 30;
    printf(YELLOW"Loading");
    int pos = bar_width * percentage / 100;
    for (int i = 0; i < bar_width; ++i)
    {
        if (i < pos)
        {
            printf(".");
        }
        else if (i == pos)
        {
            printf("!");
        }
        else
            printf(" ");
    }
    printf("|%d%%\r", percentage);
    fflush(stdout);
}
