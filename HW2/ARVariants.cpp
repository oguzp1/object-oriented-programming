/* @Author
* Student Name: Oguz Paksoy
* Student ID: 150150111
* Date: 24.04.2017
*/

#include "ARVariants.h"
#include "ARTVariants.h"


/*** FAFR Constructor & Functions ***/


/* default constructor:
 * constructs the AdderRemover object and sets the name of the FAFR object
 */
FAFR::FAFR() : AdderRemover() {
	name = "FAFR";
}

/* add:
 * adds given integer to the linked list's beginning
 * returns true if it succeeds, returns false if it fails
 */
bool FAFR::add(int list_in) {
	//construct new Node object
	Node *newElem = new Node(list_in);

	//if allocation failed, return false
	if (newElem == NULL)
		return false;

	//if list is empty, assign newElem as the head and the tail of the list
	if (head == NULL)
		head = tail = newElem;
	//else
	else {
		//the element after newElem should be the head
		newElem->next = head;
		//the element before head should be newElem
		head->prev = newElem;
		//new head of the list is newElem
		head = newElem;
	}

	//increment nodeCount
	++nodeCount;

	//if allocation didn't fail, return true
	return true;
}

/* remove:
 * removes an integer from the linked list's beginning
 * returns true if it succeeds, returns false if it fails
 */
bool FAFR::remove() {
	//if the list is empty, return false
	if (head == NULL)
		return false;
	
	//if there's only one element in the list
	if (head == tail) {
		//remove the element and set head and tail to NULL
		delete head;
		head = tail = NULL;
	}
	//else
	else {
		//keep the first element
		Node *temp = head;
		//advance head once
		head = head->next;
		//eliminate the prev connection of the new head of the list by setting the pointer to NULL
		head->prev = NULL;
		//deallocate the first element
		delete temp;
	}

	//decrement nodeCount
	--nodeCount;

	//if the list wasn't empty, an element has been removed, return true
	return true;
}

/* setTraverser:
 * sets the traversal method for this class when called
 */
void FAFR::setTraverser() {
	//the default traversal method for the FAFR class is ARTF
	traverser = new ARTF(head);
}


/*** FALR Constructor & Functions ***/


/* default constructor:
 * constructs the AdderRemover object and sets the name of the FALR object
 */
FALR::FALR() : AdderRemover() {
	name = "FALR";
}

/* add:
 * adds given integer to the linked list's beginning
 * returns true if it succeeds, returns false if it fails
 */
bool FALR::add(int list_in) {
	//construct new Node object
	Node *newElem = new Node(list_in);

	//if allocation failed, return false
	if (newElem == NULL)
		return false;

	//if list is empty, assign newElem as the head and the tail of the list
	if (head == NULL)
		head = tail = newElem;
	//else
	else {
		//the element after newElem should be the head
		newElem->next = head;
		//the element before head should be newElem
		head->prev = newElem;
		//new head of the list is newElem
		head = newElem;
	}

	//increment nodeCount
	++nodeCount;

	//if allocation didn't fail, return true
	return true;
}

/* remove:
 * removes an integer from the linked list's end
 * returns true if it succeeds, returns false if it fails
 */
bool FALR::remove() {
	//if the list is empty, return false
	if (tail == NULL)
		return false;

	//if there's only one element in the list
	if (tail == head) {
		//remove the element and set head and tail to NULL
		delete tail;
		tail = head = NULL;
	}
	//else
	else {
		//keep the last element
		Node *temp = tail;
		//advance tail once
		tail = tail->prev;
		//eliminate the next connection of the new tail of the list by setting the pointer to NULL
		tail->next = NULL;
		//deallocate the first element
		delete temp;
	}

	//decrement nodeCount
	--nodeCount;

	//if the list wasn't empty, an element has been removed, return true
	return true;
}

/* setTraverser:
 * sets the traversal method for this class when called
 */
void FALR::setTraverser() {
	//the default traversal method for the FALR class is ARTF
	traverser = new ARTF(head);
}


/*** LAFR Constructor & Functions ***/


/* default constructor:
 * constructs the AdderRemover object and sets the name of the LAFR object
 */
LAFR::LAFR() : AdderRemover() {
	name = "LAFR";
}

/* add:
 * adds given integer to the linked list's end
 * returns true if it succeeds, returns false if it fails
 */
bool LAFR::add(int list_in) {
	//construct new Node object
	Node *newElem = new Node(list_in);

	//if allocation failed, return false
	if (newElem == NULL)
		return false;

	//if list is empty, assign newElem as the head and the tail of the list
	if (tail == NULL)
		tail = head = newElem;
	//else
	else {
		//the element before newElem should be the tail
		newElem->prev = tail;
		//the element after tail should be newElem
		tail->next = newElem;
		//new tail of the list is newElem
		tail = newElem;
	}

	//increment nodeCount
	++nodeCount;

	//if allocation didn't fail, return true
	return true;
}

/* remove:
 * removes an integer from the linked list's beginning
 * returns true if it succeeds, returns false if it fails
 */
bool LAFR::remove() {
	//if the list is empty, return false
	if (head == NULL)
		return false;

	//if there's only one element in the list
	if (head == tail) {
		//remove the element and set head and tail to NULL
		delete head;
		head = tail = NULL;
	}
	//else
	else {
		//keep the first element
		Node *temp = head;
		//advance head once
		head = head->next;
		//eliminate the prev connection of the new head of the list by setting the pointer to NULL
		head->prev = NULL;
		//deallocate the first element
		delete temp;
	}

	//decrement nodeCount
	--nodeCount;

	//if the list wasn't empty, an element has been removed, return true
	return true;
}


/* setTraverser:
 * sets the traversal method for this class when called
 */
void LAFR::setTraverser() {
	//the default traversal method for the LAFR class is ARTL
	traverser = new ARTL(tail);
}


/*** LALR Constructor & Functions ***/


/* default constructor:
 * constructs the AdderRemover object and sets the name of the LALR object
 */
LALR::LALR() : AdderRemover() {
	name = "LALR";
}

/* add:
 * adds given integer to the linked list's end
 * returns true if it succeeds, returns false if it fails
 */
bool LALR::add(int list_in) {
	//construct new Node object
	Node *newElem = new Node(list_in);

	//if allocation failed, return false
	if (newElem == NULL)
		return false;

	//if list is empty, assign newElem as the head and the tail of the list
	if (tail == NULL)
		tail = head = newElem;
	//else
	else {
		//the element before newElem should be the tail
		newElem->prev = tail;
		//the element after tail should be newElem
		tail->next = newElem;
		//new tail of the list is newElem
		tail = newElem;
	}

	//increment nodeCount
	++nodeCount;

	//if allocation didn't fail, return true
	return true;
}

/* remove:
 * removes an integer from the linked list's end
 * returns true if it succeeds, returns false if it fails
 */
bool LALR::remove() {
	//if the list is empty, return false
	if (tail == NULL)
		return false;

	//if there's only one element in the list
	if (tail == head) {
		//remove the element and set head and tail to NULL
		delete tail;
		tail = head = NULL;
	}
	//else
	else {
		//keep the last element
		Node *temp = tail;
		//advance tail once
		tail = tail->prev;
		//eliminate the next connection of the new tail of the list by setting the pointer to NULL
		tail->next = NULL;
		//deallocate the first element
		delete temp;
	}

	//decrement nodeCount
	--nodeCount;

	//if the list wasn't empty, an element has been removed, return true
	return true;
}

/* setTraverser:
 * sets the traversal method for this class when called
 */
void LALR::setTraverser() {
	//the default traversal method for the LALR class is ARTL
	traverser = new ARTL(tail);
}