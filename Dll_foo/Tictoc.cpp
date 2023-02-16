#include "Tictoc.h"

using namespace std;
using namespace Dll::Foo;


Tictoc::Tictoc( string_view s )
	: m_Name( s )
{
	if( m_Name.starts_with( "watch" ) )
		m_T0 = clock_type::now();
}

void Tictoc::Tic()
{
	m_T0 = clock_type::now();
}

Time Tictoc::Toc()
{
	using namespace std::chrono;

	auto dur = clock_type::now() - m_T0;
	auto _seconds = duration_cast< seconds >( dur );
	auto _ms = duration_cast< milliseconds >( dur - _seconds );

	return { .Seconds = ( int )_seconds.count(), .Ms = ( int )_ms.count() };
}