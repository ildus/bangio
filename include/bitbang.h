#ifndef bitbang_h
#define bitbang_h

#include "libbangio.h"

int bitbang_cmd(IOCtrl *ctrl, const unsigned char *cmd, unsigned char *res);
void bitbang_init(IOCtrl *ctrl);
void bitbang_begin(IOCtrl *ctrl);
void bitbang_end(IOCtrl *ctrl);

#endif
