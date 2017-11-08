/* @Author
* Student Name: Oguz Paksoy
* Student ID: 150150111
* Date: 20.03.2017
*/
#pragma once
#include <cstring>
#define STATIC_BUFFER_SIZE 32

class SmallVector {
	private:
		int staticBuffer[STATIC_BUFFER_SIZE];
		int *dynamicBuffer;
		int size;
		int capacity;

		//expandIfNeeded: expands capacity according to the used and required memory space
		void expandIfNeeded(int requiredEmptySpace);
		//shrinkIfPossible: shrinks capacity according to the used and required memory space
		void shrinkIfPossible();
	public:
		//default constructor
		SmallVector();
		//constructor with array and arraysize arguments
		SmallVector(const int* const arr, int arrsize);
		//copy constructor
		SmallVector(const SmallVector &sm);

		//push_back with one integer
		void push_back(int inp);
		//push_back with an array of integers
		void push_back(const int* const arr, int arrsize);

		//pop_back: returns the final element and removes it from the SmallVector object
		int pop_back();

		//getSize: returns current number of elements
		int getSize() const;
		//getCapacity: returns current capacity
		int getCapacity() const;

		//+: SmallVector concatenation
		SmallVector operator+(const SmallVector& sm);

		//=: chainable SmallVector assignment
		SmallVector& operator=(const SmallVector& sm);

		//*: creates a new SmallVector object with the replicated elements of another SmallVector object
		SmallVector operator*(int multp);

		//[]: enables access of SmallVector elements, can take negative integers as its argument
		int operator[](int index) const;
		//[]: enables accessing and editing of SmallVector elements, can take negative integers as its argument
		int& operator[](int index);

		//reverse: returns the reverse of the SmallVector object
		SmallVector reverse();

		//destructor
		~SmallVector();
};
