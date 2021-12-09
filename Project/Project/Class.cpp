#include "Product.h"
#include "ProductList.h"
#include "ProductInputScreen.h"
#include "UserInterface.h"


void getaLine(string& inStr) // получение строки текста
{
	char temp[21];
	cin.get(temp, 20, '\n');
	cin.ignore(20, '\n'); //число пропускаемых символов и символ разделения
	inStr = temp;
}
//---------------------------------------------------------
char getaChar() // получение символа
{
	char ch = cin.get();
	cin.ignore(80, '\n'); //число пропускаемых символов и символ разделения
	return ch;
}
//---------------------------------------------------------
////////////////методы класса Product///////////////////////
//в конструкторе задаём параметры украшений
Product::Product(string n, string n1, string n2, double aNo1, int aNo, double aNo2) : name(n), type(n1), material(n2), size(aNo1), number(aNo), price(aNo2)
{
	/* тут пусто */
}
//---------------------------------------------------------
Product::~Product() // деструктор
{
	/* тут тоже пусто */
}
//---------------------------------------------------------
int Product::getAptNumber() //геттер возвращает кол-во на складе
{
	return number;
}
double Product::getAptSize() //геттер возвращает нразмер
{
	return size;
}
double Product::getAptPrice() //геттер возвращает цену
{
	return price;
}
//--------------------------------------------------------
string Product::getName() //геттер возвращает название
{
	return name;
}
string Product::getType() //геттер возвращает тип
{
	return type;
}
string Product::getMaterial() //геттер возвращает материал
{
	return material;
}
///////////метод класса ProducttInputScreen//////////////////
void ProductInputScreen::setProduct() // добавить данные об украшении
{

	cout << "Введите название украшения: " << endl;
	getaLine(tName);
	cout << "Введите тип: " << endl;
	getaLine(tType);
	cout << "Введите материал: " << endl;
	getaLine(tMaterial);
	cout << "Введите размер: " << endl;
	cin >> tSize;
	cout << "Введите количество: " << endl;
	cin >> tNumber;
	cout << "Введите цену: " << endl;
	cin >> tPrice;
	cin.ignore(80, '\n');
	Product* ptrProduct = new Product(tName, tType, tMaterial, tSize, tNumber, tPrice); // создать украшение
	ptrProductList->add(ptrProduct); // занести в список украшений
}
//---------------------------------------------------------
////////////////методы класса ProductList///////////////////
ProductList::~ProductList() // деструктор
{
	while (!setPtrsProd.empty()) // удаление всех украшений,
	{ // удаление указателей из контейнера
		iter = setPtrsProd.begin();
		delete* iter;
		setPtrsProd.erase(iter);
	}
}
//---------------------------------------------------------
void ProductList::add(Product* ptrT)
{
	setPtrsProd.push_back(ptrT); // вставка нового украшения в список
}
//---------------------------------------------------------


void ProductList::display() // вывод списка украшений
{
	cout << setw(22) << left << "Название украшения"
		<< setw(8) << "Тип"
		<< setw(15) << "Материал"
		<< setw(15) << "Размер"
		<< setw(22) << "Кол-во на складе"
		<< setw(22) << "Цена"
		<< endl;
	if (setPtrsProd.empty()) { // если список украшений пуст
		cout << "***Нет украшений***\n" << endl; // выводим запись, что он пуст)
	}
	else
	{
		iter = setPtrsProd.begin();
		while (iter != setPtrsProd.end()) // распечатываем все украшения
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
////////////////методы класса userInterface//////////////
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

		cout << "Для ввода данных нажмите '1', \n"
			<< "Для вывода отчета '2', \n"
			<< "Для выхода '0': \n";
		ch = getaChar();
		if (ch == '1') // ввод данных
		{
			cout << "Нажмите для добавления украшения '3', \n";
			ch = getaChar();
			switch (ch)
			{
				//экраны ввода существуют только во время их
				//использования
			case '3': ptrProductInputScreen =
				new ProductInputScreen(ptrProductList);
				ptrProductInputScreen->setProduct();
				delete ptrProductInputScreen;
				break;
			default: cout << "Неизвестная функция\n";
				break;
			} // конец секции switch
		} // конец условия if
		else if (ch == '2') // вывод данных
		{

			cout << "Нажмите для вывода украшений '3', \n";
			ch = getaChar();
			switch (ch)
			{
			case '3': ptrProductList->display();
				break;
			default: cout << "Неизвестная функция вывода\n";
				break;
			} // конец switch
		} // конец elseif
		else if (ch == '0')
			return; // выход
		else
			cout << "Неизвестная функция. Нажимайте только '1', '2' или '0'\n";
	} // конец while
}