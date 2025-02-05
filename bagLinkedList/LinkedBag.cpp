//
//  LinkedBag.cpp
//  bagLinkedList
//
//  Created by Usaid Ali Syed on 2025-02-04.
//

#include "LinkedBag.hpp"

template <class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0){}

template <class ItemType>
LinkedBag<ItemType>:: LinkedBag(const LinkedBag<ItemType>& aBag) : headPtr(nullptr), itemCount(aBag.itemCount) {
    Node<ItemType> *curPtr = aBag.headPtr;
    
    while (curPtr != nullptr) {
        tail_insert(curPtr ->getItem());
        curPtr = curPtr->getNext();
    }
    /*
    if (!aBag.isEmpty()) {
        head_insert(aBag.headPtr->getItem());  //Insert one node into *this object
        Node<ItemType> *tailNodePtr = headPtr; //Point tailNodePtr to the only node of *this object
        Node<ItemType> *curPtr = aBag.headPtr->getNext(); //Use curPtr to loop in the nodes of aBag object
        while (curPtr != nullptr ) {
            tailNodePtr = insert_after(tailNodePtr, curPtr->getItem());
            curPtr = curPtr->getNext();
        }
    }
    */
}

template <class ItemType>
LinkedBag<ItemType>:: ~LinkedBag(){
    this->clear();
}

template <class ItemType>
int LinkedBag<ItemType>:: getCurrentSize() const{
    return itemCount;
}

template <class ItemType>
bool LinkedBag<ItemType>:: isEmpty() const{
    return itemCount == 0;
}

template <class ItemType>
bool LinkedBag<ItemType>:: add(const ItemType &newEntry) {
    head_insert(newEntry);
    itemCount++;
    return true;
}

template <class ItemType>
bool LinkedBag<ItemType>:: remove(const ItemType &anEntry) {
    
    bool success = false;
    if (headPtr == nullptr) {
        return false;
    }
    
    else if (headPtr->getItem() == anEntry) {
        Node<ItemType> *curPtr = headPtr;
        headPtr = headPtr->getNext();
        delete curPtr;
        success = true;
    }
    
    else {
        Node<ItemType> *prevPtr = headPtr;
        Node<ItemType> *curPtr = headPtr->getNext();
        
        while (curPtr != nullptr) {
            
            if (curPtr->getItem() == anEntry) {
                //delete the node pointed to by curPtr
                prevPtr ->setNext(curPtr->getNext());
                delete curPtr;
                success = true;
                break;
            }
            
            else {
                prevPtr = curPtr;
                curPtr = curPtr->getNext();
            }
        }
        
    }
    
    if (success) {
        itemCount --;
        return true;
    }
    
    else {
        return false;
    }
}

template <class ItemType>
void LinkedBag<ItemType>:: clear() {
    while (headPtr != nullptr) {
        Node<ItemType> *curPtr = headPtr;
        headPtr = headPtr->getNext();
        delete curPtr;
    }
    
    itemCount = 0;
}

template <class ItemType>
bool LinkedBag<ItemType>:: contains(const ItemType &anEntry) const{
    return getPointerTo(anEntry) != nullptr;
}

template <class ItemType>
int LinkedBag<ItemType>:: getFrequencyOf(const ItemType &anEntry) const{
    int freq = 0;
    Node<ItemType> *curPtr = headPtr;
    while (curPtr != nullptr) {
        if (curPtr->getItem() == anEntry) {
            freq++;
        }
        
        curPtr = curPtr->getNext();
    }
    return freq;
}
template <class ItemType>
vector<ItemType> LinkedBag<ItemType>:: toVector() const{
    
    vector<ItemType> v;
    Node<ItemType> *curPtr = headPtr;
    while (curPtr != nullptr) {
        v.push_back(curPtr->getItem());
        curPtr = curPtr->getNext();
    }
    
    return v;
}


template <class ItemType>
void LinkedBag<ItemType>::head_insert(const ItemType &newEntry) {
    Node<ItemType> *nodePtr = new Node<ItemType>(newEntry);
    nodePtr ->setNext(headPtr);
    headPtr = nodePtr;
}

template <class ItemType>
void LinkedBag<ItemType>::tail_insert(const ItemType &newEntry) {
    if (headPtr == nullptr) {
        head_insert(newEntry);
    }
    else {
        Node<ItemType> *curPtr = headPtr;
        while (curPtr->getNext() != nullptr) {
            curPtr = curPtr->getNext();
        }
        
        Node<ItemType> *nodePtr = new Node<ItemType>(newEntry);
        nodePtr->setNext(nullptr);
        curPtr->setNext(nodePtr);
    }
}

template <class ItemType>
Node<ItemType>* LinkedBag<ItemType>::insert_after(Node<ItemType> *curPtr, const ItemType &newEntry) {
    if (curPtr == nullptr) {
        return nullptr;
    }
    
    else {
        Node<ItemType> *nodePtr = new Node<ItemType>(newEntry);
        nodePtr->setNext(curPtr -> getNext());
        curPtr->setNext(nodePtr);
        
        return nodePtr;
    }
}

template <class ItemType>
Node<ItemType>* LinkedBag<ItemType>:: getPointerTo(const ItemType &target) const{
    //This is a utility method returns a pointer to a node whose item matches target
    //If such a node is not found, then this method returns nullptr
    /*
    
     Node<ItemType> *curPtr = headPtr;
    while (curPtr != nullptr) {
        if (curPtr ->getItem() == target) {
            break;
        }
        
        curPtr = curPtr ->getNext();
    }
     
    */
    return getPointerTo(headPtr, target);
}

template <class ItemType>
Node<ItemType>* LinkedBag<ItemType>:: getPointerTo(Node<ItemType> *headPtr, const ItemType &target) const{
    if (headPtr == nullptr) {
        return nullptr;
    }
    
    else if (headPtr->getItem() == target){
        return headPtr;
    }
    
    else {
        return getPointerTo(headPtr->getNext(), target);
    }
    
}
