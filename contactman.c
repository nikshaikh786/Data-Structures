#include<stdio.h>

//#include<conio.h>  //for using console

#include<string.h> //for using string built in functons

//#include<process.h> //working with threads and processes

#include<stdlib.h>  //memory allocations,process control 


void add(void);      //adding a contact
void listing (void);  //printing all contacts
void searching(void); //searching function 
void deleting(void);  // to delete a contact

struct contact    //structure to store all information
{
    long ph;
    char name[20],add[20],email[30];
} list;

char query[20],name[20];
FILE *fp, *ft;
int i,n,ch,l,found;

void add()
{
    system("clear");//it clears the current screen and print the output in new blank screen and it present in stdlib.h header file

        fp=fopen("contact.txt","a");// creating a file named contact.txt to store data 

        for (;;)  //for loop 

        {
            fflush(stdin);  //use to flush/clean the file and it is present in stdio.h

            printf("To exit enter blank space in the name input\nName (Use identical):");

            scanf("%s",&list.name);//%[^]indicates that user can input anything e.g " " space

            if(strcmp(list.name,"")==0 || strcmp(list.name," ")==0)//compare string without thinking of UPPERCASE or lowercase

                break;

            fflush(stdin);  //use to flush/clean the file 

            printf("Phone:");

            scanf("%ld",&list.ph);

            fflush(stdin);  //use to flush/clean the file

            printf("address:");

            scanf("%s",&list.add); //%[^]indicates that user can input anything e.g " " space

            fflush(stdin);  //use to flush/clean the file

            printf("email address:");

            scanf("%s",&list.email);
            fflush (stdin);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp); // fwrite(ptr,int size,int n,FILE *p) where ptr is reference of structure,size is total no of bytes to be written and fp is FILE where data should be saved
break;
        }
        fclose(fp); //closing the file 
}

void listing()
{
    system("clear");//it clears the current screen and print the output in new blank screen and it present in stdlib.h header file

        printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n=================================================================\n\n");

        for(i=97; i<=122; i=i+1)
        {

            fp=fopen("contact.txt","r"); // opening a file and reading its content  

            fflush(stdin);  //use to flush/clean the file

            while(fread(&list,sizeof(list),1,fp)==1) //fread(ptr,int size,int n,FILE *p) where ptr is reference of structure,size is total no of bytes to be read and fp is FILE where data is stored

            {

                if(list.name[0]==i || list.name[0]==i-32)//name should always contain any character from a-z or A-Z

                {

                    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n",list.name,list.ph,list.add,list.email);

                }

            }
            fclose(fp); //closing the file

        }
}

void searhing()
{
    system("clear");//it clears the current screen and print the output in new blank screen and it present in stdlib.h header file

        do

        {

            found=0;

            printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of contact to search: ");

            fflush(stdin);  //use to flush/clean the file

            scanf("%s",&query); //%[^]indicates that user can input anything e.g " " space

            l=strlen(query); //strlen gives total length of string

            fp=fopen("contact.txt","r"); // opening a file and reading its content

            system("clear");//it clears the current screen and print the output in new blank screen and it present in stdlib.h header file

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1) //fread(ptr,int size,int n,FILE *p) where ptr is reference of structure,size is total no of bytes to be read and fp is FILE where data is stored

            {
				    
                if(strcmp(list.name,query)==0) //compare string without thinking of UPPERCASE or lowercase

                {

                    printf("\n..::Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n..::Email\t: %s\n",list.name,list.ph,list.add,list.email);

                    found++;
                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found); //total number of matches found in data

            fclose(fp); //closing the file

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");  //if wanna continue

            scanf("%d",&ch);

        }
        while(ch==1);   //if want to search again click 1 else click 0
}

void deleting()
{
           system("clear");//it clears the current screen and print the output in new blank screen and it present in stdlib.h header file and it can only be run on windows
      	  // system("clear");//this is use for linux based operating system    

        fflush(stdin);  //use to flush/clean the file

        printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of contact to delete:");

        scanf("%s",&query);  //%[^]indicates that user can input anything e.g " " space

        fp=fopen("contact.txt","r"); // opening a file and reading its content

        ft=fopen("temp.txt","w");  //creating temporary file 

        while(fread(&list,sizeof(list),1,fp)!=0)  //fread(ptr,int size,int n,FILE *p) where ptr is reference of structure,size is total no of bytes to be read and fp is FILE where data is stored

            if (strcmp(query,list.name)!=0) //compare string without thinking of UPPERCASE or lowercase

                fwrite(&list,sizeof(list),1,ft);  //writing structure into ft file

        fclose(fp); //closing the file

        fclose(ft); //closing the ft file

        remove("contact.txt");  //removing original file. remove is an inbuilt function present in stdio.h

        rename("temp.txt","contact.txt"); //changing the temporary file into permanent file.rename is an inbuilt function present in stdio.h
}

int main()
{

main:

    system("clear");//it clears the current screen and print the output in new blank screen and it present in stdlib.h header file    /* ************Main menu ***********************  */

    printf("\n\t **** Welcome to Contact Management System ****");

    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Delete a Contact\n\t\t[0] Exit\n\t\t=================\n\t\t");

    printf("Enter the choice:");

    scanf("%d",&ch);

    switch(ch)
    {
    case 0:
    printf("\n\n\t\tAre you sure you want to exit?");
    break;

    case 1:
    add();    //add new Contacts
    break;
        
    case 2:
    listing();  //list of contacts
    break;

    case 3:
    searhing();  //search
    break;

    case 4:
    deleting();  //delete a contact
    break;

    default:
    printf("Invalid choice");
    
    }

invalid:

    printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1:
    goto main;

    case 0:
    break;

    default:
    printf("Invalid choice");
    goto invalid;
    }
    
    return 0;
}

