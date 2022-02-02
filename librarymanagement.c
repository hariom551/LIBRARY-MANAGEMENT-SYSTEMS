#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

void add_books(int count);
void book_record();
void issue_books();
void update_record();
void student_details();
void change_password();
int temp_bookId;
int temp;
struct library
{
int book_id;    
char book_name[30];
char author[30];
float price;
char issued_status[10];
}om[100];

struct date
    {
      int da_day;
      int da_mon;
      int da_year;
    }submit;

struct students
{
char student_name[20];
int student_id[20];
char student_course[20];
int issued_bookid[20];
struct date submit_date;
}std[100];


int main()
{   
    int j,i=0,count,n=0,m;    
    char username[20];                 
    char password[20];                   
    char originalpassword[20];
    printf("\n");
    printf("\t\t\t\t\t*MINI PROJECT OR INTERNSHIP ASSESSMENT*\n");
    printf("\t\t\t**PREPARED BY - HARIOM NATHANIIT DEPT, DR.AITH, KANPUR & MANMAY GHOSH, IT DEPT, DR.AITH, KANPUR\n");

 //authentication

printf("enter username:");
 scanf("%s", &username);
     
 printf("enter password:");
 scanf("%s",&password);
FILE *fp;
fp=fopen("password.txt","r");
fgets(originalpassword,10,fp);
fclose(fp);

if((strcmp(username,"admin@123")==0)&&(strcmp(password,originalpassword)==0))
  {
        printf("\nWelcome To The Library");

    while(j!=9)
     {
       printf("\n\n1. Add book information\n");
       printf("2. Display book information\n"); 
       printf("3. Search book\n");
       printf("4. Issue book\n"); 
       printf("5. Update books record\n");
       printf("6. Student details\n");
       printf("7. Change password\n");
       printf("8. Exit\n");
       printf ("\n\n\nEnter one of the above : ");
       scanf("%d",&j);

       switch (j)
        {
             case 1: //printf("\nEnter number of books needed to be added:\t");
            //         scanf("%d",&count);
                    count=1;
                    add_books(count);
                    break;
            case 2: book_record(count);  
                    break;      
            case 3: printf("press 1. search using book_name");
                    printf("\npress 2. search using book_id\n");
                     
                    scanf("%d",&n);
                    fp = fopen("booklib.txt","rb");
                    if(fp == NULL)    
                      {
                        printf("\n\t\t\tFile is not opened\n");
                        exit(1);
                        printf("%d", (fread (&om, sizeof(om), 1, fp)));
                      }
                    if(n==1)
                        {
                            char book_name[30];
                            printf ("Enter book name:\t ");
                            scanf ("%s",&book_name);
                            // for (i=0; i<count; i++)
                              while (fread (&om, sizeof(om), 1, fp))
                            {
                               // printf(" %d", fread (&om, sizeof(om), 1, fp));
                                //printf("%d ", om[i].book_id);
                              if (strcmp(book_name, om[i].book_name) == 0)
                                printf ("book name: %s\t author: %s\t book id: %d\t price: %f",om[i].book_name,om[i].author,om[i].book_id,om[i].price);
                            }
                            printf("%d",fread (&om, sizeof(om), 1, fp));
                        }    
                    else if(n==2)
                     {
                        int book_id1;
                        printf("\nenter book_id:\t");
                        scanf("%d",&book_id1);                                                     
                        while (fread (&om, sizeof(om), 1, fp))
                        {
                         if (book_id1==om[i].book_id)
                          {
                            printf ("book name: %s\t author: %s\t book id: %d\t price: %f",om[i].book_name,om[i].author,om[i].book_id,om[i].price);
                          }
                        }    
                     }   
                    break;
                    
            case 4: issue_books();
                    break;    
            
             case 5: 
                     update_record();
                     break;

            case 6: student_details();
                    break;
           case 7: change_password();
                   break;
           case 8:  printf("Thank You for using our library management sytem\nPress any key to exit...");
                    getch();
            exit(0);
        }
     }
    return 0;
  }
  else
  printf("wrong password");
}



void add_books(int count)                                //add book information
{
  int i;
  FILE *fp;
  fp=fopen("booklib.txt","ab+");
   if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }

  for(i=0; i<count; i++)
   {
    printf("\nEnter book name = ");
    scanf("%s",om[i].book_name);


    printf("Enter bookid = ");
    scanf ("%d",&om[i].book_id);

     printf("Enter price = ");
     scanf("%f",&om[i].price);

     printf("Enter author = ");
     scanf("%s",&om[i].author); 
     fwrite(&om,sizeof(om),1,fp);
     fclose(fp);   
   }
   
   book_record();
}   


void book_record()                             //display book information
{
  int i=0;
  FILE *fp;
  fp=fopen("booklib.txt","rb");
  if(fp==NULL)
  {
    printf("file not found");
    exit(1);
  }

 printf("following books are in the library\n");      
    while (fread (&om, sizeof(om), 1, fp))
 {
    // fread(&om,sizeof(om[0]),1,fp;
      printf("\nbookid = %d",om[i].book_id); 
      printf("\tbook name = %s",om[i].book_name);
      fflush(stdin);
      printf("\tauthor name = %s",om[i].author);
      printf("\tprice = %f",om[i].price);
    
  }
  fclose(fp);
 
}


void issue_books()                                
{
  int i=0,j=0;
  FILE *fp;
  fp=fopen("booklib.txt","ab+");
   if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }

     printf("\nEnter bookid = ");
     scanf ("%d",&std[i].issued_bookid);
     temp_bookId=*std[i].issued_bookid;
     while(fread (&om, sizeof(om), 1, fp))
     {
       if (*std[i].issued_bookid==om[j].book_id && om[j].issued_status=="Issued")        
           printf("\nThis book is not available in library");
      else
      {
        printf("Enter student name = ");
        scanf("%s",&std[i].student_name);

        printf("Enter student id = ");
        scanf ("%d",&std[i].student_id);

        printf("Enter student course = ");
        scanf("%s",&std[i].student_course);
    
        if(*std[i].issued_bookid==om[j].book_id)                
          strcpy(om[j].issued_status,"Issued");

        tested();  
      std[i].submit_date=submit;

    fwrite(&std,sizeof(std),1,fp);
    fwrite(&om,sizeof(om),1,fp);
     fclose(fp);   
    }
    }
   
printf("\n\n\nfollowing books are issued\n");            
printf("\nIssued bookid = %d",temp_bookId);      
fp=fopen("booklib.txt","rb");
while(fread (&om, sizeof(om), 1, fp))
   {
      if (temp_bookId==om[i].book_id)
        {
         printf ("\nbook name: %s\nauthor: %s\nbook id: %d\nprice: %f",om[i].book_name,om[i].author,om[i].book_id,om[i].price);
         fread (&std, sizeof(std), 1, fp);
                 {
         //      printf("\nIssued book name = %s",om[j].book_name);
                 printf("\nStudent name = %s",std[i].student_name);
                 printf("\nStudent course = %s",std[i].student_course);
                 printf("\nRent to be paid = %f",0.2*om[j].price);
                 printf("\nReturn date =%d/%d/%d",std[i].submit_date.da_day,std[i].submit_date.da_mon,std[i].submit_date.da_year);
                }
        }
        fclose(fp); 
    }                    
} 

void update_record()
{
  int i=0,j,k,m,issuebook,submitdate;
  FILE *fp;
  fp=fopen("booklib.txt","ab+");
   if(fp == NULL)
    {
        printf("File is not opened\n");              ////fwrite use
        exit(1);
    }
     printf("\nPress 1. Reissue\n");
     printf("Press 2. Submit\n");
     scanf("%d",&k);

     printf("\nEnter bookid = ");
     scanf ("%d",&issuebook);
      temp= issuebook;
    if(k==1)
      {
          while (fread (&std, sizeof(std), 1, fp))
          {    
           if(*std[i].issued_bookid==issuebook)
              {
                tested();
                printf("\nReturn date =%d/%d/%d",std[j].submit_date.da_day,std[j].submit_date.da_mon,std[j].submit_date.da_year);
              }
         }
      }
     else if(k==2)  
       {
          while (fread (&std, sizeof(std), 1, fp))
          {    
           if(*std[i].issued_bookid==issuebook)
              {
                //  temp= issuebook;
                for(m=0;i<strlen(std[j].student_id);i++)
                {
                 std[j].student_id[m] = 0;
                }

                for(m=0;i<strlen(std[j].student_name);i++)
                {
                 std[j].student_name[m] = 0;
                }

                for(m=0;i<strlen(std[j].student_course);i++)
                {
                 std[j].student_course[m] = 0;
                }
              }
       }
       }
     else  
       printf("Please enter a valid number");

      fwrite(&std,sizeof(std),1,fp);
      fclose(fp);  
   
    printf("\nFollowing books are reissued/submit\n");   


fp=fopen("booklib.txt","rb");
printf("\nIssued bookid = %d",temp);

while(fread (&om, sizeof(om), 1, fp))
   {
      if (temp==om[i].book_id)
        {
         printf ("\nbook name: %s\nauthor: %s\nbook id: %d\nprice: %f",om[i].book_name,om[i].author,om[i].book_id,om[i].price);
         fread (&std, sizeof(std), 1, fp);
                 {
         //      printf("\nIssued book name = %s",om[j].book_name);
                 printf("\nStudent name = %s",std[i].student_name);
                 printf("\nStudent course = %s",std[i].student_course);
                 printf("\nRent to be paid = %f",0.05*om[j].price);
                 printf("\nReturn date =%d/%d/%d",std[i].submit_date.da_day,std[i].submit_date.da_mon,std[i].submit_date.da_year);
                }
        }
        fclose(fp); 
    }                    

}


void student_details()
{
  
  int i=0;
  FILE *fp;
  fp=fopen("booklib.txt","rb");
  if(fp==NULL)
  {
    printf("file not found");
    exit(1);
  }

 printf("following books are issued \n");      
    while (fread (&std, sizeof(std), 1, fp))
 {
     printf("\nStudent id = %d",*std[i].student_id);
     printf("\nStudent name = %s",std[i].student_name);
     printf("\nStudent course = %s",std[i].student_course);  
     printf("\nIssued book id = %d\n",*std[i].issued_bookid);

  }
  fclose(fp);

}


void change_password()
{
  char pwd[50];
  FILE *fp;
  fp= fopen("password.txt","w");
  printf("Enter New Password: ");
  fseek(stdin,0,SEEK_END);
  scanf("%s",&pwd);
  fputs(pwd,fp);
  fclose(fp);
}
    
void tested()
{
    int j;
    SYSTEMTIME stime;
    GetSystemTime(&stime);
    printf("Todays's date: %d/%d/%d",stime.wDay,stime.wMonth,stime.wYear);
    int noOfdayinmonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    submit.da_day = (int)stime.wDay+15;
    submit.da_mon = (int)stime.wMonth;
    submit.da_year = (int)stime.wYear;
    if(noOfdayinmonth[(int)stime.wMonth] < submit.da_day)
    {
        submit.da_day -=  noOfdayinmonth[(int)stime.wMonth];

        submit.da_mon +=1;
        if(submit.da_mon>12){
            submit.da_mon -= 12;
            submit.da_year += 1; 
        }
        else
            submit.da_year=(int)stime.wYear;
    }
    else{
        submit.da_mon=(int)stime.wMonth;
        submit.da_year=(int)stime.wYear;
    }
  //  printf("\nReturn date: %d/%d/%d",submit.da_day, submit.da_mon, submit.da_year);
}