/* @Author
* Student Name: Oguz Paksoy
* Student ID: 150150111
* Date: 24.04.2017
*/

#pragma once
#include "AdderRemover.h"

/*** Classes that handle the behaviour of the linked list ***/

//First Add First Remove variant class
class FAFR : public AdderRemover {
	public:
		//default constructor
		FAFR();

		//add function which adds an integer to the beginning of the linked list
		bool add(int);
		//remove function which removes an integer from the beginning of the linked list
		bool remove();
		//setTraverser which sets the traverser to traverse the linked list from the beginning to the end
		void setTraverser();
};

//First Add Last Remove variant class
class FALR : public AdderRemover {
	public:
		//default constructor
		FALR();

		//add function which adds an integer to the beginning of the linked list
		bool add(int);
		//remove function which removes an integer from the end of the linked list
		bool remove();
		//setTraverser which sets the traverser to traverse the linked list from the beginning to the end
		void setTraverser();
};

//Last Add First Remove variant class
class LAFR : public AdderRemover {
	public:
		//default constructor
		LAFR();

		//add function which adds an integer to the end of the linked list
		bool add(int);
		//remove function which removes an integer from the beginning of the linked list
		bool remove();
		//setTraverser which sets the traverser to traverse the linked list from the end to the beginning
		void setTraverser();
};

//Last Add Last Remove variant class
class LALR : public AdderRemover {
	public:
		//default constructor
		LALR();

		//add function which adds an integer to the end of the linked list
		bool add(int);
		//remove function which removes an integer from the end of the linked list
		bool remove();
		//setTraverser which sets the traverser to traverse the linked list from the end to the beginning
		void setTraverser();
};