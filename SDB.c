#include "SDB.h"




student *start = NULL;


bool SDB_AddEntry()
{
    student  *ptr ;
    student *temp  = (student*)(malloc (sizeof (student))) ;
    if (temp == NULL )
        return 1 ;

    printf("\nEnter Student ID : ") ;
    scanf("%d" , &temp->Student_ID) ;

    printf("\nEnter Student year : ") ;
    scanf("%d" , &temp->Student_year) ;

    printf("\nEnter Course1 ID : ") ;
    scanf("%d" , &temp->Course1_ID) ;

    printf("\nEnter Course1 grade : ") ;
    scanf("%d" , &temp->Course1_grade) ;

    printf("\nEnter Course2 ID : ") ;
    scanf("%d" , &temp->Course2_ID) ;

    printf("\nEnter Course2 grade : ") ;
    scanf("%d" , &temp->Course2_grade) ;

    printf("\nEnter Course3 ID : ") ;
    scanf("%d" , &temp->Course3_ID) ;

    printf("\nEnter Course3 grade : ") ;
    scanf("%d" , &temp->Course3_grade) ;
    temp->next = NULL ;

    if (start == NULL)
        start = temp ;
    else{

        ptr = start ;
        while (ptr->next !=NULL){
            ptr = ptr->next ;
        }
    ptr->next = temp ;

    }

    return 0 ;
}

uint8 SDB_GetUsedSize()
{
    if (start == NULL)
        return 0;

    int counter = 1 ;
    student *ptr ;
    ptr = start ;


    while (ptr->next != NULL){
        ptr = ptr->next ;
        counter++;
    }
    return counter ;
}



bool SDB_ReadEntry (uint32 id)
{
    if (start == NULL)
        return 0 ;

        if (start->Student_ID == id){

            printf("\n\nStudent ID = %d"    ,start->Student_ID    ) ;
            printf("\nStudent year = %d"  ,start->Student_year  ) ;
            printf("\nCourse1 ID = %d"    ,start->Course1_ID    ) ;
            printf("\nCourse1 grade = %d" ,start->Course1_grade ) ;
            printf("\nCourse2 ID = %d"    ,start->Course2_ID    ) ;
            printf("\nCourse2 grade = %d" ,start->Course2_grade ) ;
            printf("\nCourse3 ID = %d"    ,start->Course3_ID    ) ;
            printf("\nCourse3 grade = %d\n" ,start->Course3_grade ) ;

          return 1 ;
        }

    student *ptr ;
    ptr = start ;


    while (ptr->next !=NULL){

        ptr = ptr->next ;
        if (ptr->Student_ID == id){

            printf("\n\nStudent ID = %d"    ,ptr->Student_ID    ) ;
            printf("\nStudent year = %d"  ,ptr->Student_year  ) ;
            printf("\nCourse1 ID = %d"    ,ptr->Course1_ID    ) ;
            printf("\nCourse1 grade = %d" ,ptr->Course1_grade ) ;
            printf("\nCourse2 ID = %d"    ,ptr->Course2_ID    ) ;
            printf("\nCourse2 grade = %d" ,ptr->Course2_grade ) ;
            printf("\nCourse3 ID = %d"    ,ptr->Course3_ID    ) ;
            printf("\nCourse3 grade = %d\n" ,ptr->Course3_grade ) ;


          return 1 ;
        }

    }
    return 0 ;
}


bool SDB_IsIdExist (uint32 id)
{
    if (start == NULL)
        return 0 ;
    if (start->Student_ID == id){
          return 1 ;
        }

    student *ptr ;
    ptr = start ;

    while (ptr->next !=NULL){

        ptr = ptr->next ;
        if (ptr->Student_ID == id){
          return 1 ;
        }

    }
    return 0 ;

}

bool SDB_IsFull ()
{
    if (start == NULL)
        return false ;

    int counter = 1 ;
    student *ptr ;
    ptr = start ;

    while (ptr->next != NULL){
        counter++ ;
        ptr = ptr->next ;
        if (counter == 10)
            return true ;
    }
    return false ;
}

void SDB_DeletEntry (uint32 id)
{

    if(start == NULL){
        printf("\nThere is no element in the list!\n") ;
        return ;
    }

     student *temp,*ptr;

    if (start->Student_ID == id){
       ptr = start ;
       start = start->next ;
       printf("\nThe deleted student ID is %d \n" ,ptr->Student_ID ) ; //delete the data corresponding to this ID
       free(ptr) ;
    }

    else{
        ptr = start ;
        while (ptr->next != NULL){

            temp = ptr ;
            ptr = ptr->next ;

            if (ptr->Student_ID == id){
                temp ->next = ptr->next;
                printf("\nThe deleted student ID is %d \n" ,ptr->Student_ID ) ; //delete the data corresponding to this ID
                free(ptr) ;
                return ;
            }


        }
        printf("\nID not found !\n") ;
    }




}


void SDB_GetList (uint8 * count, uint32* list)
{
    student *ptr ;
    ptr = start ;

    list = (uint32*)malloc((*count)* sizeof(uint32));
    printf("\nIDs list: ") ;
    for (int i = 0 ; i<*count ; i++){
           *(list+i) = ptr->Student_ID ;
           printf("%d , " , *(list+i)) ;
           ptr= ptr->next ;
    }
    printf("\n") ;
}










