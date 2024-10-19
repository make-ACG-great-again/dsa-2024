#include <iostream>
#include <cstring>

char s[1000001];

int main(){
    bool hh = 0;
    while(scanf("%s", s) && s[0] != '.'){
        if(hh) std::cout << std::endl;
        hh = 1;
        int num = 1;
        int len = strlen(s);
        if(len < 2){
            std::cout << '1';
            continue;
        }
        for(int i = 1, j = 0; i < len && num <= (len / 2) + 1; i++){
            if(s[i] == s[j]){
                j++;
            }
            else if(j == 0){
                num = i + 1;
                continue;
            }
            else {
                j = 0;
                num = ((i + 1) / num) * num;
                i = num - 1;
            }
        }
        if(num > 0 && (len / num) * num == len) std::cout << (len / num);
        else std:: cout << '1';
    }
    return 0;
}