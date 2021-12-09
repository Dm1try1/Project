#include "Product.h"
#include "ProductList.h"
#include "ProductInputScreen.h"
#include "UserInterface.h"


void getaLine(string& inStr) // ��������� ������ ������
{
	char temp[21];
	cin.get(temp, 20, '\n');
	cin.ignore(20, '\n'); //����� ������������ �������� � ������ ����������
	inStr = temp;
}
//---------------------------------------------------------
char getaChar() // ��������� �������
{
	char ch = cin.get();
	cin.ignore(80, '\n'); //����� ������������ �������� � ������ ����������
	return ch;
}
//---------------------------------------------------------
////////////////������ ������ Product///////////////////////
//� ������������ ����� ��������� ���������
Product::Product(string n, string n1, string n2, double aNo1, int aNo, double aNo2) : name(n), type(n1), material(n2), size(aNo1), number(aNo), price(aNo2)
{
	/* ��� ����� */
}
//---------------------------------------------------------
Product::~Product() // ����������
{
	/* ��� ���� ����� */
}
//---------------------------------------------------------
int Product::getAptNumber() //������ ���������� ���-�� �� ������
{
	return number;
}
double Product::getAptSize() //������ ���������� �������
{
	return size;
}
double Product::getAptPrice() //������ ���������� ����
{
	return price;
}
//--------------------------------------------------------
string Product::getName() //������ ���������� ��������
{
	return name;
}
string Product::getType() //������ ���������� ���
{
	return type;
}
string Product::getMaterial() //������ ���������� ��������
{
	return material;
}
///////////����� ������ ProducttInputScreen//////////////////
void ProductInputScreen::setProduct() // �������� ������ �� ���������
{

	cout << "������� �������� ���������: " << endl;
	getaLine(tName);
	cout << "������� ���: " << endl;
	getaLine(tType);
	cout << "������� ��������: " << endl;
	getaLine(tMaterial);
	cout << "������� ������: " << endl;
	cin >> tSize;
	cout << "������� ����������: " << endl;
	cin >> tNumber;
	cout << "������� ����: " << endl;
	cin >> tPrice;
	cin.ignore(80, '\n');
	Product* ptrProduct = new Product(tName, tType, tMaterial, tSize, tNumber, tPrice); // ������� ���������
	ptrProductList->add(ptrProduct); // ������� � ������ ���������
}
//---------------------------------------------------------
////////////////������ ������ ProductList///////////////////
ProductList::~ProductList() // ����������
{
	while (!setPtrsProd.empty()) // �������� ���� ���������,
	{ // �������� ���������� �� ����������
		iter = setPtrsProd.begin();
		delete* iter;
		setPtrsProd.erase(iter);
	}
}
//---------------------------------------------------------
void ProductList::add(Product* ptrT)
{
	setPtrsProd.push_back(ptrT); // ������� ������ ��������� � ������
}
//---------------------------------------------------------


void ProductList::display() // ����� ������ ���������
{
	cout << setw(22) << left << "�������� ���������"
		<< setw(8) << "���"
		<< setw(15) << "��������"
		<< setw(15) << "������"
		<< setw(22) << "���-�� �� ������"
		<< setw(22) << "����"
		<< endl;
	if (setPtrsProd.empty()) { // ���� ������ ��������� ����
		cout << "***��� ���������***\n" << endl; // ������� ������, ��� �� ����)
	}
	else
	{
		iter = setPtrsProd.begin();
		while (iter != setPtrsProd.end()) // ������������� ��� ���������
		{
			cout << setw(22) << left << (*iter)->getName()
				<< setw(8) << (*iter)->getType()
				<< setw(15) << (*iter)->getMaterial()
				<< setw(15) << (*iter)->getAptSize()
				<< setw(22) << (*iter)->getAptNumber()
				<< setw(22) << (*iter)->getAptPrice()
				<< endl;
			*iter++;
		}
	}
}
////////////////������ ������ userInterface//////////////
UserInterface::UserInterface()
{
	ptrProductList = new ProductList;

}
//---------------------------------------------------------
UserInterface::~UserInterface()
{
	delete ptrProductList;

}
//---------------------------------------------------------
void UserInterface::interact()
{
	while (true)
	{

		cout << "��� ����� ������ ������� '1', \n"
			<< "��� ������ ������ '2', \n"
			<< "��� ������ '0': \n";
		ch = getaChar();
		if (ch == '1') // ���� ������
		{
			cout << "������� ��� ���������� ��������� '3', \n";
			ch = getaChar();
			switch (ch)
			{
				//������ ����� ���������� ������ �� ����� ��
				//�������������
			case '3': ptrProductInputScreen =
				new ProductInputScreen(ptrProductList);
				ptrProductInputScreen->setProduct();
				delete ptrProductInputScreen;
				break;
			default: cout << "����������� �������\n";
				break;
			} // ����� ������ switch
		} // ����� ������� if
		else if (ch == '2') // ����� ������
		{

			cout << "������� ��� ������ ��������� '3', \n";
			ch = getaChar();
			switch (ch)
			{
			case '3': ptrProductList->display();
				break;
			default: cout << "����������� ������� ������\n";
				break;
			} // ����� switch
		} // ����� elseif
		else if (ch == '0')
			return; // �����
		else
			cout << "����������� �������. ��������� ������ '1', '2' ��� '0'\n";
	} // ����� while
}