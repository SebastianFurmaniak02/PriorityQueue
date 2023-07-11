#include "MessageOperations.hh"

// W najgorszym przypadku f(n) = 10n^2 + 21n + 9, co daje O(n^2)
void sendMessage(std::string filename, int partLength) {
    std::ifstream stream(filename, std::ios::binary); //1

    if (stream.is_open() == false) throw Exception("Wrong Filename"); //2

    std::string mess = ""; //1
    SPriorityQueue<std::string> *Q = new SPriorityQueue<std::string>; //1
    SNode<std::string> *n; //1
    int packageNumber = 0; //1
    while (getline(stream,mess)) { // n(8n + 1)
        for (uint i = 0; i < mess.length(); i += partLength) { //8n
            if (mess[i+partLength] == '\\' && mess[i+partLength+1] == 'n') {Q->insert(packageNumber, mess.substr(i,partLength+1), false); ++i;} //2
            else Q->insert(packageNumber, mess.substr(i,partLength), false); //1
            ++packageNumber; //1
            if (Q->getHead()->getNext() == NULL) n = Q->getHead(); //2
            if (n->getNext() != NULL) n = n->getNext(); //2
        }
        n->setNewLane(true); //1
    }

    int size = Q->getSize(); //1
    SNode<std::string> oldNode; //1
    std::ofstream file("../datasets/Channel.txt"); //1
    for (int i = 0; i < size; ++i) { // n(2n+20)
        oldNode = Q->removeRandom(); //2n + 16
        file << oldNode.getKey() << " " << oldNode.isNewLane() << " " << oldNode.getElement() << std::endl; //4
    }
}

// W najgorszym przypadku f(n) = 4n^2 + 30n + 9, co daje O(n^2)
void reciveMessage(std::string filename) {
    std::ofstream stream(filename, std::ios::binary); //1

    if (stream.is_open() == false) throw Exception("Wrong Filename"); //2

    std::ifstream file("../datasets/Channel.txt");  //1
    SPriorityQueue<std::string>* queue = new SPriorityQueue<std::string>; //1
    std::string newMessage; //1
    int newKey; //1
    bool isLine; //1
    while (file >> newKey) { // n(4n + 18)
        file.ignore(); //1
        file >> isLine; //1
        file.ignore();  //1
        std::getline(file,newMessage); //1
        queue->insert(newKey,newMessage,isLine); //4n +12
    }
    
    SNode<std::string> oldNode; //1
    int size = queue->getSize(); //1
    for(int i = 0; i < size; ++i) { //12n
        oldNode = queue->removeMin(); //9
        stream << oldNode.getElement(); //1
        if (oldNode.isNewLane() == true) stream << "\n"; //2
    }
}