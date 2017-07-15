#if		!defined(_WIN32)
#  ident	"$Id: map97.h,v 1.1 2010/05/29 05:32:48 pwh Exp $"
#endif

/*
 *	Definitions for the enigma97 encryption process.
 *
 *	The printable ASCII charcters plus space and tab are encrypted, the
 *	rest are passed through as-is.
 */

#  define	MODULUS 97
#  define	MAP(x) map97(x)
#  define	UNMAP(x) unmap97(x)
#  define	USE_MAP

int map97 ( unsigned int );
int unmap97 ( unsigned int );
