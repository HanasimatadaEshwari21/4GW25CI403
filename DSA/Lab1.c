#include<stdio.h>
#include<stdlib.h>
struct Day
{
    char *dayname;
    char *activity;
    int date;
};
void create(struct Day *day)
{
    day->dayname=(char*)malloc(sizeof(char)*50);
    day->activity=(char*)malloc(sizeof(char)*100);
    printf("enter the dayname : ");
    scanf("%s",day->dayname);
    printf("enter the date : ");
    scanf("%d",&day->date);
    printf("enter the activity for the day : ");
    scanf("%s",day->activity);
}

void read(struct Day* calendar,int size)
{
    for(int i=0;i<size;i++)
{
printf(" enter the details for day %d:\n",i+1);
create(&calendar[i]);
}
}


void display(struct Day* calendar,int size)
{
    printf("weeks activity detalis:\n");
    for(int i=0;i<size;i++)
{
    printf("Day:%d\n", i+1);
    printf("Day name:%s\n",calendar[i].dayname);
    printf("Date:%d\n",calendar[i].date);
    printf("activity:%s\n",calendar[i].activity);
    printf("\n");
}
}

void freememory(struct Day* calendar,int size)
{
    for(int i=0;i<size;i++)
{
    free (calendar[i].dayname);
    free (calendar[i].activity);

}
}

int main()
{
    int size;
    printf("enter the number of  day in weeks:");
    scanf("%d",&size);
    struct Day calendar=(struct Day)malloc(sizeof(struct Day)*size);
    if(calendar==NULL)
    {
      printf("\n memory allocation failed exiting program\n");
      return 1;
    }
    read (calendar,size);
    display (calendar,size);
    freememory (calendar,size);
    free (calendar);
return 0;
}
