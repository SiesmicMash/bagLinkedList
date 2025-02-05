//
//  Node.hpp
//  bagLinkedList
//
//  Created by Usaid Ali Syed on 2025-02-04.
//

#ifndef NODE_
#define NODE_

template <class ItemType>
class Node {
private:
    ItemType item;
    Node<ItemType>* next;
    
public:
    
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    ItemType getItem() const;
    Node<ItemType>* getNext() const;
};

#endif /* Node_hpp */
