#include <iostream>
#include <cmath>

int deal(int head, int left, int width){
    while(left > width){
        left -= width;
        head++;
    }
    if (width == 1) return head;
    while(left > 1){
        left--;
        // if(width == 0) return head;
        head = head % int(pow(10, width - 1));
        width--;
    }
    if(width == 1) return head;
    int outcome = head / int(pow(10, width - 1));
    return outcome;
}

int count(int len, int left){
    int width = 1;
    int head = 1;
    int tail = 9;
    while(len > tail){
        int temp = (tail - head + 1) * width;
        if(temp >= left){
            return deal(head, left, width);
        }
        left -= temp;
        head *= 10;
        tail *= 10;
        tail += 9;
        width++;
    }
    int temp = (len - head + 1) * width;
    if(temp >= left){
        return deal(head, left, width);
    }else return count(len + 1, left - temp);
}

int main(){
    int n;
    bool enter = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int j;
        std::cin >> j;
        if(enter) std::cout << std::endl;
        enter = 1;
        int outcome = count(1, j);
        if(outcome < 0 || outcome > 9) int f = 1 / 0;
        else std::cout << outcome;
    }
}