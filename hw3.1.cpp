// 每次最值失效就遍历当前窗口，O(n^2)，超时
// #include <iostream>
// #include <cmath>

// int a[1000010];
// int c[1000000];

// int main(){
//     int n, k;
//     std::cin >> n >> k;
//     int num = n - k + 1;
//     int max = -1000000000, min = 1000000000;
//     for(int i = 0; i < k; i++){
//         int temp;
//         std::cin >> temp;
//         // max = std::max(temp, max);
//         // min = std::min(temp, min);
//         if(temp > max) max = temp;
//         if(temp < min) min = temp;
//         a[i] = temp;
//     }
//     c[0] = max;
//     std::cout << min;
//     if(n > k){
//         for(int i = k; i < n; i++){
//             int t = i - k + 1;
//             int temp;
//             std::cin >> temp;
//             a[i] = temp;
//             if(temp <= min) min = temp;
//             else if(a[i - k] == min){
//                 min = temp;
//                 for(int j = 0; j < k - 1; j++){
//                     //min = std::min(a[t + j], min); 
//                     if(a[t + j] < min) min = a[t + j];
//                 }
//             }
//             if(temp >= max) max = temp;
//             else if(a[i - k] == max){
//                 max = temp;
//                 for(int j = 0; j < k - 1; j++){
//                     //max = std::max(a[t + j], max);
//                     if(a[t + j] > max) max = a[t + j];
//                 }
//             }
//             c[t] = max;
//             std::cout << ' ';
//             std::cout << min;
//         }
//     }
//     bool space = 0;
//     std::cout << std::endl;
//     for(int i = 0; i < num; i++){
//         if(space) std::cout << ' ';
//         space = 1;
//         std::cout << c[i];
//     }
//     return 0;
// }

#include <iostream>
#include <cmath>

int a[100000000];
int b[100000000];
int c[100000000];
int min_stack[1000000];
int max_stack[1000000];
int min_p = 0, max_p = 0;
int min_q = 0, max_q = 0;

int main(){
    int n, k;
    std::cin >> n >> k;
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        for(int j = min_q; j < min_p; j++){
            if(min_stack[j] <= i - k) min_q++;
            else break;
        }
        for(int j = min_p - 1; j >= min_q; j--){
            if(a[i] <= a[min_stack[j]]) min_p--;
            else break;
        }
        min_stack[min_p] = i;
        b[i] = a[min_stack[min_q]];
        min_p++;
        for(int j = max_q; j < max_p; j++){
            if(max_stack[j] <= i - k) max_q++;
            else break;
        }
        for(int j = max_p - 1; j >= max_q; j--){
            if(a[i] >= a[max_stack[j]]) max_p--;
            else break;
        }
        max_stack[max_p] = i;
        c[i] = a[max_stack[max_q]];
        max_p++;
    }
    bool kg = 0;
    for(int i = k - 1; i < n; i++){
        if(kg) std::cout << ' ';
        std::cout << b[i];
        kg = 1;
    }
    std::cout << std::endl;
    kg = 0;
    for(int i = k - 1; i < n; i++){
        if(kg) std::cout << ' ';
        std::cout << c[i];
        kg = 1;
    }
    return 0;
}