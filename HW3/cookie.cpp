/* @Author
* Student Name: Oguz Paksoy
* Student ID: 150150111
* Date: 13.05.2017
*/

#include "cookie.h"

//constructor: initializes Cookie with the given variables
Cookie::Cookie(const string& name_in, int number_in, double pricePerDozen_in) : name(name_in), number(number_in), pricePerDozen(pricePerDozen_in) {
	cost = number * pricePerDozen / 12;
}

//copy constructor: takes its values from an existing object
Cookie::Cookie(const Cookie& cookie_in) : name(cookie_in.name), number(cookie_in.number), pricePerDozen(cookie_in.pricePerDozen) {
	cost = number * pricePerDozen / 12;
}

//getAmount: returns number
int Cookie::getAmount() const {
	return number;
}

//setAmount: sets number to the given value, also updates cost
void Cookie::setAmount(int num_in) {
	number = num_in;
	cost = number * pricePerDozen / 12;
}

//friend function operator<<: lets the class send relevant data to standard ostream
ostream& operator<<(ostream& stream_in, const Cookie& cookie_in) {
	return stream_in << cookie_in.name << " #" << cookie_in.number << " Cost: " << cookie_in.cost; 
}