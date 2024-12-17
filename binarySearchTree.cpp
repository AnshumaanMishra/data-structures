#include <stdio.h>
#include <stdlib.h>


struct TreeNode{
    int _value;
    TreeNode* _leftChild;
    TreeNode* _rightChild;
    TreeNode* _parentTreeNode;
};

struct QueueNode{
    TreeNode* _value;
    QueueNode* _nextQueueNodeAddress;
};

class Queue{
    private:
        TreeNode** _head;
        TreeNode** _tail;
        QueueNode* _firstQueueNode;
        QueueNode* _lastQueueNode;
        QueueNode* _container = new QueueNode;
        int _lengthOfQueue = 0;
        QueueNode* currentQueueNode = new QueueNode;
        QueueNode* prevQueueNode = new QueueNode;

    public:
        Queue(){

        }
        Queue(TreeNode* localNode){
            EnQueue(localNode);
        }
        Queue(int length, TreeNode** localArray){
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
        int getLength(){
            return _lengthOfQueue;
        }

        QueueNode* EnQueue(TreeNode* element){
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

        TreeNode* DeQueue(){
            QueueNode* tempQueueNode = _firstQueueNode;
            _firstQueueNode = tempQueueNode->_nextQueueNodeAddress;
            _lengthOfQueue -- ;
            return tempQueueNode->_value;
        }

        void printQueue(){
            QueueNode* currentQueueNode = _firstQueueNode;
            for(int i = 0; i < _lengthOfQueue; i++){
                printf("%d\n", currentQueueNode->_value->_value);
                currentQueueNode = currentQueueNode->_nextQueueNodeAddress;
            }
        }

        TreeNode* front(){
            return _firstQueueNode->_value;
        }

        bool isEmpty(){
            return _lengthOfQueue <= 0;
        }


};


class BinarySearchTree{
    private:
        TreeNode* _rootTreeNode = NULL;
        int _rootHeight;
        Queue _traversalQueue;
        Queue _deleteQueue;
        TreeNode* _nearestLeftParent = NULL;
        // int 

    public:
        BinarySearchTree(){

        }

        BinarySearchTree(int size, int* localArray){
            for(int i = 0; i < size; i++){
                insert(localArray[i]);
            }
        }

        void insert(int element){
            if(_rootTreeNode == NULL){
                TreeNode* tempTreeNode = new TreeNode;
                tempTreeNode->_value = element;
                tempTreeNode->_leftChild = NULL;
                tempTreeNode->_rightChild = NULL;
                _rootTreeNode = tempTreeNode;
                // TreeNode** array = {_rootTreeNode};
                _traversalQueue = Queue(_rootTreeNode);
                return;
            }
            TreeNode* currentTreeNode = _rootTreeNode;
            checkPosition(element, currentTreeNode);            
        }

        TreeNode* deleteByValue(int element, TreeNode* currentTreeNode){
            if(leftChildExists(currentTreeNode) && currentTreeNode->_leftChild->_value == element){
                deleteQueueTraversal(currentTreeNode);
                // _deleteQueue.DeQueue();
                TreeNode* currentChild = currentTreeNode->_leftChild;
                currentTreeNode->_leftChild = NULL;
                printf("After Deletion: ");
                breadthFirstTraversal();
                insertQueueElements(_deleteQueue);
                return currentChild;
            }
            else if(rightChildExists(currentTreeNode) && currentTreeNode->_rightChild->_value == element){
                deleteQueueTraversal(currentTreeNode->_rightChild);
                _deleteQueue.DeQueue();
                // _deleteQueue.DeQueue();
                TreeNode* currentChild = currentTreeNode->_rightChild;
                currentTreeNode->_rightChild = NULL;
                printf("After Deletion: ");
                breadthFirstTraversal();
                printf("\n");
                _deleteQueue.printQueue();
                insertQueueElements(_deleteQueue);
                return currentChild;
            }
            else if((element < currentTreeNode->_value) && leftChildExists(currentTreeNode)){
                return deleteByValue(element, currentTreeNode->_leftChild);
            }
            else if((element > currentTreeNode->_value) && rightChildExists(currentTreeNode)){
                return deleteByValue(element, currentTreeNode->_rightChild);
            }
            
            return NULL;
        }

        TreeNode* efficientDelete(int element, TreeNode* currentNode){
            if(element < currentNode->_value){
                currentNode->_leftChild = efficientDelete(element, currentNode->_leftChild);   
            }
            else if(element > currentNode->_value){
                currentNode->_rightChild = efficientDelete(element, currentNode->_leftChild);   
            }
            else{
                if(!leftChildExists(currentNode) && !rightChildExists(currentNode)){
                    delete currentNode;
                    currentNode = NULL;
                }
                else if(!leftChildExists(currentNode) && rightChildExists(currentNode)){
                    TreeNode* temp = currentNode;
                    currentNode = currentNode->_rightChild;
                }
                else if(!rightChildExists(currentNode) && leftChildExists(currentNode)){
                    TreeNode* temp = currentNode;
                    currentNode = currentNode->_leftChild;
                }
                else{
                    TreeNode* temp = returnMinimum(currentNode->_rightChild);
                    currentNode->_value = temp->_value;
                    // printf("\n%d\n", temp->_value);
                    currentNode->_rightChild = efficientDelete(temp->_value, currentNode->_rightChild);
                }
            }
            return currentNode;
            
        }

        void insertQueueElements(Queue localQueue){
            while(!localQueue.isEmpty()){
                int removedValue = localQueue.DeQueue()->_value;
                insert(removedValue);
                printf("Removed value: %d, After Insertion: ", removedValue);
                lengthFirstTraversal(getRootTreeNode());
                printf("\n");
            }
        }

        int findHeight(TreeNode* currentTreeNode){
            if(!leftChildExists(currentTreeNode) && !rightChildExists(currentTreeNode)){
                return 0;
            }
            else if(leftChildExists(currentTreeNode) && !rightChildExists(currentTreeNode)){
                return 1 + findHeight(currentTreeNode->_leftChild);
            }

            else if(!leftChildExists(currentTreeNode) && rightChildExists(currentTreeNode)){
                return 1 + findHeight(currentTreeNode->_rightChild);
            }
            else{
                int rightHeight = findHeight(currentTreeNode->_leftChild);
                int leftHeight = findHeight(currentTreeNode->_rightChild);
                int value = (rightHeight > leftHeight) ? (1 + rightHeight) : (1 + leftHeight);
                return value;
            }
            return 0;
        }

        TreeNode* returnMinimum(TreeNode* currentTreeNode){
            if(leftChildExists(currentTreeNode)){
                return returnMinimum(currentTreeNode->_leftChild);
            }
            return currentTreeNode;
        }

        TreeNode* returnMaximum(TreeNode* currentTreeNode){
            if(rightChildExists(currentTreeNode)){
                return returnMaximum(currentTreeNode->_rightChild);
            }
            return currentTreeNode;
        }

        void checkPosition(int element, TreeNode* currentTreeNode){
            if((element < currentTreeNode->_value) && leftChildExists(currentTreeNode)){
                currentTreeNode = currentTreeNode->_leftChild;
                checkPosition(element, currentTreeNode);
            }
            else if((element < currentTreeNode->_value) && !leftChildExists(currentTreeNode)){
                TreeNode* tempTreeNode = new TreeNode;
                tempTreeNode->_value = element;
                tempTreeNode->_leftChild = NULL;
                tempTreeNode->_rightChild = NULL;
                tempTreeNode->_parentTreeNode = currentTreeNode;
                currentTreeNode->_leftChild = tempTreeNode;
            }
            else if((element > currentTreeNode->_value) && rightChildExists(currentTreeNode)){
                currentTreeNode = currentTreeNode->_rightChild;
                checkPosition(element, currentTreeNode);
            }
            else if((element == currentTreeNode->_value)){
                return;
            }
            else{
                TreeNode* tempTreeNode = new TreeNode;
                tempTreeNode->_value = element;
                tempTreeNode->_leftChild = NULL;
                tempTreeNode->_rightChild = NULL;
                tempTreeNode->_parentTreeNode = currentTreeNode;
                currentTreeNode->_rightChild = tempTreeNode;
            }
        }
        
        TreeNode* search(int element, TreeNode* currentTreeNode){
            if(currentTreeNode->_value == element){
                return currentTreeNode;
            }
            else if((element < currentTreeNode->_value) && leftChildExists(currentTreeNode)){
                return search(element, currentTreeNode->_leftChild);
            }
            else if((element > currentTreeNode->_value) && rightChildExists(currentTreeNode)){
                return search(element, currentTreeNode->_rightChild);
            }
            return NULL;
        }

        bool leftChildExists(TreeNode* currentTreeNode){
            return !(currentTreeNode->_leftChild == NULL);
        }
        
        bool rightChildExists(TreeNode* currentTreeNode){
            return (currentTreeNode->_rightChild != NULL);
        }

        TreeNode* getRootTreeNode(){
            return _rootTreeNode;
        }

        void enterTreeNode(TreeNode* currentTreeNode){
            printf("%d->", currentTreeNode->_value);
            if(leftChildExists(currentTreeNode)){
                enterTreeNode(currentTreeNode->_leftChild);
            }
            if(rightChildExists(currentTreeNode)){
                enterTreeNode(currentTreeNode->_rightChild);
            }
            printf("\n");
        }

        void deleteQueueTraversal(TreeNode* currentTreeNode){
            _deleteQueue.EnQueue(currentTreeNode);
            if(leftChildExists(currentTreeNode)){
                deleteQueueTraversal(currentTreeNode->_leftChild);
            }
            if(rightChildExists(currentTreeNode)){
                deleteQueueTraversal(currentTreeNode->_rightChild);
            }
        }
        
        void lengthFirstTraversal(TreeNode* currentTreeNode){
            printf("%d, ", currentTreeNode->_value);
            if(leftChildExists(currentTreeNode)){
                lengthFirstTraversal(currentTreeNode->_leftChild);
            }
            if(rightChildExists(currentTreeNode)){
                lengthFirstTraversal(currentTreeNode->_rightChild);
            }
        }

        void breadthFirstTraversal(){
            while(_traversalQueue.getLength() > 0){
                TreeNode* currentTreeNode = _traversalQueue.DeQueue();
                printf("%d, ", currentTreeNode->_value);
                EnQueueChildren(currentTreeNode, &_traversalQueue);
            }
            // printf("IsEmpty %d", _traversalQueue.isEmpty());
            if(_traversalQueue.isEmpty()){
                _traversalQueue.EnQueue(_rootTreeNode);
                printf("\n");
            }
        }

        void inorderTraversal(TreeNode* currentNode){
            if(leftChildExists(currentNode)){
                inorderTraversal(currentNode->_leftChild);
            }
            printf("%d, ", currentNode->_value);
            if(rightChildExists(currentNode)){
                inorderTraversal(currentNode->_rightChild);
            }
        }

        TreeNode* getInorderSuccessor(TreeNode* passedNode, TreeNode* currentNode){
            if(passedNode == returnMaximum(_rootTreeNode)){
                printf("\n%d is the last node in an inorder traversal of the binary tree\n", passedNode->_value);
                return passedNode;
            }
            if(rightChildExists(passedNode)){
                // printf("\nRight child of %d is %d\n", passedNode->_value, passedNode->_rightChild->_value);
                return returnMinimum(passedNode->_rightChild);
            }
            else{
                return findNearestLeftParent(passedNode, currentNode);
            }
        }

        TreeNode* findNearestLeftParent(TreeNode* passedNode, TreeNode* currentNode){
            // printf("\nCurrent Node = %d ", currentNode->_value);
            // printf("\nPassed Node  = %d\n", passedNode->_value);
            if((leftChildExists(currentNode)) && (currentNode->_value > passedNode->_value)){
                if(currentNode->_leftChild == passedNode){
                    return currentNode;
                }
                // printf("\nLeftChild = %d \n", currentNode->_leftChild->_value);
                TreeNode* tempNode = getInorderSuccessor(passedNode, currentNode->_leftChild);
                // printf("\nLeftChild = %d \n", currentNode->_leftChild->_value);
                return (tempNode) ? tempNode : currentNode;
            }
            if(rightChildExists(currentNode) && (currentNode->_value < passedNode->_value)){
                return getInorderSuccessor(passedNode, currentNode->_rightChild);
            }
            return 0;
        }

        TreeNode* inorderSuccessor(int value){
            return getInorderSuccessor(search(value, _rootTreeNode), _rootTreeNode);
        }

        void EnQueueChildren(TreeNode* currentTreeNode, Queue* localQueuePointer){
            if(leftChildExists(currentTreeNode)){
                localQueuePointer->EnQueue(currentTreeNode->_leftChild);
            }
            if(rightChildExists(currentTreeNode)){
                localQueuePointer->EnQueue(currentTreeNode->_rightChild);
            }
        }

        bool checkBST(TreeNode* currentNode){
            bool returnValue;
            if(leftChildExists(currentNode)){
                returnValue = checkLeft(currentNode);
                returnValue = returnValue*checkBST(currentNode->_leftChild);
            }
            if(rightChildExists(currentNode)){
                returnValue = returnValue*checkRight(currentNode);
                returnValue = returnValue*checkBST(currentNode->_rightChild);
            }
            if(!leftChildExists(currentNode) && !rightChildExists(currentNode)){
                returnValue = 1;
            }
            // printf("\n");
            return returnValue;
        }

        bool checkLeft(TreeNode* currentNode){
            return currentNode->_leftChild->_value < currentNode->_value;
        }

        bool checkRight(TreeNode* currentNode){
            return currentNode->_rightChild->_value > currentNode->_value;
        }

};

int main(){
    BinarySearchTree tree1;
    tree1.insert(5);
    tree1.insert(2);
    tree1.insert(1);
    tree1.insert(3);
    tree1.insert(4);
    tree1.insert(6);
    tree1.insert(8);
    tree1.insert(7);
    // printf("%d\n", tree1.returnMaximum(tree1.getRootTreeNode()));
    // printf("%d\n", tree1.findHeight(tree1.getRootTreeNode()));
    // tree1.enterTreeNode(tree1.getRootTreeNode());
    // tree1.breadthFirstTraversal();
    // printf("\n");
    // tree1.lengthFirstTraversal(tree1.getRootTreeNode());
    // printf("\n");
    // tree1.deleteByValue(3, tree1.getRootTreeNode());
    // tree1.efficientDelete(2, tree1.getRootTreeNode());

    // printf("BST: %d\n", tree1.checkBST(tree1.getRootTreeNode()));
    // tree1.lengthFirstTraversal(tree1.getRootTreeNode());
    // printf("\n");
    // tree1.inorderTraversal(tree1.getRootTreeNode());
    printf("\nInorder Succesor = %d\n", tree1.inorderSuccessor(8)->_value);
    printf("\n");
}