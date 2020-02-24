#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/FL_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Input_Choice.H>

int main(int argc, char **argv)
{
	Fl_Window *Flwindow = new Fl_Window(1030, 620);
	Fl_Box *lblMoveCamera = new Fl_Box(860, 20, 90, 20, "Moving camera");
	lblMoveCamera->labelsize(12);
	Flwindow->show(argc, argv);

	while (Fl::wait())
	{
	}
	return 0;
}