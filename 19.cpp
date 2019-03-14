#include <iostream>
//В интернетах сказали ,что делаеться через сортировку слиянием за (O(n log2 n))
using namespace std;
//Вроде работет и должно пройти 
long x = 0;

void merge(long * A, long l, long m, long r)
{
	long N_L = m - l + 1;
	long N_R = r - m;

	long * left = new long[N_L];
	long * right = new long[N_R];

	long i, j, k;

	for (i = 0; i < N_L; ++i)
		left[i] = A[l + i];
	for (j = 0; j < N_R; ++j)
		right[j] = A[m + 1 + j];

	i = 0;
	j = 0;
	k = l;

	while (i < N_L && j < N_R)
		if (left[i] <= right[j])
			A[k++] = left[i++];
		else
		{
			A[k++] = right[j++];
			x += N_L - i;
		}

	while (i < N_L)
		A[k++] = left[i++];

	while (j < N_R)
		A[k++] = right[j++];

	//Если и так не заработает ,то непонятки чо делат ((
	delete[] right;
	delete[] left;

}

void MergeSort(long * A, long l, long r)
{
	if (l < r)
	{
		long m = (l + r) / 2;
		MergeSort(A, l, m);
		MergeSort(A, m + 1, r);
		merge(A, l, m, r);
	}
}

int main()
{
	long N;
	cin >> N;
	long* A = new long[N];
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	MergeSort(A, 0, N - 1);
	cout << x;
	return 0;
}