#if		!defined(_WIN32)
#  ident	"$Id: map257.h,v 1.1 2010/05/29 05:31:34 pwh Exp $"
#endif

/*
 *	Definitions for the enigma encryption process.
 *
 *	All input characters (e.g. 8 bit bytes) are encrypted, none are
 *	passed through as-is.
 */

#  define	MODULUS 257
#  define	MAP(x) (x)
#  define	UNMAP(x) (x)
