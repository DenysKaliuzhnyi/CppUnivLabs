//Автор - Калюжний Денис, К-13
#include "Container.h"
#include <ostream>
#include <exception>
#include "Functions.h"
using namespace std;


///////////////////////////////////////////////////////InvoicesList

void InvoicesList::add_product(const std::string &number, const std::string &product_name, double count, double price_per_1, double cost)
{
	std::vector<Invoice>::iterator it;
	bool u = false;
	for (it = begin(); it != end(); it++)
	{
		if (it->getNumber() == number)
		{
			it->add_product(product_name, count, price_per_1, cost);
			u = true;
			break;
		}
	}
	if (!u)
	{
		Invoice a(number);
		a.add_product(product_name, count, price_per_1, cost);
		invoiceList.push_back(a);
	}
}

unsigned InvoicesList::size() const
{
	return invoiceList.size();
}

bool InvoicesList::isEmpty() const
{
	return size() == 0;
}

void InvoicesList::erase()
{
	head = 0;
	foot1 = 0;
	foot2 = 0;
	invoiceList.clear();
}

double& InvoicesList::getHead()
{
	return head;
}

double& InvoicesList::getFoot1()
{
	return foot1;
}

double& InvoicesList::getFoot2()
{
	return foot2;
}

double InvoicesList::getHead() const
{
	return head;
}

double InvoicesList::getFoot1() const
{
	return foot1;
}

double InvoicesList::getFoot2() const
{
	return foot2;
}

std::vector<Invoice>::const_iterator InvoicesList::cend() const
{
	return invoiceList.end();
}

std::vector<Invoice>::const_iterator InvoicesList::cbegin() const
{
	return invoiceList.begin();
}

std::vector<Invoice>::iterator InvoicesList::end()
{
	return invoiceList.end();
}

std::vector<Invoice>::iterator InvoicesList::begin()
{
	return invoiceList.begin();
}

InvoicesList InvoicesList::sorList() const
{
	InvoicesList inL;
	inL = *this;
	for (vector<Invoice>::iterator it = inL.begin(); it != inL.end(); it++)
		sort(it->begin(), it->end());
	sort(inL.begin(), inL.end());
	return inL;
}

std::pair<Invoice, int> InvoicesList::findPopularProducts() const
{
	int count = 0;
	std::vector<Invoice>::const_iterator it1 = cbegin();
	for (std::vector<Invoice>::const_iterator it = cbegin(); it != cend(); it++)
	{
		if (it->findTopProductInInvoice().count > it1->findTopProductInInvoice().count)
		{
			if (it->findTopProductInInvoice() == it1->findTopProductInInvoice()) count++; //how to count invoices???
			it1 = it;
		}
	}
	return make_pair(*it1, 0); //return count as second param 
}

ostream& operator <<(ostream &f, const InvoicesList& inL)
{
	if (!inL.isEmpty())
	{
		f << "header:" << inL.getHead() << endl;
		int i = 1;
		for (auto it = inL.cbegin(); it != inL.cend(); it++)
		{
			f << i++ << ":";
			f << *it;
		}
		f << "footer:" << inL.getFoot1() << "<>" << inL.getFoot2() << endl;
	}
	return f;
}
/////////////////////////////////////////Invoice
Invoice::Invoice(const std::string& number) : number_(trim(number))
{
	isValidNumber(number_);
}

void Invoice::isValidNumber(const std::string &s)
{
	if (s.size() != 11) throw invalid_argument("The number [" + s + "] is invalid for invoice.\n");
}

std::string Invoice::getNumber() const
{
	return number_;
}

std::string& Invoice::getNumber()
{
	return number_;
}

double Invoice::getProductsCount() const
{
	return productList.size();
}

std::vector<Invoice::Product>::const_iterator Invoice::cbegin() const
{
	return productList.begin();
}

std::vector<Invoice::Product>::const_iterator Invoice::cend() const 
{
	return productList.end();
}

std::vector<Invoice::Product>::iterator Invoice::begin() 
{
	return productList.begin();
}

std::vector<Invoice::Product>::iterator Invoice::end() 
{
	return productList.end();
}

void Invoice::add_product(const std::string &product_name, double count, double price_per_1, double cost)
{
	Product a(product_name);
	a.add(round(count * 100) / 100, round(price_per_1 * 10000) / 10000, round(cost * 100) / 100);
	productList.push_back(a);
}

Invoice & Invoice::operator =(const Invoice &in)
{
	getNumber() = in.getNumber();
	productList = in.productList;
	return *this;
}

bool Invoice::operator <(const Invoice& in) const
{
	return trim(getNumber()) < trim(in.getNumber());
}

bool Invoice::Product::operator ==(const Invoice::Product &p)
{
	return trim(product_name_) == trim(p.product_name_);
}

Invoice::Product Invoice::findTopProductInInvoice() const
{
	std::vector<Invoice::Product>::const_iterator it1 = cbegin();
	for (std::vector<Invoice::Product>::const_iterator it = cbegin(); it != cend(); it++)
	{
		if (it->count > it1->count) { it1 = it; }
		if (it->product_name_ == it1->product_name_ && it->count == it1->count)
			if (it->price_per_1 > it1->price_per_1) 
				it1 = it; 
	}
	return *it1;
}

ostream& operator <<(ostream &f, const Invoice& in)
{
	const int last = in.getProductsCount();
	int i = 1;
	int counter = 1;
	bool isLast = false;
	f << in.getNumber() << "<>";
	for (auto it = in.cbegin(); it != in.cend(); it++, counter++)
	{
		if (last == i++) isLast = true;
		f << *it;
		if (counter != in.getProductsCount()) f << "<>";
	}
	f << endl;
	return f;
}

/////////////////////////////////////////////////////////////Product


Invoice::Product::Product(const std::string& product_name) : product_name_(trim(product_name))
{
	isValidProductName(product_name_);
}

void Invoice::Product::isValidProductName(const std::string& s)
{
	if (s.empty()) throw invalid_argument("The white name is invalid for product name.\n");
}

Invoice::Product & Invoice::Product::operator =(const Product &in)
{
	product_name_ = in.product_name_;
	count = in.count;
	price_per_1 = in.price_per_1;
	cost = in.cost;
	return *this;
}

void Invoice::Product::add(double count, double price_per_1, double cost)
{
	Product::count = count;
	Product::price_per_1 = price_per_1;
	Product::cost = cost;
}

bool Invoice::Product::operator <(const Product& p)
{
	if (trim(product_name_) != trim(p.product_name_)) return trim(product_name_) < trim(p.product_name_);
	if (count != p.count) return count < p.count;
	if (price_per_1 != p.price_per_1) return price_per_1 < p.price_per_1;
	return cost < p.cost;
}

ostream& operator <<(ostream &f, const Invoice::Product &pr)
{
	f << pr.product_name_ << "<>" << pr.count << "<>" << pr.price_per_1 << "<>" << pr.cost;
	return f;
}