#include <stdio.h>
#include <stdlib.h>

class FizedSizeQueue{
    private:
        int* _mainQueue;
        int _startIndex;
        int _endIndex;
        int _lengthOfQueue = 0;
        int _newSize;

        int* _head;
        int* _tail;

    public:
        FizedSizeQueue(int size, int localArray[]){
            _mainQueue = new int[2 * size];
            _newSize = 2 * size;
            _startIndex = 0;
            // printf("Start Index: %d\n", _startIndex);
            _endIndex = _startIndex + (size - 1);
            for(int i = 0; i < size; i++){
                _mainQueue[_startIndex + i] = localArray[i];
                // printf("\n%d: %d", _startIndex + i, _mainQueue[_startIndex + i]);
                _lengthOfQueue ++;
            }
            // printf("\nPointer: %p\n", _mainQueue);
            int* _head = &(_mainQueue[_startIndex]);
            int* _tail = &(_mainQueue[_endIndex]);

            printf("LengthOfQueue: %d, newSize: %d\n", _lengthOfQueue, _newSize);
        }

        int deQueue(){
            _startIndex++;
            int* _head = &(_mainQueue[_startIndex]);
            return *_head;
            _lengthOfQueue--;
        }

        void enQueue(int element){
            printf("LengthOfQueue: %d, newSize: %d\n", _lengthOfQueue, _newSize);
            if (_lengthOfQueue >= _newSize-2){
                reallocate();
            }
            
            _mainQueue[_endIndex + 1] = element;
            _endIndex++;
            int* _tail = &(_mainQueue[_endIndex]);
            _lengthOfQueue++;
        }

        void reallocate(){
            _newSize *= 2;
            int* _tempQueue = new int[_newSize];
            // int size = 2 * _lengthOfQueue;
            int localStartIndex = 0;
            int localEndIndex = localStartIndex + (_lengthOfQueue - 1);
            printf("\nLength Of Queue: %d\n", _lengthOfQueue);

            for(int i = 0; i < _lengthOfQueue; i++){
                // printf("\n%d: %d", _startIndex + i, _mainQueue[_startIndex + i]);
                _tempQueue[localStartIndex + i] = _mainQueue[i];
            }
            _startIndex = localStartIndex;
            _endIndex = localEndIndex;

            free(_mainQueue);
            _mainQueue = _tempQueue;
            
        }

        int front(){
            return _mainQueue[_startIndex];
        }

        bool isEmpty(){
            printf("Pointer: %p", _mainQueue);
            return _lengthOfQueue <= 1;
        }

        void printQueue(){
            printf("\nLength Of Queue: %d", _lengthOfQueue);
            for(int i = 0; i < _lengthOfQueue; i++){
                printf("\n%d ", _mainQueue[_startIndex + i]);
            }
            printf("\n");
        }


};

class DynamicSizeQueue{

};

int main(){
    int passedArray[] = {1, 2, 3, 4, 5};
    int passedSize = sizeof(passedArray)/sizeof(int);
    FizedSizeQueue newQueue = FizedSizeQueue(passedSize, passedArray);
    // printf("\nIs Empty? %d\n", newQueue.isEmpty());
    // newQueue.deQueue();
    // newQueue.printQueue();
    newQueue.enQueue(6);
    newQueue.enQueue(7);
    newQueue.enQueue(8);
    newQueue.enQueue(9);
    newQueue.enQueue(10);
    newQueue.enQueue(11);
    newQueue.enQueue(12);
    newQueue.enQueue(13);
    printf("\nSize After: %d\n", sizeof(newQueue));
    newQueue.printQueue();
    return  0;
}
