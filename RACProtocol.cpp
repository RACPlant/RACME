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
  }
}

void RACProtocol::sendMessage(String messageToSend){
  
  String messageArray[1] = {messageToSend};
  sendMessages(messageArray, 1);
//  
//  if(Serial.availableForWrite()>0){
//    Serial.println(startMessage);
//    Serial.println(messageToSend);
//    Serial.println(endMessage);
//    return true;
//  }else{
//    return false;  
//  }
}

String RACProtocol::readInput(){
    String input =  Serial.readString();
    input.trim();
    return input;
}
