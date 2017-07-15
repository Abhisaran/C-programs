#if		!defined(_WIN32)
#  ident	"$Id: enigma.h,v 1.4 2013/02/27 02:47:43 pwh Exp $"
#endif

/*
 * Definitions for the enigma encryption processes.
 */


typedef struct {

	int		maxRotors;
	int		maxRings;
	unsigned char	*seed;
	int		rotors [1];

} ENIGMA;


/* Reentrant version of the enigma encryption engine. */
ENIGMA * enigmaOpen ( unsigned char *, int, unsigned char *, int );
#define enigmaClose(deadMeat)	free((void*)(deadMeat))
unsigned char * enigmaEncrypt ( ENIGMA *, unsigned char *, int );
unsigned char * enigmaDecrypt ( ENIGMA *, unsigned char *, int );

/* Compatibility with old (non-reentrant) version. */
unsigned char * setRotors ( unsigned char *, unsigned char * );
unsigned char * encrypt ( unsigned char *, int );
unsigned char * decrypt ( unsigned char *, int );
