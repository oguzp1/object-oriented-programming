/* @Author
* Student Name: Oguz Paksoy
* Student ID: 150150111
* Date: 20.03.2017
*/
#include "SmallVector.h"

/* ---------- PRIVATE FUNCTIONS ---------- */

void SmallVector::expandIfNeeded(int requiredEmptySpace) {
	//if required space is more than the available capacity
	if (requiredEmptySpace > capacity - size) {
		//while required space is more than the available capacity, double the capacity
		while (requiredEmptySpace > capacity - size)
			capacity *= 2;

		//dynamically allocate new memory space for the new capacity, store it in temp
		//(has to change, otherwise it wouldn't enter the if block)
		int *temp = new int[capacity - STATIC_BUFFER_SIZE];

		//if dynamicBuffer has some allocated space
		if (dynamicBuffer != NULL) {
			//copy all elements that were in the dynamic buffer to temp
			memcpy(temp, dynamicBuffer, (size - STATIC_BUFFER_SIZE)*sizeof(int));

			//deallocate the old memory space
			delete[] dynamicBuffer;
		}

		//temp is the new dynamicBuffer address
		dynamicBuffer = temp;
	}
}

void SmallVector::shrinkIfPossible() {
	//if half of the current capacity is enough to store all the current data
	//and half of the current capacity is more than STATIC_BUFFER_SIZE
	if ((capacity / 2) >= size && (capacity / 2) >= STATIC_BUFFER_SIZE) {
		//while half of the current capacity is enough to store all the current data
		//and half of the current capacity is more than STATIC_BUFFER_SIZE, halve the capacity
		while ((capacity / 2) >= size && (capacity / 2) >= STATIC_BUFFER_SIZE)
			capacity /= 2;

		//if the capacity is now equal to STATIC_BUFFER_SIZE
		if (capacity == STATIC_BUFFER_SIZE) {
			//if there is empty allocated space for the dynamic buffer
			if (dynamicBuffer != NULL) {
				//deallocate it and set dynamicBuffer back to NULL
				delete[] dynamicBuffer;
				dynamicBuffer = NULL;
			}
		}
		//if there's still a need to store elements in the dynamic buffer
		else {
			//dynamically allocate new memory space for temp
			//(has to change, otherwise it wouldn't enter the first if block)
			int *temp = new int[capacity - STATIC_BUFFER_SIZE];


			//copy all elements that were in the dynamic buffer to temp
			memcpy(temp, dynamicBuffer, (size - STATIC_BUFFER_SIZE)*sizeof(int));

			//deallocate the old memory space
			delete[] dynamicBuffer;

			//temp is the new dynamicBuffer address
			dynamicBuffer = temp;
		}
	}
}

/* ---------- CONSTRUCTORS ---------- */

SmallVector::SmallVector() : size(0), capacity(STATIC_BUFFER_SIZE), dynamicBuffer(NULL) { }

SmallVector::SmallVector(const int* const arr, int arrsize) : size(0), capacity(STATIC_BUFFER_SIZE), dynamicBuffer(NULL) {
	//if the desired size is positive
	if (arrsize > 0) {
		//if the desired size exceeds the default capacity
		if (arrsize > capacity) {
			//double the capacity until the capacity becomes more than or equal to the desired size
			while (arrsize > capacity)
				capacity *= 2;

			//dynamically allocate new memory space for the new capacity, store it in dynamicBuffer
			dynamicBuffer = new int[capacity - STATIC_BUFFER_SIZE];
		}

		//add the array to the SmallVector starting from the staticBuffer
		for (int i = 0; i < STATIC_BUFFER_SIZE && i < arrsize; ++i)
			staticBuffer[i] = arr[i];

		//add rest of the array to the SmallVector by adding the remaining elements to dynamicBuffer
		//(if arrsize is less than STATIC_BUFFER_SIZE this is skipped)
		for (int i = STATIC_BUFFER_SIZE; i < arrsize; ++i)
			dynamicBuffer[i - STATIC_BUFFER_SIZE] = arr[i];

		//update size
		size = arrsize;
	}
}

SmallVector::SmallVector(const SmallVector& sm) : dynamicBuffer(NULL) {
	//copy size and capacity
	this->size = sm.size;
	this->capacity = sm.capacity;

	//if the input SmallVector has all its elements in the static buffer, only copy those
	if (sm.size <= STATIC_BUFFER_SIZE)
		memcpy(this->staticBuffer, sm.staticBuffer, (sm.size)*sizeof(int));
	//otherwise
	else {
		//allocate new memory space for this SmallVector's dynamicBuffer
		this->dynamicBuffer = new int[this->capacity - STATIC_BUFFER_SIZE];

		//copy both staticBuffer and dynamicBuffer to this SmallVector
		memcpy(this->staticBuffer, sm.staticBuffer, (STATIC_BUFFER_SIZE)*sizeof(int));
		memcpy(this->dynamicBuffer, sm.dynamicBuffer, (sm.size - STATIC_BUFFER_SIZE)*sizeof(int));
	}
}

/* ---------- PUBLIC FUNCTIONS ---------- */

void SmallVector::push_back(int inp) {
	//expand if needed for 1 new element
	expandIfNeeded(1);

	//if there's available space in the staticBuffer, add the integer to the staticBufffer
	if (size < STATIC_BUFFER_SIZE)
		staticBuffer[size] = inp;
	//otherwise add the integer to the dynamicBuffer
	else
		dynamicBuffer[size - STATIC_BUFFER_SIZE] = inp;

	//increment size
	++size;
}

void SmallVector::push_back(const int* const arr, int arrsize) {
	//if the array size is positive
	if (arrsize > 0) {
		//expand if needed for arrsize number of new elements
		expandIfNeeded(arrsize);

		//if size was smaller than STATIC_BUFFER_SIZE
		if (size < STATIC_BUFFER_SIZE) {
			//add the array to the SmallVector starting from the staticBuffer
			for (int i = size; i < STATIC_BUFFER_SIZE && i < size + arrsize; ++i)
				staticBuffer[i] = arr[i - size];

			//add rest of the array to the SmallVector by adding the remaining elements to dynamicBuffer
			//(if size + arrsize is less than STATIC_BUFFER_SIZE this is skipped)
			for (int i = STATIC_BUFFER_SIZE; i < size + arrsize; ++i)
				dynamicBuffer[i - STATIC_BUFFER_SIZE] = arr[i - size];
		}
		//if size was bigger or equal to STATIC_BUFFER_SIZE
		else {
			//add the array to the SmallVector starting from the dynamicBuffer
			for (int i = size; i < size + arrsize; ++i)
				dynamicBuffer[i - STATIC_BUFFER_SIZE] = arr[i - size];
		}

		//update size
		size += arrsize;
	}
}

int SmallVector::pop_back() {
	//if an element exists
	if (size > 0) {
		//decrement size, it's now the index of the final element
		--size;

		//if size is bigger than STATIC_BUFFER_SIZE, final element is in the dynamic buffer, otherwise final element is in the static buffer
		int popped = (size >= STATIC_BUFFER_SIZE) ? dynamicBuffer[size - STATIC_BUFFER_SIZE] : staticBuffer[size];

		//shrink SmallVector if possible
		shrinkIfPossible();

		//return the popped integer
		return popped;
	}
	//if no elements exists return 0
	else
		return 0;
}

int SmallVector::getSize() const {
	return size;
}

int SmallVector::getCapacity() const {
	return capacity;
}

SmallVector SmallVector::operator+(const SmallVector& sm) {
	//define a temporary SmallVector for the sum
	SmallVector temp(*this);

	//if the input SmallVector has all its elements in the static buffer, only push those to this SmallVector
	if (sm.size <= STATIC_BUFFER_SIZE)
		temp.push_back(sm.staticBuffer, sm.size);
	//otherwise, push both staticBuffer and dynamicBuffer of the input SmallVector to this SmallVector
	else {
		temp.push_back(sm.staticBuffer, STATIC_BUFFER_SIZE);
		temp.push_back(sm.dynamicBuffer, sm.size - STATIC_BUFFER_SIZE);
	}

	//return the reference of this SmallVector
	return temp;
}

SmallVector& SmallVector::operator=(const SmallVector& sm) {
	//if the assignment isn't between the same objects
	if (this != &sm) {
		//copy size and capacity
		this->size = sm.size;
		this->capacity = sm.capacity;

		//if the input SmallVector has all its elements in the static buffer, only copy those
		if (sm.size <= STATIC_BUFFER_SIZE)
			memcpy(this->staticBuffer, sm.staticBuffer, (sm.size)*sizeof(int));
		//otherwise
		else {
			//deallocate old memory space
			if (this->dynamicBuffer != NULL)
				delete[] this->dynamicBuffer;

			//allocate new memory space for this SmallVector's dynamicBuffer
			this->dynamicBuffer = new int[this->capacity - STATIC_BUFFER_SIZE];

			//copy both staticBuffer and dynamicBuffer content to this SmallVector
			memcpy(this->staticBuffer, sm.staticBuffer, (STATIC_BUFFER_SIZE)*sizeof(int));
			memcpy(this->dynamicBuffer, sm.dynamicBuffer, (sm.size - STATIC_BUFFER_SIZE)*sizeof(int));
		}
	}

	//return the reference of this SmallVector
	return *this;
}

SmallVector SmallVector::operator*(int multp) {
	//define new SmallVector to return
	SmallVector mulSV;

	//add this SmallVector to the new one, assign the result to the new SmallVector, multp times
	for (int i = 0; i < multp; ++i)
		mulSV = mulSV + *this;

	//return the SmallVector defined
	return mulSV;
}

int SmallVector::operator[](int index) const {
	//if the given index is nonnegative
	if (index >= 0) {
		//if the element at index exists
		if (index < size)
			//return a reference to the element at index
			//the element is in staticBuffer boundaries if index is smaller than STATIC_BUFFER_SIZE
			//otherwise, it's in dynamicBuffer boundaries
			return (index < STATIC_BUFFER_SIZE) ? staticBuffer[index] : dynamicBuffer[index - STATIC_BUFFER_SIZE];
		//if the element at index doesn't exist
		else
			//return a reference to the highest indexed element (both for negatives and positives)
			//the highest indexed element is in dynamicBuffer if size exceeds STATIC_BUFFER_SIZE
			//otherwise, it's in staticBuffer
			return (size > STATIC_BUFFER_SIZE) ? dynamicBuffer[size - 1 - STATIC_BUFFER_SIZE] : staticBuffer[size - 1];

	}
	//if the given index is negative
	else {
		//if the element at index exists
		if (index >= -size) {
			//convert negative index to a regular nonnegative index as actualIndex
			int actualIndex = size + index;

			//return a reference to the element at actualIndex
			//the element is in staticBuffer boundaries if actualIndex is smaller than STATIC_BUFFER_SIZE
			//otherwise, it's in dynamicBuffer boundaries
			return (actualIndex < STATIC_BUFFER_SIZE) ? staticBuffer[actualIndex] : dynamicBuffer[actualIndex - STATIC_BUFFER_SIZE];
		}
		//if the element at index doesn't exist
		else
			//return a reference to the highest indexed element (both for negatives and positives)
			//the highest indexed element is in dynamicBuffer if size exceeds STATIC_BUFFER_SIZE
			//otherwise, it's in staticBuffer
			return (size > STATIC_BUFFER_SIZE) ? dynamicBuffer[size - 1 - STATIC_BUFFER_SIZE] : staticBuffer[size - 1];
	}
}

int& SmallVector::operator[](int index) {
	//if the given index is nonnegative
	if (index >= 0) {
		//if the element at index exists
		if (index < size)
			//return a reference to the element at index
			//the element is in staticBuffer boundaries if index is smaller than STATIC_BUFFER_SIZE
			//otherwise, it's in dynamicBuffer boundaries
			return (index < STATIC_BUFFER_SIZE) ? staticBuffer[index] : dynamicBuffer[index - STATIC_BUFFER_SIZE];
		//if the element at index doesn't exist
		else
			//return a reference to the highest indexed element (both for negatives and positives)
			//the highest indexed element is in dynamicBuffer if size exceeds STATIC_BUFFER_SIZE
			//otherwise, it's in staticBuffer
			return (size > STATIC_BUFFER_SIZE) ? dynamicBuffer[size - 1 - STATIC_BUFFER_SIZE] : staticBuffer[size - 1];

	}
	//if the given index is negative
	else {
		//if the element at index exists
		if (index >= -size) {
			//convert negative index to a regular nonnegative index as actualIndex
			int actualIndex = size + index;

			//return a reference to the element at actualIndex
			//the element is in staticBuffer boundaries if actualIndex is smaller than STATIC_BUFFER_SIZE
			//otherwise, it's in dynamicBuffer boundaries
			return (actualIndex < STATIC_BUFFER_SIZE) ? staticBuffer[actualIndex] : dynamicBuffer[actualIndex - STATIC_BUFFER_SIZE];
		}
		//if the element at index doesn't exist
		else
			//return a reference to the highest indexed element (both for negatives and positives)
			//the highest indexed element is in dynamicBuffer if size exceeds STATIC_BUFFER_SIZE
			//otherwise, it's in staticBuffer
			return (size > STATIC_BUFFER_SIZE) ? dynamicBuffer[size - 1 - STATIC_BUFFER_SIZE] : staticBuffer[size - 1];
	}
}

SmallVector SmallVector::reverse()  {
	//copy from this SmallVector to a new SmallVector to be returned
	SmallVector revSV(*this);

	//(i)th element in revSV is equal to the -(i + 1)th element in this SmallVector
	for (int i = 0; i < this->size; ++i)
		revSV[i] = (*this)[-i - 1];

	//return the SmallVector defined
	return revSV;
}

SmallVector::~SmallVector() {
	//delete all dynamically allocated space
	if (dynamicBuffer != NULL)
		delete[] dynamicBuffer;
}
