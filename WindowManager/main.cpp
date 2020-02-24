#include <iostream>
#include <string> 
#include <sstream>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/FL_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Select_Browser.H>

int col_window = 0;
std::vector<Fl_Window*> windows;

/*Позаимствовал неплохие функции*/
template <typename T>
std::string toString(T val)
{
	std::ostringstream oss;
	oss << val;
	return oss.str();
}

template<typename T>
T fromString(const std::string& s)
{
	std::istringstream iss(s);
	T res;
	iss >> res;
	return res;
}

void new_window_button_click(Fl_Button *button, Fl_Select_Browser *flSelectWindow)
{
	if (button->value())
	{
		col_window++;
		std::string name_window = "window" + toString(col_window);
		windows.push_back(new Fl_Window(220, 200));
		windows[col_window - 1]->show();
		flSelectWindow->add(name_window.c_str(), 0);
	}
}

int main(int argc, char **argv)
{
	Fl_Window *Main_Window = new Fl_Window(220, 200);
	Fl_Select_Browser *flSelectWindow = new Fl_Select_Browser(20, 20, 90, 100, "Windows");
	Fl_Button *new_window_button = new Fl_Button(120, 20, 85, 25, "New window");
	new_window_button->callback((Fl_Callback *)new_window_button_click, flSelectWindow);
	new_window_button->when(FL_PUSH);
	Main_Window->show(argc, argv);

	while (Fl::wait())
	{
	}
	return 0;
}