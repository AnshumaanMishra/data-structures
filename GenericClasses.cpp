#include <stdio.h>
#include <iostream>
using namespace std;

template <typename T>
class Calculator{
    private:
        T Num1;
        T Num2;
    
    public:
        Calculator(T num1, T num2){
            Num1 = num1;
            Num2 = num2;
        }

        T add(){
            return Num1 + Num2;
        }

        T subtarct(){
            return Num1 - Num2;
        }

        T multiply(){
            return Num1 * Num2;
        }

        T divide(){
            return Num1 / Num2;
        }

        T reverse(){
            T temp = Num1;
            Num1 = Num2;
            Num2 = temp;
        }

        T modulo(){
            return Num1 % Num2;
        }

        T changeSign(){
            return -Num1;
        }

        T changeNums(T num1, T num2){
            Num1 = num1;
            Num2 = num2;
        }

};

int main(){
    printf("\n");
    
    Calculator<int> calculator1(5, 7);
    printf("%d\n", calculator1.add());

    printf("\n");
    return 0;
}