#include <cstring>
#include <stdio.h>
#include <cmath>
#include <string>
#include <iostream>
// #include <string.h>
using namespace std;

/*
struct Node{
    int _value;
    Node* _nextNodeAddress;
};
*/
struct Node{
    char _value;
    Node* _nextNodeAddress;
};

/*
class Stack{
    private:
        int _topElement = -1;
        Node* _topElementAddress = new Node;
        Node* _container = new Node;

    public:
        Stack(int size, int* localArray){
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
            if(!(_topElement == -1)){
                int returnElement = _topElementAddress->_value;
                _topElement --;
                _topElementAddress = _topElementAddress->_nextNodeAddress;
                return returnElement;
            }
            return 0;
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
*/

class Stack{
    private:
        int _topElement = -1;
        Node* _topElementAddress = new Node;
        Node* _container = new Node;

    public:
        Stack(int size, char* localArray){
            for(int i = 0; i < size; i++){
                push(localArray[i]);
                // printf("Top Element = %d", _topElement);
            }
        }

        void push(char element){
            // Node* lastNode = _topElementAddress;
            Node* newNode = new Node;
            newNode->_value = element;
            newNode->_nextNodeAddress = _topElementAddress;
            _topElement ++;
            _topElementAddress = newNode;
        }

        char pop(){
            if(!(_topElement == -1)){
                int returnElement = _topElementAddress->_value;
                _topElement --;
                _topElementAddress = _topElementAddress->_nextNodeAddress;
                return returnElement;
            }
            return 0;
        }

        void printStack(){
            Node* currentNode = _topElementAddress;
            for(int i = 0; i < _topElement + 1; i++){
                printf("%c\n", currentNode->_value);
                currentNode = currentNode->_nextNodeAddress;
            }
        }

        bool isEmpty(){
            return (_topElement == -1);
        }

        char top(){
            return _topElementAddress->_value;
        }
};

class postFix{
    private:
        Stack* _operatorStack = new Stack(0, "");
        // Stack* _numberStack = new Stack(0, {});
        string _postFix = "";
        bool _insertOperatorNext = false;

    public:
        postFix(string expression){
            int size = expression.size();
            char currentCharacter;
            
            for(int i = 0; i < size; i++){
                currentCharacter = (char)expression[i];
                cout << "Current Character " << currentCharacter << endl;
                // Checking for numbers and pushing
                int currentNumber = 0;
                bool numberModified = false;

                while((currentCharacter != ' ') && (checkOperand(currentCharacter))){
                    currentNumber *= 10;
                    currentNumber += toInt(currentCharacter);
                    i++;
                    currentCharacter = expression[i];
                    numberModified = true;
                }
                
                if(numberModified){
                    // _numberStack->push(currentNumber);
                    _postFix.append(" " + to_string(currentNumber));
                    // _insertOperatorNext = false;
                    // _postFix += (char*)currentNumber;
                    cout << "_postFix: " << _postFix << endl;
                    continue;
                }

                if(currentCharacter == ' '){
                    i++;
                    currentCharacter = expression[i];
                    continue;
                }

                if(_operatorStack->isEmpty()){
                    _operatorStack->push((currentCharacter));
                }

                else if(getOperatorPriority(currentCharacter) > getOperatorPriority(_operatorStack->top())){
                    // _insertOperatorNext = true;
                    _operatorStack->push((currentCharacter));
                }
                
                else if(getOperatorPriority(currentCharacter) < getOperatorPriority(_operatorStack->top())){
                    // _insertOperatorNext = true;
                    cout << "Found: " << _operatorStack->top() << endl;
                    pushOperator(_operatorStack->pop());
                    cout << _postFix << endl;
                }


                i++;
                currentCharacter = expression[i];
            }
        }

        void pushOperator(char operatorA){
            _postFix.append(" " + convertOperator(operatorA));
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

        int getOperatorPriority(char operatorCharacter){
            if(operatorCharacter == '+'){
                return 2;
            }
            else if(operatorCharacter == '-'){
                return 1;
            }
            else if(operatorCharacter == '*'){
                return 3;
            }
            else if(operatorCharacter == '/'){
                return 4;
            }
            else if(operatorCharacter == '^'){
                return 5;
            }
            return 6;
        }
        
        string convertOperator(char operatorCharacter){
            if(operatorCharacter == '+'){
                return "+";
            }
            else if(operatorCharacter == '-'){
                return "-";
            }
            else if(operatorCharacter == '*'){
                return "*";
            }
            else if(operatorCharacter == '/'){
                return "/";
            }
            else if(operatorCharacter == '^'){
                return "^";
            }
            return "Error";
        }
};

int main(){
    string expression = "33 + 4 * 53 - 2 * 3"; // Postfix = 3 4 5 * 2 3 * + -
    // int size = strlen(expression);
    postFix newFiz = postFix(expression);
    // Stack operators = Stack(size, expression);
}
