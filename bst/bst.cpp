#include<iostream>
#include<cmath>
#include<time.h>
#include <iomanip>

using namespace std;
struct NODE {
	int data;
	NODE* right;
	NODE* left;
	int height; //Chiều cao của node
};

NODE* newNode(int x)
{
	NODE* node = new NODE();
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

//Hàm tìm chiều cao của node
int height(NODE* t) {
	return t == NULL ? 0 : t->height;
}


//Xoay phải
NODE* rightRotate(NODE* y)
{
	NODE* x = y->left;
	NODE* T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left),
		height(y->right)) + 1;
	x->height = max(height(x->left),
		height(x->right)) + 1;

	// Return new root
	return x;
}
//Xoay trái
NODE* leftRotate(NODE* x)
{
	NODE* y = x->right;
	NODE* T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left),
		height(x->right)) + 1;
	y->height = max(height(y->left),
		height(y->right)) + 1;

	// Return new root
	return y;
}


//Tìm hệ số cân bằng của NODE = chiều cao cây con trái trừ chiều cao cây con phải
int balanceFactor(NODE* t) {
	return t == NULL ? 0 : (height(t->left) - height(t->right));
}

//Hàm thêm data
NODE* insertData(NODE*& contact, int data) {
	if (contact == NULL) { //Nếu cây rỗng
		return newNode(data);
	}
	if (contact->data < data) {
		contact->right = insertData(contact->right, data);
	}
	else if (contact->data > data) {
		contact->left = insertData(contact->left, data);
	}

	//Cập nhật lại hệ số cân bằng và cây cân bằng
	contact->height = 1 + max(height(contact->left), height(contact->right));
	int balance = balanceFactor(contact);
	// Left Left Case
	if (balance > 1 && data < contact->left->data)
		return rightRotate(contact);

	// Right Right Case
	if (balance < -1 && data> contact->right->data)
		return leftRotate(contact);

	// Left Right Case
	if (balance > 1 && data > contact->left->data)
	{
		contact->left = leftRotate(contact->left);
		return rightRotate(contact);
	}

	// Right Left Case
	if (balance < -1 && data < contact->right->data)
	{
		contact->right = rightRotate(contact->right);
		return leftRotate(contact);
	}
	return contact;
}

//Xóa
NODE* find_minValue(NODE* node) {
	NODE* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}

NODE* deleteContact(NODE*& contact, int sdtData) {
	if (sdtData < contact->data)
		contact->left = deleteContact(contact->left, sdtData);
	else if (sdtData > contact->data)
		contact->right = deleteContact(contact->right, sdtData);
	else {
		if ((contact->left == NULL) || (contact->right == NULL)) {
			NODE* temp = contact->left ? contact->left : contact->right;
			if (temp == NULL) {
				temp = contact;
				contact = NULL;
			}
			else
				*contact = *temp;
			free(temp);
		}
		else {
			NODE* temp = find_minValue(contact->right);
			contact->data = temp->data;
			contact->right = deleteContact(contact->right, temp->data);
		}
	}
	if (contact == NULL)
		return contact;
	// Cập nhật hệ số cân bằng
	contact->height = 1 + max(height(contact->left),
		height(contact->right));
	int balance = balanceFactor(contact);
	if (balance > 1 && balanceFactor(contact->left) >= 0)
		return rightRotate(contact);

	if (balance > 1 && balanceFactor(contact->left) < 0) {
		contact->left = leftRotate(contact->left);
		return rightRotate(contact);
	}

	if (balance < -1 && balanceFactor(contact->right) <= 0)
		return leftRotate(contact);

	if (balance < -1 && balanceFactor(contact->right) > 0) {
		contact->right = rightRotate(contact->right);
		return leftRotate(contact);
	}
	return contact;
}

//Hàm duyệt data
void duyetContact(NODE* contact) {
	if (contact != NULL) {
		cout << contact->data << "\n";
		duyetContact(contact->left);
		duyetContact(contact->right);
	}
}


void timKiem(NODE* t, int x)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (x > t->data)
		{
			timKiem(t->right, x);
		}
		else if (x < t->data)
		{
			timKiem(t->left, x);
		}
		else
		{
			cout << "\n\t\t" << t->data << " ";
		}
	}
}


// tính thời gian trong Menu 
void Menu(NODE*& tree) {
	int luachon;
	while (true) {
		system("cls");
		cout << "\n\n\t\t===========================MENU==============================";
		cout << "\n\n\t\t1. Them";
		cout << "\n\n\t\t2. Xoa";
		cout << "\n\n\t\t3. Tim kiem";
		cout << "\n\n\t\t4. Xuat";
		cout << "\n\n\t\t===========================END==============================";

		cout << "\n\tNhap lua chon: ";
		cin >> luachon;
		if (luachon == 1) {
			double max = INT_MIN;
			double min = INT_MAX;
			double mean = 0;
			for (int i = 0; i < 10000; i++)
			{
				clock_t start, end;
				double cputime;
				start = clock();
				tree = insertData(tree, i);
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
				tree = deleteContact(tree, i);
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
		else if (luachon == 3) {
			double max = INT_MIN;
			double min = INT_MAX;
			double mean = 0;
			for (int i = 0; i < 1000; i++)
			{
				clock_t start, end;
				double cputime;
				start = clock();
				timKiem(tree, i);
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
			cout << "\n\n\t\t";
			duyetContact(tree);
			system("pause");
		}
	}
}

int main() {
	NODE* tree = NULL;
	Menu(tree);
}

