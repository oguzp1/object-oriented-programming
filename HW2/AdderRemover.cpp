/* @Author
* Student Name: Oguz Paksoy
* Student ID: 150150111
* Date: 24.04.2017
*/

#include "AdderRemover.h"
#include <iostream>

using namespace std;

/* default constructor:
 * sets head, tail and traverser pointers to NULL
 */
AdderRemover::AdderRemover() : head(NULL), tail(NULL), traverser(NULL) { }

/* display:
 * prints information about the contents of the linked list  
 */
void AdderRemover::display() {
	cout << name << " | NodeCount:" << nodeCount << endl << "------" << endl;

	//if the linked list is empty, print out a message indicating that it's empty
	if (nodeCount == 0)
		cout << "There are no elements to print." << endl;
	//else, iterate from the first element to the last element and print contents
	else {
		Node *t = head;

		while (t) {
			cout << t->data << endl;
			t = t->next;
		}
	}
}

/* removeAll:
 * removes all nodes from the linked list
 */
void AdderRemover::removeAll() {
	//if head isn't NULL
	if (head) {
		//iterate from the first element to the last element and remove all elements
		Node *t, *t2;
		t = head;
		t2 = t->next;

		//making the while loop condition t2 avoids the cases where t2 is NULL when trying to access its next field
		while (t2) {
			delete t;
			t = t2;
			t2 = t2->next;
		}
		//however it leaves out 1 element, which is deleted outside the loop
		delete t;

		//set head and tail to NULL
		head = tail = NULL;

		//set nodeCount to zero
		nodeCount = 0;
	}
}

/* traverse:
 * traverses the list in the desired traversal mode, and prints information about the contents of the linked list
 */
void AdderRemover::traverse() {
	cout << name << " | NodeCount:" << nodeCount << endl << "------" << endl;

	//if the linked list is empty, print out a message indicating that it's empty
	if (nodeCount == 0)
		cout << "There are no elements to print." << endl;
	//else, use the ARTraverser pointer to traverse the linked list and print contents
	else {
		while (traverser->hasNode())
			cout << traverser->next()->data << endl;
	}
}

/* destructor:
 * deallocates all data associated with the AdderRemover object
 */
AdderRemover::~AdderRemover() {
	//delete the traverser object if it was set
	if (traverser)
		delete traverser;
	//remove all elements
	removeAll();
}