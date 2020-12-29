/** Created by @author Obr4nj on 12/29/20. **/
#include <bits/stdc++.h>
using namespace std;
#define oo 100005

/**
 * ------------------ Longest Increasing Subsequence -------------------
 *
 * Cho một dãy số nguyên gồm N phần tử A[1], A[2], ... A[N].
 * Biết rằng dãy con tăng đơn điệu là 1 dãy A[i1],... A[ik] thỏa mãn
 * i1 < i2 < ... < ik và A[i1] < A[i2] < .. < A[ik].
 * Hãy cho biết dãy con tăng đơn điệu dài nhất của dãy này có bao nhiêu phần tử?
 *
 * ------------------------------ Example ------------------------------
 * Input:
 *      n = 6
 *      a[] = {1, 2, 5, 4, 6, 2}
 * Output:
 *      Dãy con tăng dài nhất là 4
 * Explain:
 *      Dãy con tăng dài nhất là dãy 1 2 5 6 hoặc 1 2 4 6
 *
**/

int main() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    
    // Khởi tạo mảng dãy con tăng dài nhất là 0
    vector < int > dp (n, 0);
    
    // Vòng lặp i từ 0 đến n-1 để xác định số thứ i trong dãy ban đầu
    for (int i = 0; i < n; ++i) {
        
        // Vòng lặp j từ i-1 về 0 để xác định số thứ j trong dãy ban đầu
        // Vì mỗi giá trị tại vị trí < i đều có khả năng nằm trong dãy tăng
        for (int j = i-1; j >= 0; --j) {
            
            // Nếu giá trị a[j] thỏa mãn
            if (a[i] > a[j]) {
                
                // Giá trị có thể tại i là giá trị lớn hơn tại vị trí i và j
                dp[i] = max(dp[j], dp[i]);
            }
        }
        
        // Giá trị tại i cộng thêm 1 là giá trị của trường hợp cơ sở
        dp[i] += 1;
    }
    
    // In ra độ dài dãy con tăng dài nhất trong n dãy con {a[i], ..., a[n]} của dãy ban đầu
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
