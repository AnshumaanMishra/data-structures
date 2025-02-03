#include <stdio.h>
#include <cmath>

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
        Stack(int size, char* localArray){
            int i = 0;
            char currentCharacter = localArray[i];
            printf("%d \n", size);
            while((i < size) && (currentCharacter != '\0')){
                int tempNumber = 0;
                bool isNumber = false;
                printf("\nI(OuterLoop) = %d, char = %c\n", i, currentCharacter);    
                while((currentCharacter != ' ') && (checkOperand(currentCharacter))){
                    isNumber = 1;
                    printf("\nI(innerLoop) = %d, char = %c\n", i, currentCharacter);     
                    tempNumber *= 10;
                    tempNumber += toInt(currentCharacter);
                    i++;
                    currentCharacter = localArray[i];          
                }
                printf("TempNumber = %d\n", tempNumber);
                if(isNumber){
                    printf("\\ %d \\\n", tempNumber);
                    push(tempNumber);
                }

                else if(currentCharacter == ' '){
                    i++;
                    currentCharacter = localArray[i];
                    continue;
                }
                else{
                    int number2 = pop();
                    int number1 = pop();
                    if(currentCharacter == '+'){
                        printf("\nnumber1 = %d + number2 = %d\n", number1, number2);
                        push(number1 + number2);
                        i++;
                        currentCharacter = localArray[i];
                        continue;
                    }
                    if(currentCharacter == '-'){
                        printf("\nnumber1 = %d - number2 = %d\n", number1, number2);
                        push(number1 - number2);
                        i++;
                        currentCharacter = localArray[i];
                        continue;
                    }
                    if(currentCharacter == '*'){
                        printf("\nnumber1 = %d * number2 = %d\n", number1, number2);
                        push(number1 * number2);
                        i++;
                        currentCharacter = localArray[i];
                        continue;
                    }
                    if(currentCharacter == '/'){
                        printf("\nnumber1 = %d / number2 = %d\n", number1, number2);
                        push(number1 / number2);
                        i++;
                        currentCharacter = localArray[i];
                        continue;
                    }
                    if(currentCharacter == '^'){
                        printf("\nnumber1 = %d ^ number2 = %d\n", pow(number1, number2));
                        push(pow(number1, number2));
                        i++;
                        currentCharacter = localArray[i];
                        continue;
                    }

                }
            }
        }

        int evaluate(){
            return _topElementAddress->_value;
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

        int top(){
            return _topElementAddress->_value;
        }

        bool checkOperand(char element){
            if((element == '1') || (element == '2') || (element == '3') || (element == '4') || (element == '5') || (element == '6') || (element == '7') || (element == '8') || (element == '9') || (element == '0')){
                return true;
            }
            return false;
        }

    

        int toInt(char a){
            switch (a)
            {
            case '1':
                return 1;
                break;
            
            case '2':
                return 2;
                break;
            
            case '3':
                return 3;
                break;
            
            case '4':
                return 4;
                break;
            
            case '5':
                return 5;   
                break;
            
            case '6':
                return 6;
                break;
            
            case '7':
                return 7;
                break;
            
            case '8':
                return 8;
                break;
            
            case '9':
                return 9;
                break;
            
            case '0':
                return 0;
                break;
            
            default:
                return -1;
                break;
            }
        }

        int toInteger(char* element){
            int num = 0;
            for(int i = 0; i < sizeof(element)/sizeof(char); i++){
                num *= 10;
                int casted = toInt(element[i]);
                if(casted > -1){
                    num += casted;
                }
                // printf("%d ", toInt(element[i]));
            }
            return num;
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

    char passedArray[] = "2 2 ^ 2 ^ 4 +";
    int passedSize = sizeof(passedArray)/sizeof(char);    
    Stack operands = Stack(passedSize, passedArray);
    printf("Value = %d\n", operands.evaluate());
    return 0;
}
