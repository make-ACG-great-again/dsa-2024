#include <iostream>
#include <cstring>

char hw[100000][50];
char s[100000];
char temp[100000];
char t[100000];

int main(){
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> hw[i];
    }
    std::cin >> s;
    int l = 0;
    int a,b;
    bool th = 0;
    for(int i = 0; i < strlen(s); i++){
        if (isupper(s[i])) {
            s[i] = tolower(s[i]);
        }
    }
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == ']') {
            b = i;
            break;
        }
        else if(s[i] == '['){
            a = i;
            th = 1;
            continue;
        }
        if(th) t[l++] = s[i];
    }
    bool hh = 0;
    for(int i = 0; i < n; i++){
        bool pp = 1;
        int j = 0, k = 0;
        strcpy(temp, hw[i]);
        for( ; j < strlen(temp); j++, k++){
            if (isupper(temp[j])) {
                temp[j] = tolower(temp[j]);
            }
            if(j == a){
                bool cmp = 0;
                for(int h = 0; h < l; h++){
                    if(t[h] == temp[j]){
                        cmp = 1;
                        break;
                    }
                }
                if(!cmp) {
                    pp = 0;
                    break;
                }
                k = b;
            }
            else if(temp[j] != s[k]){
                pp = 0;
                break;
            }
        }
        if(pp && j == strlen(temp) && k == strlen(s)){
            if(hh) std::cout << std::endl;
            hh = 1;
            std::cout << (i + 1) << ' ' << hw[i];
        }
    }
    return 0;
}