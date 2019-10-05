#ifndef RACProtocol_h
#define RACProtocol_h

#include <Arduino.h>

class RACProtocol
{
private:
    String startMessage;
    String endMessage;
public:
    RACProtocol();
    String readInput();
    bool sendMessages(String * messagesToSend, int n_messages);
    bool sendMessage(String messageToSend);

};

#endif
