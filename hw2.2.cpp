#include <iostream>

int count(int len, int left){
    int length = 1;
    int head = 1;
    int tail = 9;
    while(len > tail){
        head *= 10;
        tail *= 10;
        tail += 9;
        length++;
    }
}

int main(){
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int j;
        std::cin >> j;

    }
}