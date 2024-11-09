#include <iostream>
#include <algorithm>

int main(){
    int t;
    bool hh = 0;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        if(hh) std::cout << std::endl;
        hh = 1;
        int n;
        std::cin >> n;
        int num[128];
        for(int j = 0; j < n; j++) std::cin >> num[j];
        std::sort(num, num + n);
        int k = 0;
        int sum = 0;
        while(k < n - 1){
            num[k + 1] += num[k];
            sum += num[k + 1];
            k++;
            std::sort(num + k, num + n);
        }
        std::cout << sum;
    }
    return 0;
}