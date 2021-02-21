//
//  main.cpp
//  JumpGame
//
//  Created by yujeong on 2021/01/31.
//

#include <iostream>
#include<string.h>
using namespace std;


int map[101][101] ;
int cache[101][101] ;
int n;


int jumpGame(int x, int y) {
    
    // 기저
    if (x >= n || y >= n)   return 0;
    if (x == n - 1 && y == n - 1)   return 1;
    int& res = cache[x][y]; // res는 cache의 참조형
       if (res != -1) return res; // -1이 아니라면 계산된 값
       

    // 메모이제이션
    res = (jumpGame(x + map[x][y], y) || jumpGame(x, y + map[x][y]));
        return res;
}



int main()
{
    int tc;
    cin >> tc;
    
    while(tc--)
    {
        memset(cache, -1, sizeof(cache));
        memset(map, -1, sizeof(map));
        
        cin >> n;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> map[i][j];
            }
        }
        
        
        if (jumpGame(0, 0) == 1)  cout << "YES" << endl;
        else    cout << "NO" << endl;
        
    }
    
    return 0;
}
