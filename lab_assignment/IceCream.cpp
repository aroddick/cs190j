// IceCream.cpp

#include <iostream>
#include <vector>
#include "IceCream.h"
using namespace std;

IceCream::IceCream(string flavor, vector<string> toppings) {
    numToppings = 0;
    this->flavor = flavor;
    for (int i = 0; i < toppings.size(); i++) {
        this->addTopping(toppings.at(i));
    }
}

IceCream::IceCream(string flavor) {
    numToppings = 0;
    this->flavor = flavor;
}

void IceCream::addTopping(string topping) {
    this->toppings.push_back(topping);
    numToppings++;
}

void IceCream::changeFlavor(string flavor) {
    this->flavor = flavor;
}

string IceCream::getFlavor() {
    return flavor;
}

vector<string> IceCream::getToppings() {
    return toppings;
}

int IceCream::getNumToppings() {
    return numToppings;
}