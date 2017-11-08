/* @Author
* Student Name: Oguz Paksoy
* Student ID: 150150111
* Date: 13.05.2017
*/

#include "candy.h"

//constructor: initializes the object with the given parameters
Candy::Candy(const string& name_in, double weight_in, double pricePerKG_in) : name(name_in), weight(weight_in), pricePerKG(pricePerKG_in) {
	cost = weight * pricePerKG;
}

//copy constructor: takes its values from an existing object
Candy::Candy(const Candy& candy_in) : name(candy_in.name), weight(candy_in.weight), pricePerKG(candy_in.pricePerKG) {
	cost = weight * pricePerKG;
}

//getAmount: returns weight
double Candy::getAmount() const {
	return weight;
}

//setAmount: sets weight to the given value, also updates cost
void Candy::setAmount(double w_in) {
	weight = w_in;
	cost = weight * pricePerKG;
}

//friend function operator<<: lets the class send relevant data to standard ostream
ostream& operator<<(ostream& stream_in, const Candy& candy_in) {
	return stream_in << candy_in.name << " #" << candy_in.weight << " Cost: " << candy_in.cost;
}