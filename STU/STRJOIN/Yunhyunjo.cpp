#include <iostream>
#include <queue>

using namespace std;

int strjoin(priority_queue <int> pq){

    int res = 0;

    while (pq.size() != 1) {
        int a = -pq.top();
        pq.pop();
        int b = -pq.top();
        pq.pop();
        res = res + a + b;
        pq.push(-(a + b));
    }
    
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, num;

    cin >> n;
    
    while (n--) {
        cin >> num;
        priority_queue <int> pq;
        int a;
        for (int i = 0; i < num; i++) {
            cin >> a;
            pq.push(-a);
        }
        cout << strjoin(pq) << "\n";
    }

    return 0;
}