#include<stdio.h>
#include<stdlib.h>
#include<string.h>

///Logic Functions

 /// Update, Delete & Insert Function
void insertfood(int data, char foodname[25], int quantity, float price);
void updatefood(int udata, int uquantity);
void deletefood(int serial);

 /// Display Function
void foodlist();
void order_view(int order, int quantity, int or_no);
void main_menu();
void welcomeScr();

///extra design Function
void echo(char print[]);
void br(int line);
void pre(int tab);
void span(int space);
void middleln(void);
void midtab(void);


///START Structure Here
struct Node
{
	char foodname[50];
	int quantity;
	float price;
	int data;
	struct Node *next;
};

///Global Linked List.
typedef struct Node node ;
node *head, *list;

int main()
{

	 
	welcomeScr();

	 

	int c=0; int any;
	int cardno[100];
	float cardmoney[100];
	float totalmoney = 0;
	int total_order[100];
	int order_quantity[100];
	int order=0;
	int uquantity;
	int citem;

	head = NULL;
	insertfood(1," Lava Cake   ",8,720.83);
	insertfood(2,  "Coffee       ",46,70.23);
	insertfood(3,  "Ice-Cream    ",46,70.23);
	insertfood(4,  "Sandwich     ",34,60.23);
	insertfood(5,  "Burger       ",23,120.23);
	insertfood(6,  "Pizza        ",13,100.67);
	insertfood(7,  "Hot Chocolate",7,520.29);
	insertfood(8,  "Garlic-Bread ",121,35.13);
	insertfood(9,  "Cold Drinks  ",73,20.13);


	mainmenu:
	br(1);

	main_menu();

	int main_menu_choice;

	br(1); pre(4); scanf("%d",&main_menu_choice);

	if((main_menu_choice >=1 && main_menu_choice <=3))
	{

		if(main_menu_choice == 1)
		{
			foodlist:

			 
			printf("=> 0. Main Menu ");
			foodlist();
		}
		else if( main_menu_choice == 2)
		{
			adminpanelchoice :
			{

			int admin_panel_choice;

			  middleln() ;   pre(4);  printf("1. Main Menu\n\n\t"); 
			printf("Please Enter Password or ( 1 to Back in Main Menu ) : ");


			   scanf("%d",&admin_panel_choice);

			if(admin_panel_choice==123321)
			{
				node *temp;
				temp = list;

				adminchoise:

				   br(5); pre(4); echo("You are on Admin Pannel\n\n");
				pre(4);
				printf(" 1. Total Cash Today \n\n");pre(4);
				printf(" 2. View Card Pay \n\n");pre(4);
				printf(" 3. Add Food \n\n");pre(4);
				printf(" 4. Delete Food \n\n");pre(4);
				printf(" 5. Instant Food List \n\n");pre(4);
				printf(" 6. Instant Order Preview\n\n");pre(4);
				printf(" 0. Main Menu \n\n");
				printf("Enter Your From 1-0: ");
				
				int adminchoise;

				    scanf("%d",&adminchoise);

				if(adminchoise==1)
				{
					   middleln(); pre(4);   printf("Todays Total Cash : %0.2f  \n",totalmoney);
					 
					goto adminchoise;
				}
				else if(adminchoise==2)
				{
					if(c!=0)
					{
						   br(3); pre(4);

						printf(" ____________________________\n");pre(4);
						printf("|   Card NO.   |   Money $   |\n");pre(4);
						printf("------------------------------\n");pre(4);

						for(int z=1; z<=c;z++)
						{
							printf("|  %d  | %0.2f |\n",cardno[z],cardmoney[z]);pre(4);
							printf("------------------------------\n");pre(4);
						}
					}

					if(c==0)
					{
						   middleln(); pre(4);
					    printf("No Card History\n");
					}
					
					goto adminchoise;
				}

				else if(adminchoise==3)
				{
					foodadd:
                    {

					 

					char ffoodname[25];
					int fquantity;
					int fdata;
					float fprice;
					int fposi;


					br(3);pre(4);  
					printf(" Enter Food Name :  ");
					scanf("%s",&ffoodname);
					fquantity:
					 

					br(2);pre(4);
					printf(" Enter Food Quantity :  ");

					scanf("%d",&fquantity);  

                        foodserial:
					br(2);pre(4);  printf(" Enter Food Serial :  ");
                      scanf("%d",&fdata);
                            node *exist;
                            exist = list;
                      while(exist->data!=fdata)
					  {
                            if(exist->next==NULL)
							{
                                break;
                            }
                        exist=exist->next;
                      }
                      if(exist->data==fdata)
					  {
                         br(5);pre(3);  printf(" Food Serial Already Exist, Please Re-Enter!! ");
                       goto foodserial;
                      }

                    fprice:
                       

					br(2);pre(4);  printf(" Enter Food Price :  "); 

					scanf("%f",&fprice);



					br(2);pre(4);  printf("Submiting your data");

					for(int cs=0;cs<4;cs++)
					    printf(" .");
					
					insertfood(fdata,ffoodname,fquantity,fprice);

					br(2);pre(4);     
					printf("Adding Food  Successfull....\n");
					
					goto adminchoise;
                }

				}
				else if(adminchoise==4)
				{
					 
					middleln();pre(2);
					printf("Enter Serial No of the Food To Delete : ");
					fdelete :
					{
					int fdelete;
					  scanf("%d",&fdelete);
					node *temp;
					temp=list;
					while(temp->data != fdelete)
					{
						temp = temp->next;
					}
					if(temp->data==fdelete)
					{
						deletefood(fdelete);
					}
					else
					{
						br(2); pre(2); printf("Please Enter Correct Number :  ");
						goto fdelete;
					}
					}
                    
					goto adminchoise;
				}

				else if(adminchoise==5)
				{
					 
					foodlist();
     				br(2);
					pre(4);
					printf("1. <-- back  \n\n");pre(5);
					scanf("%d",&any);

                    
					goto adminchoise;

				}

				else if(adminchoise==6)
				{
					 br(2);pre(2);
					
					printf("\n\t\t"); 
					printf("______________________________________________________ "); 
					printf("\n\t\t");  
					printf("|  Order No.  |   FooD Name   |  Quantity |  In Stock |");
					printf("\n\t\t");  
					printf("------------------------------------------------------"); 
					for(int o=1;o<=order;o++){
						order_view(total_order[o],order_quantity[o],o);
					}

					br(2);pre(4);  printf("1. <-- back  \n\n");pre(5);

					    scanf("%d",&any);

					
					goto adminchoise;

				}
				else if(adminchoise==0)
				{
					goto mainmenu;
				}

				else
				{
					br(2); pre(4); printf("Please Select From List :  "); 
					goto adminchoise;
				}



			}

			else if(admin_panel_choice==1)
			{
				goto mainmenu;
			}
			else
			{
				br(2); pre(4);  printf("Please Enter Correct Choice");
				goto adminpanelchoice;
			}

			}

		}

		else if(main_menu_choice==3)
		{
			 
			middleln(); pre(3); printf("Thank You For Using Our System \n\n\n\n\n\n\n");
			exit(1);
		}

	}
	else
	{
		br(2); pre(4); printf("Please Enter Correct Choice");
		goto mainmenu;
	}

	int get_food_choice;

	br(2); pre(3); 
	printf("Place Your Order: ") ;
	scanf("%d",&get_food_choice);

	if(get_food_choice==0)
	{
		goto mainmenu;
	}

	node *temp;
	temp = list ;

	while(temp->data != get_food_choice)
	{
		temp = temp->next;
		if(temp==NULL)
		{
			br(2); pre(4);  echo("Please Choice From List: "); br(2);
			goto foodlist;
		}

	}
	if(get_food_choice == temp->data)
	{
		fcquantity:
		br(2); pre(4);
		printf("Enter Food Quantity : ");

		int fcquantity;
	    scanf("%d",&fcquantity);  

		if(fcquantity==0)
		{
			  middleln();pre(3); printf("Quantity Can not be Zero ");
			 
			goto foodlist;
		}
		else if(fcquantity>temp->quantity)
		{
			  middleln();pre(3); printf("Out of Stock ! ");

			goto foodlist;
		}

		middleln();pre(4);  printf("Choice food %s  its price is %0.2f \n\n",temp->foodname,temp->price*fcquantity);pre(4);
		printf("1. Confirm to buy this \n\n");pre(4);
		printf("2. Food List \n\n");
		printf("Press 1 to confirm and 2 to back to list :");

		confirm:
		{
			int confirm;

			scanf("%d",&confirm);

			if(confirm == 1 )
			{
				br(2);pre(4);
				printf(" 1. Cash ");
				br(2);pre(4);
				printf(" 2. Credit\n");
				printf("Select Method Of payment 1-2: ");

				payment:
				{
				int payment;

				scanf("%d",&payment);

				if(payment==1)
				{
					totalmoney += temp->price*fcquantity;
					order++;
					total_order[order]=get_food_choice;
					order_quantity[order]=fcquantity;
					uquantity = temp->quantity - fcquantity;

					updatefood(get_food_choice,uquantity);


					 middleln();pre(4);  printf("===>THANK YOU<===");
					br(2);pre(4);  printf("Food Ordered Successfully ...");
					br(2);pre(4);  printf("1. Wanna Buy Another Delicacy ? ");
					br(2);pre(4);  printf("2. Main Menu \n");
					br(2);pre(4);   printf("Select: ");
					psmenu:
					{
					int ps_menu;

					scanf("%d",&ps_menu);

					if(ps_menu==1)
					{
						goto foodlist;
					}
					else if(ps_menu==2)
					{
						goto mainmenu;
					}
					else
					{
						br(2);pre(4);printf("Please Choice from list : "); goto psmenu;
					}
					}

				}

			///Credit Card Option

			else if(payment==2)
			{
				int card_number[100];

				c++;

				middleln();pre(4); printf("Enter Your Card No : ");
     		    scanf("%d",&card_number[c]);

				cardno[c] = card_number[c];

				int pin;

				br(2);pre(2);  
				printf("Enter Your Card Pin [we never save your pin]  : ");
     		    
				scanf("%d",&pin);

				cardmoney[c] = temp->price*fcquantity;

				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;

				uquantity = temp->quantity - fcquantity;

				updatefood(get_food_choice,uquantity);

				br(2);pre(4);  printf("Payment Success...");
				br(2);pre(4);    printf("1. Wanna Buy Another Delicacy ? ");
				br(2);pre(4);    printf("2. Main Menu \n");
				br(2);pre(4);   printf("select: ");

				psmenu2:
				{
				int ps_menu2;

				scanf("%d",&ps_menu2);

				if(ps_menu2==1)
				goto foodlist;

				else if(ps_menu2==2)
				goto mainmenu;

				else
				{
					br(2);pre(4);printf("Please Choice from list : ");
				    goto psmenu2;
				}
				}

			}

			else
			{
				br(2);pre(4);   printf("Enter Choice from List : ");

				goto payment;
			}
			}


		}    ///END Confirm Y/y



		else if(confirm == 2)
		{
			goto foodlist;
		}

		else
		{
			br(2);pre(4);    printf("Enter Choise from List : ");

			goto confirm;
		}
		}  ///end confirm;


	}  ///end get food choice if line


	else
	{
		br(2);pre(4);  echo("Please Choice From List "); br(2);
		goto foodlist;

	}  ///end get food choice
}

void echo(char print[])
{
	printf("%s",print);
}

void br(int line)
{
    for(int i=0; i<line;i++)
        {
		printf("\n");
	    }
}

void pre(int tab)
{
	for(int i=0; i<tab;i++)
	{
		printf("\t");
	}

}
void span(int space)
{
	for(int i=0; i<space;i++)
	{
		printf(" ");
	}

}

void main_menu()
{
	 
    br(2);pre(5); echo(" H O W 'S   T H E   F O O D ?"); 
    br(1);pre(6); echo(" HOT SIR!!!"); 

	br(5); pre(3); echo("===> 1. Food List"); 
	br(2); pre(3); echo("===> 2. Admin Panel"); 
	br(2); pre(3); echo("===> 3. Exit"); 

	br(1);

}

void insertfood(int data, char foodname[25], int quantity, float price)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));

	temp->data = data;
	temp->price = price;
	temp-> quantity = quantity;
	strcpy(temp->foodname,foodname);
    temp->next = NULL;

	if(head==NULL)
	{
		head = temp;
		list = head;
	}
	else
	{
		while(head->next != NULL)
			head = head->next;
		
		head->next = temp;
	}

}


void deletefood(int serial)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));

	temp = list;

	if(temp->data != serial)
	{
		while(temp->next->data != serial)
			temp = temp->next;
	
		if(temp->next->data == serial)
		{
			temp->next = temp->next->next;
			 
			printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);
			for(int cs=0;cs<4;cs++)
			printf(" .");

			printf("\n\n\n\n\t\t\tDeleted Successfylly \n");

		}
		else
		{
			printf("\n\n\n\n\t\t\tFood Item Not Found\n"); 
		}

		head = temp ;
    }
	else
	{
		temp = temp->next;
		 
		printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);for(int cs=0;cs<4;cs++){printf(" .");}
		printf("\n\n\n\n\t\t\tDeleted Successfylly \n");

		head = temp ;
		list = head;
	}
}


void updatefood(int udata, int uquantity)
{
	node *temp;
	temp = list;

	while(temp->data!=udata)
		temp = temp->next;
	
	if(temp->data == udata)
		temp->quantity = uquantity;
	
}


void foodlist()
{
	printf("\n\t\t"); 
	printf("___________________________________________________________________");
	printf("\n\t\t"); 
	printf("|  Food No.  |        Food Name        |     Price     |  In Stock |");
	printf("\n\t\t"); 
	printf("-------------------------------------------------------------------");

	node *temp;
    temp = list;

	while(temp != NULL)
	{
		printf("\n\t\t"); 
		printf("|     %d      |       %s      |     %0.2f    |    %d    |",temp->data,temp->foodname, temp->price, temp->quantity);
		printf("\n\t\t"); 
		printf("-----------------------------------------------------------------");

		temp = temp->next ;
	}

}


void order_view(int order, int quantity, int or_no)
{
	node *temp;
    temp = list;

	while(temp->data != order)
		temp = temp->next;
    
	if(temp->data == order)
	{
		printf("\n\t\t"); 
		printf("|     %d      |    %s  |     %d     |     %d     |",or_no,temp->foodname,quantity,temp->quantity);
		printf("\n\t\t"); 
		printf("-------------------------------------------------------");

	}

}


void welcomeScr()
{
	printf("\n\n\n\n\n\t\t\t");	
	printf("W E L C O M E");
	printf("\n\n\t\t\t\t ");	
	printf(" T O");	
	printf("\n\n\n\t\t\t ");
	printf(" F O O D   O R D E R");
	printf("\n\n\n\t\t\t\t ");
	printf(" M A N A G E M E N T   S Y S T E M ");
	
}


void middleln(void)
{
	printf("\n\n\n\n\n\n\n");
}

void midtab(void)
{
	printf("\t\t\t\t\t");
}