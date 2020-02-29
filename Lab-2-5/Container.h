//јвтор -  алюжний ƒенис,  -13
#pragma once
#include <string>
#include <vector>
#include <ios>
#include <algorithm>

class Invoice;

class InvoicesList
{
public:
	InvoicesList() = default;

	//return sorted list (B3)
	InvoicesList sorList() const;

	//return invoise where TOP product is located and count of invoices where top product is located too (B4)
	std::pair<Invoice, int> findPopularProducts() const;

	bool isEmpty() const;

	void erase();

	//Getters
	std::vector<Invoice>::const_iterator cbegin() const;
	std::vector<Invoice>::const_iterator cend() const;
	std::vector<Invoice>::iterator begin();
	std::vector<Invoice>::iterator end();
	double& getHead();
	double& getFoot1();
	double& getFoot2();
	double getHead() const;
	double getFoot1() const;
	double getFoot2() const;
	unsigned size() const;

	void add_product(const std::string &number, const std::string &product_name, double count, double price_per_1, double cost);
	//если нету такой накладной создаем новую и добавл€ем продукт или добавл€ем продукт в сущ накладную
private:
	double head = 0, foot1 = 0, foot2 = 0; //значени€ в заголовке и колонтитуле
	std::vector <Invoice> invoiceList;
};
std::ostream& operator <<(std::ostream &f, const InvoicesList& inL);

class Invoice
{
public:
	struct Product;

	explicit Invoice(const std::string &number);  //throw invalid_argument if not valid name  
	Invoice & operator =(const Invoice &in);
	Invoice & operator =(Invoice &&in) = default;
	Invoice(const Invoice&) = default;
	Invoice(Invoice&&) = default;
	~Invoice() = default;

	//return TOP product in invoice (B3)
	Invoice::Product findTopProductInInvoice() const;

	bool operator <(const Invoice& in) const;

	//Getters
	std::vector<Invoice::Product>::const_iterator cbegin() const;
	std::vector<Invoice::Product>::const_iterator cend() const;
	std::vector<Invoice::Product>::iterator begin();
	std::vector<Invoice::Product>::iterator end();
	std::string getNumber() const;
	std::string& getNumber();
	double getProductsCount() const;
 
	void add_product(const std::string &product_name, double count, double price_per_1, double cost);
	//добавл€ем продукт с нужным названием, вызываем метод add класса Product чтобы добавить его характеристики
private:
	void isValidNumber(const std::string &s);
	std::string number_; //const
	std::vector<Product> productList;
};
std::ostream& operator <<(std::ostream &f, const Invoice& il);


struct Invoice::Product
{
	Product() = default;
	explicit Product(const std::string& product_name); //throw(invalid_argument)   
	Product(const Product&) = default;
	Product(Product&&) = default;
	Product & operator =(const Product &in);
	Product & operator =(Product &&in) = default;
	~Product() = default;

	bool operator <(const Product& p);
	bool operator ==(const Product &p);

	void isValidProductName(const std::string& product_name); //throw(invalid_argument) 

	void add(double count, double price_per_1, double cost);

	std::string product_name_ = ""; 
	double count = 0;
	double price_per_1 = 0;
	double cost = 0;
};
std::ostream& operator <<(std::ostream &f, const Invoice::Product &pr);
