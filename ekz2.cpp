#include <string>
#include <iostream>
#include <cmath>

using namespace std;

double min(double* arr, size_t n) {
	double temp = arr[0];
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] < temp) {
			temp = arr[i];
		}
	}

	return temp;
}

double ser(double* arr, size_t n) {
	double sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	return sum / n;
}

double mein(double* arr, size_t n, double ser) {
	double minn = fabs(arr[0] - ser);
	for (size_t i = 0; i < n; i++)
	{
		if (minn > fabs(arr[i] - ser)) {
			minn = fabs(arr[i] - ser);
		}
	}

	return minn;
}

int main()
{
	size_t n;
	cout << "ENter n:\n";
	cin >> n;


	double* mas = new double[n];
	cout << "Enter the numbers: \n";
	for (size_t i = 0; i < n; i++)
	{
		cin >> mas[i];
	}

	double x = ser(mas, n);
	cout << mein(mas, n, x);

}