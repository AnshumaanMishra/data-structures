#include <stdio.h>

class newclass{
    private:
        int* _mainArray;

    public:
        newclass(){
            int _mainArray[10];
            _mainArray[5] = 5;
            printf("%p\n", _mainArray); 
        }

        void getelement(){
            printf("%p\n", _mainArray);
        }
};

int main(){
    newclass a = newclass();
    a.getelement();
    return 0;
}
