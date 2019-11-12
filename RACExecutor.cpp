#include "RACExecutor.h"

RACExecutor::RACExecutor(String aId, RACProtocol* p ){
    arduinoId = aId;
    i_pumps = -1;
    protocol = p;
}

void RACExecutor::addPump(RACPump *p){
    i_pumps ++;
    pumps[i_pumps] = p;
}

RACPump* RACExecutor::findPumpById(String id){
    for(int i = 0; i<=i_pumps; i++){
        if(pumps[i]->pumpId == id){
            return pumps[i];
        }
    }

}

void RACExecutor::waterById(int timeSeconds, String pump){
    RACPump* p = findPumpById(pump);
    p->water(timeSeconds);
}

void RACExecutor::listPumps(){
  String messages[i_pumps+1];
  for(int i=0;i<=i_pumps;i++){
    messages[i]=  pumps[i]->pumpId;
  }
  protocol->sendMessages(messages,i_pumps+1);
}

void RACExecutor::processPlan(String plan){
//  water:pump_id:time
    plan.replace("water:","");
    int i_first_comma = plan.indexOf(',');
    String pumpId = plan.substring(0,i_first_comma);
    int timeSeconds = plan.substring(i_first_comma+1).toInt();
    waterById(timeSeconds, pumpId);
    protocol->sendMessage(arduinoId+","+pumpId+","+timeSeconds);
 
}
