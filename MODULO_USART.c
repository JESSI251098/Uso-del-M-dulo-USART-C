//INSTITUTO TECNOLOGICO SUPERIOR DE COATZACOALCOS 
//EQUIPO= LA EGG-CELENCIA 
//INGENIERIA MECATRÓNICA    Práctica 2: MODULO USART
//MATERIA: MICROCONTROLADORES
// INTEGRANTES:
// Agustín Madrigal Luis           17080167           imct17.lagustinm@itesco.edu.mx
//Cruz Gallegos Isaac             17080186           imct17.icruzg@itesco.edu.mx
//Godínez Palma Jessi Darissel    17080205 	         imct17.jgodinezp@itesco.edu.mx
//Guzmán García Omar de Jesús     17080211           imct17.oguzmang@itesco.edu.mx
//Medina Ortiz Mauricio           17080237           imct17.mmedinao@itesco.edu.mx
//Méndez Osorio Julia Vanessa     17080238           imct17.jmendezo@itesco.edu.mx
//DOCENTE: JORGE ALBERTO SILVA VALENZUELA
//SEMESTRE: 7 °     GRUPO: A
//FECHA:  22 / 10 / 2020
#include <xc.h>//DECLARAMOS NUESTRAS LIBRERIAS
#include<stdio.h>
#define _XTAL_FREQ 8000000 //CONFIGURACIÓN DEL OSCILADOR
//CONFIG 1
#pragma config FOSC = INTRC_CLKOUT
#pragma config WDTE = OFF       
#pragma config PWRTE = ON       
#pragma config MCLRE = ON       
#pragma config CP = OFF         
#pragma config CPD = OFF        
#pragma config IESO = ON        
#pragma config FCMEN = ON       
#pragma config LVP = OFF        
//CONFIG 2
#pragma config BOR4V = BOR40V   
#pragma config WRT = OFF      
unsigned char Activado;

void main(void) {
    OSCCONbits.IRCF=0b1110;v //registros osccon
    OSCCONbits.SCS=0b00;
    ANSEL=0B00000000; //entrada y salida 
    ANSELH=0B00000000;
    TRISCbits.TRISC6=0;
    TRISCbits.TRISC7=1;
    INTCON=0B00000000; //Interrupción
    PIE1=0b00000000;
    TXSTA=0b00100110;
    BAUDCTL=0b00000000;
    RCSTA=0b10010000;
    SPBRG=12;
    while(1){ //ciclo infinito
   if(PIR1bits.RCIF==1){
            Activado=RCREG;
            while(TXSTAbits.TRMT==0); //ciclo de monitoreo
            TXREG=Activado;
            __delay_ms(10);
        }        
    }
    return;
}