#include "HardwareSerial.h"
#include "Arduino.h"
#include "drv_controleir.h"
#include "IRremote.h"
#include "drv_led.h"


static driver meu_receptor_ir;
static ptrFuncDrv ir_funcs[IR_END];
IRrecv irrecv(RECV_PIN);
decode_results results; 
static driver * led;


char irInit(void * parameters) { 
  Serial.begin(115200);  // Establish serial communication
  irrecv.enableIRIn(); // Start the receiver
  led = getLedDriver();
  led->initFunc(0);
  Serial.println("IR driver initialized.");
  return SUCCESS;
}

char decodeIr(void * parameters) {
  results.value = 0;
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);  
    irrecv.resume();  
  }
  
  switch(results.value) {
    case 0xFFA25D: 
      Serial.println("Entrei no botão 1");
      led->funcoes[LED_ON](12);
      return SUCCESS;
      break;
    case 0xFF629D: 
      Serial.println("Entrei no botão 2");
      led->funcoes[LED_OFF](12);
      return SUCCESS;
      break;
    default:
      break;
  }

  return FAIL;
}

driver * getIrDriver(void) {
  
	meu_receptor_ir.initFunc = irInit;
	ir_funcs[IR_INIT] = irInit;
	ir_funcs[IR_RECEIVE] = decodeIr;
	meu_receptor_ir.funcoes = ir_funcs;
	
	return &meu_receptor_ir;
}
