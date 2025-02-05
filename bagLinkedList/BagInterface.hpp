//
//  BagInterface.hpp
//  bagLinkedList
//
//  Created by Usaid Ali Syed on 2025-02-04.
//
#ifndef BAG_INTERFACE_
#define BAG_INTERFACE_

#include <vector>
using namespace std;

template <class ItemType>
class BagInterface {

public:
    virtual int getCurrentSize() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool add(const ItemType& newEntry) = 0;
    virtual bool remove(const ItemType& anEntry) = 0;
    virtual void clear() = 0;
    virtual int getFrequencyOf(const ItemType& anEntry) const= 0;
    virtual bool contains(const ItemType& anEntry) const = 0;
    virtual vector<ItemType> toVector() const = 0;
    virtual ~BagInterface () { }; //Empty destructor
    
};

#endif /* BagInterface_hpp */
