/**********************************************************/
/****   Author : Basem Nagah             ******************/
/****   SWC: Clinic Management System    ******************/
/**********************************************************/

#ifndef OPTIONS_H
#define OPTIONS_H

typedef struct node
{
    
    
    u8 age  ;
    u32 id  ;
    
    u8 gender[100] ;
    u8 name[100] ;
    struct node * next_node ;
}node;



void voidAddNewPatient(node data);
void voidPrintList(void);
void voidEditList(u8 id);
void voidDeletePatient(u8 id);
void voidTimeRes(void) ;
void voidCancelRes(u8 id);
void Print_Res(void);
void voidPrintPatient(u8 id);


#endif