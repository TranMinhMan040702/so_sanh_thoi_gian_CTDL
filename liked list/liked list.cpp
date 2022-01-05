#include<iostream>
#include<cmath>
#include<time.h>
#include <iomanip>

using namespace std;

struct NODE {
	int data;
	NODE* pNext;
};

NODE* khoiTaoNode(int x) {
	NODE* p = new NODE;
	p->data = x;
	p->pNext = NULL;
	return p;
}

void themDau(NODE*& pHead, NODE* p) {
	if (pHead == NULL) {
		pHead = p;
	}
	else {
		p->pNext = pHead; //Lấy con trỏ của NODE p trỏ đến NODE đầu danh sách
		pHead = p; //Cập nhật lại NODE đầu
	}
}

void xuatDanhSach(NODE* pHead) {
	int dem = 1;
	for (NODE* k = pHead; k != NULL; k = k->pNext) {
		cout << dem << k->data << "\n";
		dem++;
	}
}

void themCuoi(NODE*& pHead, NODE* p) {
	if (pHead == NULL) {
		pHead = p;
	}
	else {
		for (NODE* k = pHead; k != NULL; k = k->pNext) {
			//Kiểm tra nếu pNext hiện tại là NULL thì NODE đang duyệt là cuối danh sách
			if (k->pNext == NULL) {
				k->pNext = p; //thêm p vào cuối danh sách
				return; //Không cần duyệt nữa
			}
		}
	}
}

void them_NODE_Sau_NODE_Bat_Ky(NODE* pHead, int x, NODE* p) {
	for (NODE* k = pHead; k != NULL; k = k->pNext) {
		if (k->data == x) {
			p->pNext = k->pNext; //Lấy NODE p trỏ vào NODE sau NODE k
			k->pNext = p; //Ngắt mối liên kết giữa NODE k và NODE nằm sau NODE k, Cho NODE k liên kết với NODE p
			if (p->data == x) {
				return;
			}
		}
	}
}

void them_NODE_Truoc_NODE_Bat_Ky(NODE*& pHead, int x, NODE* p) {
	if (pHead->data == x) {
		themDau(pHead, p);
	}
	else {
		NODE* q = NULL; //NODE q để giữ NODE trước NODE k có giá trị x
		for (NODE* k = pHead; k != NULL; k = k->pNext) {
			if (k->data == x) {
				p->pNext = k; //Lấy p liên kết với NODE k cần tìm
				q->pNext = p; //Ngắt mỗi liên hệ giữa NODE k và NODE trước k, lấy NODE trước k liên kết với NODE p
			}
			q = k;
		}
	}
}

void xoaPhanTuDauDanhSach(NODE*& pHead) {
	if (pHead == NULL) {
		return;
	}
	else {
		NODE* k = pHead; //Node k tạm giữ NODE đầu danh sách
		pHead = pHead->pNext; //NODE pHead liên kết với NODE sau NODE k
		delete k;
	}
}

void xoaPhanTuCuoiDanhSach(NODE*& pHead) {
	if (pHead == NULL) {
		return;
	}
	else {
		NODE* q = NULL; //NODE q liên kết với NODE trước NODE k
		for (NODE* k = pHead; k != NULL; k = k->pNext) {
			if (k->pNext == NULL) {
				q->pNext = NULL; //Ngắt mỗi liên kết giữa NODE trước NODE k và NODE k
				delete k; //Xóa NODE k
				return; //Sau khi xóa NODE thì kết thúc công việc
			}
			q = k;

		}
	}
}

void xoa_NODE_Bat_Ky(NODE*& pHead, NODE* p) {
	if (pHead->data == p->data) {
		xoaPhanTuDauDanhSach(pHead);
	}
	else {
		NODE* q = NULL; //NODE q liên kết với NODE trước NODE k
		for (NODE* k = pHead; k != NULL; k = k->pNext) {
			if (k->data == p->data) {
				q->pNext = k->pNext; //NODE q liên kết kết với NODE sau NODE k
				delete k; //Xóa NODE k
				return;
			}
			q = k;
		}
	}
}

void timKiem(NODE* pHead, int sdt) {
	bool kt = false;
	for (NODE* k = pHead; k != NULL; k = k->pNext) {
		if (k->data == sdt) {
			cout << "\n\n\t\t" << k->data<<"\t";
			kt = true;
			break;
		}
	}
	if (kt == false) {
		cout << "\n\tKhong co so dien thoai can tim";
	}
}


// tính thời gian trong Menu 
void Menu(NODE*& pHead) {
	int luachon;
	while (true) {
		system("cls");
		cout << "\n\n\t\t==================================MENU================================== ";
		cout << "\n\t1. Them NODE vao cuoi danh sach";
		cout << "\n\t2. Xoa NODE bat ky";
		cout << "\n\t3. Xuat danh sach lien ket don";
		cout << "\n\t4. Tim kiem";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t===================================END===================================";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 3) {
			xuatDanhSach(pHead);
			system("pause");
		}
		else if (luachon == 1) {
			double max = INT_MIN;
			double min = INT_MAX;
			double mean = 0;
			for (int i = 0; i < 1000; i++)
			{
			clock_t start, end;
			double cputime;
			start = clock();
			NODE* p = khoiTaoNode(i);
			themCuoi(pHead, p);
			end = clock();
			cputime = double(end - start) / CLOCKS_PER_SEC;
			cout << cputime << "\n";
			if (max < cputime)
			{
				max = cputime;
			}
			if (min > cputime)
			{
				min = cputime;
			}
			mean += cputime;
			}
			cout << "max:" << max << "\n";
			cout << "min:" << min << "\n";
			cout << "mean:" << mean / 1000;

			system("pause");
		}
		else if (luachon == 2) {
			double max = INT_MIN;
			double min = INT_MAX;
			double mean = 0;
			for (int i = 0; i < 1000; i++)
			{
			clock_t start, end;
			double cputime;
			start = clock();
			NODE* p = khoiTaoNode(i);
			p->data = i;
			p->pNext = NULL;
			xoa_NODE_Bat_Ky(pHead, p);
			end = clock();
			cputime = double(end - start) / CLOCKS_PER_SEC;
			cout << cputime << "\n";
			if (max < cputime)
			{
				max = cputime;
			}
			if (min > cputime)
			{
				min = cputime;
			}
			mean += cputime;
		}
		cout << "max:" << max << "\n";
		cout << "min:" << min << "\n";
		cout << "mean:" << mean / 1000;

			system("pause");
		}
		else if (luachon == 4) {
			double max = INT_MIN;
			double min = INT_MAX;
			double mean = 0;
			for (int i = 0; i < 1000; i++)
			{
			clock_t start, end;
			double cputime;
			start = clock();
			timKiem(pHead, i);
			end = clock();
			cputime = double(end - start) / CLOCKS_PER_SEC;
			cout << cputime << "\n";
			if (max < cputime)
			{
				max = cputime;
			}
			if (min > cputime)
			{
				min = cputime;
			}
			mean += cputime;
		}
		cout << "max:" << max << "\n";
		cout << "min:" << min << "\n";
		cout << "mean:" << mean / 1000;
			system("pause");
		}


	}
}

int main() {
	NODE* pHead = NULL;
	Menu(pHead);

	//Giải phóng vùng nhớ cho danh sách liên kết đơn
	for (NODE* k = pHead; k != NULL; k = k->pNext) {
		NODE* tam = pHead;// NODE tạm giữ con trỏ đầu danh sách
		pHead = pHead->pNext; //Cập nhật lại con trỏ đầu danh sách tiếp theo
		delete tam; //Giải phóng NODE đầu danh sách
	}
	return 0;

}