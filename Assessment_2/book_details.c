
typedef struct book
{
    int isbn;
    char b_name[10], author[15];
    float price;
}b;

void read_book_details(b *a, int n)
{
    printf("Enter book name, author, ISBN no and price : \n");
    for(int i=0; i<n; i++)
        scanf("%s %s %d %f", (a+i)->b_name, (a+i)->author, &(a+i)->isbn, &(a+i)->price);
}

void display_details(b *a, int n)
{
    printf("\nISBN no.\tBook Name\tAuthor\tPrice\n");
    for(int i=0; i<n; i++)
        printf("%d\t\t%s\t\t%s\t%.2f\n", (a+i)->isbn, (a+i)->b_name, (a+i)->author, (a+i)->price);
}

void book_sort(b *a, int n)
{
    b temp;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if((a+j)->isbn>(a+j+1)->isbn)
            {
                temp = *(a+j);
                *(a+j) = *(a+j+1);
                *(a+j+1) = temp;
            }
        }
    }
    printf("\nBooks have been successfully sorted.\n");
}

void book_search(b *a, int n)
{
    int key, flag = 0, i;
    printf("\nEnter the isbn number : ");
    scanf("%d", &key);
    for(i=0; i<n; i++)
    {
        if(key==(a+i)->isbn)
        {
            flag = 1;
            break;
        }
    }
    if(flag)
        printf("\nBook has been found.\n%d\t\t%s\t\t%s\t%f\n", (a+i)->isbn, (a+i)->b_name, (a+i)->author, (a+i)->price);
    else
        printf("\nBook was not found.\n");
}

void store_details(FILE *f, b *a, int n)
{
    printf("\nISBN no.\tBook Name\tAuthor\tPrice\n");
    for(int i=0; i<n; i++)
        fprintf(f, "%d\t\t%s\t\t%s\t%.2f\n", (a+i)->isbn, (a+i)->b_name, (a+i)->author, (a+i)->price);
    printf("\nData has been stored successfully.\n");
}

void main()
{
    int n;
    FILE *f;
    f = fopen("book.txt", "w");
    printf("Enter the no. of book : ");
    scanf("%d", &n);
    b *a = (b*)malloc(n*sizeof(b));
    read_book_details(a,n);
    display_details(a,n);
    book_sort(a,n);
    display_details(a,n);
    store_details(f, a, n);
    book_search(a,n);
    free(a);
}