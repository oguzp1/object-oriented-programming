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

//Icecream class
class Icecream {

	//Shop can access private elements
	template <class T>
	friend class Shop;

	private:
		string name;
		double litre, pricePerLitre, cost;
	public:
		//constructor: initializes the object with the given parameters
		Icecream(const string&, double, double);
		//copy constructor
		Icecream(const Icecream&);

		//getAmount function
		double getAmount() const;
		//setAmount function
		void setAmount(double);

		//operator<< overloaded for cout use, used as a friend function
		friend ostream& operator<<(ostream&, const Icecream&);
};
