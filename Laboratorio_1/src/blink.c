/**
 @file blink.c
 @author Angeles Ulate Jarquín
 @date 25 de marzo de 2025
 @brief Simulador de DADO utilizando un microcontrolador PIC12F683.
 
Este archivo contiene la implementación de un sistema digital que simula
el funcionamiento de un dado electrónico. La visualización del número
aleatorio se realiza mediante una combinación de LEDs dispuestos según el
patrón clásico de un dado físico. El sistema se activa a través de un
interruptor momentáneo y utiliza un microcontrolador PIC12F683, 
junto con resistencias limitadoras de corriente para cada salida.
 
 @version 1.0
 @carnet C07908
 */

#include <pic14/pic12f683.h>

// Configuración de bits: desactivar MCLR y WDT
__code unsigned int __at (_CONFIG) configword = _INTOSCIO & _WDTE_OFF & _PWRTE_OFF & _MCLRE_OFF & _CP_ON & _CPD_ON;

// Prototipos
void pausa(unsigned int milis);
void mostrar_dado(unsigned char valor);

void main(void) {
    TRISIO = 0b00100000; // GP5 como entrada, demás como salidas
    GPIO = 0x00;

    unsigned int contador = 0;
    unsigned char valor_dado = 0;

    while (1) {
        contador++;

        if (GP5) {
            pausa(2); // Antirebote
            while (GP5); // Espera a que se suelte

            // "Aleatoriedad" básica basada en contador
            valor_dado = (contador % 6) + 1;

            mostrar_dado(valor_dado);

            pausa(500); // Tiempo visible
            GPIO = 0x00;
        }
    }
}
// Muestra el número en LEDs según distribución personalizada
void mostrar_dado(unsigned char valor) {
    switch (valor) {
        case 1:
            GPIO = 0b00000100; // GP2 (P2) = centro
            break;
        case 2:
            GPIO = 0b00010000; // GP4 (P4)
            break;
        case 3:
            GPIO = 0b00010100; // GP4 + GP2
            break;
        case 4:
            GPIO = 0b00010001; // GP0 + GP4
            break;
        case 5:
            GPIO = 0b00010101; // GP0 + GP4 + GP2
            break;
        case 6:
            GPIO = 0b00010011; // GP0 + GP1 + GP4
            break;
        default:
            GPIO = 0x00;
            break;
    }
}


// Delay aproximado en ms (no preciso)
void pausa(unsigned int milis) {
    unsigned int i, j;
    for (i = 0; i < milis; i++) {
        for (j = 0; j < 1275; j++);
    }
}