/* @Author
* Student Name: Oguz Paksoy
* Student ID: 150150111
* Date: 24.04.2017
*/

#pragma once
#include "Node.h"

//abstract ARTraverser class
class ARTraverser {
	//AdderRemover can access ARTraverser's private elements
	friend class AdderRemover;

	protected:
		Node *current;

		//constructor with an argument to initialize current
		ARTraverser(Node *firstElem) : current(firstElem) { }

		//pure virtual hasNode
		virtual bool hasNode() = 0;
		//pure virtual next
		virtual Node* next() = 0;
	public:
		//virtual destructor (empty)
		virtual ~ARTraverser() { }
};