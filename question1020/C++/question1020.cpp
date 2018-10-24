#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct product {
	double quantity;
	double price;
};

bool compare(product product1, product product2);

int main() {
	int type;
	int need;

	cin >> type >> need;

	double quantity;
	double price;

	vector<double> quantities;
	vector<double> prices;
	vector<product> products;

	product moonCake;

	for (int i = 0; i < type; i++) {
		cin >> quantity;
		quantities.push_back(quantity);
	}
	for (int i = 0; i < type; i++) {
		cin >> price;
		prices.push_back(price);
	}
	for (int i = 0; i < type; i++) {
		moonCake.quantity = quantities[i];
		moonCake.price = prices[i];
		products.push_back(moonCake);
	}
	sort(products.begin(), products.end(), compare);
	double total = 0;
	double profit = 0;
	for (int i = 0; i < products.size(); i++) {
		if (total + products[i].quantity <= need) {
			profit += products[i].price;
			total += products[i].quantity;
		} else {
			profit += (need - total) * products[i].price / products[i].quantity;
			break;
		}
	}
	printf("%.2f", profit);
}

bool compare(product product1, product product2) {
	if (product1.price / product1.quantity - product2.price / product2.quantity >= 0) {
		return true;
	} else {
		return false;
	}
}