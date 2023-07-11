#pragma once

#include "Node.hh"
#include "Exception.hh"
#include "RandomNumber.hh"

template <typename type>
class SPriorityQueue {
    private:

        int minKey;

        int size;

        SNode<type>* head;

    public:

        SPriorityQueue() { head = NULL; size = 0; minKey = 0;}

        ~SPriorityQueue() {};

        SNode<type> *getHead() const { return head; }

        bool isEmpty();

        int getSize() const { return size; }

        void insert(int const key, type const value, const bool isEndline);

        SNode<type> removeMin();

        SNode<type> min();

        SNode<type> removeRandom();
};

// 2 co daje O(1)
template<typename type>
bool SPriorityQueue<type>::isEmpty(){
if (size == 0) { //1
    return true; //1
}
return false; //1
}

// W najgorszym przypadku 4n + 12 co daje O(n)
template<typename type>
void SPriorityQueue<type>::insert (const int key, const type value, const bool isEndline) {
    SNode<type>* newNode = new SNode<type>; //1
    SNode<type>* N = head; //1
    SNode<type>* prevN = N; //1
    newNode->setKey(key); //1
    newNode->setElement(value); //1
    newNode->setNewLane(isEndline); //1

    if (isEmpty()) { minKey = key; } //2 + 1
    if (minKey >= key) { //1
        minKey = key; //1
        newNode->setNext(head); //1
        head = newNode; //1
        size++; //1
        return; //1
    }
    while (N->getKey() <= key && N->getNext() != NULL) { //4n
        prevN = N; //1
        N = N->getNext(); //1
    }

    if (N->getNext() == NULL && key > N->getKey()) { //2
        N->setNext(newNode); //1
    }
    else { 
        prevN->setNext(newNode); //1
        newNode->setNext(N); //1
    }
    size++; //1
}

// 9 co daje O(1)
template<typename type>
SNode<type> SPriorityQueue<type>::removeMin() {
    if (!isEmpty()) { //2
        SNode<type> remElem = *head; //1
        SNode<type> *N = head; //1
        head = head->getNext(); //1
        if (head != NULL) minKey = head->getKey(); //1
        size--; //1
        delete N; //1
        return remElem; //1
    }
    throw(Exception("Queue is empty")); //1
}
// 3 co daje O(1)
template<typename type>
SNode<type> SPriorityQueue<type>::min() {
    if (!isEmpty()) { //2
        return *head; //1
    }
    throw(Exception("Queue is empty")); //1
}

// W najgorszym przypadku 2n + 16 co daje O(n)
template<typename type>
SNode<type> SPriorityQueue<type>::removeRandom() {
    SNode<type>* N = head; //1
    SNode<type>* prevN = N; //1
    SNode<type> value; //1
    if (!isEmpty()) { //2
        for (int i = 1; i < getRandomNumber(1,size); ++i) { //2n + 4
            prevN = N; //1
            N = N->getNext(); //1
        }
        value = *N; //1
        if (N == head) { //1
            head = head->getNext(); //1
            delete N; //1
        }
        else if (N->getNext() == NULL) { //1
            prevN->setNext(NULL); //1
            delete N; //1
        }
        else {
            prevN->setNext(N->getNext()); //1
            delete N; //1
        }
        size--; //1
        return value; //1
    }
    throw(Exception("Queue is empty")); //1
}