#include <iostream>
#include <string>

#include "Delegate.hpp"

using namespace std;
using namespace Meteora;


enum MouseButtons	{
	Left,
	Right
};

inline std::ostream& operator<<( std::ostream &os, const MouseButtons &btn )	{
	switch ( btn )
	{
	case Left:
		os << "Left Button";	break;
	case Right:
		os << "Right Button";	break;
	}
	return os;
}


class Button
{
public:
	Button()
		: MouseClick{ &Button::OnClickMyself, this }	{}
	
	~Button()	{ MouseClick = nullptr; }	// you can do this, but it's not necessary

public:
	MulticastDelegate< void( MouseButtons, int, int ) > MouseClick;

public:
	void DoClick( MouseButtons btn, int x, int y )	{
		if( MouseClick )
			MouseClick( btn, x, y );
		else
			std::cout << "No delegates registered to ButtonClickEvent" << std::endl;
	}

private:
	void OnClickMyself( MouseButtons btn, int x, int y )	{
		std::cout<< "Btnitself CallBack,  " << btn << ":\t( " << x << ", " << y << " )" << std::endl;
	}
};


class VDialog
{
public:
	VDialog( Button *button )
		: m_Button( button )
	{
		m_Button->MouseClick += { &VDialog::m_Button_Click_CallBack1, this };
		m_Button->MouseClick += { &VDialog::m_Button_Click_CallBack2, this };
		m_Button->MouseClick += { &VDialog::m_Button_Click_CallBack3, this };
	}

public:
	void m_Button_Click_CallBack1( MouseButtons btn, int x, int y )	{
		std::cout<< "Dialog CallBack1, " << btn << ":\t( " << x << ", " << y << " )" << std::endl;
	}

	// CallBack2 only call once.
	void m_Button_Click_CallBack2( MouseButtons btn, int x, int y )
	{
		std::cout<< "Dialog CallBack2, " << btn << ":\t( " << x << ", " << y << " )" << std::endl;
		m_Button->MouseClick -= { &VDialog::m_Button_Click_CallBack2, this };
	}

	void m_Button_Click_CallBack3( MouseButtons btn, int x, int y )	{
		std::cout<< "Dialog CallBack3, " << btn << ":\t( " << x << ", " << y << " )" << std::endl;
	}

private:
	Button *m_Button;
};

void GlobalOnBtnClk( MouseButtons btn, int x, int y )	{
	std::cout << "Global CallBack, " << btn << ":\t" << x << "\t" << y << std::endl;
}


void Test_DialogBtnClick()
{
	Button *button = new Button();
	VDialog *dialog = new VDialog( button );


	// single delegate
	using MouseEventHandler = Delegate< void( MouseButtons, int, int ) >;

	MouseEventHandler singleCallBack = { &VDialog::m_Button_Click_CallBack2, dialog };
	singleCallBack = { &VDialog::m_Button_Click_CallBack1, dialog };
	singleCallBack = []( MouseButtons btn, int x, int y ){ std::cout << "single lambda\t" << x << "\t" << y << std::endl; };

	if( singleCallBack )
		singleCallBack( Left, 11, 55 );
	singleCallBack = nullptr;
	std::cout << std::endl;

	
	// MulticastDelegate
	button->MouseClick += GlobalOnBtnClk;
	button->MouseClick += []( MouseButtons btn, int x, int y ){ std::cout << "lambda Clk " << btn << "\t" << x << "\t" << y << std::endl; };
	button->DoClick( Left, 100, 300 );
	std::cout << std::endl;

	// remove some items from MulticastDelegate
	button->MouseClick -= { &VDialog::m_Button_Click_CallBack3, dialog };
	button->MouseClick -= GlobalOnBtnClk;
	button->MouseClick -= []( MouseButtons btn, int x, int y ){ std::cout << "lambda Clk " << btn << "\t" << x << "\t" << y << std::endl; };
	button->DoClick( Right, 500, 900 );
	std::cout << std::endl;

	button->MouseClick = nullptr;
	button->DoClick( Left, 1, 1 );
	std::cout << std::endl;

	delete dialog;
	delete button;
}


int main(int argc, char* argv[])
{
	while( 1 )
		Test_DialogBtnClick();
}
