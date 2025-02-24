#include "Arduino.h"
#include "drv_display7seg.h"


static int num;
static driver meu_display;
static ptrFuncDrv display_funcs[DISPLAY_END];
static byte displaySeteSeg[10][7] = { 
 
    { 1,1,1,1,1,1,0 },  //DIGITO 0
    { 0,1,1,0,0,0,0 },  //DIGITO 1
    { 1,1,0,1,1,0,1 },  //DIGITO 2
    { 1,1,1,1,0,0,1 },  //DIGITO 3
    { 0,1,1,0,0,1,1 },  //DIGITO 4
    { 1,0,1,1,0,1,1 },  //DIGITO 5
    { 1,0,1,1,1,1,1 },  //DIGITO 6
    { 1,1,1,0,0,0,0 },  //DIGITO 7
    { 1,1,1,1,1,1,1 },  //DIGITO 8
    { 1,1,1,1,0,1,1 }   //DIGITO 9
   
   };

char initDisplay(void * parameters) {
    pinMode(PORT_1, OUTPUT);
    pinMode(PORT_2, OUTPUT);
    pinMode(PORT_3, OUTPUT);
    pinMode(PORT_4, OUTPUT);
    pinMode(PORT_5, OUTPUT);
    pinMode(PORT_6, OUTPUT);
    pinMode(PORT_7, OUTPUT);
    pinMode(PORT_8, OUTPUT);
    meu_display.id = (char) parameters;
    
    // por padrão inicializa no botao 0 
    int num = 0;
    alternateDisplay(0);
    return SUCCESS;

}


char alternateDisplay(void * parameters) { 
    byte pino = 3;

    for (byte contadorSegmentos = 0; contadorSegmentos < 7; contadorSegmentos++){ 
        digitalWrite(pino, displaySeteSeg[digito][contadorSegmentos]);
        pino++; 
      }
}


driver * getLedDriver(void){
    meu_display.initFunc = initDisplay;
    my_funcs[DISPLAY_INIT] = initDisplay;
    my_funcs[DISPLAY_ALTERNATE] = alternateDisplay;
    meu_display.funcoes = my_funcs;
  
    return &meu_display;
  }
  


