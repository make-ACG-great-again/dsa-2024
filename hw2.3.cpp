#include <iostream>
#include <cmath>

int a[40][40];

int main(){
    int n;
    std::cin >> n;
    int len = 2 * n - 1;
    int x = 0;
    int y = n - 1;
    for(int i = 1; i <= pow(len, 2); i++){
        a[x][y] = i;
        int old_x = x, old_y = y;
        if(x == 0 && y == len - 1){
            x++;
        }else{
            if(x == 0)
                x = len - 1;
            else x--;
            if(y == len - 1)
                y = 0;
            else y++;
        }
        if(a[x][y] != 0){
            x = (old_x + 1) % len;
            y = old_y;
        }
    }
    bool enter = 0;
    for(int i = 0; i < len; i++){
        if(enter) std::cout << std::endl;
        enter = 1;
        bool space = 0;
        for(int j = 0; j < len; j++){
            if(space)
                std::cout << ' ';
            space = 1;
            std::cout << a[i][j];
        }
    }
    return 0;
}