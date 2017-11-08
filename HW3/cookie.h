/* @Author
* Student Name: Oguz Paksoy
* Student ID: 150150111
* Date: 13.05.2017
*/

#pragma once

#include <string>
#include <iostream>

using std::string;
using std::ostream;

//Candy class
class Cookie {

	//Shop can access private elements
	template <class T>
	friend class Shop;

	private:
		string name;
		int number;
		double pricePerDozen, cost;
	public:
		//constructor
		Cookie(const string&, int, double);
		//copy constructor
		Cookie(const Cookie&);

		//getAmount function
		int getAmount() const;
		//setAmount function
		void setAmount(int);

		//operator<< overloaded for cout use, used as a friend function
		friend ostream& operator<<(ostream&, const Cookie&);
};