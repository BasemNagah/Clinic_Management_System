/**********************************************************/
/****   Author : Basem Nagah             ******************/
/****   SWC: Clinic Management System    ******************/
/**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "OPTIONS.h"
#include <string.h>



node * head = NULL ;
u8 list_size = 0 ;
node *temp = NULL ;
node *temp_2 = NULL ;
u8 status ; 
s8 SlotsArr[5] = {-5 , -5 , -5 , -5 , -5 };

///////////////add patient /////////////
void voidAddNewPatient(node data)
{
    node *ptr = (node*)malloc(sizeof(node)) ;
    ptr->id = data.id ;
    strcpy(ptr->name,data.name);
    ptr->age = data.age ;
    strcpy(ptr->gender,data.gender);
    ptr->next_node = NULL ;
    status = 0 ;
    if(head == NULL)
    {
        head = ptr ;
        printf("\n******Patient added successfully !*******\n");
        list_size++ ;
    }
    else
    {
        temp = head ;
        for(u8 i=0 ; i< list_size ; i++)
        {
            if(ptr->id == temp->id)
            {
                status = 1 ;
            }
            temp = temp->next_node ;
        }
        if(status!= 1)
        {
            ptr->next_node = head ;
            head = ptr ;
            printf("\n******Patient added successfully !*******\n");
            list_size++ ;
        }
        else
        {
            printf("\nThis id is already existed please try again !\n");
        }
        
    }
    

    

}
//////print lists///////////////
void voidPrintList(void)
{
    
    if(list_size != 0)
    {
        temp = head ;
        for(u8 i=1 ; i<= list_size ; i++)
        {
            printf("\n********Patient : %d **************",i);
            printf("\n     Name    : ");
            printf(temp->name);
            printf("\n");
            printf("       id    : %d \n",temp->id);
            printf("      age    : %d \n",temp->age);
            printf(" gender(m/f) : ");
            printf(temp->gender);
            printf(" .\n");
            temp = temp->next_node ;
            
        }
    }
    else
    {
        printf("\nThe list is empty !\n");
    }
}

////////////edit lists //////////
void voidEditList(u8 id)
{
    status = 0 ;
    temp = head ;
    if(temp == NULL)
    {
        printf("\nSorry There is no patients in the list to edit !\n");
    }
    else
    {
        for(u8 i=0 ; i<list_size ; i++)
        {
            if(temp->id == id)
            {
                printf("\n       id    : %d \n",temp->id);
                printf("     Name    : ");
                printf(temp->name);
                printf("\n");
                printf("      age    : %d \n",temp->age);
                printf(" gender(m/f) : ");
                printf(temp->gender);
                printf(" .\n");
                printf("\nPlease enter new values !\n");

                printf("\nPlease enter patient name : ");
                scanf(" %[^\n]%*c",temp->name);
                printf("Please enter patient age  : ");
                scanf("%d",&temp->age);
                printf("Please enter patient gender : ");
                scanf(" %[^\n]%*c",temp->gender);
                status = 1 ;
                break ;

            }
            else
            {
            }
            temp = temp->next_node ;

        }
        if(status !=1)
        {
            printf("\nSorry id you enterd is not exist !\n");

        }

    }
}


/////////delete node ///////////////
void voidDeletePatient(u8 id)
{
    // u8 delete_status = 0  ;
    status = 0 ;
    temp = head ;
    if(temp == NULL)
    {
        printf("\nSorry There is no patients in the list to delete !\n");
    }
    else
    {
        while(temp != NULL )
            {
                if(temp->id == id)
                {
                    printf("\n       id    : %d \n",temp->id);
                    printf("     Name    : ");
                    printf(temp->name);
                    printf("\n");
                    printf("      age    : %d \n",temp->age);
                    printf(" gender(m/f) : ");
                    printf(temp->gender);
                    printf(" .\n");
                    printf("\n*********** Deleting ............. ********\n");
                    // printf("\nAre you sure you want to delete this ? \n");
                    // printf("\nAnswer (if yes = 1 , no = any number) : ");
                    // scanf("%d",&delete_status);
                    //     if(delete_status == 1)
                    //     {
                            temp_2 = temp->next_node ;
                            free(temp) ;
                            temp = NULL ;
                            temp = head ;
                            while(temp != NULL)
                            {    
                                temp = temp->next_node;
                            }
                            temp = temp_2 ;
                            list_size -- ;
                            printf("\n****** Deleted successfuly ! ******\n");
                        // }
                        // else
                        // {
                        //     printf("\n****** Not deleted ! ******\n");
                        // }


                        status = 1 ;
                        break ;
                }
                else
                {
                }
                temp = temp->next_node ;

            }

            if(status !=1)
            {
                printf("\nSorry id you enterd is not exist !\n");
            }
            else
            {
            }

    }

}


////////////////////////time slots /////////
void voidTimeRes(void) 
{
    u32 id ;
    u8 Slot ;
    u8 counter = 0 ;
    for(u8 i=0 ; i<5 ; i++)
    {
        switch (i)
        {
        case 0:
                if(SlotsArr[0] != -5)
                {
                    break;
                }
                else
                {
                    printf("From 2pm to 2.30pm is available , to reserve this slot enter 1 .\n");
                    break;
                }
        case 1:
                if(SlotsArr[1] != -5)
                {
                    break;
                }
                else
                {
                    printf("From 2.30pm to 3pm is available , to reserve this slot enter 2 .\n");
                    break;
                }
        case 2:
                if(SlotsArr[2] != -5)
                {
                    break;
                }
                else
                {
                    printf("From 3pm to 3.30pm is available , to reserve this slot enter 3 .\n");
                    break;
                }
        case 3:
                if(SlotsArr[3] != -5)
                {
                    break;
                }
                else
                {
                    printf("From 4pm to 4.30pm is available , to reserve this slot enter 4 .\n");
                    break;
                }
        case 4:
                if(SlotsArr[4] != -5)
                {
                    break;
                }
                else
                {
                    printf("From 4.5pm to 5pm is available , to reserve this slot enter 5 .\n");
                    break;
                }
        default:
            break;
        }
    }

    printf("\nDate number : ");
    scanf("%d",&Slot);
    printf("\nPlease enter your id : ");
    scanf("%d",&id);
    
    temp = head ;

    while(temp != NULL )
    {
        if(temp->id == id)
        {
            SlotsArr[Slot-1] = id ;
            counter = 1 ;
        }
        temp = temp->next_node ;
    }

    if(counter != 1)
    {
        printf("\n***** Your id is not exist! *****\n");
    }
    else
    {
       printf("\n***** Added Successfuly ! *****"); 
    }

}

////////////// cancel reservitons ///////////
void voidCancelRes(u8 id)
{
    u8 counter = 0 ;
    u8 stat ;
    printf("\nAre you sure you want to Cancel the reserviton of id(%d) ? \n",id);
    printf("\nAnswer (if yes = 1 , no = any number) : ");
    scanf("%d",&stat);

    if(stat == 1){
        for(u8 i=0 ; i<5 ; i++)
        {
            if(SlotsArr[i] == id)
            {
                SlotsArr[i] = -5 ;
                counter = 1 ;
            }
        }
        
        if(counter != 1)
        {
            printf("\n******** Sorry id is not exist ! ********\n");
        }
        else
        {
            printf("\n******** Reserve is Cancel successfuly ! ********\n");
        }
    }
    else
    {
        printf("\n ******** Not Cancelled ! ********");
    }
}

//////////////Print all reservation ////
void Print_Res(void)
{
    u8 counter = 0 ;
    for(u8 i=0 ; i<5 ; i++)
    {
        switch (i)
        {
            case 0 : if(SlotsArr[0] == -5) break;
						else printf("From 2pm to 2:30pm is reserved by the id : %d\n",SlotsArr[0]); 
                        counter = 1 ;
                    break;
			case 1 : if(SlotsArr[1] == -5) break;
						else printf("From 2:30pm to 3pm is reserved by the id : %d\n",SlotsArr[1]);
                        counter = 1 ;
                    break;		
			case 2 : if(SlotsArr[2] == -5) break;
						else printf("From 3:30pm to 4pm is reserved by the id : %d\n",SlotsArr[2]);
                        counter = 1 ;
                    break;
			case 3 : if(SlotsArr[3] ==- 5) break;
						else printf("From 4pm to 4:30pm is reserved by the id : %d\n",SlotsArr[3]);
                        counter = 1 ;
                    break;
			case 4 : if(SlotsArr[4] == -5) break;
						else printf("From 4:30pm to 5pm is reserved by the id : %d\n",SlotsArr[4]);
                        counter = 1 ;
                    break;
        }
    }
    if(counter != 1 )
    {
        printf("\n********** No dates Today ***********");
    }
}


///////////////print patient /////////
void voidPrintPatient(u8 id)
{
    status = 0 ;
    temp = head ;

    while(temp != NULL)
    {
        if(temp->id == id)
        {
            printf("\n******** Your record **************");
            printf("\n     Name    : ");
            printf(temp->name);
            printf("\n");
            printf("       id    : %d \n",temp->id);
            printf("      age    : %d \n",temp->age);
            printf(" gender(m/f) : ");
            printf(temp->gender);
            printf(" .\n");
            status = 1 ;
            break;
        }
        else
        {
        }
        temp = temp->next_node ;
    }

    if(status != 1)
    {
        printf("\n******** Sorry Your id is not exist ! ********");
    }




}



