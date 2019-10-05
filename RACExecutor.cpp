#include "RACExecutor.h"

RACExecutor::RACExecutor(String aId, int n_max_pumps, RACProtocol* p ){
    max_pumps = n_max_pumps;
    arduinoId = aId;
    i_pumps = -1;
    protocol = p;
    pumps = (RACPump **) malloc (max_pumps*sizeof(RACPump));
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

void RACExecutor::processPlan(String plan){
    plan.replace("water:","");
    int i_first_comma = plan.indexOf(',');
    String pumpId = plan.substring(0,i_first_comma);
    int timeSeconds = plan.substring(i_first_comma+1).toInt();
    waterById(timeSeconds, pumpId);
    protocol->sendMessage("done:"+arduinoId+","+pumpId+","+timeSeconds);
 
}
