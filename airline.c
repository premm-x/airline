#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<string.h>

 #define MAX_TASK_LENGTH 100

typedef struct {
    char pass[MAX_TASK_LENGTH];
    char gmail[MAX_TASK_LENGTH];
} air;

typedef struct {
	char name [MAX_TASK_LENGTH];
	int date ;
	int plane_number ;	
}fly;

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
//flight functions
void recent_flights();
void search_flight();
void booking();

void main() {
    int choice = 0;

    while (choice != 3) {
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
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("cls");
                // systemenu();
                user();
                break;
            case 2:
                //login_
                admin();
                break;
            case 3:
                exitt();
                break;
            default:
                system("cls");
                HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(clr, 4);
                printf("Invalid syntax..!! \n\nPress any (Number key) to RESTART again.. ");
                SetConsoleTextAttribute(clr, 7);  
                int error;
                scanf("%d", &error);
                break;
        }
    }
}


void systemenu(){
	int select;
    system("cls");
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

     SetConsoleTextAttribute(clr,2);
     printf("\t\t     -~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~-~- \n");
     printf("\t\t    /                                    \\ \n");
     printf("\t\t-~<{\t    Welcome in User portal        }>~-\n");
     printf("\t\t    \\                                    / \n");
     printf("\t\t     -~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~-~- \n\n");
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
     printf("Enter 5 to Exit: \n");
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
         case 5: UserExit();     //completed
         break;
         default: UserError();    //completed
         break;
        }   
}
void login() {
    system("cls");

    HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);

     SetConsoleTextAttribute(clr,6);
     printf("\t\t  -~-~-~-~-~--~-~-~-~-~-~-~-~- \n");
     printf("\t\t<(\t    User Login        )>\n");
     printf("\t\t  -~-~-~-~-~--~-~-~-~-~-~-~-~- \n\n");
     SetConsoleTextAttribute(clr,7);

    air id;
    char stored_gmail[50], stored_pass[50];

    printf("Enter the gmail: ");
    scanf("%s", id.gmail);

    printf("Enter the password: ");
    scanf("%s", id.pass);

    FILE *fin = fopen("id.txt", "r");
    if (fin == NULL) {
        printf("User not Found!!\n");

        printf("\nComfirm Exit? (y/n) : ");
        char exit;
        scanf("%s",&exit);

        if(exit == 'y'){
        systemenu();   
        }
        else if(exit == 'n'){
         login();
        }
        else{
         HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);
         SetConsoleTextAttribute(clr,4);  
         printf("invalid systax..! \nPress (1) to restart Login page... ");
         SetConsoleTextAttribute(clr,7);  
         int reuser;
         scanf("%d",&reuser);
         if(reuser == 1){
           systemenu();
         }system("cls");
        }
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
     
     HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);

     SetConsoleTextAttribute(clr,6);
     printf("\t\t  -~-~-~-~-~--~-~-~-~-~-~-~-~- \n");
     printf("\t\t<(\t    User SignUp        )>\n");
     printf("\t\t  -~-~-~-~-~--~-~-~-~-~-~-~-~- \n\n");
     SetConsoleTextAttribute(clr,7);

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
	printf("\t Try again Password didn't match........\n\n");

    printf("\nComfirm Exit? (y/n) : ");
        char exit;
        scanf("%s",&exit);

        if(exit == 'y'){
        systemenu();   
        }
        else if(exit == 'n'){
         sigin();
        }
        else{
         HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);
         SetConsoleTextAttribute(clr,4);  
         printf("invalid systax..! \nPress (1) to restart Login page... ");
         SetConsoleTextAttribute(clr,7);  
         int reuser;
         scanf("%d",&reuser);
         if(reuser == 1){
           systemenu();
         }system("cls");
        }

}
	
}


// user function's--------------------------

void UserBook() {
    int select;
    system("cls");

    HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(clr,6);
     printf("\t\t  -~-~-~-~-~--~-~-~-~-~-~-~-~- \n");
     printf("\t\t<(\t    Book Flight        )>\n");
     printf("\t\t  -~-~-~-~-~--~-~-~-~-~-~-~-~- \n\n");
     SetConsoleTextAttribute(clr,7);

    printf("---------------------------------- \n");
    printf("Enter 1 to see Available: \n");
    printf("---------------------------------- \n\n");

    printf("-------------------------------------------- \n");
    printf("Enter 2 to Search flight for specific date : \n");
    printf("-------------------------------------------- \n\n");

    printf("-------------------------------- \n");
    printf("Enter 3 for exit: \n");
    printf("-------------------------------- \n\n");

    printf("Enter your choice: ");
    scanf("%d", &select);

    switch (select) {
        case 1:
            recent_flights();
            break;
        case 2:
            search_flight();
            break;
        case 3:
            user();
            break;
        default:
            UserError();
            break;
    }
}
 
void  recent_flights(){
	  system("cls");
    fly flight;
   	printf("Plane\t\tdate\t\t\tName\nnumber\n");
    FILE *fin = fopen("flight.txt", "r");
    if (!fin) {
        system("cls");
        printf("name: Empty..!!\n");
        
        printf("\nComfirm Exit? (y/n) : ");
        char exit;
        scanf("%s",&exit);

        if(exit == 'y'){
        user();   
        }
        else if(exit == 'n'){
         recent_flights();
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
        return;
    }

  while (fscanf(fin, "%d %d %s", &flight.plane_number, &flight.date, flight.name) != EOF) {
        printf("\n%d \t\t%d \t\t%s", flight.plane_number, flight.date, flight.name);
        }
    fclose(fin);

    char book;
    printf("\nDo you want to book flight? (y/n)\n");
    scanf(" %c", &book);
    if (book != 'y') {
       UserBook();
    }
      booking(); 
}



void search_flight(){
    system("cls");
    fly flight;
    int date;
    printf("Enter the date: ");
    scanf("%d", &date);

    if(date >= 4 && date <= 8) {
        FILE *fin = fopen("flight.txt", "r");
        if (!fin) {
            printf("Not found !!\n");
            return;
        }

        while (fscanf(fin, "%d %d %s", &flight.plane_number, flight.date, flight.name) != EOF) {
            printf("Plane\t\tDate\t\t\tName\nnumber\n");
            if (flight.date == date) {
                system("cls");
                printf("\n%d \t\t%d \t\t%s", flight.plane_number, flight.date, flight.name);
                fclose(fin);
                return;
            }
        }
        fclose(fin);
    } else {
        system("cls");
        printf("\n\n\n\t\t coming soon..........!");  
        scanf("%d",&date);
        system("cls");
        UserBook();    
    }

    char book;
    printf("\n\nExit? (y/n)\n");
    scanf(" %c", &book);
    if (book != 'y') {
       UserBook();
    }
}

void booking(){
	int num;
	printf("Enter the plane number:");
	  scanf("%d", &num);
    fly flight ;
    FILE *fin = fopen("flight.txt", "r");
    if (!fin) {
        printf("Error opening file.\n");
        return;
    }
    char book;
    printf("you want to book this flight? (y/n)\n");
    scanf(" %c", &book);
    
    if (book == 'y') {
        FILE *tempfile = fopen("myflight.txt", "w");
        
         while (fscanf(fin, "%d %d %s", &flight.plane_number, &flight.date, flight.name) != EOF) { 
            if (flight.plane_number == num) {
                fprintf(tempfile, "\n%d \t\t%d \t\t%s", flight.plane_number, flight.date, flight.name); 
            }
        }
        fclose(fin);
        fclose(tempfile); 
        system("cls");
        printf("booketed Successfully..!\n");
         UserBook();
    } else {
        system("cls");
        printf("Not booketed\n");
         UserBook();
    }
}

void UserCancel(){
    system("cls");

    HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);

     SetConsoleTextAttribute(clr,6);
     printf("\t\t  -~-~-~-~-~--~-~-~-~-~-~-~-~-~-~- \n");
     printf("\t\t<(\t Cancel the Flight        )>\n");
     printf("\t\t  -~-~-~-~-~--~-~-~-~-~-~-~-~-~-~- \n\n");
     SetConsoleTextAttribute(clr,7);

    fly flight;
   	printf("Plane\t\tDate\t\t\tName\nnumber \n");
    FILE *fin = fopen("myflight.txt", "r");
    if (!fin) {
        system("cls");
        printf("name: Empty..!!\n");

        printf("\nComfirm Exit? (y/n) : ");
        char exit;
        scanf("%s",&exit);

        if(exit == 'y'){
        user();   
        }
        else if(exit == 'n'){
         UserCancel();
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
        return;
    }

   while (fscanf(fin, "%d %d %s", &flight.plane_number, &flight.date, flight.name) != EOF) { 
        printf("\n%d \t\t%d \t\t%s", flight.plane_number, flight.date, flight.name); 
    }
    fclose(fin);
    
    printf("\n\nEnter the plane number which you wanted to delete ");
    int num;
    scanf("%d",&num);
    char delete;
    printf("\nyou want to book this flight? (y/n)\n");
    scanf(" %c", &delete);
    
    if (delete == 'y') {
        FILE *tempfile = fopen("temp.txt", "w");

        fin = fopen("myflight.txt", "r");
        while (fscanf(fin, "%d %d %s", &flight.plane_number, &flight.date, flight.name) != EOF) { 
            if (flight.plane_number != num) {
                fprintf(tempfile, "\n%d \t\t%d \t\t%s", flight.plane_number, flight.date, flight.name);
            }
        }
        fclose(fin);
        fclose(tempfile);
        remove("myflight.txt");
        rename("temp.txt", "myflight.txt");
        system("cls");
        printf("cancelled Successfully..!\n");
         UserBook();
    } else {
        system("cls");
        printf("Not cancelled\n");
         UserBook();
    }
}
void UserView_book_flight(){
    system("cls");
    
    HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);

     SetConsoleTextAttribute(clr,6);
     printf("\t\t  -~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~-~-~-~- \n");
     printf("\t\t<(\t    View the booking Flight       )>\n");
     printf("\t\t  -~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~-~-~-~- \n\n");
     SetConsoleTextAttribute(clr,7);

    fly flight;
    printf("Plane\t\tDate\t\t\tName\nnumber\n");
    FILE *fin = fopen("myflight.txt", "r");
    if (!fin) {
        system("cls");
        printf("name: Empty..!!\n");

        return;
    }

    while (fscanf(fin, "%d %d %s", &flight.plane_number, &flight.date, flight.name) != EOF) { 
        if (strlen(flight.name) > 0) {
            printf("%d \t\t%d \t\t%s", flight.plane_number, flight.date, flight.name); 
        } else {
            printf("Empty..!!\n");
        }
    }
    fclose(fin);
    
    
    printf("\n\nComfirm Exit? (y/n) : ");
        char exit;
        scanf("%s",&exit);

        if(exit == 'y'){
        user();   
        }
        else if(exit == 'n'){
         UserView_book_flight();
        }
        else{
         HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);
         SetConsoleTextAttribute(clr,4);  
         printf("invalid systax..! \nPress (1) to restart the page... ");
         SetConsoleTextAttribute(clr,7);  
         int reuser;
         scanf("%d",&reuser);
         if(reuser == 1){
           UserView_book_flight();
         }system("cls");
        }
   
}
void UserAnnoucement(){
    system("cls");
    printf("user annoucement");
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

     SetConsoleTextAttribute(clr,1);
     printf("\t\t     -~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~-~- \n");
     printf("\t\t    /                                    \\ \n");
     printf("\t\t-~<{\t    Welcome in Admin portal       }>~-\n");
     printf("\t\t    \\                                    / \n");
     printf("\t\t     -~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~-~- \n\n");
     SetConsoleTextAttribute(clr,7);

     printf("-------------------------------- \n");
     printf("Enter 1 to book flight: \n");
     printf("-------------------------------- \n\n");

     printf("-------------------------------- \n");
     printf("Enter 2 to cancel flight: \n");
     printf("-------------------------------- \n\n");

     printf("-------------------------------- \n");
     printf("Enter 3 to List of flight: \n");
     printf("-------------------------------- \n\n");

     printf("-------------------------------- \n");
     printf("Enter 4 to read annoucement: \n");
     printf("-------------------------------- \n\n");

     printf("-------------------------------- \n");
     printf("Enter 5 to Exit: \n");
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
         case 5: AdminExit();    //completed
         break;
         default: AdminError();    //completed
         break;
        }   

}

//Admin function's-------------------------------------

void AdminAdd(){
    system("cls");
    
    HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);

     SetConsoleTextAttribute(clr,6);
     printf("\t\t  -~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~-~-~-~- \n");
     printf("\t\t<(\t    Add Flight for booking        )>\n");
     printf("\t\t  -~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~-~-~-~- \n\n");
     SetConsoleTextAttribute(clr,7);

    fly flight;
    printf("Enter the flight name :");
    scanf("%s", flight.name);
    
    printf("Enter the flight date: ");
    scanf("%d", &flight.date);

    printf("Enter the flight number: ");
    scanf("%d", &flight.plane_number);

    FILE *fout = fopen("flight.txt", "a");
    fprintf(fout, "\n%d\t\t%d\t\t\t%s", flight.plane_number, flight.date, flight.name);
    fclose(fout);

    char con;

    printf("\n\nWant to add more (y/n) ");
    scanf(" %c", &con);
    if (con == 'y') {
        AdminAdd();
    } else {
        admin();
    }
}

void AdminCancel(){
   system("cls");

   HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);

     SetConsoleTextAttribute(clr,6);
     printf("\t\t  -~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~-~-~-~- \n");
     printf("\t\t<(\t    Cancel Flight        )>\n");
     printf("\t\t  -~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~-~-~-~- \n\n");
     SetConsoleTextAttribute(clr,7);

    fly flight;
   	printf("Plane\t\tDate\t\t\tName\nnumber \n");
    FILE *fin = fopen("myflight.txt", "r");
    if (!fin) {
        printf("name: Empty..!!\n");
        return;
    }

   while (fscanf(fin, "%d %d %s", &flight.plane_number, &flight.date, flight.name) != EOF) { 
        printf("\n%d \t\t%d \t\t%s", flight.plane_number, flight.date, flight.name); 
    }
    fclose(fin);
    
    printf("Enter the plane number which you wanted to cancel : ");
    int num;
    scanf("%d",&num);
    char delete;
    printf("you want to cancel this flight? (y/n)\n");
    scanf(" %c", &delete);
    
    if (delete == 'y') {
    	char reason[MAX_TASK_LENGTH];
    	printf("Enter the reason for why flight got cancelled :");
    	scanf("%[^\n]%c", reason);
        FILE *tempfile = fopen("temp.txt", "w");
        
        fin = fopen("flight.txt", "r");
        while (fscanf(fin, "%d %d %s", &flight.plane_number, &flight.date, flight.name) != EOF) { 
            if (flight.plane_number != num) {
                fprintf(tempfile, "\n%d \t\t%d \t\t%s", flight.plane_number, flight.date, flight.name);
            }
             else  {
                fprintf(tempfile, "Cancelled \t\t%d \t\t%s ( %s )", flight.date, flight.name, reason);
            }
        }
        fclose(fin);
        fclose(tempfile);
        remove("myflight.txt");
        rename("temp.txt", "myflight.txt");
        system("cls");
        printf("cancelled Successfully..!\n");
         admin();
    } else {
        system("cls");
        printf("Not cancelled\n");
        admin();
    };
}
void AdminView_book_flight(){
    system("cls");

    HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);

     SetConsoleTextAttribute(clr,6);
     printf("\t\t  -~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~-~-~-~- \n");
     printf("\t\t<(\t    View Added Flight        )>\n");
     printf("\t\t  -~-~-~-~-~--~-~-~-~-~-~-~-~-~-~-~-~-~-~- \n\n");
     SetConsoleTextAttribute(clr,7);

    fly flight;
   	printf("Plane\t\tdate\t\t\tName\nnumber\n");
    FILE *fin = fopen("flight.txt", "r");
    if (!fin) {
        printf("name: Empty..!!\n");
        return;
    }

  while (fscanf(fin, "%d %d %s", &flight.plane_number, &flight.date, flight.name) != EOF) {
        printf("\n%d \t\t%d \t\t%s", flight.plane_number, flight.date, flight.name);
        }
    fclose(fin);

    char book;
    printf("\n\nExit? (y/n)\n");
    scanf(" %c", &book);
    if (book != 'y') {
       AdminView_book_flight();
    }
     admin(); 
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

void airoplane() {
    HANDLE clr = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(clr, 1);
    printf("\t\t\t                            | \n");
    SetConsoleTextAttribute(clr, 2);
    printf("\t\t\t                           _|_  \n");
    SetConsoleTextAttribute(clr, 3);
    printf("\t\t\t                         / ___ \\ \n");
    SetConsoleTextAttribute(clr, 4);
    printf("\t\t\t                        /oo   oo\\ \n");
    SetConsoleTextAttribute(clr, 5);
    printf("\t\t\t\\_______________________\\       /_______________________/ \n");
    SetConsoleTextAttribute(clr, 6);
    printf("\t\t\t  `-----|--------|-------\\_____/-----|--------|-------' \n");
    SetConsoleTextAttribute(clr, 1);
    printf("\t\t\t     ( )    ( )         ()oo|oo()        ( )     ( )  \n");
    printf("\n");
    SetConsoleTextAttribute(clr, 2);
    printf("\t\t\t\t  WELCOME TO AIRLINE MANAGEMENT SYSTEM  \n\n\n");

    SetConsoleTextAttribute(clr, 7);
}
