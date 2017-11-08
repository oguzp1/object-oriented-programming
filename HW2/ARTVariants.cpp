/* @Author
* Student Name: Oguz Paksoy
* Student ID: 150150111
* Date: 24.04.2017
*/

#include "ARTVariants.h"


/*** ARTF Constructor & Functions ***/


/* default constructor:
 * constructs the ARTraverser object using the constructor, sets current pointer to the given pointer
 */
ARTF::ARTF(Node *firstElem) : ARTraverser(firstElem) { }

/* hasNode:
 * returns true if current isn't NULL
 * returns false otherwise
 */
bool ARTF::hasNode() {
	return (current != NULL);
}

/* next:
 * returns the current element in the linked list, and advances current element to the next element
 * it is guaranteed that current->next always exists (even if NULL)
 */
Node* ARTF::next() {
	Node* ret = current;
	current = current->next;
	return ret;
}


/*** ARTL Constructor & Functions ***/


/* default constructor:
 * constructs the ARTraverser object using the constructor, sets current pointer to the given pointer
 */
ARTL::ARTL(Node *firstElem) : ARTraverser(firstElem) { }

/* hasNode:
 * returns true if current isn't NULL
 * returns false otherwise
 */
bool ARTL::hasNode() {
	return (current != NULL);
}

/* next:
 * returns the current element in the linked list, and advances current element to the previous element
 * it is guaranteed that current->prev always exists (even if NULL)
 */
Node* ARTL::next() {
	Node *ret = current;
	current = current->prev;
	return ret;
}