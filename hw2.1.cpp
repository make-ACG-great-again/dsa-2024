#include <iostream>

int count = 0;

void put(int left, int unused_plate, int min){
    if(left < min) return;
    if (unused_plate == 1){
        count++;
        return;
    }
    for(int i = min; i <= left; i++){
        put(left - i, unused_plate - 1, i);
    }
    return;
}

int main(){
    int t;
    std::cin >> t;
    bool enter = 0;
    for(int i = 0; i < t; i++){
        int m, n;
        std::cin >> m >> n;
        int min = 0;
        int all = 0;
        put(m, n, 0);
        if(enter) std::cout << std::endl;
        enter = true;
        std::cout << count;
        count = 0;
    }
    return 0;
}