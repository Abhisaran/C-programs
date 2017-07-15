all: encrypt.exe decrypt.exe encrypt127.exe decrypt127.exe encrypt97.exe decrypt97.exe encrypt89.exe decrypt89.exe

encrypt.exe: encrypt.obj enigma.lib
	link /OUT:$@ encrypt.obj enigma.lib

encrypt127.exe: encrypt.obj enigma127.lib
	link /OUT:$@ encrypt.obj enigma127.lib

encrypt97.exe: encrypt.obj enigma97.lib
	link /OUT:$@ encrypt.obj enigma97.lib

encrypt89.exe: encrypt.obj enigma89.lib
	link /OUT:$@ encrypt.obj enigma89.lib

decrypt.exe: decrypt.obj enigma.lib
	link /OUT:$@ decrypt.obj enigma.lib

decrypt127.exe: decrypt.obj enigma127.lib
	link /OUT:$@ decrypt.obj enigma127.lib

decrypt97.exe: decrypt.obj enigma97.lib
	link /OUT:$@ decrypt.obj enigma97.lib

decrypt89.exe: decrypt.obj enigma89.lib
	link /OUT:$@ decrypt.obj enigma89.lib
