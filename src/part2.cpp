/*
 * part2.cpp
 *
 *  Created on: Feb 16, 2017
 *      Author: aaron
 */

#include <iostream>

#include "part2.h"
#include "part1.h"

void doubleCapacity(const float *ptrArray, int &size){
	float *newArray = nullptr;
	newArray = new float(2*size);
	for(int i = 0; i < size; i++){
		newArray[i] = ptrArray[i];
	}
	for(int i = size; i < (2 * size); i++){
		newArray[i] = 0;
	}
	delete [] ptrArray;
	ptrArray = newArray;
	size = 2*size;
}

void part2(void){
	int size = 0;
	float *ptrFloatArray = nullptr;
	createArray(ptrFloatArray, size);

	/*
	for(int i = 0; i < size; i++){
		std::cout << ptrFloatArray[i] << std::endl;
	}
	*/

	float average;
	arrayAverage(ptrFloatArray, size, average);
	std::cout << "The average value was: ";
	std::cout << average << std::endl;

	int num;
	numAboveAverage(ptrFloatArray, size, average, num);
	std::cout << "Computing how many grades are above average" << std::endl;
	std::cout << "There are: " << num << " above average entries" << std::endl;

	std::cout << "Now doubling capacity" << std::endl;
	doubleCapacity(ptrFloatArray, size);
	std::cout << std::endl;
	std::cout << "Now you may add an additional " << (size / 2) << " numbers" << std::endl;
	std::cout << "Entering a non number value will allow you to use the <enter> key to exit early, " << std::endl;
	std::cout << "this will cause the remaining values to be '0'" << std::endl;
	std::cout << "Please enter your data now, remember to leave a space in between entries: " << std::endl;
	bool loop = true;
	int i = size / 2;
	while((!std::cin.fail()) && (i < size)){
		std::cin >> ptrFloatArray[i];
		i++;
	}
	std::cout << "The final array size is: " << size << std::endl;
	std::cout << std::endl << "This is what I recorded: " << std::endl;
	for(int i = 0; i < size; i++){
		std::cout << ptrFloatArray[i] << " ";
	}

	arrayAverage(ptrFloatArray, size, average);
	std::cout << "The average value was: ";
	std::cout << average << std::endl;

	numAboveAverage(ptrFloatArray, size, average, num);
	std::cout << "Computing how many grades are above average" << std::endl;
	std::cout << "There are: " << num << " above average entries" << std::endl;
}

