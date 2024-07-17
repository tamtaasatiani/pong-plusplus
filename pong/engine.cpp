#include "tahm/seek.h"

//#include "main.cpp"

Tahm tahm;


int main(int argc, char* argv[])
{
	
	memset(&tahm, 0, sizeof(Tahm));


	tahm.init();

	while (tahm.running) tahm.loop();

	tahm.destroy();

	return 0;
	
}


