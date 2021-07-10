#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int solution(vector<vector<int>> matrix_sizes) {

	int n = matrix_sizes.size();
	unsigned dp[200][200];
	memset(dp, -1, sizeof dp);



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			int left = j, right = j + i;
			if (left == right)
				dp[left][right] = 0;
			else {
				
				for (int k = left; k < right; k++) {
					dp[left][right] = min(dp[left][right],
						dp[left][k] + dp[k + 1][right] +
						(matrix_sizes[left][0] * matrix_sizes[k][1] * matrix_sizes[right][1])
					);
				}
			}
		}
	}

	return dp[0][n-1];
}
int main() {
	solution({ {5, 3},{3, 10},{10, 6} });
}