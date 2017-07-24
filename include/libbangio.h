#ifndef libbangio_h
#define libbangio_h

enum PINFUNC
{
	PIN_SCK,
	PIN_MISO,
	PIN_MOSI,
	PIN_SS,
	N_PINS
};

typedef struct ioctrl_t
{
	enum PINFUNC pinno[N_PINS];
	int  (*open)			(struct ioctrl_t *ctrl);
	void (*close)			(struct ioctrl_t *ctrl);
	void (*begin)			(struct ioctrl_t *ctrl);
	void (*end)				(struct ioctrl_t *ctrl);
	int  (*setpin)			(struct ioctrl_t *ctrl, int pinfunc, int value);
	int  (*getpin)			(struct ioctrl_t *ctrl, int pinfunc);
	int  (*cmd)				(struct ioctrl_t *ctrl, const unsigned char *cmd,
								unsigned char *res);
	int  (*highpulsepin)	(struct ioctrl_t *ctrl, int pinfunc);
} IOCtrl;

void linuxgpio_init(IOCtrl *ctrl, enum PINFUNC *pinno);

#endif
