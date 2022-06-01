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
strcpy(data3->name , "Chicken_biryani");
data3->amount = 100;
data3->next = NULL;
strcpy(data2->name , "CB");
data2->amount = 10;
data2->next = data3;
strcpy(data1->name , "Chicken_biryani");
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
    printf("%d",chain[i]);
    while (1)
    {
        if (chain[i]==pass)
        {
            printf("logged In");
            return 1;
        }
        else{
            if(chain[i]%size==key)
            {   
                if(i==size-1) i = 0;
                else i++;

                if(i==key){
                    printf("no user exists");
                    return 0;
                }
            }
            else {
                printf("wrong password");
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
        printf("this is data");
        // printf("\n  %s  --> %d",root1->name,root1->amount);
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
    strcpy(ptr->name, item->name);
    ptr->amount = item->amount;
    root = setList(root,ptr);
    int day, month, year;

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
    fprintf(fp,"%s","_________________________START OF ITERATION________________________");
    fprintf(fp,"%s %s",ctime(&now),"  ");
    fclose(fp);
}



void printTotal(){
    if(total==0){
        printf("you haven't ordered anything yet");
    }
    else{
        printf("You total amount is   :%d",total);
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
    printf("\nEnter the name of dish as appear in the menu  :");
    scanf("%s",choice);


    ptr = dummyData();                      //resetting the ptr
    while(ptr!=NULL){
        if((strcmp(choice,ptr->name))==0){
            flag = 1;
            return ptr;
        }
        ptr = ptr->next;
    }
    if(flag) printf("\nPlease Enter a valid Dish Name");
    


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
        printf("\n\n\n1.Watch Menu\n2.Total of the session\n3.Print Items you have ordered\nAny other key to.Exit              :");
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
            break;
        
        default:
            exit(0);
        }
        
    }

}

//signup function
void signup(){
    user temp = (user)malloc(sizeof(struct users));
    printf("\n\nWelocome to the restuarant:");
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
            printf("Signup successfull");
           break;
        }

        else
        {
            if(i == size-1) key  = 0;
            else i++;

            if(i==key){
                printf("no space avilable");
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
    printf("\nWelocome to the Login:");
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
    else printf("try again");
    }
}

//Initial setup
int setup(){
    int choice;
    init();

    while(1){
        printf("\n\n\n1.SigUp\n2.Login\nAny other key to.Exit              :");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            signup();
            break;
        
        case 2:
            login();
            break;
        
        default:
            exit(0);
        }
        
    }
}