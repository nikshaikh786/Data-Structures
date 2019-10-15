#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<dos.h>
typedef struct{
	char name[50];
	int train_num;
	int num_of_seats;
}pd;

//Functions
void reservation(void);							// reservation function
void viewdetails(void);							//view details of all the trains
void cancel(void);								
void printticket(char name[],int,int,float);	//print ticket 
void specifictrain(int);						//print data related to specific train
float charge(int,int);							//charge automatically w.r.t number of seats and train
void login();
void disp();
int main()

{  
	time_t t;
	int i;
	time(&t);
		system("cls");
	printf("\t\t\t\t=================================================\n");
	printf("\t\t\t\t|*                                             *|\n");
	printf("\t\t\t\t|*       -----------------------------         *|\n");
	printf("\t\t\t\t|*          TRAIN TICKET RERS. SYSTEM          *|\n");
	printf("\t\t\t\t|*       -----------------------------         *|\n");
	printf("\t\t\t\t|*                                             *|\n");
	printf("\t\t\t\t|*                                             *|\n");
	printf("\t\t\t\t|*                                             *|\n");
	printf("\t\t\t\t|*             !! WELCOME TO                   *|\n");
	printf("\t\t\t\t|*          |   INDIAN RAILWAY !! |            *|\n");
	printf("\t\t\t\t|*                                             *|\n");
	printf("\t\t\t\t=================================================\n");
	printf("\t\t\t\t\t  %s\n\n\n",ctime(&t));
	printf(" \n Press any key to continue:");
	
	getch();	
    system("cls");
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n=================================\n");
	printf("    TRAIN RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n1-->> Book A Ticket");
	printf("\n------------------------");
	printf("\n2-->> View All Trains");
	printf("\n------------------------");
	printf("\n3-->> Cancel Ticket ");
	printf("\n------------------------");
	printf("\n4-->> To Terminate The Code");
	printf("\n------------------------");
	printf("\n5-->> LOGOUT");
	printf("\n------------------------");
    printf("\n6-->> View Pasengers Details..");
	printf("\n------------------------");
	printf("\n\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{  
        
		case 1:
			reservation();		//Fucntion still not added
			break;
		case 2:
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 3:
			cancel();
			//function not added. code has been removed due to some errors
			break;
		case 4:
			return(0);
		case 5:
			printf("LOGOUT SUCCESSFULLY.!!!!!!");
			login();
		case 6:
			disp();
		default:
			printf("\nInvalid choice");
      
	}
	goto start;
	
	return(0);
}

/*********************************************VIEWDETAILS()**********************************************/
void viewdetails(void)
{ 
	system("cls");
	printf("-----------------------------------------------------------------------------");	
	printf("-----------------------------------------------------------------------------");
	printf("\nTr.no:12925\nName:Paschim  Express\nDestination:Mumbai(Bandra Terminus) To Hazrat Nizamuddin Dargah(Delhi)\nCharges:Rs.500\nTime:12pm\n");
	printf("\nTr.no:15017\nName:Kashi Express\nDestinations:Mumbai CSMT To Varansi\nCharges:Rs.600\nTime:6:30pm\n");
	printf("\nTr.no:11061\nName:Pawan Express\nDestinations:LTT(Mumbai) To Darbhanga\nCharges:Rs.640\nTime12:15pm\n");
	printf("\nTr.no:12925\nName:Paschim(DELUX) Express\nDestinations:Bantra T. To Vadodara\nChatges:Rs.685\nTime:12am\n");
	printf("\nTr.no:16345\nName:Netravati Express\nDestinations:Tilak T. To MADGAON\nCharges:Rs.320\nTime:3:20am\n");
	printf("\nTr.no:17031\nName:Mumbai CSMT Express\nDestinations:Mumbai CSMT To Pune JN\nCharges:Rs.145\nTime:12:45am\n");
    printf("\nTr.no:19707\nName:Amrapur Arawali Express\nDestinations:Bandra T. To Jaipur\nCharges:Rs.495\nTime:5pm\n");	
    printf("\nTr.no:11027\nName:Chennai Express\nDestinations:Mumbai CSMT To Chennai Central\nCharges:Rs.540\nTime:11:45pm\n");
    printf("\nTr.no:12859\nName:Gtanjali Express\nDestinations:Mumbai CSMt To Howrah JN.\nCharges:Rs.740\nTime:6am\n");
    printf("\nTr.no:17318\nName:Hubballi Express\nDestinations:LTT(Mumbai) To Belagavi\nCharges:Rs.330\nTime:6.45pm\n");
    
}

/*********************************************RESERVATION()*************************************************/
void reservation(void)
{  
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");
	
	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	//error here have to take input of the name 
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Trains<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter train number:> ");
	start1:
	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num==12925 || passdetails.train_num==15017 || passdetails.train_num==11061 || passdetails.train_num==12925 || passdetails.train_num==16345 || passdetails.train_num==17031 || passdetails.train_num==19707 || passdetails.train_num==11027 || passdetails.train_num==12859 || passdetails.train_num==17318)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);		
	}
 
	else
	{
		printf("\nInvalid train Number! Enter again--> ");
		goto start1;
	}
	
	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"\n%s\t\t\t\t%d\t\t\t\t%d\t\t\t%2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();

}
void  disp(void)
{   char ch;
    FILE *fp;
	fp=fopen("seats_reserved.txt","r");
	if(fp==NULL)
	 {
	 	printf("Error while opening the file.....");
	 	exit(0);
	 }
	 else
	  {
	  	printf("The Detail Of Pasengers Are.....\n");
	  	  while((ch=fgetc(fp)) !=EOF)
			{
			
	  	     printf("%c",ch);
	        }
	  	fclose(fp);
	  
	  	getch();
    }
}
/*********************************************CHARGE()*************************************************/
float charge(int train_num,int num_of_seats)
{
		if (train_num==12925)
	{
		return(500.0*num_of_seats);
	}
	if (train_num==15017)
	{
		return(600*num_of_seats);
	}
	if (train_num==11061)
	{
		return(640.0*num_of_seats);
	}
	if (train_num==12925)
	{
		return(685.0*num_of_seats);
	}
	if (train_num==16345)
	{
		return(320.0*num_of_seats);
	}
	if (train_num==17031)
	{
		return(145.0*num_of_seats);
	}
	if (train_num==19707)
	{
		return(495.0*num_of_seats);
	}
	if (train_num==11027)
	{
		return(540.0*num_of_seats);
	}
	if (train_num==12859)
	{
		return(740.0*num_of_seats);
	}
	if (train_num==17318)
	{
		return(330.0*num_of_seats);
	}
}


/*********************************************PRINTTICKET()*************************************************/

void printticket(char name[],int num_of_seats,int train_num,float charges)
{   int num=1;
	system("cls");
	printf("\t-------------------\n");
	printf("\t\tTICKET\n");
	printf("\t-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nTrain Number:\t\t%d",train_num);
	specifictrain(train_num);
	printf("\nCharges:\t\t%.2f",charges);
	
}

/*********************************************SPECIFICTRAIN()*************************************************/

void specifictrain(int train_num)
{
	
	if (train_num==12925)
	{
		printf("\nTrain:\t\t\tPaschim  Express");
		printf("\nDestination:\t\tMumbai(Bandra Terminus)"); 
		printf("To Hazrat Nizamuddin Dargah(Delhi)");
		printf("\nDeparture:\t\t12pm ");
	}
	if (train_num==15017)
	{
		printf("\nTrain:\t\t\tKashi Express");
		printf("\nDestination:\t\tMumbai CSMT To Varansi");
		printf("\nDeparture:\t\t6:30pm");
	}
	if (train_num==11061)
	{
		printf("\nTrain:\t\t\tPawan Express");
		printf("\nDestination:\t\tLTT CSMT To Darbhanga");
		printf("\nDeparture:\t\t12:15pm");
	}
	if (train_num==12925)
	{
		printf("\nTrain:\t\t\tPaschim(DELUX) Express");
		printf("\nDestination:\t\tBantra T. To Vadodara");
		printf("\nDeparture:\t\t12am ");
	}
	if (train_num==16345)
	{
		printf("\nTrain:\t\t\tNetravati Express");
		printf("\nDestination:\t\tTilak T. To MADGAON");
		printf("\nDeparture:\t\t3:20am");
	}
	if (train_num==17031)
	{
		printf("\ntrain:\t\t\tMumbai CSMT Express");
		printf("\nDestination:\t\tMumbai CSMT To Pune JN");
		printf("\nDeparture:\t\t12.45am ");
	}
	if (train_num==19707)
	{
		printf("\ntrain:\t\t\tAmrapur Arawali Express");
		printf("\nDestination:\t\tAmrapur Arawali Express");
		printf("\nDeparture:\t\t5pm ");
	}
	if (train_num==11027)
	{
		printf("\ntrain:\t\t\tChennai Express");
		printf("\n Destination:\t\tMumbai CSMT To Chennai Central");
		printf("\nDeparture:\t\t11:45pm ");
	}
	if (train_num==12859)
	{
		printf("\ntrain:\t\t\tGitanjali Express");
		printf("\nDestination:\t\tMumbai CSMt To Howrah JN.");
		printf("\nDeparture:\t\t6am ");
	}
	if (train_num==17318)
	{
		printf("\ntrain:\t\t\tHubballi Express");
		printf("\nDestination:\t\tLTT(Mumbai) To Belagavi");
		printf("\nDeparture:\t6:45pm ");
	}
}

 void login()
{  
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
abc : do
{
	 //setcolor(12);
    printf("\n\t\t\t  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n\t\t\t                       ENTER USERNAME:-");
	scanf("%s", &uname); 
	printf(" \n\t\t\t                       ENTER PASSWORD:-");
 	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0; 
	 if(strcmp(uname,"admin")==0 && strcmp(pword,"admin")==0)
	{
	
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL PLEASE TRY AHGAIN...");
		a++;
		goto abc;
		getch();//holds the screen
		system("cls");
	}
}
   	while(a<=2);
	if (a>2)
     {
	 
		
		getch();
			
		}

		system("cls");	
}

void cancel(void)   
{
	int trainnum;
	char name[50];
	system("cls");
	printf("-----------------------\n");
		printf("Enter the train number: \n");
			printf("-----------------------\n");
		fflush(stdin);
		scanf("%i",&trainnum);
		printf("Enter name ");
		scanf("%s",&name);
sleep(10);
		   printf("\tCancelation is Successfull");
		
		getch();
	}
	
