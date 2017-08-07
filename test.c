#include "bitbang.h"
#include "linuxgpio.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int stop = 0;

void int_handler(int dummy)
{
	stop = 1;
}

int main(void)
{
	enum PINFUNC pinno[N_PINS];
	unsigned char buf[4], res[4];
	IOCtrl ctrl;

	signal(SIGINT, int_handler);
	pinno[PIN_SCK] = 66;
	pinno[PIN_MOSI] = 64;
	pinno[PIN_MISO] = 65;
	pinno[PIN_SS] = 68;

	linuxgpio_init(&ctrl, pinno);
	ctrl.open(&ctrl);
	while (!stop)
	{
		ctrl.begin(&ctrl);
		ctrl.cmd(&ctrl, buf, res);
		for (int i=0; i < 4; i++)
			printf("%d\n", res[i]);
		ctrl.end(&ctrl);
		sleep(1);
	}
	ctrl.close(&ctrl);
}
