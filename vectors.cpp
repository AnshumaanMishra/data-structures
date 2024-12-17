#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    printf("\n");
    vector<int> numbers;
    numbers.push_back(0);

    for(int i = 1; i < 11; i++){
        numbers.push_back(i);
    }
    int a;
    a = numbers.at(0);
    for(auto it = numbers.begin(); it != numbers.end(); it ++){
        printf("Element              : %d\n", *it);
        printf("Address of Iterator  : %d\n", &it);
        printf("Address of Element   : %d\n", &(*it));
    }

    auto it = numbers.begin();
    printf("%d\n", *(it+5));

    printf("\n");
    return 0;
}