#include "Numbers.h"

Numbers::Numbers(){
    sizesHashT.clear();
}

Numbers::~Numbers(){
    sizesHashT.clear();
}

bool Numbers::isPrime(int number){
    if (number <= 1){
        return false;
    }

    else if (number <= 3){
        return true;
    }

    else if (number % 2 == 0 || number % 3 == 0){
        return false;
    }

    int i = 5;

    while (i * i <= number){

        if (number % i == 0 || number % (i + 2) == 0){
            return false;
        }

        i += 6;
    }

    return true;
}

std::vector<int> Numbers::findClosePrime(int number){
    sizesHashT.clear();
    number++;

    while (sizesHashT.size() < 5){

        if (isPrime(number)){
            sizesHashT.push_back(number);
        }

        number++;
    }

    return sizesHashT;
}
