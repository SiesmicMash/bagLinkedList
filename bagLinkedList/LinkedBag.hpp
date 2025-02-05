//
//  LinkedBag.hpp
//  bagLinkedList
//
//  Created by Usaid Ali Syed on 2025-02-04.
//

#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "BagInterface.hpp"
#include "Node.hpp"

template <class ItemType>
class LinkedBag : public BagInterface<ItemType> {
private:
    Node<ItemType>* headPtr; //Pointer to first node
    int itemCount;
    
public:
    LinkedBag();
    LinkedBag(const LinkedBag<ItemType>& aBag); //copy constructor
    virtual ~LinkedBag(); //Destructor should be virtual
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    bool contains(const ItemType& anEntry) const;
    int getFrequencyOf(const ItemType& anEntry) const;
    vector<ItemType> toVector() const;

private:
    void head_insert(const ItemType& newEntry); //head insert
    void tail_insert(const ItemType& newEntry);
    
    //this method inserts a new node after a given node
    //it returns a pointer to the newly inserted node
    //if insertion fails, it returns a nullptr
    Node<ItemType>* insert_after(Node<ItemType> *curPtr, const ItemType& newEntry); //find node
    
    Node<ItemType>* getPointerTo(const ItemType& target) const;
    Node<ItemType>* getPointerTo(Node<ItemType> *headPtr, const ItemType& target) const; //recursive
};


#endif /* LinkedBag_hpp */
