#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>


void login();
void book_ticket();
void menu();
void logout();
void display_ticket();
void cancel_ticket();



struct ticket {
    char name[20];
    char age;
    char gender[10];
    char source[20];
    char destination[20];
    char train_no[10];
};

struct ticket t[50];
int n = 0;

int is_authenticated = 0;

void login() {

    int choice;
    char username[20], password[20];

    printf("\n\t================================================================================\n");
    
    printf("\t-----> Enter your username: ");
    scanf("%s", username);
    
    printf("\t-----> Enter your password: ");
    scanf("%s", password);
    
    printf("\n\t================================================================================\n");

    // Check if the username and password match
    if (strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0) {
        printf("\t-----> Login successful!");
        printf("\n\t================================================================================\n");
        menu();

    
    } else {
        printf("\t-----> Invalid username or password.\n");
    }

       
}

void book_ticket() {

    FILE *fp;
    char name[20];
    char age[20];
    char gender[15];
    char source[100];
    char destination[100];
    char train_no[10];
    
        if (n < 50) {
            printf("\n\t================================================================================\n");
            printf("\t-----> Enter passenger details:");
            printf("\n\t================================================================================\n");
            fp = fopen("details.txt","a"); 
            printf("\t-----> Name: ");
            scanf("%s",name);
            fprintf(fp,"%s ",name);
            printf("\t-----> Age: ");
            scanf("%s", age);
            fprintf(fp,"%s ",age);
            printf("\t-----> Gender: ");
            scanf("%s", gender);
            fprintf(fp,"%s ",gender);
            printf("\t-----> Source: ");
            scanf("%s", source);
            fprintf(fp,"%s ",source);
            printf("\t-----> Destination: ");
            scanf("%s", destination);
            fprintf(fp,"%s ",destination);
            printf("\t-----> Train number: ");
            scanf("%s",train_no);
            fprintf(fp,"%s\n ",train_no);
            fclose(fp);
            n++;
            printf("\n\t================================================================================\n");
            printf("\t-----> Ticket booked successfully.\n");
            printf("\t================================================================================\n");
        } 
        else {
            printf("\n\t================================================================================\n");
            printf("\t-----> Ticket booking not possible. All tickets sold out.\n");
            printf("\n\t================================================================================\n");
        }
    }


void cancel_ticket() {
   


    FILE *fp;
    FILE *tempFile;
    char name[20];
    char age[20];
    char gender[15];
    char source[100];
    char destination[100];
    char train_no[10];
    char trainName[10];
    char DelName[20];
            

    fp = fopen("details.txt", "r");
    tempFile = fopen("temp.txt", "w");

    if (fp == NULL || tempFile == NULL) {
        printf("Failed to open the file.\n");
        return;

    }
    printf("\n\t================================================================================\n");
    printf("\t-----> Enter the TRAIN NAME to DELETE: ");
    scanf("%s",trainName);
    printf("\t-----> Enter the NAME of PASSENGER: ");
    scanf("%s",DelName);
    printf("\n\t================================================================================\n");
    
    int found = 0;

    while (fscanf(fp, "%s %s %s %s %s %s",name, age,gender, source,destination,train_no) != EOF) {
        if (strcmp(train_no, trainName) == 0 && strcmp(name, DelName) ==0 ) {
            found = 1;
            continue;
        }

        fprintf(tempFile, "%s %s %s %s %s %s", name, age,gender, source,destination,train_no);
    }

    fclose(fp);
    fclose(tempFile);

    if (found) {
        remove("details.txt");
        rename("temp.txt", "details.txt");
        printf("\n\t================================================================================\n");
        printf("\t-----> Train deleted successfully.");
        printf("\n\tREFUND will be initiated in 42 WORKING HOURS.");
        printf("\n\t================================================================================\n");
    } else {
        remove("temp.txt");
        printf("\n\t================================================================================\n");
        printf("\t-----> Train not found.\n");
        printf("\n\t================================================================================\n");

    }
   
}

void display_ticket() {
        int i;
        FILE *fp;
        char name [20];
        char age[20];
        char gender[15];
        char source[100];
        char destination[100];
        char train_no[10];

        
        fp = fopen("details.txt","r"); 
        printf("\n\t================================================================================");
        printf("\n\t-----> Tickets Information");
        printf("\n\t================================================================================\n");
        
        while(fscanf(fp, "%s %s %s %s %s %s ",name,age,gender,source,destination,train_no) != EOF)
        {
        printf("\n\tNAME         :%s",  name);
        printf("\n\tAGE          :%s",  age);
        printf("\n\tGENDER       :%s",  gender);
        printf("\n\tSOURCE       :%s",  source);
        printf("\n\tDESTINATION  :%s",  destination);
        printf("\n\tTRAIN NO.    :%s",  train_no);
        printf("\n\t---------------------------------------------------------------------------------\n");
        printf("\t---------------------------------------------------------------------------------\n");
        }
         fclose(fp);
         printf("\n\t================================================================================\n\n\n\n\n");
    
    
}
void logout() {
        printf("\n\t================================================================================\n");
        printf("\t-----> Thanks For Visiting our system");  
        printf("\n\t================================================================================\n");
}

void menu() {
        int choice;
        do{
        printf("\n\n\t================================================================================\n");
        printf("\t|                                  MAIN MENU                                   |\n");
        printf("\t================================================================================\n");

        printf("\t-----> 1. Book Ticket\n");
        printf("\t-----> 2. Cancel Ticket\n");
        printf("\t-----> 3. Display Tickets Information\n");
        printf("\t-----> 4. Exit\n");
        printf("\t-----> Enter your choice: ");
        scanf("%d", &choice);
        printf("\n\t================================================================================\n\n");


    switch (choice) {
        case 1:
            book_ticket();
            break;
        case 2:
            cancel_ticket();
            break;
        case 3:
            display_ticket();
            break;
        case 4:
            printf("\t-----> Thank You for using Railway Management System...!\n");
            break;
        default:
            printf("\t-----> Invalid choice.\n");
            break;
        }  
    }while (choice != 4);
        printf("\n\t================================================================================\n");
}

int main() {
    int choice;
    

    do {
        printf("\n\t|||||||||||[][][][][][][][][][][][][][][][][][][][][][][][][][][][][]|||||||||||");
        printf("\n\t||||||||||[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]||||||||||");
        printf("\n\t|||||||||||[]                                              [][][][][]|||||||||||");
        printf("\n\t|||||||||||[]    WELCOME TO Railway Management System      [][][][][][]|||||||||");
        printf("\n\t|||||||||||[]                                              [][][][][]|||||||||||");
        printf("\n\t||||||||||[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]||||||||||");
        printf("\n\t|||||||||||[][][][][][][][][][][][][][][][][][][][][][][][][][][][][]|||||||||||\n\n");   
        printf("\t================================================================================\n");
        printf("\t-----> 1. Login\n");
        printf("\t-----> 2. Logout\n");
        printf("\t-----> Enter your choice: ");
        scanf("%d", &choice);
        printf("\n\t================================================================================\n");


    switch (choice) {
        case 1:
            login();
            break;
        case 2:
            logout();
            break;
        default:
            printf("\t-----> Invalid choice.\n");
            break;
    }
} while (choice != 2);

return 0;
}

