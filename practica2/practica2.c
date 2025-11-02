#include <stdio.h>
#include <string.h>

#define TAM 1000 // tamaño máximo del buffer

// --- Prototipos de funciones ---
void llenarBuffer(char *texto);
void mostrarTexto(const char *texto);
void buscarYReemplazar(char *texto, const char *buscar, const char *reemplazar);

// --- Función principal ---
int main()
{
    char texto[TAM];
    char buscar[100], reemplazar[100];

    printf("=== Editor de texto basico ===\n\n");

    // 1. Llenar el buffer
    llenarBuffer(texto);

    // 2. Mostrar el texto original
    printf("\nTexto original:\n");
    mostrarTexto(texto);

    // 3. Solicitar palabra a buscar y reemplazar
    printf("\nIngrese el texto a buscar: ");
    fgets(buscar, sizeof(buscar), stdin);
    buscar[strcspn(buscar, "\n")] = '\0'; // eliminar salto de línea

    if (buscar[0] == '\0') {
        printf("No se ingresó texto a buscar. Saliendo.\n");
        return 0;
    }

    printf("Ingrese el texto de reemplazo: ");
    fgets(reemplazar, sizeof(reemplazar), stdin);
    reemplazar[strcspn(reemplazar, "\n")] = '\0';

    // 4. Realizar reemplazo
    buscarYReemplazar(texto, buscar, reemplazar);

    // 5. Mostrar resultado final
    printf("\n=== Texto final ===\n");
    mostrarTexto(texto);

    return 0;
}

// --- Implementaciones ---
void llenarBuffer(char *texto)
{
    printf("Ingrese el texto (max %d caracteres):\n", TAM - 1);
    fgets(texto, TAM, stdin);
    texto[strcspn(texto, "\n")] = '\0'; // eliminar salto de línea
}

void mostrarTexto(const char *texto)
{
    printf("%s\n", texto);
}

void buscarYReemplazar(char *texto, const char *buscar, const char *reemplazar)
{
    char resultado[TAM];
    char *pos, *inicio = texto;
    int lenBuscar = strlen(buscar);
    resultado[0] = '\0'; // inicializar cadena vacía

    while ((pos = strstr(inicio, buscar)) != NULL)
    {
        strncat(resultado, inicio, pos - inicio); // copiar texto antes de coincidencia
        strcat(resultado, reemplazar);            // agregar reemplazo
        inicio = pos + lenBuscar;                 // avanzar puntero
    }
    strcat(resultado, inicio); // copiar el resto del texto
    strcpy(texto, resultado);  // guardar en el buffer original
}
