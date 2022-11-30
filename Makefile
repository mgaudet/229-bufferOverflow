overflow: bufferOverflow.c Makefile
	clang -m32 -z execstack -o overflow -g bufferOverflow.c 

spawn: spawn.c
	clang -o spawn spawn.c
