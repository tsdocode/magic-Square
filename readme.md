*Ma Phương*

![ma_phuong](https://lh5.googleusercontent.com/proxy/sJumO1Q6vyN8CesLafqlGcV3-gVIskJ3tpKJgopG9zbr3cygrkWBS0pLv9pJFiMuF-rRYQnrLFXIYi3iLafJqrPX5eI1AiIMgFt0b7e1srg6LfISn7Cke0ANk7g=s0-d)

> *write up by ts from UTE*

> [*ts's facebook*](https://www.facebook.com/tstheloser)


##*Ma phương là gì ?*
    - Ma phương là một ma trận vuông có tổng các phần tử trên:
        + Hàng
        + Cột
        + Đường chéo
        => Bằng nhau
    - Các loại ma phương:
        + Ma phương bậc 4 (n = 4k)
        + Ma phương chẵn (n = 4k + 2)
        + Ma phương lẽ   (n = 2k + 1)
        + Không có ma phương bậc 2
	
	
	
##*1. Giải ma phương bậc là bội 4*
###Phương pháp
    - Chia ma trận n * n thành các ma trận 4 * 4
    - Số ma trận 4 * 4 = (n / 4)^2
    - Các ma trận 4 * 4 có dạng:

                    xx--xx
			--xx--
			--xx--
			xx--xx
		x là các vị trí đượng điền số
		- là các vị trí không điền
		Sau đó lấy các số chưa được điền viết ngược lại vào mảng
###Các bước lập trình:
    Bước 1: Tính số ma phương con và vị trí của chúng:
Code:
```cpp
    //vector subMat để lưu vị trí các ma phương con
    int MaTranCon(int n, vector<int> &subMat) {
	for (int i = 0; i < n; i++) {
		if (i % 4 == 0) {
			subMat.push_back(i);
		}
	}
	return n / 4;
}
```
    Bước 2: Tạo các ma phương con như đã nói ở trên. Cho các phần tử trống bằng 0

Code:
```cpp
//count là số các ma phương con
//missingNum để lưu các số chưa được điền vào bảng
    for (int i = 0; i < count; i++) {
        //i và j dùng để lấy ra vị trí của ma phương trong Vector subMat 
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
```
![mp](https://i0.wp.com/i.imgur.com/Sk8OFg8.jpg?w=780)

    Bước 3: Thêm các phần tử chưa được thêm ngược vào ma phương chính:
Code:
```cpp
    x = missingNum.size() - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = missingNum[x];
				x--;
			}
		}
	}
```
![mp](https://i0.wp.com/i.imgur.com/huoS1a8.jpg?w=780)
###Kết quả:
Một vài kết quả tiêu biểu:

n = 16:

![16](https://lh3.googleusercontent.com/_38-_PxJY0xsu5LGiwxCagL01lIKCUPQlrUgjqAGtFYk_8catW2cfVDB-rQY3lmp0XuN0sT1rhzy5CeiGicudWWip3gdaMNhppmb90NieYi28wvnI5MVY6hgiI85C5XJj-BFT-70phmcz0ixFpyWJLU5eFoOsGoC_rFqSacF_9GS05z3K7O1R7tUliIF3tlDRuIPe5RggopWE5AU8Gk7M1u6couRgyicAi_EgmykGRSCWnuBYwHMD4-fgIdSFhQ3u_NOrC2ADC6-jAhqmBxweKfKhbwI4GLILDRX9h_kBVljyN3PGUnzrMJjmkUcsucmx4CBdGPRlseBfdXin6BDQe4Ha8VAV5dZkzjffPbj2v8p9vSKS1IuouaEL_QkFkg09W20k4ktFkYiCyJEv6hNUh--k2evkrpTbeS_KfxW8NSo2VmpHghi-yHEJrTp3ASDbxeLqK-6eByGC1hrDo1i9-9kZlj0-Cb83-4M1ZXyY4MwP-wBhI-qk5Un3Ysrdd8VASVWTyGZWbrdlkx9zNZB6qzZfBeLtzBTcSnLj8HG6VOPJt1dgzWAOw8TAOcYMR7aCyyIPFODGX1JdxziYfbSguJgG0-C15K5NY61ftns9xITZ86ky5lxSY8nGRHhuBXgBfF5-xC-4bfFihwtq409kdDrbtKtH7NpIcGAoP7QFPqunKXnspwG7EwkRXnuJDoFdtHiYGaoEzZBODD_rbSVvjyYV2TDEOc0tsAQAPzUX_KCJA=w584-h320-no)

##*2. Ma phương bậc lẻ*
###Phương pháp
####1.  Các đường chéo
![duong_cheo](https://i0.wp.com/i.imgur.com/k3zQBbJ.png?w=780)
#####Mô tả
    - Với n là số lẽ, vẽ n đường chéo mang giá trị từ 1 tới n^2
    - Giữa hình thoi là một ma phương
    - Lắp các số ở ngoài ma phương đến vị trí trống gần với cạch hình vuông ở xa nhất
#####Các bước lập trình
    Bước 1: Tạo các đường chéo có giá trị như đã nói ở trên
Code:
```cpp
    	//Khởi tạo mảng = 0
	for (int i = 0; i < 2*n; i++) {
		for (int j = 0; j < 2*n ; j++) {
			arr[i][j] = 0;
		}
	}


	//Điểm bắt đầu
	startPoint[0] = (2*n-1)/ 2;
	startPoint[1] = 0;

    //temp0 kiểm soát số các đường chéo
    //temp1 kiểm soát số các giá trị trong một đường chéo
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
```
    Bước 2: Xây dựng hàm xét vị trí một ô so với ma phương:
        Ta có số ô một cạnh hình thoi có công thức:
             = 2*i + 1 (i <= n - 1),
             = 4n - 2i -3 (i > n-1)
        => Cạnh trái ma phương có j = (n-1) /2
        => Cạnh phải ma phương có j = (3*n -3) /2
        => Cạnh trên ma phương có i = (n-1) /2
        => Cạnh dưới ma phương có i = (3*n -3) /2
    => Để xét vị trí một số với ma phương ta xét vị trí của nó với các giá trị ở trên
Code:
```cpp
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
```
    Bước 3: Xét vị trí các số trong mảng đã tạo, xử dụng hàm vị trí ở trên,
     để lắp các số ở ngoài ma phương đến vị trí trống gần với cạch hình vuông ở xa nhất.
Code:
```cpp
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
```

 #### 2.Phương pháp Siamese
 ![siamese](https://i.imgur.com/M0wezEc.gif)
 ##### Quy tắt Siamese:
    1. Bắt đầu từ trung tâm cạnh trên
    2. Đi theo hướng ĐN(Đông Nam)
	3. Nếu đi ra khỏi ma phương:
        3.1 Ra khỏi phía trên => Đi xuống đáy 
        3.2 Ra khỏi phía phải => Đi về phía trái cùng
        3.3 Đi đến ô tiếp theo đã có giá trị => Đi xuống dưới ô đang đứng 
#####Các bước lập trình
    Bước 1: Khởi tạo:
        1.1 Khởi tạo vị trí đầu
        1.2 Các phần tử trong ma phương = 0
        1.3 Giá trị đầu bằng 1
```cpp
    int i = 0;
	int j = n / 2 ;
	int x = 1;

	//Khởi tạo mảng = 0
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}
```
    Bước 2: Xử lý di chuyển:
        2.1 Đi xuống đáy : i = n -1
        2.2 Đi về phía trái cùng : j = 0
        2.3 Đi xuống dưới ô đang đứng:
            Dùng tempi và tempj để lưu vị trí đang đứng
            => ô dưới = (tempi +1, tempj)
Code:
```cpp
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
```

##*Ma phương bậc chẵn (4k + 2)*
###1. Phương pháp Strachey 
- Chia ma phương bật chẵn thành 4 ma phương bật lẻ, sắp xếp theo thứ tự:
![tt](https://lh3.googleusercontent.com/Q_s4TSeQZStMP_JDl6m1gaxhGFoqJt1dRUuE0f8MHzeiHocMhjCrfQCkMYxmF4Vw3mfBEjOlbrckcr3n2QcKM80hRsQS_8A9a7Pn1hJtGqkpI0yuJ4kBOCPvymjIh1KCwgeRi1ks_np1O5YjdnpJaxZWXq9XzBpY7nWvqAWm409HCerW0S_cEScawZ4Ly9vN6DCHJPLF7rCpqhBYD1NMXjlMwcG3zA5n5bxVvnBOmouCoQT9JDueTGGWixpIUSbEEoJzE5_w2ZIsnKvoTkdprRRGNpNaV3V70U7XbfWybskegSxGC0rEjbdp7bsxB3ZYmnkJTRT6dRcxsC57mdgJ94SAYHhDOA5jdj6zB01J5c40BU13y1jC-1Dn7lAb7v9OV14DYeJ56fWnT4yGrdDFpYZqpLuiHCwC1-tRVLK8QSMHCadjNgndEX2HXPaE9THztrh3CgwVCqOthNYcVKE4CwKhITfUsvyq1-D5_vWyp4d6p7BEcgoj3eCr9cOPSpxhCbnXPi-1RgLC31qPKsUB-LPfEa9kyEzwCM0qT_aR4vZGTRQk8xx9GrqC-Fv5oNjJB-o3ipzJUeCFrnbKoMOMGgUrGMDT05HnWEgV7mhF19oisJYm6Axjg7Mu4UZ-dGRDb61cN8x34VwqUizPaAPQYegHmDc3NsP7ALDEhAqrLd55LYIqYpdH=w74-h68-no)
- Lập các ma phương lẻ theo thứ tự bằng phương pháp Siamese ở trên:
![mp](https://lh3.googleusercontent.com/smuBFyWHtcSkuDaPaFOn62MpcJJGIq1UkptM3sBQeOzCL09aU_4XVe0dBx2hHsKg-11wrDzwkbURE_p4GZ_DctvBDnHQ5glwPm9SptnpGelIJ9p32Kpc88bO5os_xLyiNFg-Xi507AaxlJkId2DaFTfZiUt9ANozsVn5-nZdba3nTnnHerwVRSrnwYPSPeXYpbbdtrpnQ_ipQ3EZbGcBp4psBUGFd8QG4FspZtcjXxaL93rMvShUSfEz6hT_n9IfLm3iyp7Juv3L_9wB0fxVoh4-AxhgeMKpRnKW8JcCs_py25d3KVTw--mhcbkTe-mQlgxFcHAmrI60idQkGqa6XfC28U0BmOjCcTyHrgF1uz6MawxXnyEZ1ql2U8G_jC_LfiPoH9Bsr7he_ZE5vguy6UJ-6D-wcvbRTkRzh9c_DrqYnvqL_J781Uh04jPsgEQse77_Mn0uUsqSxfXkRS3z8k3mpJRmSnCz-rLaIyXoB4Na-xCImMBYnLReYn8SLzQsgSq9GipsJt2HuHhMpyY_NEmcoQbLswbBzZcfPx3OHKVFD5GDefWnxAjUmWW2DBfzRAN7OUBIKqMiqRWJvXX8o9ve_lQ66l7JUIBhQlcSznec1vPmqHhBr1ZpQV2p_-SOiSKdZPyiHEk5CqZNjp5meC36OHAoJKqFOnV7DUqds2c5s9HFea2S=w535-h538-no)
- Đổi chỗ k cột ngoài cùng bên trái của ma phương con A và D
![swap](https://lh3.googleusercontent.com/Am9RBBIPXrGQedHO20-kGmgfundfPGC8GGXwd9qmqNWFG8sSqwOV9fRC2XrkJaTZjSwr5QUSG16P7Dj22J49Skm_uvN2_OBaR9PkZVhlJgmQsN_366f_FWFq8O9cNFDdRNzHF3aWqxMH2ileu5lfRkV70WwK5mUZ_QTk7d7RbzNXg_JnjCJcMC_nt5GDp42QOVZ6vyMdUc68_MZxNyybHXI0JkfKFK4d7zZTXGnLlG0M7IEGuJNzlUvVEJQbTRTgkG7c5HdGGlyb974pzB1AItk3V0eVhr9AltVZb5VkQjv4k0yPQJR4EeSOkXihayd_jn0GEeG__tJmG9iV7DB_IpOgWYw8Ra-4ixQ4R-8utt30DrUujt-rhObFgUz8DPHCA99JqSPWkgTbnobxNhXuGV3DPeJF2sCXhMmHLYU2ZVKiarujLA6ceAhjoMQELvtOWjTQQt8WBVjYPqaEq9yD_Jtn6SSBOF9LegDGqGPi1Wa4g_LYRP2PqZ7D2UKQfGk0PrqO6kTsL1kbbGAGGAX_FKUYru6aZH8MLvcmCmRm5dOxFXRwPba56UC38848q4fjQtSbi7uwuYpjMLBN4eDjwLxgVWPbMc_VXYiM9HSiEjslLg8QPtmOVxsrB29naKM57zn6B88LNvVc-zTr-dRSNDJOZToO4ffm01jg4h6a_MOr0Zs6l1UB=w533-h532-no)
- Đổi chỗ k-1 cột ngoài cùng bên phải của hai ma phương B và C
![swap](https://lh3.googleusercontent.com/-wRoPdcrMotOiuIQDqv9yQ4eXnTKroHNqsZ9NQndAt48UtK_Wdxgr2I1Qlmt-Eo5ZrCh7fpfEaJjxwHQEzhf2rppIsWmes8utDH8iLP8etPVZkyuMdZ_WV4HOTrV-9qgqkDvi6rkjR70Cu5ZYw9HBmrGRXo-k0HSJDMZqyN2pqH6t9pv3hG40ubgTCFGZxDPlwBOwsM5O6CNa_N2y9-p2HyxwGfwQwx1yg4dPVu8C0q0WIrjl8NE3eaZGLGRgBfRQ7akd2zpcdmG2dVzYokEvvahQZt8T5RLzGUSJvVl9GDnq81-r0dK76KebQ6-7oE2DMFAqr1S6WCAVYRa-WIBAUUJ_30r5K-GYPvDpUz1gbkk1N6awA2bjI6-O0_CHBBi7lb7yMO5x2dKThBdRTzM-VG3mHF5LGeyYQeZFKrJUrDRQV6bfR5jFgXYKQFOzRGS7QSoOi3LitgAZFUWmirhN993IGL7FObUUh5NCrwB5SjRM63-5mnpYjX60giTfhWOl0Qe6VN_tmRzUecYlRTT6jajAa9oY2ho_wA9J_56D1IvU2kQduqMGBH7_ZSDXLX2xqGZB9GF3CF70BhKC3sVcM-VsWYoR4YHog6GPOLp35uFB8lQA3hKZYJjb1Kw8lNkv1LY0iz2hXCUtcl0AOekp0KM_3VUrvl776jf7uzSgqbi1zDhWZyB=w531-h535-no)
- Đổ chỗ trung tâm cạch ngoài cùng và trung tâm của ma phương A và D 
![swap](https://lh3.googleusercontent.com/WeyYf37YerBg1wmox1FoT0sa_IvUM6M8H1dOtutFkp3cm3lCB-dvYgNW3aGwzjgixWLV0tPm3bbqzCpknygIwRY7lejxOnOliT_EK9Yk4sUQHicaTeEFN2BGvlFYZ9LO77Gog7M8mX_oDfoKHSdF9nGK1UO5mVYIIdWW0_xJjxfd4oLRWfHzFouxUh6YIrQCrdagNelnxHzOs7oYXCbJiRAr5WtT_w9o0a3IMHYgauEKhi6PxMCFPZCOTspDPe_hcg_TzrEKPhPswp7CYYavSbCq3-l0bML6g5NxuXNFfPy-ECKHeh04mKLIi1gsLTIy1jMjjUOO6KBiIgR9ngtCQmfH2fDvMUjps4gjuSoybdZMNZ6eaBSyzLfgth4QGxTrjqLI7LUcsvnxNdtr5B0uPx88CpieBTxkzVyS3qNX5gzNZ_bFOoT_qyD-6kdu0nD-v4nq3KtcLdOB7ahbDm4LeXiOrc1sF1bZ1Kin_qo_waRnJ8VwSHSZ93ZdZm-cVg5Vd6t0hv879vEY4XJ5JUz6j5THUd4Z7Aw21EUAfZ1cBKsCvhVrPCqhrGD5vrnxIbw1GOQ6lceZKA4_y5fj-ouAYq2EzSEeWsG10j4W8WP4W0gTv-5iX5blFNVchlKPdFMKYejbU6M7Lh8P8QZNcSTx1Vcuca8n6Yp5OmLXr0ud1zgD13b7X0rD=w535-h530-no)
###Các bước lập trình
    Bước 1: Tạo các ma phương con
```cpp
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
```
    Bước 2:Đổi chổ k cột của ma phương A và D
```cpp
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
```
    Bước 3: Đổi chỗ k - 1 cột của ma phương B và C
```cpp
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
``` 
    Bước 4: Đổi chỗ trung tâm cạch trái và trung tâm hai ma phương A và D
```cpp
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
```

##*4.Nguồn tham khảo*
[Ma phương](https://vi.wikipedia.org/wiki/Ma_tr%E1%BA%ADn_k%C3%AC_%E1%BA%A3o)
[Siamese Method](https://en.wikipedia.org/wiki/Siamese_method)
[StrachheyMethod](https://en.wikipedia.org/wiki/Strachey_method_for_magic_squares)
[4n Magic Square](http://www.math.wichita.edu/~richardson/mathematics/magic%20squares/4th-ordermagicsquares.html)

