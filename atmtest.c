/* Mini Project
 * TOPIC : Bank Management System
 * */
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct node
{
    char fname[20];
    char lname[20];
    char phn[11];
    int acno;
    int pswrd[4];
    int rpswrd[4];
    double acb;
    struct node *next;
}*head;

void newac()
{
    struct node *newnode,*current;
    int a,i;
    char ch;
    newnode=(struct node*)malloc(sizeof(struct node));
    current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    printf("\tEnter user first Name:");
    scanf("%s",&newnode->fname);
    printf("\tEnter user last Name:");
    scanf("%s",&newnode->lname);
    printf("\tEnter user's phone no.:");
    scanf("%s",&newnode->phn);
    printf("\tEnter user's account no.:");
    scanf("%d",&newnode->acno);
    printf("\tEnter user's first account balance:");
    scanf("%lf",&newnode->acb);
    printf("\tEnter user's PIN <any 4 digit>:");
    for(i=0; i<4; i++)
    {
        ch = getch();
        newnode->pswrd[i] = ch;
        ch = '*' ;
        printf("%c",ch);
    }
    printf("\n\tRe-type PIN:");
    for(i=0; i<4; i++)
    {
        ch = getch();
        newnode->rpswrd[i] = ch;
        ch = '*' ;
        printf("%c",ch);
    }
    //scanf("%s",&newnode->rpswrd);
    a=strcmp(newnode->pswrd,newnode->rpswrd);
    while(a!=0)
    {
        printf("\tRe-type PIN:");
        scanf("%s",&newnode->rpswrd);
        newnode->rpswrd[4]=newnode->rpswrd[4];
    }
    newnode->next=NULL;
    current->next=newnode;
}

void tm()
{
    time_t now;
    now = time(NULL);
    struct tm tm = *localtime(&now);
    printf(" Date: %d-%d-%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    printf(" Time: %d:%d:%d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void editac()
{
    struct node *current;
    int item,a=0,b,ed;
    printf("\tEnter an a/c no. what you want to edit:");
    scanf("%d",&item);
    current=head;
    while(current!=NULL)
    {
        if(current->acno==item)
        {
            printf("\n\tWhat you want to edit?\n\tPress -->'1' User first name edit.\n\tPress -->'2' User last name edit.\n\tPress -->'3' User phone no. edit.\n\tPress -->'4' User a/c no. edit.\n\t");
            scanf("%d",&ed);
            switch(ed)
            {
            case 1:
                printf("\tEnter user new first Name:");
                scanf("%s",&current->fname);
                break;
            case 2:
                printf("\tEnter user new last Name:");
                scanf("%s",&current->lname);
                break;
            case 3:
                printf("\tEnter user's new phone no.:");
                scanf("%s",&current->phn);
                break;
            case 4:
                printf("\tEnter user's new account no.:");
                scanf("%d",&current->acno);
                break;
            }
            a=1;
            break;
        }
        current=current->next;
    }
    if(a==0)
    {
        printf("\tDoes not match A/C\n");
    }
}

void acdelete()
{
    struct node *current,*prev;
    current=head;
    int acn;
    printf("\tEnter the a/c no. you want to delete:");
    scanf("%d",&acn);
    if(head->acno==acn)
    {
        head=current;
        head=head->next;
        free(current);
    }
    else
    {
        while(current!=NULL)
        {

            if(current->acno==acn)
            {
                prev->next=current->next;
                free(current);
                break;
            }
            prev=current;
            current=current->next;
        }
    }
}

void search()
{
    struct node *current;
    int item,a=0;
    printf("\tEnter an a/c no. what you want to searching:");
    scanf("%d",&item);
    current=head;
    while(current!=NULL)
    {
        if(current->acno==item)
        {
            printf("\n User name: %s %s\n",current->fname,current->lname);
            printf(" User phone no: %s\n",current->phn);
            printf(" User a/c no: %d\n",current->acno);
            printf(" User a/c balance: %.2lf\n",current->acb);
            a=1;
            break;
        }
        current=current->next;
    }
    if(a==0)
    {
        printf("\tDoes not match A/C\n");
    }
}

void dispaly()
{
    struct node *current;
    current=head;
    while(current!=NULL)
    {
        printf("\n User name: %s %s\n",current->fname,current->lname);
        printf(" User phone no: %s\n",current->phn);
        printf(" User a/c no: %d\n",current->acno);
        printf(" User a/c balance: %.2lf\n",current->acb);
        current=current->next;
    }
}

void transfer(int ac,int mn)
{
    struct node *currnt;
    currnt=head;
    while(currnt!=NULL)
    {
        if(currnt->acno==ac)
        {
            currnt->acb=currnt->acb+mn;
            break;
        }
        currnt=currnt->next;
    }
}

void fst()
{
    printf("********\tWELCOME TO ZOSS BANK Ltd.\t********\n\n\t\tFirst you need to LOG IN\n\n");
    char id[10]="Admin",usr[10],ps[4]="1010",pw[4];
    int cm,cmp,vr;
    char pasword[10],usrname[10], ch;
    int i;
    struct node *current,*newnode;
    char fnam[20],lnam[20],ph[11];
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("\tUnable to allocate memory\n");
    }
    else
    {
        char fnam[]="Omkar";
        char lnam[]="Babrekar";
        char ph[]="9930923562";
        char ps[]="2020";
        strcpy(head->fname,fnam);
        strcpy(head->lname,lnam);
        strcpy(head->phn,ph);
        head->acno=1001;
        head->acb=0.0;
        strcpy(head->pswrd,ps);
        head->next=NULL;
        current=head;
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("\tUnable to allocate memory\n");
        }
        else
        {
            char fnam[]="Shruti";
            char lnam[]="Nair";
            char ph[]="9527384986";
            char ps[]="3030";
            strcpy(newnode->fname,fnam);
            strcpy(newnode->lname,lnam);
            strcpy(newnode->phn,ph);
            newnode->acno=1002;
            newnode->acb=0.0;
            strcpy(newnode->pswrd,ps);
            newnode->next=NULL;
            current->next=newnode;
            current=current->next;
        }
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("\tUnable to allocate memory\n");
        }
        else
        {
            char fnam[]="Zarin";
            char lnam[]="Khan";
            char ph[]="8689988497";
            char ps[]="4040";
            strcpy(newnode->fname,fnam);
            strcpy(newnode->lname,lnam);
            strcpy(newnode->phn,ph);
            newnode->acno=1003;
            newnode->acb=0.0;
            strcpy(newnode->pswrd,ps);
            newnode->next=NULL;
            current->next=newnode;
            current=current->next;
        }
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("\tUnable to allocate memory\n");
        }
        else
        {
            char fnam[]="Sakib";
            char lnam[]="Arkate";
            char ph[]="8451880634";
            char ps[]="5050";
            strcpy(newnode->fname,fnam);
            strcpy(newnode->lname,lnam);
            strcpy(newnode->phn,ph);
            newnode->acno=1004;
            newnode->acb=0.0;
            strcpy(newnode->pswrd,ps);
            newnode->next=NULL;
            current->next=newnode;
            current=current->next;
        }
    }
    printf("\tPress '0' -->Log in as Administration \n\tPress '1' -->Log in as Customer\n\n\t");
    int rg;
    scanf("%d",&rg);
    switch(rg)
    {
    case 1:
        vr=1;
        int more2,a;
        char paswrd[10], ch;
        int i,acn,cs;
        printf("\n\tEnter A/C no. : ");
        scanf("%d",&acn);
        printf("\tEnter PIN: ");
        for(i=0; i<4; i++)
        {
            ch = getch();
            paswrd[i] = ch;
            ch = '*' ;
            printf("%c",ch);
        }
        do
        {
            int a=0,wd,dp,b=0,ac,mn;
            char nps[4],op[4],npsn[4],p[4];
            current=head;
            while(current!=NULL)
            {
                if(acn==current->acno)
                {
                    printf("\n\tEnter your choice\n\n\tPress '1' --> A/C balance inquiry\n\tPress '2' --> balance withdraw\n\tPress '3' --> deposite money\n\tPress '4' --> change PIN\n\tPress '5' --> Transfer money\n\tPress '6' --> Logout\n\n\t");
                    scanf("%d",&cs);
                    switch(cs)
                    {
                    case 1:
                        printf(" Your a/c no: %d\n",current->acno);
                        printf(" Your a/c balance: %.2lf\n",current->acb);
                        printf("\n\tZOSS BANK Ltd.\n\n");
                        break;
                    case 2:
                        if(b<=5)
                        {
                            printf("\tEnter the amount what you want withdraw <minimum 500,maximum 20000> : ");
                            scanf("%d",&wd);
                            if(wd>=500&&wd<=20000&&wd%500==0&&current->acb-100>=wd)
                            {
                                current->acb=current->acb-wd;
                                printf("\n Your a/c no: %d\n",current->acno);
                                printf(" You withdraw Tk: %d\n",wd);
                                printf(" Your current a/c balance: %.2lf\n",current->acb);
                                tm();
                                printf("\n\tZOSS BANK Ltd.\n\n");
                            }
                            else
                            {
                                printf("\n\tWrong input\n");
                            }
                            b++;
                        }
                        else
                        {
                            printf("\n\tYou already withdraw money at 5 times\n");
                        }
                        break;
                    case 3:
                        printf("\tEnter the amount what you want deposit <minimum 500> :");
                        scanf("%d",&dp);
                        current->acb=current->acb+dp;
                        printf("\n Your a/c no: %d\n",current->acno);
                        printf(" Your deposited Tk: %d\n",dp);
                        printf(" Your current a/c balance: %.2lf\n",current->acb);
                        tm();
                        printf("\n\tZOSS BANK Ltd.\n\n");
                        break;
                    case 4:
                        printf("\tEnter old PIN : ");
                        for(i=0; i<4; i++)
                        {
                            ch = getch();
                            op[i] = ch;
                            ch = '*' ;
                            printf("%c",ch);
                        }
                        printf("\n\tEnter new PIN:");
                        for(i=0; i<4; i++)
                        {
                            ch = getch();
                            nps[i] = ch;
                            ch = '*' ;
                            printf("%c",ch);
                        }
                        printf("\n\tRe-type new PIN:");
                        for(i=0; i<4; i++)
                        {
                            ch = getch();
                            npsn[i] = ch;
                            ch = '*' ;
                            printf("%c",ch);
                        }
                        if(nps[0]==npsn[0]&&nps[1]==npsn[1]&&nps[2]==npsn[2]&&nps[3]==npsn[3])
                        {
                            strcpy(current->pswrd,nps);
                            printf("\n\tPassword changed succesfully\n");
                        }
                        else
                        {
                            printf("\n\tDo not match password\n");
                        }

                        break;
                    case 6:
                        lgot();
                        break;
                    case 5:
                        printf("\n\tEnter A/C no. where you want to transfer money : ");
                        scanf("%d",&ac);
                        printf("\n\tEnter amount : ");
                        scanf("%d",&mn);
                        if(mn>=500&&mn%500==0&&current->acb-100>=mn)
                        {
                            current->acb=current->acb-mn;
                            printf("\n Your a/c no: %d\n",current->acno);
                            printf(" You transfered Tk: %d\n",mn);
                            printf(" Your current a/c balance: %.2lf\n",current->acb);
                            tm();
                            printf("\n\tZOSS BANK Ltd.\n\n");
                            transfer(ac,mn);
                        }
                        else
                        {
                            printf("\n\tWrong input\n");
                        }
                        break;
                    }
                    a=1;
                }
                current=current->next;
            }
            if(a==0)
            {
                printf("\n\tDo not match\n");
            }
            printf("\n\tDo you want to perform anymore operation? if yes press -->'1':");
            scanf("%d",&more2);
        }
        while(more2==1);
        break;
    case 0:
        vr=0;
        printf("\n\tEnter admin name: ");
        scanf("%s",&usrname);
        printf("\tEnter password: ");
        for(i=0; i<4; i++)
        {
            ch = getch();
            pasword[i] = ch;
            ch = '*' ;
            printf("%c",ch);
        }
        cm=strcmp(id,usrname);
        if(cm==0&&ps[0]==pasword[0]&&ps[1]==pasword[1]&&ps[2]==pasword[2]&&ps[3]==pasword[3])
        {
            int more;
            do
            {
                int slct;
                char psw[10],pswd[10];
                printf("\n\tSelect what you want to do.\n\n\tPress '1' --> Open new account.\n\tPress '2' --> Edit any a/c information.\n\tPress '3' --> Delete any account.\n\tPress '4' --> Search any account.\n\tPress '5' --> Display all account information.\n\tPress '6' --> change Admin password.\n\tPress '7' --> Logout.\n\t");
                scanf("%d",&slct);
                switch(slct)
                {
                case 1:
                    newac();
                    break;
                case 2:
                    editac();
                    break;
                case 3:
                    acdelete();
                    break;
                case 4:
                    search();
                    break;
                case 5:
                    dispaly();
                    break;
                case 7:
                    lgot();
                    break;
                case 6:
                    printf("\n\tEnter old password:");
                    for(i=0; i<4; i++)
                    {
                        ch = getch();
                        psw[i] = ch;
                        ch = '*' ;
                        printf("%c",ch);
                    }
                    if(ps[0]==psw[0]&&ps[1]==psw[1]&&ps[2]==psw[2]&&ps[3]==psw[3])
                    {
                        printf("\n\tEnter new password:");
                        for(i=0; i<4; i++)
                        {
                            ch = getch();
                            psw[i] = ch;
                            ch = '*' ;
                            printf("%c",ch);
                        }
                        printf("\n\tRe-type new password:");
                        for(i=0; i<4; i++)
                        {
                            ch = getch();
                            pswd[i] = ch;
                            ch = '*' ;
                            printf("%c",ch);
                        }
                        if(pswd[0]==psw[0]&&pswd[1]==psw[1]&&pswd[2]==psw[2]&&pswd[3]==psw[3])
                        {
                            ps[4]=psw[4];
                            printf("\n\tPassword changed succesfully\n");
                        }
                        else
                        {
                            printf("\n\tDo not match password\n");
                        }
                    }
                    else
                    {
                        printf("\n\tWrong password\n");
                    }
                    break;
                }
                printf("\n\tDo you want to perform anymore operation? if yes press -->'1':");
                scanf("%d",&more);
            }
            while(more==1);
        }
        else
        {
            printf("\n\tWrong username or password\n");
        }
        break;
    default:
        printf("\n\tWrong press\n");
        break;
    }
}

void lgot()
{
    while(1)
    {
        printf("********\tWELCOME TO ZOSS BANK Ltd.\t********\n\n\t\tFirst you need to LOG IN\n\n");
        char id[10]="Admin",usr[10],ps[4]="1010",pw[4];
        int cm,cmp,vr;
        char pasword[10],usrname[10], ch;
        int i;
        struct node *current,*newnode;
        char fnam[20],lnam[20],ph[11];
        printf("\tPress '0' -->Log in as Administration \n\tPress '1' -->Log in as Customer\n\n\t");
        int rg;
        scanf("%d",&rg);
        switch(rg)
        {
        case 1:
            vr=1;
            int more2,a;
            char paswrd[10], ch;
            int i,acn,cs;
            printf("\n\tEnter A/C no. : ");
            scanf("%d",&acn);
            printf("\tEnter PIN: ");
            for(i=0; i<4; i++)
            {
                ch = getch();
                paswrd[i] = ch;
                ch = '*' ;
                printf("%c",ch);
            }
            do
            {
                int a=0,wd,dp,b=0,ac,mn;
                char nps[4],op[4],npsn[4],p[4];
                current=head;
                while(current!=NULL)
                {
                    if(acn==current->acno)
                    {
                        printf("\n\tEnter your choice\n\nPress '1' --> A/C balance inquiry\nPress '2' --> balance withdraw\nPress '3' --> deposite money\nPress '4' --> change PIN\nPress '5' --> Transfer money\nPress '6' --> Logout\n\n\t");
                        scanf("%d",&cs);
                        switch(cs)
                        {
                        case 1:
                            printf(" Your a/c no: %d\n",current->acno);
                            printf(" Your a/c balance: %.2lf\n",current->acb);
                            printf("\n\t ZOSS BANK Ltd.\n\n");
                            break;
                        case 2:
                            if(b<=5)
                            {
                                printf("\tEnter the amount what you want withdraw <minimum 500,maximum 20000> : ");
                                scanf("%d",&wd);
                                if(wd>=500&&wd<=20000&&wd%500==0&&current->acb-100>=wd)
                                {
                                    current->acb=current->acb-wd;
                                    printf("\n Your a/c no: %d\n",current->acno);
                                    printf(" You withdraw Tk: %d\n",wd);
                                    printf(" Your current a/c balance: %.2lf\n",current->acb);
                                    tm();
                                    printf("\n\tZOSS BANK Ltd.\n\n");
                                }
                                else
                                {
                                    printf("\n\tWrong input\n");
                                }
                                b++;
                            }
                            else
                            {
                                printf("\n\tYou already withdraw money at 5 times\n");
                            }
                            break;
                        case 3:
                            printf("\tEnter the amount what you want deposit <minimum 500> :");
                            scanf("%d",&dp);
                            current->acb=current->acb+dp;
                            printf("\n Your a/c no: %d\n",current->acno);
                            printf(" Your deposited Tk: %d\n",dp);
                            printf(" Your current a/c balance: %.2lf\n",current->acb);
                            tm();
                            printf("\n\tZOSS BANK Ltd.\n\n");
                            break;
                        case 4:
                            printf("\tEnter old PIN : ");
                            for(i=0; i<4; i++)
                            {
                                ch = getch();
                                op[i] = ch;
                                ch = '*' ;
                                printf("%c",ch);
                            }
                            printf("\n\tEnter new PIN:");
                            for(i=0; i<4; i++)
                            {
                                ch = getch();
                                nps[i] = ch;
                                ch = '*' ;
                                printf("%c",ch);
                            }
                            printf("\n\tRe-type new PIN:");
                            for(i=0; i<4; i++)
                            {
                                ch = getch();
                                npsn[i] = ch;
                                ch = '*' ;
                                printf("%c",ch);
                            }
                            if(nps[0]==npsn[0]&&nps[1]==npsn[1]&&nps[2]==npsn[2]&&nps[3]==npsn[3])
                            {
                                strcpy(current->pswrd,nps);
                                printf("\n\tPassword changed succesfully\n");
                            }
                            else
                            {
                                printf("\n\tDo not match password\n");
                            }
                            break;
                        case 6:
                            lgot();
                            break;
                        case 5:
                            printf("\n\tEnter A/C no. where you want to transfer money : ");
                            scanf("%d",&ac);
                            printf("\n\tEnter amount : ");
                            scanf("%d",&mn);
                            if(mn>=500&&mn%500==0&&current->acb-100>=mn)
                            {
                                current->acb=current->acb-mn;
                                printf("\n Your a/c no: %d\n",current->acno);
                                printf(" You transfered Tk: %d\n",mn);
                                printf(" Your current a/c balance: %.2lf\n",current->acb);
                                tm();
                                printf("\n\tZOSS BANK Ltd.\n\n");
                                transfer(ac,mn);
                            }
                            else
                            {
                                printf("\n\tWrong input\n");
                            }
                            break;


                        }
                        a=1;
                    }
                    current=current->next;
                }
                if(a==0)
                {
                    printf("\n\tDo not match\n");
                }
                printf("\n\tDo you want to perform anymore operation? if yes press -->'1':");
                scanf("%d",&more2);
            }
            while(more2==1);
            break;
        case 0:
            vr=0;
            printf("\n\tEnter admin name: ");
            scanf("%s",&usrname);
            printf("\tEnter password: ");
            for(i=0; i<4; i++)
            {
                ch = getch();
                pasword[i] = ch;
                ch = '*' ;
                printf("%c",ch);
            }
            cm=strcmp(id,usrname);
            if(cm==0)
            {
                int more;
                do
                {
                    int slct;
                    char psw[10],pswd[10];
                    printf("\n\tSelect what you want to do.\n\n\tPress '1' --> Open new account.\n\tPress '2' --> Edit any a/c information.\n\tPress '3' --> Delete any account.\n\tPress '4' --> Search any account.\n\tPress '5' --> Display all account information.\n\tPress '6' --> change Admin password.\n\tPress '7' --> Logout.\n\t");
                    scanf("%d",&slct);
                    switch(slct)
                    {
                    case 1:
                        newac();
                        break;
                    case 2:
                        editac();
                        break;
                    case 3:
                        acdelete();
                        break;
                    case 4:
                        search();
                        break;
                    case 5:
                        dispaly();
                        break;
                    case 7:
                        lgot();
                        break;
                    case 6:
                        printf("\n\tEnter old password:");
                        for(i=0; i<4; i++)
                        {
                            ch = getch();
                            psw[i] = ch;
                            ch = '*' ;
                            printf("%c",ch);
                        }
                        if(ps[0]==psw[0]&&ps[1]==psw[1]&&ps[2]==psw[2]&&ps[3]==psw[3])
                        {
                            printf("\n\tEnter new password:");
                            for(i=0; i<4; i++)
                            {
                                ch = getch();
                                psw[i] = ch;
                                ch = '*' ;
                                printf("%c",ch);
                            }
                            printf("\n\tRe-type new password:");
                            for(i=0; i<4; i++)
                            {
                                ch = getch();
                                pswd[i] = ch;
                                ch = '*' ;
                                printf("%c",ch);
                            }
                            if(pswd[0]==psw[0]&&pswd[1]==psw[1]&&pswd[2]==psw[2]&&pswd[3]==psw[3])
                            {
                                ps[4]=psw[4];
                                printf("\n\tPassword changed succesfully\n");
                            }
                            else
                            {
                                printf("\n\tDo not match password\n");
                            }
                        }
                        else
                        {
                            printf("\n\tWrong password\n");
                        }
                        break;
                    }
                    printf("\n\tDo you want to perform anymore operation? if yes press -->'1':");
                    scanf("%d",&more);
                }
                while(more==1);
            }
            else
            {
                printf("\n\tWrong username or password\n");
            }
            break;
        default:
            printf("\n\tWrong press\n");
            break;
        }
    }
}

int main()
{
    fst();
    return 0;
}
