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
long z=sizeof(m1);

void data();
void add();
void display();
void sales();
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
   printf("\n\n\n1.ADD DATA\n2.DISPLAY\n3.SALES\n\n0.EXIT");
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
     case 3:
       sales();
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
   p=fopen("medical.txt","wb");
   if(p!=NULL)
   {
     printf("\n How many tablet want to be store?");
     scanf("%d",&a);
     for(i=1;i<=a;i++)
     {
       printf("\nTablet name:");
       scanf("%s",m1.tb);
       strupr(m1.tb);
       printf("\nCompany name:" );
       scanf("%s",m1.cn);
       strupr(m1.cn);
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
   p=fopen("medical.txt","rb");
    if(p!=NULL)
   {  printf("TABLET NAME        COMPANY            QUANTITY  PRICE   RACK");
      while( fread(&m1,sizeof(m1),1,p)==1)
      {

   printf("\n%-20s%-20s%-9d%-7.2f%5s\n",m1.tb,m1.cn,m1.quan,m1.price,m1.rack);
      }
     fclose(p);
    }
    else printf("\n\tFile not found");
    data();
}
void sales()
{
   int a[100],n,i,s,k;
   int total=0;
   float pr,t;
   char name[100][50],flag,r[50];
   FILE *p;
   p=fopen("medical.txt","rb+");
   if (p!=NULL)
   {
      printf("how many item?\n");
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
      printf("Enter tanblet name:");
      scanf("%s",name[i]);
      strupr(name[i]);
      printf("Quantity:");
      scanf("%d",&a[i]);
      }
       //   printf("confirm to print?");
       //   scanf("%s",flag);
   //if((flag=='y')||(flag=='Y'))
    //{
      printf("\n\nQuantity  Tablet name    Company name   Rs/per   Rate    \n");
      for(i=0;i<n;i++)
      {
          rewind(p);
          while(!(feof(p)))
           {
         fread(&m1,sizeof(m1),1,p);
         k=strcmp(m1.tb,name[i]);
         if(k==0)
         {
             t=m1.price/m1.quan;
              pr=t*a[i];
              total=pr+total;
             /* strcpy(m2.tb,m1.tb);
              strcpy(m2.cn,m1.cn);
              strcpy(m2.rack,m1.rack);*/
              m1.quan=m1.quan-a[i];
              printf("\nxxxxxxxxxxxxxxx:%d",m1.quan);
              m1.price=m1.price-pr;
              fseek(p,-z,1);
              fwrite(&m1,sizeof(m1),1,p);
              printf("%-10d%-15s%-15s%-7.2f%-7.2f",a[i],m1.tb,m1.cn,t,pr);
              break;
          }
          else
               printf("\n\nIteam not found....!");
           }
      }
      printf("\n\ntotal amount:");
      printf("%d",total);
      printf("\n\ndo u want one more bill?;(Y/N)");
      scanf("%s",flag);
    //   if((flag=='Y')||(flag=='y'))
      // sales();
          //   else
      data();
    // }     else sales();
     }else printf("\n\nFile can not be open...!");
}
   /*  ile tablet search()
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





*/