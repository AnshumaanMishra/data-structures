#include <stdio.h>
#include <stdlib.h>

class Stack{
    private:
        int _topElement = -1;
        int _mainStack[];

    public:
    
        Stack(int size, int* localArray){
            int* _mainStack =new int[size * sizeof(int)];
            for(int i = 0; i < size; i++){
                push(*(localArray + i));
            }
        }

        int* getMainStack(){
            return _mainStack;
        }

        void printStack(){
            // printf("%d ", *(getMainStack()));
            for(int i = 0; i < _topElement+1; i++){
                printf("%d\n", _mainStack[i]);
            }
        }

        void push(int element){
            *(_mainStack + _topElement + 1) = element;
            _topElement ++;
        }

        void pop(){
            _topElement --;
        }

        bool empty(){
            if(_topElement == -1){
                return true;
            }
            return false;
        }

        void reForm(){
            int* mainList2 = new int[2 * sizeof(int) * (_topElement + 1)];
            for(int i = 0; i < (_topElement + 1); i++){
                mainList2[i] = _mainStack[i];
            }
            *_mainStack = *mainList2;
        }

        int top(){
            if(_topElement == -1){
                return 0;
            }
            return _mainStack[_topElement];
        }

        void freeMem(){
            free(_mainStack);
        }
};

int main(){
    int passedArray[] = {1, 2, 3, 4, 5};
    int passedSize = sizeof(passedArray)/sizeof(int);
    
    Stack newStack = Stack(passedSize, passedArray);
    printf("Empty = %b\n", newStack.empty());
    newStack.printStack();
    newStack.pop();
    newStack.push(5);
    newStack.push(6);
    newStack.push(8);
    newStack.push(9);
    newStack.push(10);
    newStack.push(11);
    newStack.push(12);
    newStack.push(13);
    newStack.push(14);
    newStack.push(15);
    newStack.push(16);
    printf("OldSize = %d ", sizeof(newStack));
    newStack.reForm();

    printf("NewSize = %d ", sizeof(newStack));
    newStack.printStack();
    // newStack.freeMem();
}