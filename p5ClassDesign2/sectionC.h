#include <string>
#include <vector>
class Item {
public:
	Item(std::string name, long id, double price, int numInStock);

	
	std::string _name;
	double _price;
	int _numInStock;
	long _id;

};
std::ostream& operator<< (std::ostream& out, const Item& itemInfo);

class Order {
public:
	Order(std::vector<Item> orderList);

	std::vector<Item> getOrderList() const;
	void addOrder(Item itemName, int numOfItemsBought);
	std::vector<int> getNumOfItemsBought() const;
	double getTotalOrderPrice() const;

private:
	std::vector<Item> _orderList;
	std::vector<int> _numOfItemsBought;
	std::vector<double> _totalOrderPrice;
	
};

class Store {
public:
	Store(std::vector<Item> storeInventory);

	std::vector<Item> getStoreInventory() const;
	std::vector<std::string> getName() const;
	std::vector<int> getNumInStock() const;
	void addItem(std::string itemName, int numInStock);
	void processOrder(const Order& orderItem);


private:
	std::vector<Item> _storeInventory;
	std::vector<std::string> _name;
	std::vector<int> _numInStock;
	
};
std::ostream& operator<< (std::ostream& out, const Store& storeInfo);