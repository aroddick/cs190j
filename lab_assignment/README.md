NameSpace lab assignment:

Starter Code provided: IceCream.h, NameSpace.h
Files needed to be created: IceCream.cpp, NameSpace.cpp, main.cpp

The Students will be required to create an IceCream.cpp file for the purposes of this lab. The functions to be implemented are outlined in the .h file.

Students will be given a .h file with a namespace declared along with some methods. The students will define those functions in a .cpp file. Then, the students will create global methods in main.cpp with the same name.

The functions in the students' namespace and global namespace will take in an IceCream item and calculate the cost. the students' namespace function will calculate the cost by adding 10 cents to the base cost for each topping. the global namespace function will calculate the cost by adding 50 cents to the base cost if there is at least 1 topping. I referred to the global namespace function as the "global shop", and the students' namespace function as Chris Gaucho's shop. This simulates a situation in which two different shops will calculate the price of the ice cream differently. I know there may be better and more efficient ways to approach this lab, but I wanted to use namespaces because many students struggle with understanding what a namespace is and how to use it when there are functions with the same name in different namespaces.

The student will then create a function in main.cpp called "comparePrice(IceCream ic)" in which it takes in an IceCream object and determines which shop sells the IceCream for a cheaper price.