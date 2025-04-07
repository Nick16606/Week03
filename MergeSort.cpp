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
void Merge(int a[], int left, int mid, int right,int &count) {
	int n1 = mid - left + 1, n2 = right - mid;
	int a1[200], a2[200];
	for (int i = 0; i < n1; i++) {
		a1[i] = a[left + i];
	}
	for (int j = 0; j < n2; j++) {
		a2[j] = a[mid + 1 + j];
	}
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		++count;
		if (a1[i] <= a2[j]) {
			a[k] = a1[i];
			++i;
		}
		else {
			a[k] = a1[j];
			++j;
		}
		k++;
	}
	while (i < n1) {
		++count;
		a[k] = a1[i];
		++i, ++k;
	}
	while (j < n2) {
		++count;
		a[k] = a2[j];
		++j, ++k;
	}
}
void MergeSort(int a[], int left, int right,int &count) {
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort(a, left, mid,count);
		MergeSort(a, mid + 1, right,count);
		Merge(a, left, mid, right,count);
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
	if (sort == "merge-sort") MergeSort(a, 0,n-1,count);
	if (!outputfile.empty()) outputinfo(outputfile, a, n,count);
}
