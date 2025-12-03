#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include <RH_ASK.h>

class Transmitter {
public:
    Transmitter();
    void initialize();
    void sendMessage();

private:
    RH_ASK rf_driver;
};

#endif
