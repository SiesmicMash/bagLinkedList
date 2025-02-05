//
//  LinkedBagTest.cpp
//  bagLinkedList
//
//  Created by Usaid Ali Syed on 2025-02-04.
//
#include <iostream>
#include <string>
#include "LinkedBag.hpp"
#include "Node.cpp" //This include is GOOD!!!
#include "LinkedBag.cpp" //This include is GOOD!!!

void displayBag(const BagInterface<string> &bagRef)
{
    cout << "The bag contains " << bagRef.getCurrentSize() << " items:" << endl;
    vector<string> bagItems = bagRef.toVector();
    int numberOfEntries = (int) bagItems.size();
    for (int i = 0; i < numberOfEntries; i++)
        cout << bagItems[i] << " ";
    cout << endl << endl;
}

void bagTester(BagInterface<string> *bagPtr)
{
    cout << "isEmpty: returns " << bagPtr->isEmpty() << "; should be 1 (true)" << endl;
    displayBag(*bagPtr);

    string items[] = {"one", "two", "three", "four", "five", "one"};
    cout << "Add 6 items to the bag: " << endl;
    for (int i = 0; i < 6; i++)
        bagPtr->add(items[i]);

    displayBag(*bagPtr);

    cout << "isEmpty: returns " << bagPtr->isEmpty() << "; should be 0 (false)" << endl;
    cout << "getCurrentSize: returns " << bagPtr->getCurrentSize() << "; should be 6" << endl;
    cout << "Try to add another entry: add(\"extra\") returns " << bagPtr->add("extra") << endl;
    cout << "contains(\"three\"): returns " << bagPtr->contains("three") << "; should be 1 (true)" << endl;
    cout << "contains(\"ten\"): returns " << bagPtr->contains("ten") << "; should be 0 (false)" << endl;
    cout << "getFrequencyOf(\"one\"): returns " << bagPtr->getFrequencyOf("one") << " should be 2" << endl;
    cout << "remove(\"one\"): returns " << bagPtr->remove("one") << "; should be 1 (true)" << endl;
    cout << "getFrequencyOf(\"one\"): returns " << bagPtr->getFrequencyOf("one") << " should be 1" << endl;
    cout << "remove(\"one\"): returns " << bagPtr->remove("one") << "; should be 1 (true)" << endl;
    cout << "remove(\"one\"): returns " << bagPtr->remove("one") << "; should be 0 (false)" << endl;
    cout << endl;

    displayBag(*bagPtr);

    cout << "After clearing the bag, ";
    bagPtr->clear();

    cout << "isEmpty: returns " << bagPtr->isEmpty() << "; should be 1 (true)" << endl;
}

int main()
{
    BagInterface<string> *bagPtr;
    bagPtr = new LinkedBag<string>();
    cout << "Testing the Link-Based Bag:" << endl;
    cout << "The initial bag is empty." << endl;
    bagTester(bagPtr);
    delete bagPtr;
    cout << "All done!" << endl;

    system("Pause");
    return 0;
}
