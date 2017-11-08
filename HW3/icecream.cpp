/* @Author
* Student Name: Oguz Paksoy
* Student ID: 150150111
* Date: 13.05.2017
*/

#include "icecream.h"

//constructor: initializes the object with the given parameters
Icecream::Icecream(const string& name_in, double litre_in, double pricePerLitre_in) : name(name_in), litre(litre_in), pricePerLitre(pricePerLitre_in) {
	cost = litre * pricePerLitre;
}

//copy constructor: takes its values from an existing object
Icecream::Icecream(const Icecream& icecream_in) : name(icecream_in.name), litre(icecream_in.litre), pricePerLitre(icecream_in.pricePerLitre) {
	cost = litre * pricePerLitre;
}

//getAmount: returns litre
double Icecream::getAmount() const {
	return litre;
}

//setAmount: sets litre to the given value, also updates cost
void Icecream::setAmount(double l_in) {
	litre = l_in;
	cost = litre * pricePerLitre;
}

//friend function operator<<: lets the class send relevant data to standard ostream
ostream& operator<<(ostream& stream_in, const Icecream& icecream_in) {
	return stream_in << icecream_in.name << " #" << icecream_in.litre << " Cost: " << icecream_in.cost;
}