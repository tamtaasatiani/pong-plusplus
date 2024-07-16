#include "tahm/seek.h"

//#include "main.cpp"

Tahm tahm;


int main(int argc, char* argv[])
{
	
	memset(&tahm, 0, sizeof(Tahm));


	tahm.init();
	atexit(cleanup);

	while (1) tahm.loop();

	return 0;
	
}
