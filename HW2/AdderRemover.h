/* @Author
* Student Name: Oguz Paksoy
* Student ID: 150150111
* Date: 24.04.2017
*/

#pragma once
#include "ARTraverser.h"
#include <string>

//abstract AdderRemover class
class AdderRemover {
	protected:
		Node *head, *tail;
		std::string name;
		int nodeCount;
		ARTraverser *traverser;
	public:
		//default constructor for the derived classes to run
		AdderRemover();

		//pure virtual add
		virtual bool add(int) = 0;
		//pure virtual remove
		virtual bool remove() = 0;
		//pure virtual setTraverser
		virtual void setTraverser() = 0;

		//display function which prints the linked list contents
		void display();
		//removeAll function which removes all elements from the linked list
		void removeAll();
		//traverse function which prints the linked list contents with the set traversal method
		void traverse();

		//virtual destructor
		virtual ~AdderRemover();
};