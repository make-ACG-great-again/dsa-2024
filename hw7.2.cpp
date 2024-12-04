// #include <iostream>

// int m[26][26] = {100};

// int main(){
//     int n;
//     std::cin >> n;
//     for(int i = 0; i < n; i++){
//         char star, des;
//         int num, d, s;
//         std::cin >> star >> num;
//         s = star - 'A';
//         for(int j = 0; j < num; j++){
//             std::cin >> des >> d;
//             int dest = des - 'A';
//             if(s < dest) m[s][dest] = d;
//             else m[dest][s] = d;
//         }
//     }

// }

// #include <iostream>
// #include "../SourceCodes/chap7_Graph/Graph_Prim/Prim.h"
// #include "../SourceCodes/chap7_Graph/Graph_Prim/Graphm.h"
// #include "../SourceCodes/chap7_Graph/Graph_Prim/Graph.h"

// int main(){
//     int n;
//     std::cin >> n;
//     int** m = new int* [n];
//     for (int i = 0; i < n; i++) {
//         m[i] = new int[n];
//         for (int j = 0; j < n; j++) {
//             m[i][j] = 100;
//         }
//     }
//     for(int i = 0; i < n; i++){
//         char star, des;
//         int num, d, s;
//         std::cin >> star >> num;
//         s = star - 'A';
//         for(int j = 0; j < num; j++){
//             std::cin >> des >> d;
//             int dest = des - 'A';
//             m[s][dest] = d;
//             m[dest][s] = d;
//         }
//     }
//     Graphm star_map(n);
//     star_map.IniGraphm(&star_map, m, n);
//     Edge *D;
//     Prim(star_map, 0, D);
//     int ans = 0;
//     for(int i = 0; i < n - 1; i++){
//         ans += D[i].weight;
//     }
//     std::cout << ans;
// }