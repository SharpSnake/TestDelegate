#include <iostream>
#include <string>
#include <thread>
#include <boost/version.hpp>
#include <boost/filesystem.hpp>

#include <Tictoc.h>
#include "Delegate.hpp"

using namespace std;
using namespace Meteora;


enum MouseButtons	{
	Left,
	Right
};

ostream& operator<<( ostream &os, const MouseButtons &btn )	{
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
			cout << "No delegates registered to ButtonClickEvent" << endl;
	}

private:
	void OnClickMyself( MouseButtons btn, int x, int y )	{
		cout<< "Btnitself CallBack,  " << btn << ":\t( " << x << ", " << y << " )" << endl;
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
		cout<< "Dialog CallBack1, " << btn << ":\t( " << x << ", " << y << " )" << endl;
	}

	// CallBack2 only call once.
	void m_Button_Click_CallBack2( MouseButtons btn, int x, int y )
	{
		cout<< "Dialog CallBack2, " << btn << ":\t( " << x << ", " << y << " )" << endl;
	}

	void m_Button_Click_CallBack3( MouseButtons btn, int x, int y )	{
		cout<< "Dialog CallBack3, " << btn << ":\t( " << x << ", " << y << " )" << endl;
	}

private:
	Button *m_Button;
};

void GlobalOnBtnClk( MouseButtons btn, int x, int y )	{
	cout << "Global CallBack, " << btn << ":\t" << x << "\t" << y << endl;
}


void Test_DialogBtnClick()
{
	Button *button = new Button();
	VDialog *dialog = new VDialog( button );


	// single delegate
	using MouseEventHandler = Delegate< void( MouseButtons, int, int ) >;

	MouseEventHandler singleCallBack = { &VDialog::m_Button_Click_CallBack2, dialog };
	singleCallBack = { &VDialog::m_Button_Click_CallBack1, dialog };
	singleCallBack = []( MouseButtons btn, int x, int y ){ cout << "single lambda\t" << x << "\t" << y << endl; };

	if( singleCallBack )
		singleCallBack( Left, 11, 55 );
	singleCallBack = nullptr;
	cout << endl;


	// MulticastDelegate
	button->MouseClick += GlobalOnBtnClk;
	button->MouseClick += []( MouseButtons btn, int x, int y ){ cout << "lambda Clk " << btn << "\t" << x << "\t" << y << endl; };
	button->DoClick( Left, 100, 300 );
	cout << endl;

	// remove some items from MulticastDelegate
	button->MouseClick -= { &VDialog::m_Button_Click_CallBack3, dialog };
	button->MouseClick -= GlobalOnBtnClk;
	button->MouseClick -= []( MouseButtons btn, int x, int y ){ cout << "lambda Clk " << btn << "\t" << x << "\t" << y << endl; };
	button->DoClick( Right, 500, 900 );
	cout << endl;

	button->MouseClick = nullptr;
	button->DoClick( Left, 1, 1 );
	cout << endl;

	delete dialog;
	delete button;
}

void Test_BoostDep( const char *arg1 )
{
	boost::filesystem::path p( arg1 ), name( p.filename() );

	cout << "dir " << boost::filesystem::canonical( p.parent_path() ) << " filename " << name << 
		" has stem " << name.stem() << " and extension " << name.extension() << "\n";
}


int main(int argc, char* argv[])
{
	Dll::Foo::Tictoc tt( "watch 1" );
	tt.Tic();

	Test_DialogBtnClick();
	this_thread::sleep_for( 1s );

	cout << endl << "Test boost" << "(" << BOOST_LIB_VERSION << ")" << " dependency:" << endl;
	Test_BoostDep( argv[ 0 ] );
	this_thread::sleep_for( 100ms );

	auto[ _h, _s, _ms ] = tt.Toc();
	cout << endl << "Total time: " << _s << " seconds and " << _ms << " milliseconds" << endl;
}