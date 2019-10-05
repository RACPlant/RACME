#include <Arduino.h>

#include "RACProtocol.h"

RACProtocol::RACProtocol()
{
    startMessage = "startMessage";
    endMessage = "endMessage";
}

bool RACProtocol::sendMessages(String * messagesToSend, int n_messages){
  if(Serial.availableForWrite()>0){
    Serial.println(startMessage);
    for (int i = 0; i<n_messages; i++){
        Serial.println(messagesToSend[i]);
    }
    Serial.println(endMessage);
    return true;
  }else{
    return false;  
  }
}

bool RACProtocol::sendMessage(String messageToSend){
  if(Serial.availableForWrite()>0){
    Serial.println(startMessage);
    Serial.println(messageToSend);
    Serial.println(endMessage);
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