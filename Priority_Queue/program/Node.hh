#pragma once

#include <cstdio>

template <typename type>
class SNode {
    private:

        bool newLine;

        int key;

        type elem;

        SNode<type>* next;
    
    public:

        SNode() { next = NULL; key = 0; newLine = false; }

        ~SNode() { }

        type getElement() const { return elem; }

        SNode *getNext() const { return next; }

        int getKey() const { return key; }

        bool isNewLane() const {return newLine; }

        void setElement(const type newElem) { elem = newElem; }

        void setNext(SNode<type>* newNext) { next = newNext; }

        void setKey(const int newKey) { key = newKey; } 

        void setNewLane(bool isEndline) { newLine = isEndline; }
};