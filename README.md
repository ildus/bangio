# bangio

This library could be used for bit banging devices through `/sys/class/gpio` interface. I use it to implement SPI protocol between Orange PI (Banana PI) and USI in `attiny24a`.

# Installation

```
mkdir build && cd build
cmake ..
make
sudo make install
```

# Using

Take a look at `test.c`.
