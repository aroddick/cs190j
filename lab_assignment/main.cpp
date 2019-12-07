// main.cpp
// Alan Roddick
// 12/6/19

#include <iostream>
#include "NameSpace.h"
#include "IceCream.h"
#include <iomanip>
using namespace std;
using namespace lab10;

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
     cout << "Cost at global shop: $" << fixed << setprecision(2) << ::cost(iceCream) << endl;
     cout << "-----------------------------------" << endl;
 }

 void comparePrice(IceCream ic) {
    double globalCost = ::cost(ic);
    double gauchoCost = lab10::cost(ic);
    if (globalCost > gauchoCost) {
        cout << "Chris Gaucho sells the ice cream for $" << fixed << setprecision(2) 
        << globalCost - gauchoCost << " cheaper" << endl;
    } else if (globalCost == gauchoCost) {
        cout << "Global and Chris Gaucho sell this ice cream for the same price" << endl;
    } 
    else {
        cout << "Global sells the ice cream for $" << fixed << setprecision(2) 
        << gauchoCost - globalCost << " cheaper" << endl;
    }
}

int main() {
    IceCream ic1("chocolate");
    ::print(ic1);
    lab10::print(ic1);
    comparePrice(ic1);
    ic1.addTopping("sprinkles");
    ::print(ic1);
    lab10::print(ic1);
    comparePrice(ic1);
    vector<string> toppings;
    toppings.push_back("sprinkles");
    toppings.push_back("fudge");
    toppings.push_back("chocolate shell");
    toppings.push_back("m&m's");
    toppings.push_back("gummy worms");
    toppings.push_back("marshmallows");
    IceCream ic2("vanilla", toppings);
    ::print(ic2);
    lab10::print(ic2);
    comparePrice(ic2);

}

