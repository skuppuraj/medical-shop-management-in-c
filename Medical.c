#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct medical
{
   char tb[45];
   char cn[45];
   int quan;
   float price;
   char rack[10];
}m1;
void data();
void add();
void display();
void main()
{
    clrscr();
    data();
    getch();
}

void data()
{
   int n;
   x:
   printf("\n\n\n1.ADD DATA\n2.Display\n\n0.EXIT");
   printf("\n\n\t\tEnter your choice:");
   scanf("%d",&n);
   switch(n)
   {
     case 1:
	    add();
	    break;
     case 2:
	    display();
	    break;
     case 0:
	    abort();
	    break;
     default:
       printf("\n\n\n\t\t\tWRONG CHOICE.....!!");
       goto x;

   }
}
void add()
{
   FILE *p;
   int a,i;
   clrscr();
   p=fopen("med.txt","wb");
   if(p!=NULL)
   {
     printf("\n How many tablet want to be store?");
     scanf("%d",&a);
     for(i=1;i<=a;i++)
     {
       printf("\nTablet name:");
       scanf("%s",m1.tb);
       printf("\nCompany name:" );
       scanf("%s",m1.cn);
       printf("\nQuntity:");
       scanf("%d",&m1.quan);
       printf("\nPrice for quntity");
       scanf("%f",&m1.price);
       printf("\nRack name:");
       scanf("%s",m1.rack);
       fwrite(&m1,sizeof(m1),1,p);
      }
      fclose(p);
    }
    else printf("\n\tFile not found");
    data();
}
void display()
{
   FILE *p;
   int a,i;
   clrscr();
   p=fopen("med.txt","rb");
    if(p!=NULL)
   {  printf("TABLET NAME        COMPANY            QUANTITY  PRICE   RACK");
      for(i=1;i<=1;i++)
      {
	fread(&m1,sizeof(m1),1,p);
	printf("\n%-20s%-20s%-9d%-7.2f%5s\n",m1.tb,m1.cn,m1.quan,m1.price,m1.rack);
      }
     fclose(p);
    }
    else printf("\n\tFile not found");
    data();
}
