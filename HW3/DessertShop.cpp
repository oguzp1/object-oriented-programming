/* @Author
* Student Name: Oguz Paksoy
* Student ID: 150150111
* Date: 13.05.2017
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include "candy.h"
#include "cookie.h"
#include "icecream.h"
#include "shop.h"
using namespace std;

//readStock: reads stock.txt and writes data onto 3 seperate shops
void readStock(Shop<Cookie>& cookie_box, Shop<Candy>& candy_box, Shop<Icecream>& icecream_box) {
	//open file
	ifstream fr("stock.txt");
	string line, name, type, amount, price;

	//skip first line
	getline(fr, line);

	//read each string until \t or newline characters, and for each one do
	while (getline(fr, name, '\t')) {
		getline(fr, type, '\t');
		getline(fr, amount, '\t');
		getline(fr, price);

		double d_amount, d_price;
		//turn the strings into double values
		istringstream(amount) >> d_amount;
		istringstream(price) >> d_price;

		//map the type to the given shop, and add an item with the given name, amount and price values
		if (type.compare("1") == 0)
			cookie_box.add(Cookie(name, d_amount, d_price));
		else if (type.compare("2") == 0)
			candy_box.add(Candy(name, d_amount, d_price));
		else
			icecream_box.add(Icecream(name, d_amount, d_price));
	}

	//close file
	fr.close();
}

//evaluateRequest: evaluates the request according to the stock, reads order.txt, and writes the accepted requests onto checkout.txt
void evaluateRequest(Shop<Cookie>& cookie_stock, Shop<Candy>& candy_stock, Shop<Icecream>& icecream_stock) {
	//open read and write files
	ifstream fr("order.txt");
	ofstream fw("checkout.txt");
	string name, type, amount;
	//stringstream and counter for the written file
	stringstream printedItems;
	int printedIndex = 1;

	//request containers
	Shop<Cookie> cookieShopRequest;
	Shop<Candy> candyShopRequest;
	Shop<Icecream> icecreamShopRequest;

	//read each string until \t or newline characters, and for each one do
	while (getline(fr, name, '\t')) {
		getline(fr, type, '\t');
		getline(fr, amount);

		double d_amount;
		//turn the strings into double values
		istringstream(amount) >> d_amount;

		//index value for found indexes
		int index;

		//case cookie
		if (type.compare("1") == 0) {
			//find given index
			index = cookie_stock.find(name);
			//if item found
			if (index != -1) {
				//add the item to the request list, and keep a reference
				Cookie& req = cookieShopRequest.add(cookie_stock[index]);
				//assign index to checkStock's return value, if check doesn't fail
				if ((index = cookie_stock.checkStock(name, d_amount)) != -1) {
					//set request to given amount
					req.setAmount(d_amount);
					//recalculate cost
					cookieShopRequest.setCost();
				}
				//if check fails, write a warning (all of stock is added to the request list by default)
				else
					fw << "!!! We don\'t have " << d_amount << " (" << name << ")s." << endl;

				//add to the stringstream, the list of requests
				printedItems << printedIndex++ << ". " << req << endl;
			}
		}
		//case candy
		else if (type.compare("2") == 0) {
			//find given index
			index = candy_stock.find(name);
			//if item found
			if (index != -1) {
				//add the item to the request list, and keep a reference
				Candy& req = candyShopRequest.add(candy_stock[index]);
				//assign index to checkStock's return value, if check doesn't fail
				if ((index = candy_stock.checkStock(name, d_amount)) != -1) {
					//set request to given amount
					req.setAmount(d_amount);
					//recalculate cost
					candyShopRequest.setCost();
				}
				//if check fails, write a warning (all of stock is added to the request list by default)
				else
					fw << "!!! We don\'t have " << d_amount << " (" << name << ")s." << endl;

				//add to the stringstream, the list of requests
				printedItems << printedIndex++ << ". " << req << endl;
			}
		}
		//case icecream
		else {
			//find given index
			index = icecream_stock.find(name);
			//if item found
			if (index != -1) {
				//add the item to the request list, and keep a reference
				Icecream& req = icecreamShopRequest.add(icecream_stock[index]);
				//assign index to checkStock's return value, if check doesn't fail
				if ((index = icecream_stock.checkStock(name, d_amount)) != -1) {
					//set request to given amount
					req.setAmount(d_amount);
					//recalculate cost
					icecreamShopRequest.setCost();
				}
				//if check fails, write a warning (all of stock is added to the request list by default)
				else
					fw << "!!! We don\'t have " << d_amount << " (" << name << ")s." << endl;

				//add to the stringstream, the list of requests
				printedItems << printedIndex++ << ". " << req << endl;
			}
		}
	}
	//close file read
	fr.close();

	//write the number of items and the stringstream
	fw << "-----------------------" << endl;

	int sumItems = cookieShopRequest.getShopSize() + candyShopRequest.getShopSize() + icecreamShopRequest.getShopSize();

	fw << "Number of items: " << sumItems << endl;

	fw << printedItems.rdbuf();

	//taxless total
	double taxlessCostTotal = cookieShopRequest.getTaxlessCost() + candyShopRequest.getTaxlessCost() + icecreamShopRequest.getTaxlessCost();
	//8% tax added
	double costTotal = taxlessCostTotal + taxlessCostTotal * 0.08;
	//10% discount
	double discountCostTotal = costTotal - costTotal * 0.1;

	//write totals
	fw << "**********************" << std::endl;
	fw << "Total cost: " << costTotal << std::endl;

	fw << "Discount: 10%" << std::endl;
	fw << "Discount amount: -" << costTotal - discountCostTotal << std::endl;
	fw << "Discounted cost: " << discountCostTotal << std::endl;

	fw << "**********************" << std::endl;

	//close file write
	fw.close();
}

int main() {
	Cookie cookie1("Chocolate Chip Cookies", 10, 180); //(name, pieces, priceperdozen)
	Cookie cookie2("Cake Mix Cookies", 16, 210);

	Shop<Cookie> cookieShop(cookie1);
	cookieShop.add(cookie2);
	cout << cookieShop << endl;

	//Catch an exception here while trying to access the element at(2)
	try {
		cout << cookieShop[2] << endl;
	}
	catch (const char * errorMsg) {
		cout << errorMsg << endl;
	}

	Icecream icecream1("Chocolate ice cream", 1.5, 170); //(name, litre, priceperlitre)
	Shop<Icecream> icecreamShop(icecream1);
	cout << icecreamShop << endl;

	//Catch an exception here while trying to set the discount to(50) 
	try {
		icecreamShop.setDiscount(50);
	}
	catch (const char * errorMsg) {
		cout << errorMsg << endl;
	}
	Candy candy2("Gummi bears", 12, 89); //(name, weight, priceperkg)
	Candy candy3("Hanukkah gelt", 8, 110);

	Shop<Candy> candyShop(candy2);
	candyShop.add(candy3);

	candyShop.setDiscount(15);
	cout << candyShop << endl;

	/*You will also
	1) Read dessert stock and customer order from "stock.txt" and "order.txt", respectively.
	2) Write the total cost with 10% discount to "checkout.txt".
	Expected output for checkout:
	!!! We don't have 7 (Orange Jelly Candy)s.
	!!! We don't have 11 (Chocolate ice cream)s.
	-----------------------
	Number of items:4
	1: Chocolate Chip Cookies #2 Cost: 100
	2: Orange Jelly Candy #5 Cost: 750
	3: Chocolate ice cream #2 Cost: 480
	4: Cake Mix Cookies #10 Cost: 150
	**********************
	Total cost: 1598.40
	Discount: %10
	Discount amount: -159.84
	Discounted cost: 1438.56
	**********************
	*/
	
	//initialize stock containers
	Shop<Cookie> cookieShopStock;
	Shop<Candy> candyShopStock;
	Shop<Icecream> icecreamShopStock;

	//read the stock
	readStock(cookieShopStock, candyShopStock, icecreamShopStock);
	//read and evaluate requests
	evaluateRequest(cookieShopStock, candyShopStock, icecreamShopStock);
	return 0;
}