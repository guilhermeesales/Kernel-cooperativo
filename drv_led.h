#ifndef DRV_LED_H
	#define DRV_LED_H
	#include "dd_types.h"
	#include "kernel.h"
	#include <avr/io.h>
	
	//lista de fun��es do driver
	enum {
		
		LED_SET, LED_FLIP, LED_END
	};
	
	//fun��o de acesso ao driver
	
	driver * getLedDriver(void);
		
	
#endif
