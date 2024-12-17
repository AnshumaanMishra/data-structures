#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    Node* nextNodeAddress;
    Node* prevNodeAddress;
};

class linkedList{
    private:

        // Empty Containers
        Node* containerNext = new Node;
        Node* containerPrev = new Node;

        // Attributes
        int lengthOfList = 0;
        Node* firstNode = containerNext;
        Node* lastNode = containerPrev;

    public:
        linkedList(int sizeOfPassedArray, int* passedArray){
            for(int i = 0; i < sizeOfPassedArray; i++){
                Node* currentNode = addNode(passedArray[i]);
                if(i == 0){
                    setFirstNode(currentNode);
                }

                setLastNode(currentNode);
                // printf(" %d %d", currentNode->value, currentNode->nextNodeAddress);
                
                lengthOfList++;
            }
        }

        Node* addNode(int value){
            Node* currentNode = new Node;
            currentNode->value = value;
            currentNode->nextNodeAddress = containerNext;
            currentNode->prevNodeAddress = lastNode;
            lastNode->nextNodeAddress = currentNode;
            return currentNode;
        }

        void addNode(int value, int index){
            Node* currentNode = new Node;
            currentNode = firstNode;
            for(int i = 1; i < index; i++){
                currentNode = currentNode->nextNodeAddress;
            }
            Node* nextNode = currentNode->nextNodeAddress;
            Node* insertedNode = new Node;
            insertedNode->value = value;
            insertedNode->prevNodeAddress = currentNode;
            insertedNode->nextNodeAddress = nextNode;
            currentNode->nextNodeAddress = insertedNode;
            nextNode->prevNodeAddress = insertedNode;
            lengthOfList++;
        }

        void setFirstNode(Node* firstNodeLocal){
            firstNode = firstNodeLocal;            
        }

        void setLastNode(Node* lastNodeLocal){
            lastNode = lastNodeLocal;            
        }

        void printList(){
            Node* currentNode = firstNode;
            for(int i = 0; i < lengthOfList; i++){
                printf("%d ", currentNode->value);
                currentNode = currentNode->nextNodeAddress;
            }
        }

        
        void printListReverse(){
            Node* currentNode = lastNode;
            for(int i = (lengthOfList-1); i >= 0; i--){
                printf("%d ", currentNode->value);
                currentNode = currentNode->prevNodeAddress;
            }
        }

        int getElementByIndex(int index){
            Node* currentNode = firstNode;
            for(int i = 0; i < index; i++){
                currentNode = currentNode->nextNodeAddress;
                // printf("\nValue = %d\n", currentNode->value);
            }
            return currentNode->value;
        }

        void freeMemory(){
            Node* currentNode = lastNode;
            for(int i = (lengthOfList-1); i >= 0; i--){
                // printf("%d ", currentNode->value);
                Node* tempNode = currentNode->prevNodeAddress; 
                free(currentNode);
                currentNode = tempNode;
                // free(tempNode);
            }
        }
};

int main(){
    printf("\n");
    int passedArray[] = {1, 2, 3, 4, 5};
    int passedSize = sizeof(passedArray)/sizeof(int);
    linkedList list1 = linkedList(passedSize, passedArray);
    list1.addNode(6, 2);
    list1.printList();
    // printf("%d\n", list1.getElementByIndex(3));
    // list1.printListReverse();
    list1.freeMemory();
}