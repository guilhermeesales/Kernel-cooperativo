#include <TimerOne.h>
#include "kernel.h"
#include "drv_controleir.h"
#include "drv_led.h"
#include "drv_display7seg.h"

driver *led;
driver *ir_driver;
driver *display_driver;

void setup() {
  //declara os processos
  process p1 = {readDisplay,1,0};
  //process p2 = {tst1,5,0};

  
  //Inicializa Drivers
  led = getLedDriver();
  led->initFunc(0);

  ir_driver = getIrDriver();
  ir_driver->initFunc(0);

  display_driver = getDisplayDriver();
  display_driver->initFunc(0);

  //inicialização dos periféricos
  Serial.begin(9600);
    
  kernelInit();
  
  //adição dos processos no kernel
  if (kernelAddProc(&p1) == SUCCESS) {
    Serial.println("1st process added\n");}
  // if (kernelAddProc(&p2) == SUCCESS) {
  //   Serial.println("2st process added\n");
  // }

  
  //setup do tempo do tick (microsegundos)
  Timer1.initialize(1000000);
  //Defenir função que executa na interrupção de Timer
  Timer1.attachInterrupt(tick);

  //execução do kernel
  kernelLoop();

}

void tick(){
  kernelTick();  
}

unsigned int vled = 0;
char tst1(void){
  vled++;
  if (vled % 2 == 0) {
    led->funcoes[LED_ON](10);  // Liga o LED
    led->funcoes[LED_ON](11); 

  } else {
    led->funcoes[LED_OFF](10);  // Desliga o LED
    led->funcoes[LED_OFF](11);
  }


  return REPEAT;


}

char readIr(void) {
  if (ir_driver->funcoes[IR_RECEIVE](NULL) == SUCCESS) {
    Serial.println("IR Code received");
  }
  return REPEAT;  
}

int num = 0;

char readDisplay(void) {
  Serial.println(num);
  
  // Pass 'num' as byte, not as void pointer
  display_driver->funcoes[DISPLAY_ALTERNATE]((void*) num); 
  
  num++;

  if (num == 10) {
    num = 0;
  } 

  return REPEAT;

}



void loop() {}