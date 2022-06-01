typedef struct cricket_player
{
  char player_name[20];
  char team_name[20];
  int odi_rank;
}P;

void read(P *p,int n)
{
    printf("Enter player details\n");
    for(int i=0;i<n;i++)
    {
        printf("\nEnter player name : ");
        scanf("%s",(p+i)->player_name );
        printf("Enter team name : ");
        scanf("%s",(p+i)->team_name);
        printf("Enter ODI rank : ");
        scanf("%d",&(p+i)->odi_rank);
    }
}

void display(P *p,int n)
{
    printf("\nPlayer Name\t\tTeam Name\t\tODI Rank\n");
    for(int i=0;i<n;i++)
    {
        printf("%s\t\t\t%s\t\t\t%d\n", (p+i)->player_name, (p+i)->team_name, (p+i)->odi_rank);
    }
}

void sort_by_rank(P *p,int n)
{
    P temp;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if((p+j)->odi_rank>(p+j+1)->odi_rank)
            {
                temp = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = temp;
            }
        }
    }
}

void save_file(FILE *f, P *p, int n)
{
    fprintf(f, "Player Name\t\tTeam Name\t\tODI Rank\n");
    for(int i=0;i<n;i++)
    {
        fprintf(f, "%s\t\t%s\t\t%d\n", (p+i)->player_name, (p+i)->team_name, (p+i)->odi_rank);
    }
    printf("\nFile has been saved successfully.\n");
}

void main()
{
    int n;
    printf("Enter the number of players : ");
    scanf("%d",&n);
    P *p = (P*)malloc(n*sizeof(P));
    FILE *f;
    f = fopen("odi_rank.txt", "w");
    if(f==NULL)
    {
        exit(0);
    }
    read(p,n);
    display(p,n);
    sort_by_rank(p,n);
    printf("\nDetails of players sorted based on increasing order of their rank.\n");
    display(p,n);
    save_file(f, p, n);
    fclose(f);
}