#ifndef DLLFOO_EXPORT_H
#define DLLFOO_EXPORT_H


#ifdef _MSC_VER
#	if defined( DLLFOO_EXPORT )
#		define DLLFOO_DLL __declspec(dllexport)
#	else
#		define DLLFOO_DLL __declspec(dllimport)
#	endif
#else
#	define DLLFOO_DLL
#endif

#endif // !DLLFOO_EXPORT_H