#include <stdio.h>

struct Node{
    int _value;
    Node* _nextNodeAddress;
};


class Stack{
    private:
        int _topElement = -1;
        Node* _topElementAddress = new Node;
        Node* _container = new Node;

    public:
        Stack(int size, int localArray[]){
            for(int i = 0; i < size; i++){
                push(localArray[i]);
                // printf("Top Element = %d", _topElement); 
            }
        }

        void push(int element){
            // Node* lastNode = _topElementAddress;
            Node* newNode = new Node;
            newNode->_value = element;
            newNode->_nextNodeAddress = _topElementAddress;
            _topElement ++;
            _topElementAddress = newNode;
        }

        int pop(){
            if(_topElement == -1){
                return;
            }
            int returnElement = _topElementAddress->_value;
            _topElement --;
            _topElementAddress = _topElementAddress->_nextNodeAddress;
            return returnElement;
        }

        void printStack(){
            Node* currentNode = _topElementAddress;
            for(int i = 0; i < _topElement + 1; i++){
                printf("%d\n", currentNode->_value);
                currentNode = currentNode->_nextNodeAddress;
            }
        }

        bool isEmpty(){
            return (_topElement == -1);
        }

        int top(){
            return _topElementAddress->_value;
        }
};

int main(){

    int passedArray[] = {1, 2, 3, 4, 5};
    int passedSize = sizeof(passedArray)/sizeof(int);    
    Stack newStack = Stack(passedSize, passedArray);
    newStack.printStack();
    newStack.pop();
    // newStack.printStack();
    printf("%d\n", newStack.isEmpty());
    return 0;
}
