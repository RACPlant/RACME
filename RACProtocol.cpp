#include <Arduino.h>

#include "RACProtocol.h"

RACProtocol::RACProtocol()
{
    startMessage = "startMessage";
    endMessage = "endMessage";
}

void RACProtocol::sendMessages(String * messagesToSend, int n_messages){
  if(Serial.availableForWrite()>0){
    Serial.write(startMessage);
    for (int i = 0; i<n_messages; i++){
        Serial.write(messagesToSend[i]);
    }
    Serial.write(endMessage);
    return true;
  }else{
    return false;  
  }
}

void RACProtocol::sendMessage(String messageToSend){
  if(Serial.availableForWrite()>0){
    Serial.write(startMessage);
    Serial.write(messageToSend);
    Serial.write(endMessage);
    return true;
  }else{
    return false;  
  }
}

String RACProtocol::readInput(){
    String input =  Serial.readString();
    input.trim();
    return input;
}
