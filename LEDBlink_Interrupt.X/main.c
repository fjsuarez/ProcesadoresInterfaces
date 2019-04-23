/*
 * File:   main.c
 * Author: Lab03-Docente
 *
 * Created on 18 de marzo de 2019, 01:46 PM
 */



// PIC16F886 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = OFF       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR21V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define _XTAL_FREQ 8000000

void __interrupt() ISR_alternar_led(void) {
    if (RBIF==1) {
        RBIF=0;
        PORTBbits.RB2 = ~PORTBbits.RB2;
        __delay_ms(300);
    }
}

void main(void) {
    ANSELH &= ~0xFF;
    TRISB |= 0x20;
    TRISB &= ~0x05;
    PORTB &= ~0x05;
    
    RBIF = 0;
    RBIE = 1;
    INTEDG = 1;
    PEIE = 1;
    GIE = 1;
    IOCB |= 0x20;
    
    while (1) {
        RB0 = 1;
        __delay_ms(500);
        RB0 = 0;
        __delay_ms(500);
    }
    
    return;
}