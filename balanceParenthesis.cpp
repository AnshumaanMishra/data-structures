#include <stdio.h>

struct Node{
    char _value;
    int _index;
    Node* _nextNodeAddress;
};


class Stack{
    private:
        int _topElement = -1;
        Node* _topElementAddress = new Node;
        Node* _container = new Node;

    public:
        Stack(int size, char* localArray){
            for(int i = 0; i < size; i++){
                // printf("Element = %c\n", localArray[i]);
                if(checkOpening(localArray[i])){
                    push(i, localArray[i]);
                    // printf("Push Successful %d\n", i);
                }
                else if(checkClosing(localArray[i])){
                    if(checkSimilar(localArray[i])){
                        pop();
                    }
                    else{
                        if (checkClosing(localArray[i]) && !checkSimilar(localArray[i])){
                            printf("Error: No match for \'%c\' at index %d\n", localArray[i], i);
                            return;
                        }
                        
                        printf("Error: Unmatched \'%c\' starting at index %d\n", _topElementAddress->_value, _topElementAddress->_index);
                        return;
                    }

                }
                // printf("Top Element = %d", _topElement); 
            }
            if(!isEmpty()){
                printf("Error, Unmatched \'%c\' starting at index %d\n", _topElementAddress->_value, _topElementAddress->_index);
                return;
            }
            printf("Test Successful, No errors found\n");
        }

        void push(int index, int element){
            // Node* lastNode = _topElementAddress;
            Node* newNode = new Node;
            newNode->_value = element;
            newNode->_nextNodeAddress = _topElementAddress;
            newNode->_index = index;
            _topElement ++;
            _topElementAddress = newNode;
        }

        char pop(){
            if(_topElement == -1){
                return '.';
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

        char top(){
            return _topElementAddress->_value;
        }

        bool checkClosing(int element){
            if((element == ')') || (element == '}') || (element == ']')){
                return true;
            }
            return false;
        }

        bool checkOpening(int element){
            if((element == '(') || (element == '{') || (element == '[')){
                return true;
            }
            return false;
        }

        bool checkSimilar(int element){
            if((element == ')') && (_topElementAddress->_value == '(')){
                return true;
            }

            if((element == '}') && (_topElementAddress->_value == '{')){
                return true;
            }

            if((element == ']') && (_topElementAddress->_value == '[')){
                return true;
            }
            return false;
        }
};

int main(){

    char passedArray[] = "{(Hello World)})]";
    int passedSize = sizeof(passedArray)/sizeof(char);    
    Stack newStack = Stack(passedSize, passedArray);
    // newStack.printStack();
    // newStack.pop();
    // newStack.printStack();
    // printf("%d\n", newStack.isEmpty());
    return 0;
}
