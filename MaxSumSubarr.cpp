/** Created by @author Obr4nj on 12/30/20. **/
#include <bits/stdc++.h>
using namespace std;

/**
 * ------------------ Largest Sum Contiguous Subarray ------------------
 *
 * Cho một dãy X[1..n].
 * Tìm dãy con liên tiếp cạnh nhau của X có tổng lớn nhất.
 *
 * ------------------------------ Example ------------------------------
 * Input:
 *      n = 8
 *      a[] = {-2, -3, 4, -1, -2, 1, 5, -3}
 * Output:
 *      Dãy con liên tiếp có tổng lớn nhất là 4
 * Explain:
 *      Dãy con liên tiếp có tổng lớn nhẩt là dãy 4 -1 -2 1 5
 *
**/

int main() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    
    // Khởi tạo phần tử tính tổng (sum)
    int sum = a[0];
    
    // Khởi tạo phần tử ghi lại giá trị tổng lớn nhất (smax)
    // Với giá trị ban đầu là phần tử đầu tiên của dãy
    int smax = a[0];
    
    // Vòng lặp i từ 1 đến n để xác định phần tử thứ i của dãy
    for (int i = 1; i < n; ++i) {
        
        // Nếu a[i] lớn hơn giá trị sum + a[i] thì sum sẽ bằng giá trị a[i]
        // Nếu không thì sum được cộng thêm a[i]
        sum = max(a[i], sum + a[i]);
        
        // Nếu sum lớn hơn giá trị lớn nhất của sum đã dược lưu trước đó
        // thì giá trị sum lớn nhất được cập nhật
        smax = max(smax, sum);
    }
    
    cout << smax << endl;
    return 0;
}
