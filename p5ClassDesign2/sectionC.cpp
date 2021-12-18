
#include "sectionC.h"
#include <vector>
#include <string>
#include <iostream>

Item::Item(std::string name, long id, double price, int numInStock)
    : _name{ name }, _id{ id }, _price{ price }, _numInStock{ numInStock } {}

Store::Store(std::vector<Item> storeInventory)
    : _storeInventory{ storeInventory } {}

Order::Order(std::vector<Item> orderList)
    : _orderList{ orderList }, _totalOrderPrice{ 0 } {}


std::ostream& operator<< (std::ostream& out, const Item& itemInfo) {
    out << "Here is the Item Information.... \n Item Name: " << itemInfo._name << "\n ID: " << itemInfo._id << "\n Price: "
        << itemInfo._price << "\n Number In Stock: " << itemInfo._numInStock << "\n";
    return out;
}


std::vector<Item> Order::getOrderList() const{
    return _orderList;
}

void Order::addOrder(Item itemName, int numOfItemsBought) {
    if (_orderList.size() < 11) {
        _orderList.push_back(itemName);
        _numOfItemsBought.push_back(numOfItemsBought);
    }

    else {
        std::cout << "Order list is a maximum of 10 items, cannot add more items \n";
    }
}

std::vector<int> Order::getNumOfItemsBought() const {
    return _numOfItemsBought;
}

double Order::getTotalOrderPrice() const{
    double total = 0;
    for (int i = 0; i < _orderList.size(); i++) {
        total += _orderList.at(i)._price;
    }
    std::cout << "(Test) The total price of your order is: " << total << "\n";
    return total;
}




std::vector<Item> Store::getStoreInventory() const {
    return _storeInventory;
}
std::vector<std::string> Store::getName() const {
    return _name;
}

std::vector<int> Store::getNumInStock() const {
    return _numInStock;
}

void Store::addItem(std::string itemName, int numInStock) {
    if (_storeInventory.size() < 101) {
        _name.push_back(itemName);
        _numInStock.push_back(numInStock);
    }
    else {
        std::cout << "Store Inventory is Full, cannot add more items \n";
    }
}

void Store::processOrder(const Order& orderItem) {
    std::vector<int> numOfItemsBought = orderItem.getNumOfItemsBought();
    std::vector<Item> listOfOrders = orderItem.getOrderList();
    std::vector<std::string> origItemNames = getName();
    std::vector<int> originalInventory = getNumInStock();
    for (int i = 0; i < listOfOrders.size(); i++) {
        std::string orderItem = listOfOrders.at(i)._name;
        for (int goThroughNamesInStock = 0; goThroughNamesInStock < origItemNames.size(); goThroughNamesInStock++) {
            if (orderItem == origItemNames.at(goThroughNamesInStock)) {
                originalInventory.at(goThroughNamesInStock) = originalInventory.at(goThroughNamesInStock) - numOfItemsBought.at(i);
            }
        }
    }

}

std::ostream& operator<< (std::ostream& out, const Store& storeInfo) {
    std::vector<std::string> origItemNames = storeInfo.getName();
    std::vector<int> originalInventory = storeInfo.getNumInStock();
    std::vector<Item> storeInventory = storeInfo.getStoreInventory();
    std::cout << "Store: \n";
    int count = 0;
    for (int i = 0; i < storeInventory.size(); i++) {
        count++;
    }

    for (int j = 0; j < count; j++) {
        out  << origItemNames.at(j) << " x " << originalInventory.at(j) << "\n";
    }
    return out;
}