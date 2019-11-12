#include <Arduino.h>

#include "SerialProtocol.h"

SerialProtocol::SerialProtocol()
{
    startMessage = "startMessage";
    endMessage = "endMessage";
}

void SerialProtocol::sendMessages(String * messagesToSend, int n_messages){
  if(Serial.availableForWrite()>0){
    Serial.print(startMessage+";");
    for (int i = 0; i<n_messages; i++){
        Serial.print(messagesToSend[i]+";");
    }
    Serial.print(endMessage);

    delay(DALAY_BETWEEN_MESSAGES);

  }
}

void SerialProtocol::sendMessage(String messageToSend){
  
  String messageArray[1] = {messageToSend};
  sendMessages(messageArray, 1);
}

String SerialProtocol::readInput(){
    String input =  Serial.readString();
    input.trim();
    return input;
}
