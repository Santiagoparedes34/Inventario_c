
#include <stdio.h>
#include "funciones.h"

int main() {
    int opcion, n = 0;
    char nombres[10][50];
    float precios[10];

    do {
        menu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Cuantos productos desea ingresar (maximo 10): ");
                scanf("%d", &n);
                if (n > 0 && n <= 10) {
                    ingresar_productos(nombres, precios, n);
                } else {
                    printf("Numero invalido.\n");
                }
                break;

            case 2:
                if (n > 0) {
                    printf("Precio total del inventario: $%.2f\n", calcular_total(precios, n));
                } else {
                    printf("Primero debe ingresar los productos.\n");
                }
                break;

            case 3:
                if (n > 0) {
                    encontrar_caro_barato(nombres, precios, n);
                } else {
                    printf("Primero debe ingresar los productos.\n");
                }
                break;

            case 4:
                if (n > 0) {
                    printf("Promedio de precios: $%.2f\n", calcular_promedio(precios, n));
                } else {
                    printf("Primero debe ingresar los productos.\n");
                }
                break;

            case 5:
                if (n > 0) {
                    buscar_producto(nombres, precios, n);
                } else {
                    printf("Primero debe ingresar los productos.\n");
                }
                break;

            case 6:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }

    } while (opcion != 6);

    return 0;
}
