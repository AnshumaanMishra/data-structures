#include <stdio.h>
#include <stdlib.h>

struct QueueNode{
    int _value;
    QueueNode* _nextQueueNodeAddress;
};


class Queue{
    private:
        int* _head;
        int* _tail;
        QueueNode* _firstQueueNode;
        QueueNode* _lastQueueNode;
        QueueNode* _container = new QueueNode;
        int _lengthOfQueue = 0;
        QueueNode* currentQueueNode = new QueueNode;
        QueueNode* prevQueueNode = new QueueNode;

    public:
        Queue(int length, int* localArray){
            for(int i = 0; i < length; i++){
                // currentQueueNode = new QueueNode;
                if(length>0){
                    currentQueueNode = EnQueue(localArray[i]);
                }
                if(i==0){
                    _firstQueueNode = currentQueueNode;
                }
                _lastQueueNode = currentQueueNode;
            }
        }

        QueueNode* EnQueue(int element){
            // QueueNode* currentQueueNode = _lastQueueNode;
            QueueNode* insertedQueueNode = new QueueNode;

            insertedQueueNode->_value = element;
            insertedQueueNode->_nextQueueNodeAddress = NULL;
            if(_lengthOfQueue >= 1){
                _lastQueueNode->_nextQueueNodeAddress = insertedQueueNode;
            }

            if(_lengthOfQueue < 1){
                _firstQueueNode = insertedQueueNode;
            }
            _lastQueueNode = insertedQueueNode;
            _lengthOfQueue ++;
            return insertedQueueNode;
        }

        int DeQueue(){
            QueueNode* tempQueueNode = _firstQueueNode;
            _firstQueueNode = tempQueueNode->_nextQueueNodeAddress;
            _lengthOfQueue -- ;
            return tempQueueNode->_value;
        }

        void printArray(){
            QueueNode* currentQueueNode = _firstQueueNode;
            for(int i = 0; i < _lengthOfQueue; i++){
                printf("%d\n", currentQueueNode->_value);
                currentQueueNode = currentQueueNode->_nextQueueNodeAddress;
            }
        }

        int front(){
            return _firstQueueNode->_value;
        }

        bool isEmpty(){
            return _lengthOfQueue <= 0;
        }


};

int main(){
    // printf("\n");
    int passedArray[] = {};
    int passedSize = sizeof(passedArray)/sizeof(int);

    Queue newQueue = Queue(passedSize, passedArray);
    newQueue.printArray();
    newQueue.EnQueue(10);
    newQueue.printArray();

    return 0;
}
