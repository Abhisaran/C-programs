#if		!defined(_WIN32)
#  ident	"$Id: map127.h,v 1.1 2010/05/29 05:33:19 pwh Exp $"
#endif

/*
 *	Definitions for the enigma127 encryption process.
 *
 *	All ASCII charcters except NUL (0) and DEL (7F) are encrypted, the
 *	rest are passed through as-is.
 */

#  define	MODULUS 127
#  define	MAP(x) map127(x)
#  define	UNMAP(x) unmap127(x)
#  define	USE_MAP

int map127 ( unsigned int );
int unmap127 ( unsigned int );
