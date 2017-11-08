/* @Author
* Student Name: Oguz Paksoy
* Student ID: 150150111
* Date: 24.04.2017
*/

#pragma once
#ifndef NULL
#define NULL 0
#endif // !NULL


//Node class
class Node {
	//friend classes
	friend class AdderRemover;
	friend class FAFR;
	friend class FALR;
	friend class LAFR;
	friend class LALR;
	friend class ARTF;
	friend class ARTL;

	private:
		int data;
		Node *next, *prev;
		//constructor that assigns an initial value to the data kept, assigns NULL to next and prev pointers by default
		Node(int data_in) : data(data_in), next(NULL), prev(NULL) { }
};