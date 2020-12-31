/** Created by @author Obr4nj on 12/31/20. **/
#include <bits/stdc++.h>
using namespace std;
#define oo 100005

/**
 * --------------------------- Ugly Numbers ----------------------------
 *
 * Số Ugly là những số có thừa số nguyên tố duy nhất là 2, 3 hoặc 5.
 * Tìm số Ugly thứ n;
 *
 * ------------------------------ Example ------------------------------
 * Input:
 *      n = 18
 * Output:
 *      Số Ugly thứ 18 là 30
 * Explain:
 *      Số Ugly là những số có thừa số nguyên tố duy nhất là 2, 3 hoặc 5.
 *      Số 30 = 2*5*3
 *      18 số ugly đầu tiên: 1 2 3 4 5 6 8 9 10 12 15 16 18 20 24 25 27 30 ...
 *
**/

int main() {
    int n; cin >> n ;
    int a[n];
    
    // Trường hợp cơ sở
    a[0] = 1;
    
    // Chỉ số ban đầu của 2, 3 và 5
    int i2 = 0, i3 = 0, i5 = 0;
    
    // Vòng lặp i từ 1 đến n-1 để xách định các số Ugly từ 2 đến n
    for (int i = 1; i < n; ++i) {
        
        // Số Ugly thứ i là số nhỏ nhất trong tích của 2, 3, 5 với chỉ số của nó
        a[i] = min(a[i2]*2, min (a[i3]*3, a[i5]*5));
        
        // Kiểm tra các số 2, 3, 5, khi nhân với chỉ số có bằng với số Ugly thứ i không
        // Nếu bằng thì chỉ số được tăng lên một đơn vị
        if (a[i2]*2 == a[i]) i2++;
        if (a[i3]*3 == a[i]) i3++;
        if (a[i5]*5 == a[i]) i5++;
    }
    
    // In ra số Ugly thứ n theo yêu cầu đề bài
    cout << a[n-1] << " ";
    return 0;
}
