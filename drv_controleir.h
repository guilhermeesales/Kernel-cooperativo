#ifndef DRV_CONTROLE_IR_H
	#define DRV_CONTROLE_IR_H
	#include "dd_types.h"
	#include "kernel.h"

  #define RECV_PIN 13

	//lista de funcoes do driver
	enum {
		IR_INIT, IR_RECEIVE, IR_END
	};

	//funcao de acesso ao driver
	driver * getIrDriver(void);
		
#endif
