#include <stdio.h>

class tempTestObject{
    private:
        int num;
    public:
        tempTestObject(int localNum){
            num = localNum;
        }

        int getNum(){
            return num;
        }
};

int main(){
    tempTestObject object1(10);
    tempTestObject* pointer1 = &object1;

    printf("\n");

    printf("%d\n", object1.getNum());
    printf("%d", (*pointer1).getNum());

    printf("\n");
    printf("\n");

    return 0;
}
