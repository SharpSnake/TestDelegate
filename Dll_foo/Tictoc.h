#ifndef _DLL_FOO_H
#define _DLL_FOO_H

#include <chrono>
#include <string>
#include <string_view>
#include "Export.h"

#ifdef _MSC_VER
#	pragma warning( disable:4251 )
#endif


namespace Dll::Foo	{
struct Time
{
	int	Hours{};
	int Seconds{};
	int Ms{};
};

class DLLFOO_DLL Tictoc
{
	using clock_type	= std::chrono::high_resolution_clock;

public:
	Tictoc( std::string_view s );

public:
	void Tic();
	Time Toc();

private:
	std::string				m_Name;
	clock_type::time_point	m_T0;
};
}
#endif // !_DLL_FOO_H