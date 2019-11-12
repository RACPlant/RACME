#include <Arduino.h>

#include "RACProtocol.h"

RACProtocol::RACProtocol()
{
    startMessage = "startMessage";
    endMessage = "endMessage";
}

void RACProtocol::sendMessages(String * messagesToSend, int n_messages){
  if(Serial.availableForWrite()>0){
    Serial.print(startMessage+";");
    for (int i = 0; i<n_messages; i++){
        Serial.print(messagesToSend[i]+";");
    }
    Serial.print(endMessage);

    delay(DALAY_BETWEEN_MESSAGES);

  }
}

void RACProtocol::sendMessage(String messageToSend){
  
  String messageArray[1] = {messageToSend};
  sendMessages(messageArray, 1);
}

String RACProtocol::readInput(){
    String input =  Serial.readString();
    input.trim();
    return input;
}
