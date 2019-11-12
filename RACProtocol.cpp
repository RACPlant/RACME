#include <Arduino.h>

#include "RACProtocol.h"

RACProtocol::RACProtocol()
{
    startMessage = "startMessage";
    endMessage = "endMessage";
}

void RACProtocol::sendMessages(String * messagesToSend, int n_messages){
  String message = startMessage+";";

  for (int i = 0; i<n_messages; i++){
        message += messagesToSend[i]+";";
    }

  message += endMessage;
  
  if(Serial.availableForWrite()>0){
    Serial.write(message.c_str());
    Serial.flush();
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
