File name : Number_game.c

#include<stdio.h>
#include<stdlib.h>
#include<dos.h>

enum arrow_keys
{
     exit_case=0,
     up_key=8,
     down_key=2,
     left_key=4,
     right_key=6
};

enum arrow_keys arrow_key;

void display(int *puzzle);
void shift_up(int(*q)[4]);
void shift_down(int (*q)[4]);
void shift_left(int (*q)[4]);
void shift_right(int (*q)[4]);
enum arrow_keys getkey(void);
unsigned int puzzle_check(int *);


int main()
{
    int puzzle[4][4]={1,4,15,7,8,10,0,2,11,14,3,6,13,12,9,5};
    int flag=0;
    printf("\nThis is the puzzle\n");
    display(*puzzle);
    printf("\nRearrange the sequence in ascending order row wise using arrow keys\n");
    while(1)
    {
            printf("\nEnter the arrow key to rearrange or 0 to exit\n");
            arrow_key=getkey();
            switch(arrow_key)
            {
                       case exit_case:printf("You are exiting the game\n");
                                 system("pause");
                                 exit(0);
                                 break;
                                 
                       case up_key:shift_up(puzzle);
                                    break;
                       
                       case down_key:shift_down(puzzle);
                                     break;
                                                                                           
                       case left_key:shift_left(puzzle);
                                      break;
                                      
                       case right_key:shift_right(puzzle);
                                       break;
                                       
                      default: printf("\nInvalid Key press\n");     
            }
            display(*puzzle);
            flag=puzzle_check(*puzzle);
            if(flag==1)
            {
               printf("\npuzzle is complete\n");
               display(*puzzle);
               break;
            }
            
            
    
    }
    system("pause");
    return 0;
}

enum arrow_keys getkey()
{
 unsigned int key;
 scanf("%u",&key);
 return key;
}

void display(int *puzzle)
{
     int i,j;
     for(i=0;i<4;i++)
     {
          for(j=0;j<4;j++)
          {
                printf("%d\t",*(puzzle+j));
          }
          printf("\n");
          puzzle=puzzle+4;
     }
}
void shift_up(int (*q)[4])
{
  int *ptr;
  int i,j,temp;
  for(i=0;i<3;i++)
  {   
        ptr=(int *)(q+i);
        for(j=0;j<4;j++)
        {
            if(*(ptr+j)==0)
            {
                                
                    temp=*(ptr+j);            
                    *(ptr+j)=*(ptr+j+4);
                    *(ptr+j+4)=temp;
                    return;
            
            }
        }
    }                      
}
void shift_down(int (*q)[4])
{
  int *ptr;
  int i,j,temp;
  for(i=1;i<4;i++)
  {
        ptr=(int *)(q+i);
        for(j=0;j<4;j++)
        {
            if(*(ptr+j)==0)
            {
                    temp=*(ptr+j);            
                    *(ptr+j)=*(ptr+j-4);
                    *(ptr+j-4)=temp;
                    return;
            }
        }
    }       
}
void shift_left(int (*q)[4])
{
    int *ptr;
    int i,j,temp;
    for(i=0;i<4;i++)
    {
        ptr=(int*)(q+i);
        for(j=0;j<3;j++)
        {
            if(*(ptr+j)==0)
            {
                temp=*(ptr+j);
                *(ptr+j)=*(ptr+j+1);
                *(ptr+j+1)=temp;
                return;
            }
        }
    }
}
void shift_right(int (*q)[4])
{
        int *ptr;
    int i,j,temp;
    for(i=0;i<4;i++)
    {
        ptr=(int*)(q+i);
        for(j=1;j<4;j++)
        {
            if(*(ptr+j)==0)
            {
                temp=*(ptr+j);
                *(ptr+j)=*(ptr+j-1);
                *(ptr+j-1)=temp;
                return;
            }
        }
    }
     
}
unsigned int puzzle_check(int *puzzle)
{
    int i,j,flag=0;
    int *ptr;
    ptr=puzzle;
    for(i=0;i<15;i++)
    {
        if(*(ptr+i+1)-*(ptr+i)==1)
        {
            flag=1;
        }
        else
        {
            flag=0;
            break;
        }
    }
    return flag;
}
