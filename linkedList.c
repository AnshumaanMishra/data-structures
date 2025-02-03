#include <stdio.h>

struct Node{
    int value;
    struct Node* address;       
};


class Node{
    private:
        int value;
        Node* Address;
    public:

        Node(){
            value = 0;
        }
        Node(int localValue, Node* nextAddress){
            value = localValue;
            Address = nextAddress;
            // *(tempMemoryLocation + 1) = localNextAddress;
        }

        Node(int localValue){
            value = localValue;
        }

        void setNextAddress(Node* nextAddress){
            Address = nextAddress;
        }

        Node* nextNode(){
            return Address;
        }

        int getValue(){
            printf("Value = %d", value);
            return value;
        }
};

class linkedList{
    private:
        int sizeOfElement = sizeof(int);
        Node container;
        Node* firstNode;
        Node* lastNode;
        int len = 0;
        int iter;
    public:
        linkedList(int localSize, int* localArray){
            if (localSize > 1){
                Node* firstNode = (Node*)malloc(sizeof(Node));
                *firstNode = Node(localArray[0]);
                int i;
                Node* tempNodeStorage;
                Node* prevNode = firstNode;
                len++;
                
                for(int i = 1; i < localSize - 1; i++){
                    Node* tempNode = (Node*)malloc(sizeof(Node));
                    prevNode->setNextAddress(tempNode);
                    *tempNode = Node(localArray[i]);
                    // printf("a = %d", (*tempNode).getValue());
                    prevNode = tempNode;
                    len++;
                    iter = i;
                    printf("\nFirst Node Value = %d\n", (*firstNode).getValue());
                }
                iter++;
                // printf("iter = %d", iter);
                Node* lastNode = (Node*)malloc(sizeof(Node));
                *lastNode = Node(localArray[iter], &container);
                printf("\nLastNodeValue = %d\n", (*lastNode).getValue());
                // lastNode->setNextAddress(&container);
                printf("\nFirst Node Value = %d\n", (*firstNode).getValue());
                
                len++;
            }
            else if(localSize==1){
                Node* firstNode = (Node*)malloc(sizeof(Node));
                *firstNode = Node(localArray[0]);
                // lastNode = firstNode;
            }
            printf("\nFirst Node Value = %d\n", (*firstNode).getValue());
            printf("Local Begins");
        }

        void printList(){
            printf("\nFirst Node Value = %d\n", (*firstNode).getValue());
            printf("\nStart Printing \n");
            Node* currentNode = firstNode;
            for(int i2 = 0; i2 < len; i2++){
                printf("\n%d \n", (*currentNode).getValue());
                printf("\nPrinted \n");
                Node* temp = (*currentNode).nextNode();
                currentNode = temp;
            }
            printf("\nEnd Printing \n");
        }
};


int main(){
    // printf("Line 1\n");
    int passedSize = 3;
    // printf("Line 2\n");
    int passedArray[] = {1, 2, 3};
    // printf("Line 3\n");
    linkedList list1(passedSize, passedArray);
    printf("\nInitiate Printing \n");
    list1.printList();
    return 0;
}
 
