// A new game is introduced in the World Wrestling Event, wherein the competition is conducted across Countries. King is 1st player representing country Oman and Sultan 2nd player representing country India. In the game, there is a circle with N points, 1 dumble of weight W is placed at each point. The mind game here is that now the player has to pick a chit which represents K. If the weight is a modulus of K and is greater than the next dumble, only then he has to lift the dumble and that particular weight is added to the dumble score. Then the crew boy removes the lifted dumble from the circle. Once the player reaches last dumble, weight of last dumble is compared with first dumble. Also if there is only one dumble, the players stop the process of lifting. Apply Problem Solving and find out whose dumble score is highest.

//input
// 55
// 2
// 2
// 3
// 50 55 63 80 10

// output
// 80
// 0
// The winner is King



#include<stdlib.h>
#define MAX 20
typedef struct Q
{
  int rear;
  int front;
  int elements[MAX];
}Queue;

int full(Queue *m)
{
  if((m->rear+1)%MAX==m->front)
     return(1);
  return(0);
}

void enqueue(Queue *m)
{
  int x;
  scanf("%d",&x);
  if(m->rear==-1)
    m->rear=m->front=0;
  else
    m->rear=(m->rear+1)%MAX;
  m->elements[m->rear]=x;
}

void count(Queue *m,int k1,int k2)
{
  int i,count1=0,count2=0;
  for(i=m->front;i!=m->rear;i=(i+1)%MAX)
  {
    if(m->elements[i]%k1==0 && m->elements[i]>m->elements[i+1])
      count1=count1+m->elements[i];
    if(m->elements[i]%k2==0 && m->elements[i]>m->elements[i+1])
      count2=count2+m->elements[i];
  }
  if((m->elements[i]%k1==0) && (m->elements[i]>m->elements[m->front]))
    count1=count1+m->elements[i];
  if(m->elements[i]%k2==0 && m->elements[i]>m->elements[m->front])
    count2=count2+m->elements[i];
  printf("%d\n%d",count1,count2);
  if(count1>count2)
    printf("\nThe winner is King");
  if(count1<count2)
    printf("\nThe winner is Sultan");
}

int main()
{
  Queue q;
  q.front=-1;
  q.rear=-1;
  int N,M,k1,k2,i;
  scanf("%d%d",&N,&M);
  if(M<=1)
  {
    printf("Minimum number of players should be 2");
    exit(0);
  }
  scanf("%d%d",&k1,&k2);
  for(i=0;i<N;i++)
  {
    if(full(&q))
      printf("queue is full");
    else 
      enqueue(&q);
  }
  count(&q,k1,k2);
  return 0;
}