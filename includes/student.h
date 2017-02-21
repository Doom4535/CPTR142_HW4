/*
 * part3.h
 *
 *  Created on: Feb 16, 2017
 *      Author: aaron
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <vector>

// bad practice
//int maxCourseLoad = 8;

struct studentName{
	std::string Lname;
	std::string Fname;
};

class Student{
	private:
		static int IDpool;
		int ID = 0;	//! Defaulting to '0', if this value occurs the sensor has had some initialization issues
		//std::string Lname;
		//std::string Fname;
		studentName Name;
		int numClasses = 0; // Number of enrolled classes
		std::string *ClassList;
		//std::string ClassList;
		//std::vector <std::string> ClassList;

	public:
		Student(void);
		//Student(std::string Last_name, std::string First_name);
		void setName(std::string Last_name, std::string First_name);
		studentName getName(void);
		int getNumClasses(void);
		int getID(void);
		// something to list more about courses
		void addClass(std::string className);
		void dropClass(std::string className);
		void displayEnrollment(void);
		void resetClasses(void);
		// Overload assignment operator
		Student& operator=(const Student& rtSide);
		~Student();


};


#endif /* STUDENT_H_ */
