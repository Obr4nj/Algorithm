/** Created by @author Obr4nj on 12/28/20. **/
#include <bits/stdc++.h>
using namespace std;
#define oo 100005

/**
 * ------------------------ Minimum Coin Change ------------------------
 * 
 * Giả sử chúng ta có n đồng xu lần lượt có giá trị là a1, a2, ..., an.
 * Bài toán đặt ra là tìm số lượng đồng xu nhỏ nhất để tổng giá trị của chúng bằng V.
 * 
 * ------------------------------ Example ------------------------------
 * Input:
 * 		n = 3
 * 		V = 30
 * 		a[] = {25, 10, 5}
 * 
 * Output:
 * 		Ít nhất cần 2 đồng xu
 * 
 * Explain:
 * 		Chúng ta có thể sử dụng một đồng xu 25 and và một đồng 5.
**/

int main() {
	int n, V; cin >> n >> V;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	
	// Khởi tạo mảng tổng số đồng xu có thể lấy được là Infinity
	vector < int > dp (V+1, oo);

	// Trường hợp cơ sở
	// Số đồng xu tối thiểu để tạo ra Sum = 0 xu là 0
	dp[0] = 0;

	// Vòng lặp i từ 1 đến V để xác định các giá trị có thể có của tổng cần tìm
	// Vì giá trị cuối cùng của Sum = V có thể phụ thuộc vào bất kỳ giá trị nào trong số này
	for (int i = 1; i <= V; ++i) {

		// Vòng lặp j từ 0 đến n là chỉ số của đồng xu
		// Với mỗi giá trị Sum = i sẽ tìm được giá trị tối ưu tương ứng
		for (int j = 0; j < n; ++j) {

			// Nếu đồng xu thứ j thỏa mãn
			if (a[j] <= i) {

				// Giá trị có thể bao gồm đồng xu thỏa mãn được đưa vào
				dp[i] = min(dp[i], 1 + dp[i - a[j]]);
			}
		}
	}
	cout << dp[V] << endl;
	return 0;
}
