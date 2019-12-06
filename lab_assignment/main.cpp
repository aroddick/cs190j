// main.cpp
#include <iostream>
#include "NameSpace.h"
#include "IceCream.h"
#include <iomanip>
using namespace std;

double cost(IceCream iceCream) {
     double cost = 2.0;
     if (iceCream.getNumToppings() != 0) {
         cost += 0.5;
     }
     return cost;
 }

 void print(IceCream iceCream) {
     cout << "-----------Global Shop------------" << endl;
     cout << "Ice Cream flavor: " << iceCream.getFlavor() << endl;
     cout << "Toppings:\n";
     for (string topping : iceCream.getToppings()) {
         cout << "\t" << topping << endl;
     }
     cout << "Cost at global shop: $" << fixed << setprecision(2) << cost(iceCream) << endl;
     cout << "-----------------------------------" << endl;
 }

int main() {
    IceCream ic1("chocolate");
    ::print(ic1);
    alan_roddick::print(ic1);
    ic1.addTopping("sprinkles");
    print(ic1);
    alan_roddick::print(ic1);
    vector<string> toppings;
    toppings.push_back("sprinkles");
    toppings.push_back("fudge");
    toppings.push_back("chocolate shell");
    toppings.push_back("m&m's");
    toppings.push_back("gummy worms");
    toppings.push_back("marshmallows");
    IceCream ic2("vanilla", toppings);
    print(ic2);
    alan_roddick::print(ic2);

}