// 提示:给定序列中有可能有不在1...n之间的数字

#include <iostream>
#include <cmath>
#include <deque>

int num[10000000];
int op[100000000];
int p = 0;
std::deque<int> stack;

int main(){
    int n;
    int min = 1000000, max = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> num[i];
        if(num[i] < 1 || num[i] > n){
            std::cout << "NO";
            return 0;
        }
        if(num[i] >= min && num[i] <= max){
            std::cout << "NO";
            return 0;
        }
        if(num[i] > max){
            for(int j = max; j < num[i]; j++){
                op[p] = j + 1;
                p++;
                stack.push_back(j+1);
            }
            op[p] = -num[i];
            p++;
            stack.pop_back();
        }
        if(i != 0 && num[i] < min){
            if(!stack.empty()){
                int temp = stack.back();
                while(temp >= num[i]){
                    op[p] = -temp;
                    p++;
                    stack.pop_back();
                    if(stack.empty()) break;
                    temp = stack.back();
                }
            }else{
                std::cout << "NO";
                return 0;
            }
        }
        min = std::min(min, num[i]);
        max = std::max(max, num[i]);
    }
    bool hh = 0;
    for(int i = 0; i < n*2; i++){
        if(hh) std::cout << std::endl;
        hh = 1;
        if(op[i] > 0) std::cout << "PUSH " << op[i];
        else std::cout << "POP " << -op[i];
    }
    return 0;
}