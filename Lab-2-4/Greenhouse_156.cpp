//Автор - Калюжний Денис, К-13, Варіант 156
#include "Greenhouse_156.h"
using namespace std;

//--------------------------------------------------
//---------------BASE-Greenhouse--------------------
//--------------------------------------------------

Greenhouse_156::Greenhouse_156(int n_windows_, int n_open, int n_heater_, int n_heater_on, double t, double h): n_windows(n_windows_), n_heater(n_heater_)
{
	this->n_open = n_open;
	this->n_heater_on = n_heater_on;
	this->t = t;
	this->h = h;
	this->keeper = true;
}

Greenhouse_156::operator string() const
{
	const unsigned buffer_dim = 30;
	char buffer[buffer_dim];
	string s = "Cтан теплицi ";
	s += name();
	s += ": ";
	if (keeper) s += "працює ";
	else s += "вийшла з ладу ";
	s += "\nКiлькiсть вiкон: ";
	s += to_string(n_windows);
	s += ", з них вiдкритих: ";
	s += to_string(n_open);
	s += "\nКiлькiсть обiгрiвачiв: ";
	s += to_string(n_heater);
	s += ", з них працює ";
	s += to_string(n_heater_on);
	s += "\nТемпература: ";
	//to_string(double) виводить багато нулів, тому використано sprintf_s
	sprintf_s(buffer, "%.1f", t);
	s += buffer;
	s += "°C\nВологiсть: ";
	sprintf_s(buffer, "%.1f", h);
	s += buffer;
	s += "%";
	return s;
}

void Greenhouse_156::time_model()
{
	if (keeper)
	{
		change_climate();
		check_changes();
	}
}

bool Greenhouse_156::open()
{
	if ((!keeper) || (n_open == n_windows))  return false;
	n_open++;
	return true;
}
bool Greenhouse_156::close()
{
	if ((!keeper) || (n_open == 0)) return false;
	n_open--;
	return true;
}
bool Greenhouse_156::heater_on()
{
	if ((!keeper) || (n_heater_on == n_heater)) return false;
	n_heater_on++;
	return true;
}
bool Greenhouse_156::heater_off()
{
	if ((!keeper) || (n_heater_on == 0)) return false;
	n_heater_on--;
	return true;
}


int Greenhouse_156::get_n_windows() const
{
	return n_windows;
}
int Greenhouse_156::get_n_open() const
{
	return n_open;
}
int Greenhouse_156::get_n_heater() const
{
	return n_heater;
}
int Greenhouse_156::get_n_heater_on() const
{
	return n_heater_on;
}
double Greenhouse_156::get_t() const
{
	return t;
}
double Greenhouse_156::get_h() const
{
	return h;
}
bool Greenhouse_156::get_keeper() const
{
	return keeper;
}

//--------------------------------------------------
//-------------------Greenhouse1--------------------
//--------------------------------------------------

//порядок аргументів відповідає: Greenhouse_156(n_windows, n_open, n_heater, n_heater_on, t, h)
Greenhouse1_156::Greenhouse1_156() :Greenhouse_156(3, 0, 1, 0, 12.6, 34.2){}

void Greenhouse1_156::change_climate()
{
	if (h < 45) t = t - 2.1 - n_open * 0.9 + n_heater_on * 2.3;
	else t = t - 1.8 - n_open * 1.7 + n_heater_on * 2.0 + h * 0.01;
	h = h - (n_open - n_heater_on)*3.0;
}

void Greenhouse1_156::check_changes()
{
	if ((t < 1.2) || (t > 31.0 + h * 0.007) || (h < 5.3) || (h > 89.8)) set_crash();
}

void Greenhouse1_156::set_crash()
{
	n_open = 0;
	n_heater_on = 0;
	keeper = false;
}

string Greenhouse1_156::name() const
{
	return "Greenhouse 1";
}

//--------------------------------------------------
//-------------------Greenhouse2--------------------
//--------------------------------------------------

//порядок аргументів відповідає: Greenhouse_156(n_windows, n_open, n_heater, n_heater_on, t, h)
Greenhouse2_156::Greenhouse2_156() :Greenhouse_156(3, 3, 1, 0, 10.9, 48.6){}

void Greenhouse2_156::change_climate()
{
	double t_old = t;
	if (h < 30) t = t - 3 * 0.55 - n_open * n_open * 1.7 + n_heater_on * 1.8;
	else t = t - 3 * 0.95 - n_open * 1.5 + n_heater_on * 2.6 - h * 0.01*1.4;
	if (t_old > 16.0)	h = h - log(abs(n_open - n_heater_on) + 1) *4.9; 
	else h = h + (n_open + n_heater_on)*3.7;
}

void Greenhouse2_156::check_changes()
{
	if ((t < 3.0) || (t > 29.0 + sqrt(h)*0.01) || (h < 6.8) || (h > 84.9 - t * 0.1)) set_crash();
}

void Greenhouse2_156::set_crash()
{
	n_open = 3;
	n_heater_on = 0;
	keeper = false;
}

string Greenhouse2_156::name() const
{
	return "Greenhouse 2";
}