#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<string.h>

 #define MAX_TASK_LENGTH 100

typedef struct {
    char pass[MAX_TASK_LENGTH];
    char gmail[MAX_TASK_LENGTH];
} air;

//enter
void systemenu();
void login();
void sigin();
void login_admin();

//main menu
void airoplane();
void user();
void admin();
void exitt();
//user menu
void UserBook();
void UserCancel();
void UserView_book_flight();
void UserAnnoucement();
void UserRating();
void UserExit();
void UserError();     // user default function
//admin menu
void AdminAdd();
void AdminCancel();
void AdminView_book_flight();
void AdminAnnoucement();
void AdminRating();
void AdminExit(); 
void AdminError();    // admin default function


int main(){
    int choice;

    while(choice != 3){
        system("cls");

        airoplane();

     printf("---------------------------- \n");
     printf("Enter 1 for User: \n");
     printf("---------------------------- \n\n");

     printf("---------------------------- \n");
     printf("Enter 2 for Admin: \n");
     printf("---------------------------- \n\n");

     printf("---------------------------- \n");
     printf("Enter 3 for Exit: \n");
     printf("---------------------------- \n\n");

     printf("Enter your choice: ");
     scanf("%d",&choice);
    

        switch(choice){
         case 1: systemenu();
         break;
         case 2: login_admin();
         break;
         case 3:exitt();
         break;
         default:
            system("cls");
            HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(clr,4);
            printf("Invalid syntax..!! \n\nPress any (Number key) to RESTART again.. ");
            SetConsoleTextAttribute(clr,7);  
            int error;
            scanf("%d",&error);
            
         break;
        }
        
    }

}

void systemenu(){
	int select;
	 airoplane();

     printf("---------------------------- \n");
     printf("Enter 1 for Login: \n");
     printf("---------------------------- \n\n");

     printf("---------------------------- \n");
     printf("Enter 2 for Sign in: \n");
     printf("---------------------------- \n\n");

     printf("Enter your choice: ");
     scanf("%d",&select);
    

        switch(select){
         case 1: login();
         break;
         case 2: sigin();
         break;
         default:
            system("cls");
            HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(clr,4);
            printf("Invalid syntax..!! \n\nPress any (Number key) to RESTART again.. ");
            SetConsoleTextAttribute(clr,7);  
            int error;
            scanf("%d",&error);
            
         break;
        }
        
    }
// user -------------------------------------------------------------------

void user(){
    system("cls");
     int UserChoice;

     HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);

     SetConsoleTextAttribute(clr,3);
     printf("\t\t------------------------------------- \n");
     printf("\t\t|                                   | \n");
     printf("\t\t|\tWelcome in User portal      |\n");
     printf("\t\t|                                   | \n");
     printf("\t\t------------------------------------ \n\n");
     SetConsoleTextAttribute(clr,7);

     printf("-------------------------------- \n");
     printf("Enter 1 to book flight: \n");
     printf("-------------------------------- \n\n");

     printf("-------------------------------- \n");
     printf("Enter 2 to cancel flight: \n");
     printf("-------------------------------- \n\n");

     printf("-------------------------------- \n");
     printf("Enter 3 to view booked flight: \n");
     printf("-------------------------------- \n\n");

     printf("-------------------------------- \n");
     printf("Enter 4 to read annoucement: \n");
     printf("-------------------------------- \n\n");

     printf("-------------------------------- \n");
     printf("Enter 5 to give rating: \n");
     printf("-------------------------------- \n\n");

     printf("-------------------------------- \n");
     printf("Enter 6 to Exit: \n");
     printf("-------------------------------- \n\n");
     

     printf("Enter your choice: ");
     scanf("%d",&UserChoice);

        switch(UserChoice){
         case 1: UserBook();
         break;
         case 2: UserCancel();
         break;
         case 3: UserView_book_flight();
         break;
         case 4: UserAnnoucement();
         break;
         case 5: UserRating();
         break;
         case 6: UserExit();     //completed
         break;
         default: UserError();    //completed
         break;
        }   
}
void login() {
    system("cls");

    air id;
    char stored_gmail[50], stored_pass[50];

    printf("Enter the gmail: ");
    scanf("%s", id.gmail);

    printf("Enter the password: ");
    scanf("%s", id.pass);

    FILE *fin = fopen("id.txt", "r");
    if (fin == NULL) {
        printf("User not Found!!\n");
        systemenu();
        return;
    }

    int user_found = 0;
    while (fscanf(fin, "%s %s", stored_gmail, stored_pass) != EOF) {
        printf("Checking against stored credentials: %s %s\n", stored_gmail, stored_pass); // Debugging print statement
        if (strcmp(id.gmail, stored_gmail) == 0 && strcmp(id.pass, stored_pass) == 0) {
            user_found = 1;
            break;
        }
    }
    fclose(fin);

    if (user_found) {
        system("cls");
        user();
    } else {
        system("cls");
        printf("User not Found!!\n");
        systemenu();
    }
}

void sigin(){
     system("cls");
      char password2[MAX_TASK_LENGTH];
    air id ;
    printf("Enter your gmail: ");
    scanf("%s", id.gmail);

    printf("Enter the Password: ");
    scanf("%s", id.pass);

    printf("Enter the again Password: "); 
   scanf(" %s", password2);
  if (strcmp(id.pass, password2) == 0) {
  	FILE *fout = fopen("id.txt", "a");
    if (fout == NULL) {
            printf("Error opening file!\n");
            exit(1);
        } 
        fprintf(fout, "%s\n%s\n", id.gmail , id.pass);
        fclose(fout);
        system("cls");
        systemenu();
} else{
		system("cls");
	printf("\t Try again Password didn't match........");
	sigin();
}
	
}


// user function's--------------------------

void UserBook(){
    system("cls");
    printf("user book ");
    int c;
    scanf("%d",&c);
}

void UserCancel(){
    system("cls");
    printf("user cancel");
    int c;
    scanf("%d",&c);
}
void UserView_book_flight(){
    system("cls");
    printf("user view book flight");
    int c;
    scanf("%d",&c);
}
void UserAnnoucement(){
    system("cls");
    printf("user annoucement");
    int c;
    scanf("%d",&c);
}
void UserRating(){
    system("cls");
    printf("user rating");
    int c;
    scanf("%d",&c);
}

void UserExit(){
    
    printf("\nComfirm Exit? (y/n) : ");
    char exit;
    scanf("%s",&exit);

    if(exit == 'y'){
        system("cls");   
    }
    else if(exit == 'n'){
         user();
    }
    else{
         HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);
         SetConsoleTextAttribute(clr,4);  
         printf("invalid systax..! \nPress (1) to restart user portal... ");
         SetConsoleTextAttribute(clr,7);  
         int reuser;
         scanf("%d",&reuser);
         if(reuser == 1){
           user();
         }system("cls");
    }
}

void UserError(){       // user default function

    HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(clr,4);  
    printf("invalid systax..! \nPress (1) to restart user portal... ");
    SetConsoleTextAttribute(clr,7);  
    int reuser;
    scanf("%d",&reuser);
    if(reuser == 1){
      user();
    }system("cls");

}

// user function end-------------------------------


//admin-------------------------------------------------

void login_admin() {
    system("cls");

    air id2;
    char stored_gmail[50], stored_pass[50];

    printf("Enter the gmail: ");
    scanf("%s", id2.gmail);

    printf("Enter the password: ");
    scanf("%s", id2.pass);

    FILE *fin = fopen("id2.txt", "r");
    if (fin == NULL) {
        printf("ID not Found!!\n");
        return;
    }

    int user_found = 0;
    while (fscanf(fin, "%s %s", stored_gmail, stored_pass) != EOF) {
        printf("Checking against stored credentials: %s %s\n", stored_gmail, stored_pass); // Debugging print statement
        if (strcmp(id2.gmail, stored_gmail) == 0 && strcmp(id2.pass, stored_pass) == 0) {
            user_found = 1;
            break;
        }
    }
    fclose(fin);

    if (user_found) {
        system("cls");
        admin();
    } else {
        system("cls");
        printf("Id not Found!!\n");
    }
}

void admin(){
    system("cls");
     int AdminChoice;

     HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);

     SetConsoleTextAttribute(clr,3);
     printf("\t\t------------------------------------- \n");
     printf("\t\t|                                   | \n");
     printf("\t\t|\tWelcome in Admin portal     |\n");
     printf("\t\t|                                   | \n");
     printf("\t\t------------------------------------ \n\n");
     SetConsoleTextAttribute(clr,7);

     printf("-------------------------------- \n");
     printf("Enter 1 to book flight: \n");
     printf("-------------------------------- \n\n");

     printf("-------------------------------- \n");
     printf("Enter 2 to cancel flight: \n");
     printf("-------------------------------- \n\n");

     printf("-------------------------------- \n");
     printf("Enter 3 to view booked flight: \n");
     printf("-------------------------------- \n\n");

     printf("-------------------------------- \n");
     printf("Enter 4 to read annoucement: \n");
     printf("-------------------------------- \n\n");

     printf("-------------------------------- \n");
     printf("Enter 5 to give rating: \n");
     printf("-------------------------------- \n\n");

     printf("-------------------------------- \n");
     printf("Enter 6 to Exit: \n");
     printf("-------------------------------- \n\n");
     

     printf("Enter your choice: ");
     scanf("%d",&AdminChoice);

        switch(AdminChoice){
         case 1: AdminAdd();
         break;
         case 2: AdminCancel();
         break;
         case 3: AdminView_book_flight();
         break;
         case 4: AdminAnnoucement();
         break;
         case 5: AdminRating();
         break;
         case 6: AdminExit();    //completed
         break;
         default: AdminError();    //completed
         break;
        }   

}

//Admin function's-------------------------------------

void AdminAdd(){
    system("cls");
    printf("Admin add");
    int a;
    scanf("%d",&a);
}
void AdminCancel(){
    system("cls");
    printf("Admin cancel");
    int a;
    scanf("%d",&a);
}
void AdminView_book_flight(){
    system("cls");
    printf("Admin view book flight");
    int a;
    scanf("%d",&a);
}
void AdminAnnoucement(){
    system("cls");
    printf("Admin announcement");
    int a;
    scanf("%d",&a);
}
void AdminRating(){
    system("cls");
    printf("Admin rating");
    int a;
    scanf("%d",&a);
}

void AdminExit(){

    printf("\nComfirm Exit? (y/n) : ");
    char exit;
    scanf("%s",&exit);

    if(exit == 'y'){
        system("cls");   
    }
    else if(exit == 'n'){
         admin();
    }
    else{
         HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);
         SetConsoleTextAttribute(clr,4);  
         printf("invalid systax..! \nPress (1) to restart admin portal... ");
         SetConsoleTextAttribute(clr,7);  
         int readmin;
         scanf("%d",&readmin);
         if(readmin == 1){
           admin();
         }system("cls");
    }
}
void AdminError(){   //admin default function

    HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(clr,4);  
    printf("invalid systax..! \nPress (1) to restart admin portal... ");
    SetConsoleTextAttribute(clr,7);  
    int readmin;
    scanf("%d",&readmin);
    if(readmin == 1){
      admin();
    }system("cls");
}




// exit----main----------------------------------------------------------------------
void exitt(){
    system("cls");
    HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(clr,6);
    printf("VISIT AGAIN..!! \n");
    SetConsoleTextAttribute(clr,7);
}
// exit----main----ended------------------------------------------------------------------

void airoplane(){

    HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(clr,1);
    printf("\t\t\t                            | \n");
    SetConsoleTextAttribute(clr,2);
    printf("\t\t\t                           _|_  \n");
    SetConsoleTextAttribute(clr,3);
    printf("\t\t\t                         / ___ \\ \n");
    SetConsoleTextAttribute(clr,4);
    printf("\t\t\t                        /oo   oo\\ \n");
    SetConsoleTextAttribute(clr,5);
    printf("\t\t\t\\_______________________\\       /_______________________/ \n");
    SetConsoleTextAttribute(clr,6);
    printf("\t\t\t  `-----|--------|-------\\_____/-----|--------|-------' \n");
    SetConsoleTextAttribute(clr,1);
    printf("\t\t\t     ( )    ( )         ()oo|oo()        ( )     ( )  \n");
    printf("\n");
    SetConsoleTextAttribute(clr,2);
    printf("\t\t\t\t  WELCOME TO AIRLINE MANAGEMENT SYSTEM  \n\n\n");

    SetConsoleTextAttribute(clr,7);

}
