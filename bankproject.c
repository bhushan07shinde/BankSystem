#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
//Project Name :- Bank Manegment System
//Created by   :- @BHUSHAN SHINDE
//Date         :- 27-09-2020
//IDE use      :- Visual Studio Code
//Take ideas from these project but do not copy it Please !!!!
//For turbo C++ use -clrscr- instead of system("cls");

void newAccount();
void AccountInfo();
void AddCash();
void getCash();
void AtmPin();


struct date
{
    int day,month,year;
};

struct bankproject
{
    char name[90];
    int  age;
    double mobile;
    double  Adhar;
    struct date dob;
    float amount;
    double Account_no;
    char password[90];
    double cardNo;
    int pin;


}new,check,add,withdraw,ATM;


 void newAccount()
   {

      char ch;
      char x[90];
      int i,d,z,p,b;
	  int choice;

      FILE *fp;
      d=z=p=b=0;
      fp=fopen("bankData.txt","a+");
     creatAccount:
     system("cls");
       printf("\nEnter Account No==>");
       scanf("%lf",&new.Account_no);

	    printf("\nEnter your name==>");
	    scanf(" %s", new.name);
	    printf("Enter your Age==>");
	    scanf("%d",&new.age);
	    printf("Enter your mobile number==>");
	    scanf("%lf",&new.mobile);
	    printf("Enter your Adhar no==>");
	    scanf("%lf",&new.Adhar);
	    printf("Enter your birth date(dd/mm/yy)==>");
	    scanf("%d/%d/%d/",&new.dob.day,&new.dob.month,&new.dob.year);
	    printf("Enter Amount to Add in Account==>");
	    scanf("%f",&new.amount);
	    retype:
	    printf("\nPassword must be include special sym(!@#$^&*) one Number and both SMALL and capital Letters\n");
	    printf("Enter your password==>");
	    scanf("%s",new.password);


   strcpy(x,new.password);

    for(i=0;x[i]!='\0';i++)
    {
	if(x[i]>=48&&x[i]<=57)
	{
	    d++;

	}
	if(x[i]>=65&&x[i]<=90)
	{
	    b++;
	}
	if(x[i]>=97&&x[i]<=122)
	{
	    z++;
	}
	if(x[i]=='#'||x[i]=='@'||x[i]=='&'||x[i]=='*'||x[i]=='%'||x[i]=='!')
	{
	    p++;
	}
    }
    if(d>=1&&b>=1&&z>=1&&p>=1)
    {
	printf("\n DONE !!!");
    }
    else
    {
	printf("\nWRONG @@@\n");
	goto retype;
    }

	   fprintf(fp,"\n%lf \n%s \n%d \n%lf \n%lf \n%d/%d/%d/ \n%f \n%s",new.Account_no,new.name,new.age,new.mobile,new.Adhar,new.dob.day,new.dob.month,new.dob.year,new.amount,new.password);
	   fprintf(fp,"\n====================================================================================================================================================================\n");
	   fclose(fp);
	   printf("\nAccount Created Successfuly.............");
	   printf("\nGoto Main menu press 1 for exit press 2");
	   scanf("%d",&choice);
	   if(choice==1)
	   {
		    main();
	   }
	   else 
	   {
		   exit(0);
	   }
   }

   void AccountInfo()
   {
       char y[90];
       int no;
	   int choice;
       FILE *read;
       system("cls");

       read=fopen("bankData.txt","r");

       printf("Please Enter Your Password==>");
       scanf("%s",y);

       while(fscanf(read,"%lf %s %d %lf %lf %d/%d/%d/ %f %s",&new.Account_no,new.name,&new.age,&new.mobile,&new.Adhar,&new.dob.day,&new.dob.month,&new.dob.year,&new.amount,new.password)!=EOF)
	{
	  no=strcmp(y,new.password);
	  if(no==0)
	  {
	     printf("\nName: %s \nAccount No: %lf \nBalance: %f",new.name,new.Account_no,new.amount);
	     break;


	  }
	 else
	  {
	   printf("\nWrong");
	   break;

	 }
       }
       fclose(read);
	   printf("\nGoto Main menu press 1 for exit press 2");
	   scanf("%d",&choice);
	   if(choice==1)
	   {
		    main();
	   }
	   else 
	   {
		   exit(0);
	   }
   }

 void AddCash()
 {
       char y[90];
       int no;
       int accNo;
	   int choice;
       FILE *old;
       FILE *depos;
       system("cls");

       old=fopen("bankData.txt","r");
       depos=fopen("addingAmountBankData.txt","w");

       printf("Enter Your Account No==>");
       scanf("%d",&accNo);
       printf("Please Enter Your Password==>");
       scanf("%s",y);


       while(fscanf(old,"%lf %s %d %lf %lf %d/%d/%d/ %f %s",&new.Account_no,new.name,&new.age,&new.mobile,&new.Adhar,&new.dob.day,&new.dob.month,&new.dob.year,&new.amount,new.password)!=EOF)
	{
	  no=strcmp(y,new.password);
	  if(no==0&&accNo==new.Account_no)
	  {

	     printf("\nEnter your ammount tobe add in Account==>");
	     scanf("%f",&add.amount);
	     new.amount=add.amount+new.amount;
	     printf("\nAmmount Added Successfuly......");
	     printf("\nTotal Balance In Account now==>%f",new.amount);
	      fprintf(depos,"\n%lf \n%s \n%d \n%lf \n%lf \n%d/%d/%d/ \n%f \n%s",new.Account_no,new.name,new.age,new.mobile,new.Adhar,new.dob.day,new.dob.month,new.dob.year,new.amount,new.password);
	      fprintf(depos,"\n====================================================================================================================================================================\n");

	     break;


	  }
	 else
	  {
	   printf("\nWrong");
	   break;

	 }

       }
       fclose(old);
       fclose(depos);
       remove("bankData.txt");
       rename("addingAmountBankData.txt","bankData.txt");
	   printf("\nGoto Main menu press 1 for exit press 2");
	   scanf("%d",&choice);
	   if(choice==1)
	   {
		    main();
	   }
	   else 
	   {
		   exit(0);
	   }
 }

void getCash()
{
    char y[90];
       int no;
       int accNo;
	   int choice;
       FILE *old;
       FILE *with;
       system("cls");

       old=fopen("bankData.txt","r");
       with=fopen("withdrawAmountBankData.txt","w");

       printf("Enter Your Account No==>");
       scanf("%d",&accNo);
       printf("Please Enter Your Password==>");
       scanf("%s",y);


       while(fscanf(old,"%lf %s %d %lf %lf %d/%d/%d/ %f %s",&new.Account_no,new.name,&new.age,&new.mobile,&new.Adhar,&new.dob.day,&new.dob.month,&new.dob.year,&new.amount,new.password)!=EOF)
	{
	  no=strcmp(y,new.password);
	  if(no==0)
	  {

	     printf("\nEnter your ammount tobe Withdraw in Account==>");
	     scanf("%f",&withdraw.amount);

	     if(withdraw.amount>=new.amount||new.amount==100)
	     {
		 printf("Sorry You Can not withdraw full amount or you have less than 100rs in your account..");
		 break;
	     }
	     else
	     {
	       new.amount=new.amount-withdraw.amount;
	       printf("\nAmmount Withdraw Successfuly......");
	       printf("\nTotal Balance In Account now==>%f",new.amount);
	       fprintf(with,"\n%lf \n%s \n%d \n%lf \n%lf \n%d/%d/%d/ \n%f \n%s",new.Account_no,new.name,new.age,new.mobile,new.Adhar,new.dob.day,new.dob.month,new.dob.year,new.amount,new.password);
	       fprintf(with,"\n====================================================================================================================================================================\n");

	     }

	     break;

	  }
	 else
	  {
	   printf("\nWrong");
	   break;

	 }

       }
       fclose(old);
       fclose(with);
       remove("bankData.txt");
       rename("withdrawAmountBankData.txt","bankData.txt");
	   printf("\nGoto Main menu press 1 for exit press 2");
	   scanf("%d",&choice);
	   if(choice==1)
	   {
		    main();
	   }
	   else 
	   {
		   exit(0);
	   }
}

void AtmPin()
{
     char y[90];
     int fspin;
     int lspin;
	 int choice;

       int no;
       int accNo;
       FILE *old;
       FILE *card;
       system("cls");

       old=fopen("bankData.txt","r");
       card=fopen("ATMgenrate.txt","w");

       printf("Enter Your Account No==>");
       scanf("%d",&accNo);
       printf("Please Enter Your Password==>");
       scanf("%s",y);


       while(fscanf(old,"%lf %s %d %lf %lf %d/%d/%d/ %f %s",&new.Account_no,new.name,&new.age,&new.mobile,&new.Adhar,&new.dob.day,&new.dob.month,&new.dob.year,&new.amount,new.password)!=EOF)
	{
	  no=strcmp(y,new.password);
	  if(no==0)
	  {

	     printf("\nEnter your Card No==>");
	     scanf("%lf",&ATM.cardNo);

	     printf("\nEnter First Two Digit You Want Save As pin");
	     scanf("%d",&fspin);

	     srand(time(0));
	     lspin=rand()%99;

	     printf("\nNow put fisrt your two no and then this no==> %d together",lspin);
	     scanf("%d",&ATM.pin);

	     printf("You have successfuly genaret your 4 Digit pin Please Do not share it==>%d",ATM.pin);




	       fprintf(card,"\n%lf \n%s \n%d \n%lf \n%lf \n%d/%d/%d/ \n%f \n%s \n%lf \n%d",new.Account_no,new.name,new.age,new.mobile,new.Adhar,new.dob.day,new.dob.month,new.dob.year,new.amount,new.password,ATM.cardNo,ATM.pin);
	       fprintf(card,"\n====================================================================================================================================================================\n");


	     break;


	  }
	 else
	  {
	   printf("\nWrong");
	   break;

	 }

       }
       fclose(old);
       fclose(card);
       remove("bankData.txt");
       rename("ATMgenrate.txt","bankData.txt");
	   printf("\nGoto Main menu press 1 for exit press 2");
	   scanf("%d",&choice);
	   if(choice==1)
	   {
		   int main();
	   }
	   else 
	   {
		   exit(0);
	   }

}



int main()
{
    int option;
    system("cls");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t CREATED BY :- BHUSHAN SHINDE");
    printf("\n\n******** BANK MANEGMENT SYSTEN *********");

    printf("\n       press following options");

    printf("\n       1.Create New Account\n       2.Get info of your Account\n       3.Add Cash\n       4.Withdraw Cash\n       5.Genrate ATM Pin");
    printf("\n\n      Enter your option here==>");
    scanf("%d",&option);

    switch(option)
    {
	case 1:
	newAccount();
	break;

	case 2:
	AccountInfo();
	break;

	case 3:
	AddCash();
	break;

	case 4:
	getCash();
	break;

	case 5:
	AtmPin();
	break;
    }
  getch();

}




