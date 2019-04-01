/*
 * File:   main.c
 * Author: Francisco
 *
 * Created on March 25, 2019, 12:58 AM
 */



// PIC16F886 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = HS        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR21V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define _XTAL_FREQ 8000000


void patron_a() {
    for (int i=0; i<2; i++) {
        PORTB |= 0x1F;
        __delay_ms(250);
        PORTB &= ~0x1F;
        __delay_ms(250);
    }
}

void patron_b() {
    for (int i=0; i<2; i++) {
        PORTB |= 0x10;
        __delay_ms(100);
        PORTB |= 0x18;
        __delay_ms(100);
        PORTB |= 0x1C;
        __delay_ms(100);
        PORTB |= 0x1E;
        __delay_ms(100);
        PORTB |= 0x1F;
        __delay_ms(100);
        PORTB &= ~0x10;
        __delay_ms(100);
        PORTB &= ~0x18;
        __delay_ms(100);
        PORTB &= ~0x1C;
        __delay_ms(100);
        PORTB &= ~0x1E;
        __delay_ms(100);
        PORTB &= ~0x1F;
        __delay_ms(100);
    }
}

void patron_c() {
    for(int i=0; i<2; i++) {
        PORTB |= 0x10;
        __delay_ms(100);
        PORTB &= ~0x10;
        PORTB |= 0x08;
        __delay_ms(100);
        PORTB &= ~0x08;
        PORTB |= 0x04;
        __delay_ms(100);
        PORTB &= ~0x04;
        PORTB |= 0x02;
        __delay_ms(100);
        PORTB &= ~0x02;
        PORTB |= 0x01;
        __delay_ms(100);
        PORTB |= 0x02;
        PORTB &= ~0x01;
        __delay_ms(100);
        PORTB &= ~0x02;
        PORTB |= 0x04;
        __delay_ms(100);
        PORTB &= ~0x04;
        PORTB |= 0x08;
        __delay_ms(100);
        PORTB &= ~0x08;
        PORTB |= 0x10;
        __delay_ms(100);
    }
}

void patron_d() {
    for (int i=0; i<2; i++) {
        PORTB |= 0x11;
        __delay_ms(200);
        PORTB |= 0x0A;
        __delay_ms(200);
        PORTB |= 0x04;
        __delay_ms(200);
        PORTB &= ~0x04;
        __delay_ms(200);
        PORTB &= ~0x0A;
        __delay_ms(200);
        PORTB &= ~0x11;
        __delay_ms(200);
    }
}

void patron_e() {
    PORTB |= 0x15;
    for (int i=0; i<8; i++) {
        PORTB ^= 0x1F;
        __delay_ms(250);
    }
    PORTB &= ~0x1F;
}


void main(void) {
    TRISB &= ~0x1F;
    ANSELH &= ~0x1F;
    PORTB &= ~0x1F;
    while (1) {
        patron_a();
        __delay_ms(250);
        patron_b();
        __delay_ms(250);
        patron_c();
        __delay_ms(250);
        patron_d();
        __delay_ms(250);
        patron_e();
        __delay_ms(250);
    }
}
