#if		!defined(_WIN32)
#  ident	"$Id: map89.h,v 1.2 2010/06/18 21:59:57 pwh Exp $"
#endif

/*
 *	Definitions for the enigma89 encryption process.
 *
 *	A subset of the printable ASCII charcters are encrypted, the rest
 *	are passed through as-is.  Printable ASCII character not encrypted
 *	are white space characters and '"', '%', '&', '\'', '\\' and '`';
 */

#  define	MODULUS 89
#  define	MAP(x) map89(x)
#  define	UNMAP(x) unmap89(x)
#  define	USE_MAP

int map89 ( unsigned int );
int unmap89 ( unsigned int );
