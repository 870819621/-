#include<iostream>
#include<string>
using namespace std;
int min(int a, int b){
	return a < b ? a : b;
}
int edit(string str1, string str2){
	int max1 = str1.size();
	int max2 = str2.size();
	int **ptr = new int *[max1 + 1];
	for (int i = 0; i < max1 + 1; i++){
		ptr[i] = new int[max2 + 1];
	}
	for (int i = 0; i < max1 + 1; i++){
		ptr[i][0] = i;
	}
	for (int i = 0; i < max2 + 1; i++){
		ptr[0][i] = i;
	}
	for (int i = 1; i < max1 + 1; i++){
		for (int j = 1; j < max2 + 1; j++){
			ptr[i][j] = min(ptr[i][j - 1] + 1, ptr[i - 1][j] + 1);
			int d = 0;
			if (str1[i] == str2[j])
				d = 0;
			else
				d = 1;
			ptr[i][j] = min(ptr[i - 1][j - 1] + d, ptr[i][j]);
		}
	}
		cout << "*************" << endl;
		for (int i = 0; i < max1 + 1; i++){
			for (int j = 0; j < max2 + 1; j++){
				cout << ptr[i][j] << " ";
			}
			cout << endl;
		}
		cout << "*************" << endl;
		int dis = ptr[max1][max2];
		for (int i = 0; i < max1 + 1; i++){
			delete[] ptr[i];
			ptr[i] = NULL;
		}
		delete[] ptr;
		ptr = NULL;
		return dis;
	}

	int main(){
		string str1 = "fxpimu";
		string str2 = "xwrs";
		
		int r = edit(str1, str2);
		cout << " the dis is:" << r << endl;
		getchar();
		return 0;


}