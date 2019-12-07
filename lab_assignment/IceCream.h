// IceCream.h
// Alan Roddick
// 12/6/19

#ifndef ICECREAM_H
#define ICECREAM_H

#include <iostream>
#include <vector>

class IceCream {
private:
    std::vector<std::string> toppings;
    std::string flavor;
    int numToppings;

public:
    IceCream(std::string flavor, std::vector<std::string> toppings);
    IceCream(std::string flavor);
    // Adds a topping to the vector of toppings
    void addTopping(std::string topping);
    void changeFlavor(std::string flavor);
    int getNumToppings();
    std::string getFlavor();
    // Returns a vector of the toppings
    std::vector<std::string> getToppings();
};

#endif