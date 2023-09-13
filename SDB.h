#ifndef SDB_H_INCLUDED
#define SDB_H_INCLUDED

#include "STD.h"


typedef struct SimpleDb
{
    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;
    struct SimpleDb *next ;
}student;

#include "SDB.c" // her I included "SDB.c" after the definition of the struct to make the SDB.c file able to read this struct
/*
function name        : SDB_AddEntry
function returns     : bool(enum)
function arguments   : void
function description : when the user select to add entry this function asks him for the required data in the database to add one student
                        which is his (id, year, Course1_ID, Course1_grade, Course2_ID, Course2_grade, Course3_ID, and Course3_grade)
                        then it returns 1 if the data was added and 0 if not.
*/
bool SDB_AddEntry() ;

/*
function name        : SDB_GetUsedSize
function returns     : uint8
function arguments   : void
function description : this function returns the total number of student added to the data base
*/
uint8 SDB_GetUsedSize() ;

/*
function name        : SDB_ReadEntry
function returns     : bool
function arguments   : uint32 id
function description : print the data of the user by searching on his data by the given id
                        then return 1 if the data exists return 0 if this id not in your database.
*/
bool SDB_ReadEntry (uint32 id) ;

/*
function name        : SDB_IsIdExist
function returns     : bool
function arguments   : uint32 id
function description : Checks if the given id exists in your database or not.
*/
bool SDB_IsIdExist (uint32 id) ;

/*
function name        : SDB_IsFull
function returns     : bool
function arguments   : void
function description : check if the database is full or not.
*/
bool SDB_IsFull () ;

/*
function name        : SDB_DeletEntry
function returns     : void
function arguments   : uint32 id
function description : delete all data corresponding to the passed ID.
*/
void SDB_DeletEntry (uint32 id) ;

/*
function name        : SDB_GetList
function returns     : void
function arguments   : uint8 * count, uint32* list
function description : store all of the IDs in a dynamic array its size is equal to the number of students in the database
                        then print the stored IDs.
*/
void SDB_GetList (uint8 * count, uint32* list) ;

#include "SDBAPP.c"

/*
function name        : SDB_APP
function returns     : void
function arguments   : void
function description : it has a super loop it will make your project until the user chose to exit
                        it asks the user to enter a number relative to the function wanted to be activated.
*/
void SDB_APP() ;

/*
function name        : SDB_action
function returns     : void
function arguments   : uint8 choice
function description : it well takes the user choice and call the responding function for this choice.
*/
void SDB_action (uint8 choice) ;



#endif // SDB_H_INCLUDED

