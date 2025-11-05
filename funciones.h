
#ifndef FUNCIONES_H
#define FUNCIONES_H

void menu();
void ingresar_productos(char nombres[10][50], float precios[10], int n);
float calcular_total(float precios[10], int n);
void mostrar_masCaro_masBarato(char nombres[10][50], float precios[10], int n);
float calcular_promedio(float precios[10], int n);
void buscar_producto(char nombres[10][50], float precios[10], int n);

#endif
