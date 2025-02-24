#ifndef DRV_DISPLAY_7_SEG
    #define DRV_DISPLAY_7_SEG
    #include "dd_types.h"
    #include "kernel.h"

    #define PORT_1 3
    #define PORT_2 4
    #define PORT_3 5
    #define PORT_4 6
    #define PORT_5 7
    #define PORT_6 8
    #define PORT_7 9
    #define PORT_8 10

    enum {
		DISPLAY_INIT, DISPLAY_ALTERNATE, DISPLAY_END
	};

    driver * getDisplayDriver(void);


#endif