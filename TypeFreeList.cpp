#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class IntList{
    private:
        int size = 0;
        int lastIndex = size - 1;
        int sizeOfUnit = sizeof(int);
        int *mainList = (int*)malloc(size); 
    public:
        int validIndex(int index){
            if((index >= 0) && (index < size)){
                return 1;
            }
            return 0;
        }

        IntList(){
            // int *mainList = (int*)malloc(0);
            printf("MainList = %d\n", mainList);
        }

        IntList(int sizeOfArray){
            int *mainList = (int*)malloc(sizeOfArray * sizeOfUnit * 2);
            size = sizeOfArray;
            // assignValue(localArray, sizeOfArray);
            // printf("MainList = %d\n", *mainList);
        }

        IntList(int sizeOfArray, int localArray[]){
            // free(mainList);
            int *mainList = (int*)malloc(sizeOfArray * sizeOfUnit * 2);
            size = sizeOfArray;
            assignValue(localArray, sizeOfArray);
            // printf("MainList = %d\n", *mainList);
        }
        
        int assignValue(int array[], int sizeLocal){
            if(sizeLocal != size){
                printf("Invalid size;\n");
                return 0;
            }
            for(int i = 0; i < size; i++){
                *(mainList + i) = array[i];
            }
            return 1;
        }

        int getLastElement(){
            if(size > 0){
                return mainList[size-1];
            }
            printf("Zero size list, size: ");
            return 0;
        }

        int count(){
            return size;
        }
        
        void insert(int element, int position){
            if(!(validIndex(position))){
                printf("Invalid Index\n");
            }
            else{
                for(int i = size; i > position; i--){
                    mainList[i] = mainList[i-1];
                }
                mainList[position] = element;
                size++;
            }
        }

        void insert(int element){
            mainList[size] = element;
            size++;
        }

        void printList(){
            for(int i = 0; i < size; i++){
                printf("Element %d: %d\n", i, mainList[i]);
            }
        }

        void removeByPosition(int position){
            if(!(validIndex(position))){
                printf("Invalid Index\n");
            }
            else{
                for(int i = position; i < size; i++){
                    mainList[i] = mainList[i+1];
                }
                size--;
            }
        }

        void freeMemory(){
            free(mainList);
        }

        int operator[](int position){
            if(validIndex(position)){
                return this->mainList[position];
            }
            printf("Invalid Index: \n");
            return position;
        }
};
/*
class List{
    private:
    IntList integerList;
    string objectType;
    public:
        List(string type){
        }

        List(string type, int size){
            if(type == "int"){
                IntList integerList(size);
            }
            objectType = type;
        }

        List(string type, int size, int localArray[]){
            IntList integerList(size, localArray);
        }

        List(int size, int localArray[]){
            IntList integerList(size, localArray);
        }

        int assignValue(int array[], int sizeLocal){
            integerList.assignValue(array, sizeLocal);
        }

        decltype(auto) getLastElement(){
            if(objectType=="int"){
                return integerList.getLastElement();
            }
        }

        int count(){
            if(objectType=="int"){
                return integerList.count();
            }
        }

        void insert(int element){
            integerList.insert(element);
        }

        void printList(){
            integerList.printList();
        }

        void removeByPosition(int position){
            if(objectType=="int"){
                integerList.removeByPosition(position);
            }
        }

        void freeMemory(){
            if(objectType=="int"){
                integerList.freeMemory();
            }
        }

        decltype(auto) operator[](int position){
            if(objectType=="int"){
                return integerList[position];
            }
            // return ;
        }
};

*/


int main(){
    printf("\n");
    
    int passedSize = 5;
    int array[] = {1,2,3,4,7};

    IntList list(passedSize, array);
    
    printf("Size = %d\n", list.count());
    printf("Last Element = %d\n", list.getLastElement());
    
    list.removeByPosition(2);
    
    list.printList();
    
    printf("3rd Element = %d\n", list[2]);
    
    if(passedSize > 0){
        list.freeMemory();
    }

    printf("\n");
    return 0;
}