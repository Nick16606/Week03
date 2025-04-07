#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
void inputinfo(const string& input, int a[], int& n) {
	fstream file;
	file.open(input);
	if (!file.is_open()) {
		cout << "Xay ra loi";
		return;
	}
	file >> n;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % n;
	}
	file.close();
}
void outputinfo(const string& output, int a[], int n,int count) {
	fstream file;
	file.open(output);
	if (!file.is_open()) {
		cout << "Xay ra loi";
		return;
	}
	file << n << endl;
	for (int i = 0; i < n; i++) {
		file << a[i] << " ";
	}
	file << endl;
	file << count;
	file.close();
}
void QuickSort(int a[], int left, int right,int &count) {
	if (left > right) return;
	int i = left, j = i - 1;
	int Pivot = a[right];
	for (int m = left; m < right; m++) {
		++count;
		if (a[m] < Pivot) {
			++j;
			swap(a[j], a[m]);
		}
	}
	swap(a[right], a[j + 1]);
	int PivotIndex = j + 1;
	QuickSort(a, left, PivotIndex - 1,count);
	QuickSort(a, PivotIndex + 1, right,count);
}
int main(int argc, char* argv[]) {
	int count = 0;
	string inputfile, outputfile, sort;
	int a[20], n;
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-a") == 0) {
			sort = argv[i + 1];
			++i;
		}
		else if (strcmp(argv[i], "-i") == 0) {
			inputfile = argv[i + 1];
			++i;
		}
		else if (strcmp(argv[i], "-o") == 0) {
			outputfile = argv[i + 1];
			++i;
		}
	}
	if (!inputfile.empty()) inputinfo(inputfile, a, n);
	if (sort == "quick-sort") QuickSort(a, 0, n - 1, count);
	if (!outputfile.empty()) outputinfo(outputfile, a, n, count);
}
