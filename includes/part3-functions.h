/*
 * part3-functions.h
 *
 *  Created on: Feb 16, 2017
 *      Author: aaron
 */

#ifndef PART3_FUNCTIONS_H_
#define PART3_FUNCTIONS_H_

#include "student.h"

//! Adding in new student, console entry is managed in function,
// therefore, only a reference to the student body is needed
void addNewStudent(Student &StudentBody);

//! \brief Removing a student
//
// Like in addNewStudent, this function takes in the
// location of the student body to modify, all behavior
// is managed internally
void removeStudent(Student &StudentBody);

//! print all currently enrolled students
// Not sure on PTR type at this point in time.
// Could also try using pass by reference.
// This function only outputs to the console, another
// that provides manipulatable data might be useful to
// add later on, once the type of data to manipulate is
// determined
void printAllStudents(const Student *PTRtoStudents);



#endif /* PART3_FUNCTIONS_H_ */
