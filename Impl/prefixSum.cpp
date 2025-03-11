#include <iostream>
using namespace std;

void print(int arr[], int N)
{
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void PrefixSum(int ARR[], int N)
{

	int PRE[N];
	for (int i = 0; i < N; i++) {
		if (i == 0)
			PRE[i] = ARR[i];
		else
			PRE[i] = PRE[i - 1] + ARR[i];
	}
	cout << "Prefix Sum: ";
	print(PRE, N);
}

void SuffixSum(int ARR[], int N)
{
	int SUF[N];
	for (int i = N - 1; i >= 0; i--) {

		if (i == N - 1)
			SUF[i] = ARR[i];
		else
			SUF[i] = SUF[i + 1] + ARR[i];
	}
	cout << "Suffix Sum: ";
	print(SUF, N);
}

int main()
{
	int N = 5;
	int ARR[N] = { 4, 2, 1, -1, 3 };
	cout << "Given Array: ";
	print(ARR, N);

	PrefixSum(ARR, N);
    
	SuffixSum(ARR, N);
	return 0;
}
