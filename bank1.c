#include <stdio.h>
#include <stdlib.h>
#include "bankfunc.h"

typedef struct{
	int accountNumber;
	char firstName[25];
	char middleName[25];
	char lastName[25];
	float accountBalance;
} addressbook;

void addAccount();
void viewAccounts();
void insert();
void deposit(int depo);
void withdrawal(int draw);
void deleteAccount(int delete);
void balance();

addressbook a[0];
FILE *pFile;
FILE *fFile;
int count = 0;

int main(){
int option;
int depos, draw, delete;
do{
printf("0) Exit\n");
printf("1) Deposit\n");
printf("2) Withdrawal\n");
printf("3) Add account\n");
printf("4) Remove account\n");
printf("5) Balance inquiry\n");
printf("6) View accounts\n");
printf("Choose the option: ");
scanf("%d", &option);
switch (option){
   case 0: printf("Exit");
   break;
   case 1: printf("Enter account number to deposit: ");
   scanf("%d", &depos);
   deposit(depos);
   break;
   case 2: printf("Enter account number to withdraw: ");
   scanf("%d", &draw);
   withdrawal(draw);
   break;
   case 3: addAccount();
   break;
   case 4: printf("Enter account number to remove: ");
   scanf("%d", &delete);
   deleteAccount(delete);
   break;
   case 5: balance();
   break;
   case 6:insert();
	viewAccounts();
   break;
   default: printf("Choose correct option: ");
   break;
}
}while(option != 0);

return 0;
}

void addAccount()
{
	pFile = fopen("accounts.dat","ab+");
	if(pFile == NULL){
		perror("Error!");
		pFile = fopen("accounts.dat", "ab+");
		if(pFile == NULL){
			perror("Error!");
			exit(1);
		}
	}
	int i;
	for(i=0; i<1 ; i++){
		printf("Enter Details\n");
		printf("Enter First Name: \n");
		scanf("%s", a[count].firstName);
		printf("Enter Middle Name: \n");
		scanf("%s", a[count].middleName);
    		printf("Enter Last Name: \n");
    		scanf("%s", a[count].lastName);
    		printf("Please enter 6 digit account number: \n");
    		scanf("%d", &a[count].accountNumber);
    		printf("Enter Balance: \n");
    		scanf("%f", &a[count].accountBalance);
    		fwrite(&a[count], sizeof(a), 1, pFile);
	}
	fclose(pFile);
	count = count + 1;
}


void viewAccounts(){
	fopen("accounts.dat", "ab+");
	if(pFile == NULL){
		perror("Error!");
		pFile = fopen("accounts.dat", "ab+");
	if(pFile == NULL){
		perror("Error!");
		exit(1);
	}
	}
	printf(" Open an account today!\n");
	int i;
	for(i=0; i<count; i++){
		fread(&a[i], sizeof(a), 1, pFile );
		printf("Account: %d\n", a[i].accountNumber);
		printf(" Name: %s ", a[i].firstName);
		printf("%s", a[i].middleName);
		printf(" %s\n", a[i].lastName);
		printf(" Balance: %.2f\n", a[i].accountBalance);
		printf("\n");
	}
	fclose(pFile);
	}

void deposit(int depo){
	int new, past;
	int i, c;
	fopen("accounts.dat", "r+");
	for(i = 0; i < count; i++){
		fread(&a[i], sizeof(a), 1,pFile);
    if(a[i].accountNumber == depo){
    		past = a[i].accountBalance;
    		printf("Enter deposit amount: ");
    		scanf("%d", &new);
    		new += past;
    		a[i].accountBalance = new;
    		c = fwrite(&a[i].accountBalance, 25, 1, pFile);
    }
	}
	if(c == 1){
		printf("Success.\n");
	}
	else{
		printf("Fail.\n");
		printf("Enter Account Number\n");
	}
	fclose(pFile);
}

void withdrawal(int draw){
	int new, past;
	int i, c;
	fopen("accounts.dat", "r+");
	for(i = 0; i < count; i++){
		fread(&a[i], sizeof(a), 1, pFile);
		if(a[i].accountNumber == draw){
			past = a[i].accountBalance;
			printf("Enter Withdrawal Amount: ");
			scanf("%d", &new);
			past -= new;
			a[i].accountBalance = past;
			c = fwrite(&a[i].accountBalance, 25, 1, pFile);
		}
	}
	if(c == 1){
		printf("Success\n");
	}
	else{
		printf("Fail\n");
		printf("Enter Account Number\n");
	}
	fclose(pFile);
}

void deleteAccount(int delete){
	int i, c=0;
	fopen("accounts.dat", "r+");
	for(i = 0; i < count; i++){
		fFile=fopen("tmp.dat", "a+");
		fread(&a[i], sizeof(a), 1, pFile );
		if(a[i].accountNumber == delete){
			printf("Account removed!\n");
			c = 1;
		}
    else{
      fwrite(&a[i], sizeof(a), 1, fFile);
    }
	}
	if(c == 0){
		printf("No records found!\n");
	}
	fclose(pFile);
	fclose(fFile);
	remove("accounts.dat");
	count--;
}

void balance(){
        int new, acc, i, c=0, count=0;
        printf("Enter account number: ");
        scanf("%d", &acc);
        fopen("accounts.dat", "r");
        for(i=0; i<count; i++){
                fread(&a[i], sizeof(a), 1, pFile);
                new = a[i].accountNumber;
                if(new == acc){
                        printf("Account: %d\n", a[i].accountNumber);
                        printf(" Name: %s ", a[i].firstName);
                        printf("%s", a[i].middleName);
                        printf(" %s\n", a[i].lastName);
                        printf(" Balance: %.2f\n", a[i].accountBalance);
                        c=1;
                }
                printf("\n");
                if(c == 0){
                        printf("Enter Account Number\n");
                }
        }
        fclose(pFile);
        }

