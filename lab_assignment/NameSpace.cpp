// NameSpace.cpp
// Alan Roddick
// 12/6/19

#include <iostream>
#include "NameSpace.h"
#include "IceCream.h"
#include <iomanip>
using namespace std;

 double lab10::cost(IceCream iceCream) {
     double cost = 2.0;
     for (int i = 0; i < iceCream.getNumToppings(); i++) {
         cost += 0.1;
     }
     return cost;
 }

 void lab10::print(IceCream iceCream) {
     cout << "-----------Chris Gaucho's Shop------------" << endl;
     cout << "Ice Cream flavor: " << iceCream.getFlavor() << endl;
     cout << "Toppings:\n";
     for (string topping : iceCream.getToppings()) {
         cout << "\t" << topping << endl;
     }
     cout << "Cost at Chris Gaucho's shop: $" << fixed << setprecision(2) << cost(iceCream) << endl;
     cout << "-----------------------------------" << endl;
 }