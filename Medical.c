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
void sales()
{
   int a[100],n,i,s;
   int total=0;
   float p,t;
   char*name[100][50],flag;
   FILE *p;
   p=fopen("medi.txt","rbt");
   if (p!=NULL)
   {
      printf("how many item");
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
      printf("enter tanblet name");
      scanf("%s",name[i]);
      printf("quantity");
      scanf("%d",&[i]);
      }
   printf("confirm to print");
   scanf("%f",flag);
   if(flag=='y')
   ptintf("quantity tablet name company name Rs/per date");
   for(i=0;i<n;i++)
     {
       fread(&m1,sizeof(m1),1,p);
       if(m1.tb==name[i])
         {
       t=(m1.price/quantity);
       p=t*q;
       total=p+total;
       m1.quan=m1.quan-q;
       m1.price=m1.price-p;
       fseek(p,-sizeof(m1)L,1);
       printf("%d%s%f%f",q,m1.tb,m1.cn,t,p);
         }
        else
       printf("file can't be open");
     }
       fclose(p);
       printf("total amount:");
       printf("%d",total);
       printf("do u want one more bill?;(Y/N)");
       scanf("%s",flag);
       strupr(flag);
        if(flag='Y')
        sales();
         else
          data();
    }     else sales();
     tablet search()
     {
      FILE *p;
      char*name:
      p=fopen("medi.txt","rbt");
       if(p!=NULL)
        {
        printf("enter the tablet name");
        scanf("%s",name);
        while(!(feof(s)))
        fread(&m1.sizeof(m1),1,p);
         if(name==m1.tb)
          {
      printf("%s",m1.tb);
          }
      else if(name==m1.cn);
          {
      printf("%s%s%d%f%s",m1.tb,m1.cn,m1.quan,m1.price,m1.rack);
          }
      else
      {
        printf("command  not found");
      }
        } fclose(p);
      } else
        printf("file not found");
        }
        void edit()
         {
          FILE *p;
          char*name;
          p=fopen("medi.txt","rbt");
          if(p!=NULL)
          {
      printf("enter the tablet name to be edited");
      scanf("%s",name);
       while(!(foef()))
        {
         fread(&m1,sizeof(m1),p);
         if(name==m1.tb)
         {
          fseek(p,-sizeof(m1)L,1);
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
          }
           fclose(p);
           printf("do u want to edit one more item Y/N");
           scanf("%s",flag);
           strupr(flag);
           if(flag=='Y')
           edit();
           else data();
         }
         void del()
         {
          FILE *p;
          FILE *p;
          char name[30];
         p =fopen("medi.txt","rbt");
         q=fopen("medi.txt","wbt");
         if(p!=NULL && q!=NULL)
          {
           printf("enter the tablet name");
           scanf("%s",name);
           printf("





