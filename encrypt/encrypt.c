#include	<stdio.h>
#include	"enigma.h"

#define	BUFFER_SIZE 4096

/* Use: encrypt ['seed'] 'key' */
int main ( int argc, char **argv, char **envp )

{
   char *key = NULL;
   char *seed = NULL;
   int status = 1;	/* Assume the worst. */

   /* Use: encrypt 'seed' 'key' */
   if ( argc == 3 ) {

	seed = argv[1];
	key = argv[2];

   /* Use: encrypt 'key' */
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
	 * Set the initial position of the rotors, get a random seed if none
	 * was supplied.
	 */
	if ( enigma = enigmaOpen ( key, strlen ( key ), seed, 4 ) ) {

		/*
		 * If no seed was supplied, write the seed to the output.
		 */
		if ( argc == 2 ) fwrite ( enigma->seed, 1, 2, stdout );

		/*
		 * Read plain text from stdin, encrypt it and write cipher text
		 * to stdout.
		 */
		while ( ( buffSize = fread ( buffer, 1, BUFFER_SIZE, stdin ) )
									> 0 ) {

			fwrite ( enigmaEncrypt ( enigma, buffer, buffSize ),
							1, buffSize, stdout );
		}

		enigmaClose ( enigma );
	}
   }

   return ( status );
}
