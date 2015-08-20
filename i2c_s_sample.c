#include<xc.h>
#include<pic12f1822.h>

#define _XTAL_FREQ   8000000 

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF        // Watchdog Timer Enable (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT enabled)
#pragma config MCLRE = ON      // MCLR Pin Function Select (MCLR/VPP pin function is digital input)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = OFF       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF        // Internal/External Switchover (Internal/External Switchover mode is enabled)
#pragma config FCMEN = OFF       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PLLEN = ON       // PLL Enable (4x PLL enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)O_OFF & FCMEN_OFF) ;

void InitI2C_Slave(int addres) ;
interrupt void I2C_write();

void main (void)
{
    OSCCON     =0b00000110;  //????????MHz???
    OPTION_REG =0b00000000;  //????I/O???????????????
    ANSELA     =0b00000000;  //?????????
    WPUA       =0B00000000;  //???????????????

    InitI2C_Slave(8);
    while(1){

    }
}

interrupt void I2C_write(void){
    if(R_nW == 1){
        SSPBUF = 0x67;
        CKP = 1;
        SSP1IF = 0;
    }
    while(!SSPSTATbits.P);
}

void InitI2C_Slave(int address)
{
     SSP1STAT= 0b10000000 ;   // ????????????(100kHz)
     SSP1CON1= 0b00100110 ;   // SDA/SCL???I2C???????????????
     SSP1CON2bits.SEN  = 1;   // SCL??(?????????)???
//   SSP1CON2bits.GCEN = 1;   // ?????????????????
     SSP1ADD = address<<1 ;   // ?????????
     SSP1MSK = 0b11111110 ;   // ?????????????
     SSP1IE = 1 ;             // SSP(I2C)?????????
     BCL1IE = 1 ;             // MSSP(I2C)?????????????
     PEIE   = 1 ;             // ?????????????
     GIE    = 1 ;             // ????????????
     SSP1IF = 0 ;             // SSP(I2C)?????????????
     BCL1IF = 0 ;             // MSSP(I2C)?????????????????
}

