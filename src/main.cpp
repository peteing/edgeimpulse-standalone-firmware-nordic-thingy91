#include <zephyr.h>
//#include "ei_run_classifier.h"
#include "numpy.hpp"
#include <sys/printk.h>
#include "ei_device_nordic_nrf91.h"
#include "ei_zephyr_flash_commands.h"
#include "ei_main.h"




int main(void)
{
   
    /* This is needed so that output of printf 
       is output immediately without buffering 
    */
    setvbuf(stdout, NULL, _IONBF, 0);

    /* Initialize board uart */
    if(uart_init() != 0){
        ei_printf("Init uart on board error occured\r\n");
    }

    /** Initialize development board LEDs */
    if(BOARD_ledInit() != 0){
        ei_printf("Init LEDs on board error occured\r\n");
    }

    /* Custom Additions for Buzzer and Button input */

    if(BOARD_buzInit()!=0){

        ei_printf("Init Buzzer on board error occured\r\n");
    }

    if(BOARD_btnInit() !=0){

        ei_printf("Init SW3 on board error occured\r\n");


    }

    /* Initialize Edge Impulse sensors and commands */
    ei_init();


    while(1){
     
     

    ei_main();
    }
}
