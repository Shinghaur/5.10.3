#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	int arr[n][n], check[n * n] = {0};
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++)
			cin >> arr[i][j];
	}
	
	bool isSymmetric = true, isAsymmetric = true, isMagic = true;
	
	for (int i = 0; i < n && isMagic; i ++) {
		for (int j = 0; j < n && isMagic; j ++) {
			if (arr[i][j] <= n * n)
				check[arr[i][j] - 1] = 1;
			
			else
				isMagic = false;
		}
	}
	 
	for (int i = 0; i < n * n && isMagic; i ++) {
		if (check[i] == 0)
			isMagic = false;
	}
	
	for (int i = 0; i < n && isSymmetric && !isMagic; i ++) {
		for (int j = 0; j < n; j ++) {
			if (i == j)
				continue;
			
			if (arr[i][j] != arr[j][i])
				isSymmetric = false;
		}
	}
	
	for (int i = 0; i < n && isAsymmetric && !isMagic; i ++) {
		for (int j = 0; j < n; j ++)
		{
			if (i + j < n - 1)
				continue;
				
			if (arr[i][j] != arr[n - j - 1][n - i - 1])
				isAsymmetric = false; 
		}
	}

	int sum = 0, csum = 0, rsum = 0, ssum = 0, asum = 0;
	
	for (int i = 0; i < n && isMagic; i ++)	{
		rsum = 0;
		csum = 0;
		
		for (int j = 0; j < n; j ++) {
			if (i == 0)
				sum += arr[i][j];
			
			rsum += arr[i][j];
			csum += arr[j][i];	
		}
		
		if (rsum != csum || rsum != sum || csum != sum)
			isMagic = false;
	}
	
	for (int i = 0; i < n && isMagic; i ++)
	{
		ssum += arr[i][i];
		asum += arr[i][n - i - 1];
	}
	
	if (ssum != sum || asum != sum)
		isMagic = false;
 
 	if (isMagic)
		cout << "Magic Square";
	
	else if (isSymmetric && isAsymmetric)
		cout << "Symmetric Asymmetric";
	
	else if (isSymmetric)
		cout << "Symmetric";
	
	else if (isAsymmetric)
		cout << "Asymmetric";
	
	else
		cout << "NOTHING"; 
}
