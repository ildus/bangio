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
	pinno[PIN_SCK] = 14;
	pinno[PIN_MOSI] = 15;
	pinno[PIN_MISO] = 16;
	pinno[PIN_SS] = 10;

	linuxgpio_init(&ctrl, pinno);
	ctrl.open(&ctrl);
	while (!stop)
	{
		ctrl.begin(&ctrl);
		ctrl.cmd(&ctrl, buf, res);
		ctrl.end(&ctrl);
		for (int i=0; i < 4; i++)
			printf("%d\n", res[i]);
		sleep(1);
	}
	ctrl.close(&ctrl);
}
