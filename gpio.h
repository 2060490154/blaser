#ifndef GPIO_H
#define GPIO_H

#include <QWidget>
#include "jetsonGPIO.h"
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <cstdlib>

class GPIO
{
public:
    GPIO();
    int gpioGetValue ( jetsonGPIO gpio, unsigned int *value);
    int gpioSetDirection ( jetsonGPIO gpio, unsigned int out_flag );
    int gpioExport(jetsonGPIO gpio);
};

#endif // GPIO_H
