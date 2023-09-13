#include "SDB.h"

uint32 id ;
uint8 students_num ;
uint8 space_error ;
uint8 count;
bool ID_Found;

uint32 *list;
bool Full ;



void SDB_action (uint8 choice)
{

    switch (choice){

    case 1 :
        space_error = SDB_AddEntry() ;
        if (space_error==1)
            printf("\nNO space in the memory !\n") ;
        break ;

    case 2 :
    students_num = SDB_GetUsedSize() ;
    printf("\nnumber of students = %d\n" , students_num) ;
        break ;

    case 3 :
    printf("\nEnter student ID\n") ;
    scanf("%d" , &id) ;
    ID_Found = SDB_ReadEntry (id);
    if(ID_Found==false)
        printf("\nID not found !\n") ;
        break ;

    case 4 :

    count= SDB_GetUsedSize() ;
    SDB_GetList (&count,  list) ;
        break ;

    case 5 :
    printf("\nEnter student ID\n") ;
    scanf("%d" , &id) ;
    ID_Found = SDB_IsIdExist (id);
    if(ID_Found==true)
        printf("\n ID exists !\n") ;
    else
        printf("\n ID doesn't exist!\n") ;
        break ;


    case 6 :
    printf("\nEnter student ID\n") ;
    scanf("%d" , &id) ;
    SDB_DeletEntry (id);
        break ;

     case 7 :
    Full = SDB_IsFull ();
    if (Full == true)
        printf("\nThe list is full !\n") ;
    else
        printf("\nNot full !\n") ;
        break ;

     default :
        printf("\nPlease enter a valid choice !\n");
        break ;
    }
}

void SDB_APP()
{
    uint8 choice ;
    while (1){

    printf("\nTo add entry, enter 1, To get used size in database enter 2, To read student data enter 3, To get the list of all student IDs enter 4, To check is ID is existed enter 5, To delete student data enter 6, To check is database is full enter 7, To exit enter 0\n") ;
    scanf("%d" ,&choice) ;
    if (choice == 0)
        return;
    else
        SDB_action (choice) ;
    }
}
