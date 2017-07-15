#include	<stdio.h>
#include	"enigma.h"

#define	BUFFER_SIZE 4096

/* Use: decrypt ['seed'] 'key' */
int main ( int argc, char **argv, char **envp )

{
   char *key = NULL;
   char *seed = NULL;
   int status = 1;	/* Assume the worst. */

   /* Use: decrypt 'seed' 'key' */
   if ( argc == 3 ) {

	seed = argv[1];
	key = argv[2];

   /* Use: decrypt 'key' */
   } else if ( argc == 2 ) key = argv [1];

   /* Oops! */
   else fprintf ( stderr, "Use: %s [seed] key\n", argv[0] );

   /* Okay to proceed. */
   if ( key ) {

	char	buffer [BUFFER_SIZE];
	int	buffSize;
	ENIGMA	*enigma;

	status = 0;	/* Okay, we're good. */

	/*
	 * If no seed was supplied, use the first 2 characters of the input
	 * as the seed.
	 */
	if ( argc == 2 ) {

		fread ( buffer, 1, 2, stdin );
		seed = buffer;
	}

	/*
	 * Set the initial position of the rotors, no need to get a random
	 * seed.
	 */
	if ( enigma = enigmaOpen ( key, strlen ( key ), seed, 4 ) ) {

		/*
		 * Read cipher text from stdin, decrypt it and write plain text
		 * to stdout.
		 */
		while ( ( buffSize = fread ( buffer, 1, BUFFER_SIZE, stdin ) )
									> 0 ) {

			fwrite ( enigmaDecrypt ( enigma, buffer, buffSize ),
							1, buffSize, stdout );
		}

		enigmaClose ( enigma );
	}
   }

   return ( status );
}
