#ifndef SerialProtocol_h
#define SerialProtocol_h

#include <Arduino.h>

const int DALAY_BETWEEN_MESSAGES=500;


class SerialProtocol
{
private:
    String startMessage;
    String endMessage;
public:
    SerialProtocol();
    String readInput();
    void sendMessages(String * messagesToSend, int n_messages);
    void sendMessage(String messageToSend);

};

#endif
