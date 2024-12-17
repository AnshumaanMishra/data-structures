#include <stdio.h>
#include <iostream>
using namespace std;
#include <list>

void sortIntoNew(int newPlayerRating, list<int>& playersByRating){
    for(list<int>::iterator it = playersByRating.begin(); it != playersByRating.end(); it++){
        if(*it > newPlayerRating){
            playersByRating.insert(it, newPlayerRating);
            return;
        }
    }
    playersByRating.push_back(newPlayerRating);
}


void displayRating(const list<int>& playersRating){
    for(list<int>::const_iterator it = playersRating.begin(); it != playersRating.end(); it++){
        printf("Player Rating: %d\n", *it);
    }
    printf("\n");
}


int main(){
    printf("\n");

    list<int> allPlayers = {2,9,6,7,6,5,7,4,2,3,5,7,2,4,2,3};

    list<int> beginers;
    list<int> professionals;

    for(list<int>::iterator it = allPlayers.begin(); it != allPlayers.end(); it++){
        int rating = *it;
        if(rating > 5){
            sortIntoNew(rating, professionals);
        }
        else{
            sortIntoNew(rating, beginers);
        }
    }
    
    displayRating(beginers);
    displayRating(professionals);

    printf("\n");
    return 0;
}