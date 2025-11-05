#include <stdio.h>
#include <string.h>
#include "funciones.h"

void menu() {
    printf("\n------- MENU -------\n");
    printf("1. Ingresar productos y precios\n");
    printf("2. Calcular el precio total del inventario\n");
    printf("3. Mostrar producto de mayor y menor precio\n");
    printf("4. Calcular el promedio de los precios\n");
    printf("5. Buscar un producto\n");
    printf("6. Salir\n");
    printf("Seleccione una opcion: ");
}



void ingresar_productos(char nombres[10][50], float precios[10], int n) {
    for (int i = 0; i < n; i++) {
        getchar(); 
        printf("\nIngrese el nombre del producto %d: ", i + 1);
        fgets(nombres[i], 50, stdin);
        int len = strlen(nombres[i]);
        if (len > 0 && nombres[i][len - 1] == '\n') {
            nombres[i][len - 1] = '\0';
        }

        do {
            printf("Ingrese el precio del producto %d: ", i + 1);
            scanf("%f", &precios[i]);
            if (precios[i] < 0) {
                printf("Error: el precio no puede ser negativo.\n");
            }
        } while (precios[i] < 0);
    }
}

float calcular_total(float precios[10], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += precios[i];
    }
    return total;
}

void encontrar_caro_barato(char nombres[10][50], float precios[10], int n) {
    int indiceCaro = 0, indiceBarato = 0;
    for (int i = 1; i < n; i++) {
        if (precios[i] > precios[indiceCaro]) indiceCaro = i;
        if (precios[i] < precios[indiceBarato]) indiceBarato = i;
    }
    printf("\nProducto mas caro: %s - $%.2f\n", nombres[indiceCaro], precios[indiceCaro]);
    printf("Producto mas barato: %s - $%.2f\n", nombres[indiceBarato], precios[indiceBarato]);
}

float calcular_promedio(float precios[10], int n) {
    return calcular_total(precios, n) / n;
}

void buscar_producto(char nombres[10][50], float precios[10], int n) {
    char buscar[50];
    getchar(); 
    printf("\nIngrese el nombre del producto a buscar: ");
    fgets(buscar, 50, stdin);
    int len = strlen(buscar);
    if (len > 0 && buscar[len - 1] == '\n') {
        buscar[len - 1] = '\0';
    }

    int encontrado = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(buscar, nombres[i]) == 0) {
            printf("El precio de %s es: $%.2f\n", nombres[i], precios[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}
