/* @Author
* Student Name: Oguz Paksoy
* Student ID: 150150111
* Date: 13.05.2017
*/

#pragma once
#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::ostream;
using std::vector;

//pre-initialization for the compiler
template <class T> class Shop;
template <class T> ostream& operator<<(ostream&, const Shop<T>&);

//Shop container class
template <class Type>
class Shop {

	private:
		vector<Type> shop;
		double discountRate, cost;
		static const int TAX_RATE = 8;
	public:
		//default constructor
		Shop();
		//constructor that opens the shop with an item
		Shop(const Type&);
		//copy constructor
		Shop(const Shop<Type>&);

		//add function adds an item to the shop, returns item on vector
		Type& add(const Type&);
		//getDiscount function returns the discount rate
		double getDiscount() const;
		//setDiscount function sets the discount
		void setDiscount(double);
		//find function finds the index of the given item
		int find(const string&) const;
		//checkStock function looks at the stock and tells if an amount exists or not
		int checkStock(const string&, double) const;
		//getTaxlessCost function
		double getTaxlessCost() const;
		//getCost function
		double getCost() const;
		//setCost function calculates cost
		void setCost();
		//getDiscountCost function
		double getDiscountCost() const;
		//getShopSize function
		int getShopSize() const;

		//subscript operator overloaded for list access
		const Type& operator[](int) const;
		
		//destructor
		~Shop();

		//friend function operator<<: lets the class send relevant data to standard ostream
		friend ostream& operator<< <>(ostream&, const Shop<Type>&);
};

/* ----------------------------------------------------- */

//default constructor: initializes an empty shop
template <class Type>
Shop<Type>::Shop() : discountRate(0), cost(0) { }

//constructor: initializes a shop with the given item
template <class Type>
Shop<Type>::Shop(const Type& in_item) : discountRate(0) {
	shop.push_back(in_item);
	setCost();
}

//copy constructor: copies an existing shop with all its items
template <class Type>
Shop<Type>::Shop(const Shop<Type>& shop_in) : discountRate(shop_in.discountRate), cost(shop_in.cost) {
	this->shop = shop_in.shop;
}

//add: adds an item to the shop, returns item in vector
template <class Type>
Type& Shop<Type>::add(const Type& in_item) {
	shop.push_back(in_item);
	setCost();
	return shop.back();
}

//getDiscount: returns discountRate
template <class Type>
double Shop<Type>::getDiscount() const {
	return discountRate;
}

//setDiscount: sets the discount to the given value if it is within range, throws an exception otherwise
template <class Type>
void Shop<Type>::setDiscount(double discount_in) {
	if (discount_in >= 0 && discount_in <= 30)
		discountRate = discount_in;
	else
		throw "Discount rate is out of range!";
}

//find: finds a certain item's index and returns it, returns -1 if item doesn't exist
template <class Type>
int Shop<Type>::find(const string& search_string) const {
	//index, by default -1
	int index = -1;

	//search the given string in the vector
	for (int i = 0; i < getShopSize(); ++i) {
		if (search_string.compare(shop[i].name) == 0) {
			index = i;
			break;
		}
	}

	//return index
	return index;
}

//checkStocks: returns the item index if stocks have the given amount of the desired item, returns -1 otherwise
template <class Type>
int Shop<Type>::checkStock(const string& desired_item, double desired_amount) const {
	//find index
	int index = find(desired_item);

	//if the item exists and the stock has enough of the item, return true
	if (index != -1 && shop[index].getAmount() >= desired_amount)
		return index;
	//otherwise, return false
	else
		return -1;
}

//getTaxlessCost: returns taxless cost
template <class Type>
double Shop<Type>::getTaxlessCost() const {
	return cost;
}

//setCost: calculates the total cost of the shop with tax and discount
template <class Type>
void Shop<Type>::setCost() {
	//initialize the cost as 0
	cost = 0;

	//for each item in the shop, add their cost to the shop's cost
	for (int i = 0; i < getShopSize(); ++i)
		cost += shop[i].cost;
}

//getCost: returns cost
template <class Type>
double Shop<Type>::getCost() const {
	return cost + (cost * TAX_RATE) / 100;
}

//getDiscountCost: returns cost with discount
template <class Type>
double Shop<Type>::getDiscountCost() const {
	double taxCost = getCost();
	return taxCost - taxCost * discountRate / 100;
}

//getShopSize: returns size of shop
template <class Type>
int Shop<Type>::getShopSize() const {
	return static_cast<int>(shop.size());
}

//operator[]: accesses the shop contents if the content at the index exists, throws an exception otherwise
template <class Type>
const Type& Shop<Type>::operator[](int index) const {
	if (index < getShopSize() && index >= 0)
		return shop[index];
	else
		throw "We don\'t have enough cookies!";
}

//destructor: empty for this container class, std::vector automatically deallocates each item
template <class Type>
Shop<Type>::~Shop() { }

/* ----------------------------------------------------- */

//friend function operator<<: lets the class send relevant data to standard ostream
template <class Type>
ostream& operator<<(ostream& stream_in, const Shop<Type>& shop_in) {
	stream_in << "**********************" << std::endl;
	stream_in << "Number of items: " << shop_in.getShopSize() << std::endl;

	//call operator<< on Cookie, Icecream, Candy or Shop items
	for (int i = 1; i <= shop_in.getShopSize(); ++i)
	stream_in << i << ". " << shop_in.shop[i - 1] << std::endl << std::endl;

	stream_in << "**********************" << std::endl;
	stream_in << "Total cost: " << shop_in.getCost() << std::endl;

	//if there's a discount, include that as well
	if (shop_in.getDiscount() > 0) {
		stream_in << "Discount: " << shop_in.getDiscount() << "%" << std::endl;
		stream_in << "Discount amount: -" << shop_in.getDiscount() * shop_in.getCost() / 100 << std::endl;
		stream_in << "Discounted cost: " << shop_in.getDiscountCost() << std::endl;
	}

	stream_in << "**********************" << std::endl;
	return stream_in;
}