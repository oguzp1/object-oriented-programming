/* @Author
* Student Name: Oguz Paksoy
* Student ID: 150150111
* Date: 24.04.2017
*/

#pragma once
#include "ARTraverser.h"


/*** Classes that handle the traversal of the linked list ***/


//First to last element traverser class
class ARTF : public ARTraverser {
	//friend classes
	friend class AdderRemover;
	friend class FAFR;
	friend class FALR;

	private:
		//constructor that will take an element's pointer as an argument
		ARTF(Node *);

		//hasNode function which returns true if there are nodes to visit, returns false otherwise
		bool hasNode();
		//next function which returns a pointer to the current element, and advances the position to the next element
		Node* next();
};

//Last to first element traverser class
class ARTL : public ARTraverser {
	//friend classes
	friend class AdderRemover;
	friend class LAFR;
	friend class LALR;

	private:
		//constructor that will take an element's pointer as an argument
		ARTL(Node *);

		//hasNode function which returns true if there are nodes to visit, returns false otherwise
		bool hasNode();
		//next function which returns a pointer to the current element, and advances the position to the previous element
		Node* next();
};