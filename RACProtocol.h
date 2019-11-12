#ifndef RACProtocol_h
#define RACProtocol_h

#include <Arduino.h>

const int DALAY_BETWEEN_MESSAGES=1000;


class RACProtocol
{
private:
    String startMessage;
    String endMessage;
public:
    RACProtocol();
    String readInput();
    void sendMessages(String * messagesToSend, int n_messages);
    void sendMessage(String messageToSend);

};

#endif
