#include <iostream>
#include <iomanip>
#include <vector>

#define capacity 500
using namespace std;

//Giai Ma Phuong Bac 4
int MaTranCon(int n, vector<int> &subMat);
void GiaiMaPhuongBac4(int arr[capacity][capacity], int count, vector<int> subMat);



//Giai Ma Phuoc Bac Le, Phuong Phap Ve Duong Cheo
void TaoCacDuongCheo(int arr[][capacity], int n);
int ViTri(int i, int j, int n);
void ThemCacSoConLai(int arr[capacity][capacity], int n);


//Gia Ma Phuong Bac Le, Phuong Phap Siamese
void GiaiMaPhuongBacLe_SiameseMethod(int arr[][capacity], int n);


//Giai Ma Phuoc Bac Chan(4n + 2), phuong phap Strachey
void Tao4MaPhuongCon(int arr[][capacity], int n);
void DoiChoAD(int arr[][capacity], int k, int n);
void GiaiMaPhuongChan_StrachheyMethod(int n, int arr[][capacity]);
void DoiChoBC(int arr[][capacity], int k, int n);
void swap(int& a, int& b);
void DoiChoTrungTamAD(int arr[][capacity], int n);



int main() {
	int n;
	int arr[capacity][capacity];
	vector <int> subMat;
	cout << "Nhap cap ma tran:";
	cin >> n;
	if (n % 4 == 0) {
		int k = MaTranCon(n, subMat);
		GiaiMaPhuongBac4(arr, k, subMat);
	}
	else if (n % 2 != 0) {
		cout << "Phuong Phap duong cheo:" << endl;
		TaoCacDuongCheo(arr,n);
		ThemCacSoConLai(arr, n);
		cout << "Phuong Phap Siamese:" << endl;
		GiaiMaPhuongBacLe_SiameseMethod(arr, n);
	}
	else {
		GiaiMaPhuongChan_StrachheyMethod(n,arr);
	}


	
	return 0;
}












int MaTranCon(int n, vector<int> &subMat) {
	for (int i = 0; i < n; i++) {
		if (i % 4 == 0) {
			subMat.push_back(i);
		}
	}
	return n / 4;
}
	

void GiaiMaPhuongBac4(int arr[capacity][capacity], int count, vector<int> subMat) {
	int x = 1;
	vector<int> missingNum;
	/* Tạo các ma trân con 4 * 4 có dạng:
			xx--xx
			--xx--
			--xx--
			xx--xx
		x là các vị trí đượng điền số
		- là các vị trí không điền
		Sau đó lấy các số chưa được điền viết ngược lại vào mảng
	
	*/

	//Tạo các ma phương 4 * 4 con
	// count = số ma trân con 

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					if (k == 1 || k == 2) {
						if (l == 1 || l == 2) {
							arr[k + subMat[i]][l + subMat[j]] = x;
						}
						else {
							missingNum.push_back(x);
							arr[k + subMat[i]][l + subMat[j]] = 0;
						}
					}
					else {
						if (l == 0 || l == 3) {
							arr[k + subMat[i]][l + subMat[j]] = x;
						}
						else {
							missingNum.push_back(x);
							arr[k + subMat[i]][l + subMat[j]] = 0;

						}
					}
					x++;
				}
			}
		}
	}

	//Điền các số chưa được điền ngược lại vào mảng
	int n = count * 4;
	x = missingNum.size() - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = missingNum[x];
				x--;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout <<setw(4) << arr[i][j];
		}
		cout << endl;
	}
}

void TaoCacDuongCheo(int arr[][capacity], int n) {

/*
	Tạo các đường chéo có dạng :
				n   2n 
			  ..  .. 			
			3	..
		  2	  ..
		1	..
		  n+1
	

*/
	int startPoint[2];

	//Khởi tạo mảng = 0
	for (int i = 0; i < 2*n; i++) {
		for (int j = 0; j < 2*n ; j++) {
			arr[i][j] = 0;
		}
	}


	//Điểm bắt đầu
	startPoint[0] = (2*n-1)/ 2;
	startPoint[1] = 0;

	int x = 1;
	int temp0 = 0;
	while (temp0 < n) {
		int temp1 = 0;
		int i = startPoint[0];
		int j = startPoint[1];
		while (temp1 < n) {
			arr[i - temp1][j + temp1] = x;
			x++;
			temp1++;
		}
		startPoint[0]++;
		startPoint[1]++;
		temp0++;
	}

}

int ViTri(int i, int j, int n) {
	//Kiểm tra vị trí của một điểm so với ma phương chính
	int xMin = (n - 1) / 2;
	int yMin = (n-1) / 2;
	int xMax = (3*n -3) /2;
	int yMax = (3*n -3)/2;
	if (j >= xMin && j <= xMax && i < yMin) return 1; //Tren
	if (j < xMin && i >= yMin && i <= yMax) return 2; //Trai
	if (j > xMax&& i >= yMin && i <= yMax) return 3; //Phai
	if (j >= xMin && j <= xMax && i > yMax) return 4; //Duoi
	return 0; //Trong ma phuong

}

void ThemCacSoConLai(int arr[capacity][capacity], int n) {
	//Xử Lý lỗ trống

	int xMin = (n - 1) / 2;
	int yMin = (n - 1) / 2;
	int xMax = (3 * n - 3) / 2;
	int yMax = (3 * n - 3) / 2;

	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			//Xua ly cac so o tren
			if (arr[i][j] != 0 && ViTri(i, j, n) == 1) {
				for (int k = yMax; k >= yMin; k--) {
					if (arr[k][j] == 0) {
						arr[k][j] = arr[i][j];
						arr[i][j] = 0;
						break;
					}
				}
			}
			//Xu ly cac so ben trai
			if (arr[i][j] != 0 && ViTri(i, j, n) == 2) {
				for (int k = xMax; k >= xMin; k--) {
					if (arr[i][k] == 0) {
						arr[i][k] = arr[i][j];
						arr[i][j] = 0;
						break;
					}
				}
			}
			//Xu ly cac so ben phai

			if (arr[i][j] != 0 && ViTri(i, j, n) == 3) {
				for (int k = yMin; k <= yMax; k++) {
					if (arr[i][k] == 0) {
						arr[i][k] = arr[i][j];
						arr[i][j] = 0;
						break;
					}
				}
			}
			//Xu ly cac so o duoi
			if (arr[i][j] != 0 && ViTri(i, j, n) == 4) {
				for (int k = xMin; k <= xMax; k++) {
					if (arr[k][j] == 0) {
						arr[k][j] = arr[i][j];
						arr[i][j] = 0;
						break;
					}
				}
			}

		}
	}
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 *n; j++) {
			if (arr[i][j] != 0) {
				cout << setw(4) << arr[i][j];
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
}


void GiaiMaPhuongBacLe_SiameseMethod(int arr[][capacity], int n) {
	//Khởi tạo điểm bắt đầu = điểm giữa cạnh trên
	
	int i = 0;
	int j = n / 2 ;

	//Khởi tạo mảng = 0
	int x = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}


	/*Siamese Method
		i < 0 => i = n
		j > n-1 => j = 0
		arr[i][j] != null => moveBot(i+1,j);

	*/
	while (x <= n * n) {
		arr[i][j] = x;
		x++;
		int tempi = i;
		int tempj = j;
		i--;
		j++;
		if (i < 0) i = n - 1;
		if (j > n - 1) j = 0;
		if (arr[i][j] != 0) {
			i = tempi + 1;
			j = tempj;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(4) << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void GiaiMaPhuongChan_StrachheyMethod(int n, int arr[][capacity]) {
	Tao4MaPhuongCon(arr,n);
	int k = (n - 2) / 4;
	DoiChoAD(arr, k, n);
	
	DoiChoBC(arr, k-1,n);
	DoiChoTrungTamAD(arr, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(4) << arr[i][j] << " ";
		}
		cout << endl;
	}
}



void swap(int& a, int& b) {
	int c;
	c = a;
	a = b;
	b = c;
}

void DoiChoTrungTamAD(int arr[][capacity], int n) {
	//Đổi chổ vị trí trung tâm bên trai và trung tâm của ma phương con A và D
	int l = n / 4;
	int k = n / 2 + l;
	swap(arr[l][0], arr[k][0]);
	swap(arr[l][l], arr[k][l]);
}


void DoiChoAD(int arr[][capacity], int k, int n) {
	//Đổi chỗ k cột trái cùng của ma phương con A và D(4k + 2 = n)
	int temp;
	int l = n / 2;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < l; j++) {
			temp = arr[j][i];
			arr[j][i] = arr[l + j][i];
			arr[l + j][i] = temp;
		}
	}
	
}
void DoiChoBC(int arr[][capacity], int k, int n) {
	//Đổi chổ k - 1 cột phải cùng của ma phương con B và C
	int temp;
	int l = n / 2;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < l; j++) {
			temp = arr[j][n-i - 1 ];
			arr[j][n-i -1] = arr[l + j][n-i - 1];
			arr[l + j][n-i - 1] = temp;
		}
	}

}





void Tao4MaPhuongCon(int arr[][capacity], int n) {
	/*
		Tạo ma phương con theo thứ tự:  A C
										D B
	*/
	
	
	//Khởi tạo mảng bằng 0
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}
	//Tạo Ma Phương Con A
	int k = n / 2;
	int i = 0; 
	int j = n / 4;
	int x = 1;

	while (x <= k * k) {
		arr[i][j] = x;
		x++;
		int tempi = i;
		int tempj = j;
		i--;
		j++;
		if (i < 0) i = k -1;
		if (j > k -1) j = 0;
		if (arr[i][j] != 0) {
			i = tempi + 1;
			j = tempj;
		}
	}

	//Tạo ma phương B
	i = k;
	j = n / 4 + k;

	while (x <= 2 * k * k) {
		arr[i][j] = x;
		x++;
		int tempi = i;
		int tempj = j;
		i--;
		j++;
		if (i < k) i = n -1;
		if (j > n - 1) j = k;
		if (arr[i][j] != 0) {
			i = tempi + 1;
			j = tempj;
		}
	}

	//Tạo Ma Phương C
	i = 0;
	j = n / 4 + k;

	while (x <= 3 * k * k) {
		arr[i][j] = x;
		x++;
		int tempi = i;
		int tempj = j;
		i--;
		j++;
		if (i < 0) i = k -1;
		if (j > n - 1) j = k;
		if (arr[i][j] != 0) {
			i = tempi + 1;
			j = tempj;
		}
	}

	//Tạo Ma Phương D

	i = k;
	j = n / 4;

	while (x <= 4 * k * k) {
		arr[i][j] = x;
		x++;
		int tempi = i;
		int tempj = j;
		i--;
		j++;
		if (i < k) i = n - 1;
		if (j > k - 1) j = 0;

		if (arr[i][j] != 0) {
			i = tempi + 1;
			j = tempj;
		};
	}

}


