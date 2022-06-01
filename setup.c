#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define size 15


int itemCount = 10;
int total = 0;

typedef struct users{
    char name[50];
    char userName[50];
    char email[50];
    int password;
    int  mobile;
} *user;

int chain[size];

typedef struct menus{
    char name[50];
    int  amount;
    struct menus *next;
} *menu;

typedef struct trees{
    char name[50];
    int  amount;
    struct trees *left;
    struct trees *right;
} *tree;

tree root = NULL;      //initialising root for tree which stores the items ordered
// Function:     Initialser
// Description:  Initialize the chain of users by /-1
// Input param:  NULL
// Return Type:  NULL
void init(){
    for(int i = 0 ; i < size ; i++){
        chain[i] = -1;
    }

}



// Function:     validateUser
// Description:  validate the data of new user whether it exists or not
// Input param:  structure which contains of new user details
// Return Type:  boolean

menu dummyData(){
//first
menu data1 = (menu)malloc(sizeof(struct menus));
menu data2 = (menu)malloc(sizeof(struct menus));
menu data3 = (menu)malloc(sizeof(struct menus));
menu data4 = (menu)malloc(sizeof(struct menus));
menu data5 = (menu)malloc(sizeof(struct menus));
menu data6 = (menu)malloc(sizeof(struct menus));
menu data7 = (menu)malloc(sizeof(struct menus));
menu data8 = (menu)malloc(sizeof(struct menus));
menu data9 = (menu)malloc(sizeof(struct menus));
menu data10 = (menu)malloc(sizeof(struct menus));
strcpy(data10->name , "Noodles");
data10->amount = 100;
data10->next = NULL;

strcpy(data9->name , "Fried_Rice");
data9->amount = 170;
data9->next = data10;

strcpy(data8->name , "Roti");
data8->amount =35;
data8->next = data9;

strcpy(data7->name , "Butter_paneer");
data7->amount = 180;
data7->next = data8;

strcpy(data6->name , "Chole_Bhatoore");
data6->amount = 100;
data6->next = data7;

strcpy(data5->name , "North_Indian_Thali");
data5->amount = 140;
data5->next = data6;

strcpy(data4->name , "Black_Current");
data4->amount = 100;
data4->next = data5;

strcpy(data3->name , "Noodles");
data3->amount = 110;
data3->next = data4;

strcpy(data2->name , "Tea");
data2->amount = 10;
data2->next = data3;

strcpy(data1->name , "Full_Meals");
data1->amount = 1000;
data1->next = data2;
return data1;
}

// Function:     validateUser
// Description:  validate the data of new user whether it exists or not
// Input param:  structure which contains of new user details
// Return Type:  boolean

//validate user
// int validateUser(){
//     FILE *fp;
//     fp = fopen('userData.txt','w+');

// }



int hash(int phone,int pass){
    int key,i = 0;
    key = phone % size;
    i = key;
    printf("\n%d",chain[i]);
    while (1)
    {
        if (chain[i]==pass)
        {
            printf("\033[0;32m");   
            printf(" \nlogged in successfully.\n");
            printf("\033[0m");  
            return 1;
        }
        else{
            if(chain[i]%size==key)
            {
                if(i==size-1) i = 0;
                else i++;

                if(i==key){
                    printf("\033[0;31m"); 
                    printf("No user exists.");
                    printf("\033[0m");     
                    return 0;
                }
            }
            else {
                printf("\033[0;31m"); 
                printf("Wrong Password.");
                printf("\033[0m");     
                return 0;
            }
        }

    }
    return 0;
}



// int chkLogin(){
//     int uname = loginName;
//     char pass[50];
//     strcpy(loginPassword,pass);
//     int number,val;
//     val = hash(uname);
//     printf("Please check your username");


// }



tree setList(tree root1,tree item){
    if(root1==NULL){
        return item;
    }
    if(item->amount < root1->amount){
        root1->left = setList(root1->left,item);
    }
    else{
         root1->right = setList(root1->right,item);
    }
    return root1;
}

void inOrder(tree root1){
    if(root1!=NULL){
        inOrder(root1->left);
        printf("\n  %s  --> %d",root1->name,root1->amount);
        inOrder(root1->right);
    }
}


// Function:     calculate
// Description:  Claculate the orders and stores it in a txt file
// Input param:  item selected
// Return Type:  NULL
void calculate(menu item)
{

    tree ptr = (tree)malloc(sizeof(struct trees));
    ptr->left = NULL;
    ptr->right = NULL;
    strcpy(ptr->name, item->name);
    ptr->amount = item->amount;
    root = setList(root,ptr);
    int day, month, year;
    printf("\n  %s  --> %d",root->name,root->amount);
    time_t now = time(NULL);
    total+=item->amount;



    FILE *fp;
    fp = fopen("Logs.txt","a");
    if(fp==NULL) printf("could not able to open the file");
    fprintf(fp,"%s %s %s %s %d","\n\n",ctime(&now),item->name,"-----> Rs.",item->amount);
    fclose(fp);

    printf("\n\n%s   %s -----> Rs.  %d     added to your log",ctime(&now),item->name,item->amount);
}



void setLog(){
    time_t now = time(NULL);
    FILE *fp;
    fp = fopen("Logs.txt","a");
    if(fp==NULL) printf("could not able to open the file");
    fprintf(fp,"%s","\n\n");
    fprintf(fp,"%s","________START OF SESSION_________");
    fprintf(fp,"%s %s",ctime(&now),"  ");
    fclose(fp);
}



void printTotal(){
    if(total==0){
        printf("\n\nYou haven't ordered anything yet");
    }
    else{
        printf("\n\nYour total amount is   :%d",total);
    }
}

//showMenu
// Function:     showMenu
// Description:  Displays the menu and read the user choice
// Input param:  NULL
// Return Type:  Selected Item
menu showMenu(){
    int flag = 0;
    while(!flag)
    {
    char choice[50];
    menu ptr = dummyData();   //dummy data is loaded initially
    int i = 0;
    while(ptr!=NULL){
        printf("\n\n%d. %s  ====>  Rs.%d",i+1,ptr->name,ptr->amount);
        i++;
        ptr = ptr->next;
    }
    printf("\n\nEnter the name of dish as appear in the menu  :");
    scanf("%s",choice);


    ptr = dummyData();                      //resetting the ptr
    while(ptr!=NULL){
        if((strcmp(choice,ptr->name))==0){
            flag = 1;
            return ptr;
        }
        ptr = ptr->next;
    }
    if(!flag) printf("\nPlease Enter a valid Dish Name !!");



    }

}


// Function:     goToMenu
// Description:  Displays the menu and read the user choice
// Input param:  NULL
// Return Type:  Total Amount

void goToMenu(){

    int choice;

    while(1){
        menu item;
        printf("\n\n\n1.Watch Menu\n2.Total of the session\n3.Print Items you have ordered\n4.Logout             :");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            item = showMenu();
            calculate(item);
            break;

        case 2:
            printTotal();
            break;

        case 3:
            inOrder(root);
            printTotal();
            break;

        case 4:
            printf("\033[0;32m");
            printf("\n\nThank you Visit Again\n\n");
            printf("\033[0m");  
            exit(0);
        default: printf("\nInvalid Input.\n");
        }

    }

}

//signup function
void signup(){
    user temp = (user)malloc(sizeof(struct users));
    printf("\n\nSignUp here :");
    printf("\n\nPlease Enter your Name      :");
    scanf("%s",temp->name);
    printf("\n\nCreate a User Name          :");
    scanf("%s",temp->userName);
    printf("\n\nPlease Enter your Email     :");
    scanf("%s",temp->email);
    printf("\n\nPlease Enter your Ph.Number :");
    scanf("%d",&temp->mobile);
    printf("\n\nCreate a Password           :");
    scanf("%d",&temp->password);
    printf("\n");


    int phone = temp->mobile;
    int key = phone % size;
    int i = key;
    while(1){
        if (chain[i] == -1)
        {
           chain[i] = temp->password;
            printf("\033[0;32m");  
            printf("\nSignup successfull");
            printf("\033[0m");    
           break;
        }

        else
        {
            if(i == size-1) key  = 0;
            else i++;

            if(i==key){
                printf("\033[0;31m");  
                printf("no space avilable");
                printf("\033[0m");   
            }

        }
    }


    // validate();
}

//funcion trigger after successfull login
void login(){
    int val;
    int loginPassword;
    int loginName;

    while(1){
    printf("\nWelcome to the Login:");
    printf("\n");
    printf("\n");
    printf("\n  Enter Mobile Number  :");
    scanf("%d",&loginName);
    printf("\n  Enter your Password      :");
    scanf("%d",&loginPassword);
    val = hash(loginName,loginPassword);
    if(val){
        setLog();
        goToMenu();
        break;
    }
    else {
        printf("\033[0;31m"); 
        printf("try again");
        printf("\033[0m"); 
    }
    }
}

//Initial setup
int setup(){
    int choice;
    init();

    while(1){
        printf("\n\n\n1.SigUp\n2.Login\n3.Exit              :");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            signup();
            break;

        case 2:
            login();
            break;

        case 3:
            exit(0);
        default: printf("\nInvalid Input.\n");
        }

    }
}