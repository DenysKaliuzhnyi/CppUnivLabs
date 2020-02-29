//Автор - Калюжний Денис, К-13, Варіант 156
#include "Greenhouse_156.h"

Greenhouse_156::Greenhouse_156(): n_windows(3), n_heater(1)
{
	n_open = 0;
	n_heater_on = 0;
	t = 12.6;
	h = 34.2;
	keeper = true;
}

bool Greenhouse_156:: check_start() const
{
	return n_windows >= 0 && n_open >= 0 && n_open <= n_windows && n_heater >= 0
		&& n_heater_on >= 0 && n_heater_on <= n_heater && h > 0 && h < 100 && keeper;
}

Greenhouse_156::operator std::string()
{
	const unsigned int buffer_dim = 30;
	char buffer[buffer_dim];
	std::string s = "Cтан теплицi: ";
	if (keeper) s += "працює ";
	else s += "вийшла з ладу ";
	s += "\nКiлькiсть вiкон: ";
	s += std::to_string(n_windows);
	s += ", з них вiдкритих: ";
	s += std::to_string(n_open);
	s += "\nКiлькiсть обiгрiвачiв: ";
	s += std::to_string(n_heater);
	s += ", з них працює ";
	s += std::to_string(n_heater_on);
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

void Greenhouse_156::timeModel()
{
	if (keeper)
	{
		//вирази у випадках перемноження констант були спрощені 
		if (h < 45) t = t - 3*0.7 - n_open*0.9 + n_heater_on*2.3;
		else t = t - 3*0.6 - n_open*1.7 + n_heater_on*2.0 + h*0.01*1.0;
		h = h - (n_open - n_heater_on)*3.0;
	}
}

void Greenhouse_156::check_changes()
{
	if ((t < 1.2) || (t > 31.0 + h*0.7*0.01) || (h < 5.3) || (h > 89.8))
	{
		n_open = 0;
		n_heater_on = 0;
		keeper = false;
	}
}

bool Greenhouse_156::open() 
{
	if ((!keeper) || (n_open >= n_windows))  return false;
	n_open++;
	return true;
}
bool Greenhouse_156::close()
{
	if ((!keeper) || (n_open <= 0)) return false;
	n_open--;
	return true;
}
bool Greenhouse_156::heater_on()
{
	if ((!keeper) || (n_heater_on >= n_heater)) return false;
	n_heater_on++;
	return true;
}
bool Greenhouse_156::heater_off()
{
	if ((!keeper) || (n_heater_on <= 0)) return false;
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

