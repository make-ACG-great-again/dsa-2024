// 爆内存了
// #include <iostream>

// inline int get(int* tree, int a, int b, int n){
//     if(a < b){
//         int temp = b;
//         b = a;
//         a = temp;
//     }
//     return tree[a * (a - 1) / 2 + b - 1];
// }

// inline void put(int* tree, int a, int b, int n, int num){
//     if(a < b){
//         int temp = b;
//         b = a;
//         a = temp;
//     }
//     tree[a * (a - 1) / 2 + b - 1] = num;
// }

// int main(){
//     int T;
//     bool hh = 0;
//     std::cin >> T;
//     for(int i = 0; i < T; i++){
//         int n, m;
//         std::cin >> n >> m;
//         int* tree = new int[n * (n + 1) / 2]();
//         for(int j = 0; j< m; j++){
//             int a, b;
//             char q;
//             std::cin >> q >> a >> b;
//             if(q == 'D'){
//                 put(tree, a, b, n, -1);
//                 for(int j = 0; j < n; j++){
//                     if(j != a){
//                         int temp = get(tree, a, j, n);
//                         if(temp != 0)put(tree, b, j, n, -temp);
//                     }
//                     if(j != b){
//                         int temp = get(tree, b, j, n);
//                         if(temp != 0)put(tree, a, j, n, -temp);
//                     }
//                 }
//             }else{
//                 int temp = get(tree, a, b, n);
//                 if(hh) std::cout << std::endl;
//                 hh = 1;
//                 if(temp == 0) std::cout << "Not sure yet.";
//                 else if(temp == 1) std::cout << "In the same gang.";
//                 else if(temp == -1) std::cout << "In different gangs.";
//                 else std::cout << "error";
//             }
//         }
//     }
// }

#include <iostream>

int find(int* family, int n){
    if(n == 0) return 0;
    while(family[n] != n && family[n] != 0){
        n = family[n];
    }
    return n;
}

void unit(int* family, int a, int b){
    int ta = find(family, a);
    int tb = find(family, b);
    if(ta > tb){
        int temp = ta;
        ta = tb;
        tb = temp;
    }
    family[tb] = ta;
}

int main(){
    int T;
    std::cin >> T;
    bool hh = 0;
    for(int i = 0; i < T; i++){
        int n, m;
        std::cin >> n >> m;
        int* buddy = new int[n+1]();
        int* enemy = new int[n+1]();
        for(int j = 0; j < m; j++){
            int a, b;
            char q;
            std::cin >> q >> a >> b;
            if(q == 'D'){   
                int ta = find(buddy, a);
                int tb = find(buddy, b);
                if(enemy[ta] == 0){
                    enemy[ta] = tb;
                }
                else{
                    unit(buddy, enemy[ta], tb);
                }
                if(enemy[tb] == 0){
                    enemy[tb] = ta;
                }
                else{
                    unit(buddy, enemy[tb], ta);
                }
            }else if(q == 'A'){
                a = find(buddy, a);
                b = find(buddy, b);
                if(hh) std::cout << std::endl;
                hh = 1;
                if(a == b){
                    std::cout << "In the same gang.";
                }
                else if(find(buddy, enemy[a]) == b || find(buddy, enemy[b]) == a){
                    std::cout << "In different gangs.";
                }
                else{
                    std::cout << "Not sure yet.";
                }
            }

        }
        free(buddy);
        free(enemy);
    }
    return 0;
}