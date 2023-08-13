/**********************************************************/
/****   Author : Basem Nagah             ******************/
/****   SWC: Clinic Management System    ******************/
/**********************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"STD_TYPES.h"
#include"OPTIONS.h"




int main(void)
{
    u8 choice ;
    node data ;
    u8 id_edit ,mode ,password;
    
    while(1)
    {
        printf("********** Welcome To OUR Clinic ! **********\n");
        printf("\nFor admin mode enter 1 : ");
        printf("\nFor user mode enter  2 : ");
        printf("\n\n***** Your choice : ");
        scanf("%d",&mode);
        if(mode == 1)
        {   
            for(u8 i=1 ; i<4 ; i++)
            {
                printf("\n******** Admin login ********\n");
                printf("\nPlease Enter the password : ");
                scanf("%d",&password);
                if(password == 123)
                {
                    i = 4 ;
                    printf("\n******** Welcome To Admin Dashboard ! ********\n");
                    break;
                }
                else
                {
                    printf("\n******** Wrong password ! ********\n");
                    printf("\n******** still %d tries ! ********\n",(3-i));
                }
            }

            if (password == 123 )
            {
                while (1)
                {
                    printf("\n  Please select option !\n");
                    printf("1- Add new patient.\n");
                    printf("2- Show Patients list. \n");
                    printf("3- Edit patient.\n");
                    printf("4- Delete patient.\n");
                    printf("5- reserve a slot with the doctor.\n");
                    printf("6- Cancel reservation of patient .\n");
                    printf("7- View reservations of today .\n");
                    printf("8- Exit. \n");
                    printf("\nYour choice : ");
                    scanf("%d",&choice);
                    switch (choice)
                    {
                        case 1:
                                printf("\nPlease enter patient name : ");
                                scanf(" %[^\n]%*c",data.name);
                                printf("Please enter patient id : ");
                                scanf("%d",&data.id);
                                printf("Please enter patient age : ");
                                scanf("%d",&data.age);
                                printf("Please enter patient gender : ");
                                scanf(" %[^\n]%*c",data.gender);
                                voidAddNewPatient(data);
                                printf("\n********************************************\n");
                        break;
                        case 2:
                                voidPrintList();
                                printf("\n********************************************\n");
                        break;
                        case 3 :
                                printf("\nPlease enter id of patient you want to edit : ");
                                scanf("%d",&id_edit);
                                voidEditList(id_edit);
                                printf("\n********************************************\n");
                        break;
                        case 4 :
                                printf("\nPlease enter id of patient you want to delete : ");
                                scanf("%d",&id_edit);
                                voidDeletePatient(id_edit);
                                printf("\n********************************************\n");
                        break;
                        case 5 :
                                voidTimeRes();
                                printf("\n********************************************\n");
                        break;
                        case 6 :
                                printf("\nPlease enter id of patient you want to cancel his reservation : ");
                                scanf("%d",&id_edit);
                                voidCancelRes(id_edit);
                                printf("\n********************************************\n");
                        break;
                        case 7 :
                                Print_Res();
                                printf("\n********************************************\n");
                        break;
                        case 8 :
                        break;

                        default:
                                printf("******** WRONG CHOICE ******** ");
                        break;
                    }

                    if(choice == 8)
                    {
                        printf("\n********Logout successfuly !********\n");
                        break;
                    }
                }
            }
            else
            {
                printf("******** Sorry you enterd password wrong 3 times ********\n");
            }
           
        }
        else if(mode == 2)
        {
            while (1)
            {
                printf("\n******** Welcome to user mode ********\n");
                printf("1- View patient record by the id .\n");
                printf("2- View reservations of today .\n");
                printf("3- Exit .\n");
                printf("****** Your choice : ");
                scanf("%d",&choice);
                switch (choice)
                {
                case 1 :
                        printf("\nPlease enter id : ");
                        scanf("%d",&id_edit);
                        voidPrintPatient(id_edit);
                        printf("\n**********************************\n");
                    break;
                case 2 :
                        Print_Res();
                        printf("\n**********************************\n");
                    break;
                case 3 :
                        printf("\n**********************************\n");
                    break;
                
                default:
                        printf("\n************ Wrong choice ! ************\n");
                    break;
                }

                if(choice == 3)
                {
                    printf("\n******** Thank you for visit us , by ! ********\n");
                    break;
                }
            }
        }
        else
        {
            printf("\n***** Wrong choice please try again ! *****");
        }

    }

    return 0 ;
}
