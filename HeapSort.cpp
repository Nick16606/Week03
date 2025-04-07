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
void Shift(int a[], int left, int right,int &count) {
	int i = left, j = 2 * i + 1;
	int x = a[i];
	while (j <= right) {
		if (j < right) {
			++count;
			if (a[j] < a[j + 1]) {
				j = j + 1;
			}
		}
		++count;
		if (x < a[j]) {
			swap(a[j], a[i]);
			i = j;
			j = 2 * i + 1;
			x = a[i];
		}
		else {
			break;
		}
	}
}
void CreateHeap(int a[], int n,int &count) {
	int mid = n  / 2;
	while (mid >= 0) {
		Shift(a, mid, n - 1,count);
		--mid;
	}
}
void HeapSort(int a[], int n,int &count) {
	int right = n - 1;
	CreateHeap(a, n,count);
	while (right > 0) {
		swap(a[0], a[right]);
		--right;
		Shift(a, 0, right,count);
	}
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
	if (sort == "heap-sort") HeapSort(a, n,count);
	if (!outputfile.empty()) outputinfo(outputfile, a, n,count);
}