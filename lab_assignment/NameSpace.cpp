// NameSpace.cpp
#include <iostream>
#include "NameSpace.h"
#include "IceCream.h"
#include <iomanip>
using namespace std;

 double alan_roddick::cost(IceCream iceCream) {
     double cost = 2.0;
     for (int i = 0; i < iceCream.getNumToppings(); i++) {
         cost += 0.1;
     }
     return cost;
 }

 void alan_roddick::print(IceCream iceCream) {
     cout << "-----------Alan's Shop------------" << endl;
     cout << "Ice Cream flavor: " << iceCream.getFlavor() << endl;
     cout << "Toppings:\n";
     for (string topping : iceCream.getToppings()) {
         cout << "\t" << topping << endl;
     }
     cout << "Cost at Alan's shop: $" << fixed << setprecision(2) << cost(iceCream) << endl;
     cout << "-----------------------------------" << endl;
 }