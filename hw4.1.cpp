#include <iostream>
#include <cstring>

char a[100001], b[100001];

int main(){
    bool hh = 0;
    while(std::cin >> a >> b){
        if(strlen(a) == 0) return 0;
        if(hh) std::cout << std::endl;
        hh = 1;
        int la = strlen(a);
        int lb = strlen(b);
        if(la > lb){
            std::cout << "No";
            continue;
        }
        else{
            int i = 0, j = 0;
            for( ; i < la && j < lb; j++){
                if(a[i] == b[j]) i++;
                else continue;
            }
            if(i == la && a[i - 1] == b[j - 1]) std::cout << "Yes";
            else std::cout << "No";
        }
    }
    return 0;
}