#include "drv_led.h"

static driver meu_cartao;

static ptrFuncDrv my_funcs[LED_END];

char changePORT(void * parameters){
	
	return SUCCESS;
}

char inverte (void * parameters){
	
	return SUCCESS;
}

char initGenerico(void * parameters){
	
	meu_cartao.id = (char) parameters;
	return SUCCESS;
}

driver * getLedDriver(void){
	
	return &meu_cartao;
}
