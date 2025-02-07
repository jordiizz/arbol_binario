/*
 * File:   prueba_arbol_binario.c
 * Author: jcpenya
 *
 * Created on 26 nov 2024, 19:03:19
 */

#include <stdio.h>
#include <stdlib.h>
#include "../arbol_binario.h"
#include <CUnit/Basic.h>

/*
 * CUnit Test Suite
 */

FILE* tmp;

void imprimir(void*);

void _prueba_imprimir(void*, FILE*);

void imprimir(void *dato) {
    //fprintf(tmp, "%01x\n", *((int*) dato)); // se usa para la prueba
    fprintf(stdout, "%d\n", *((int*) dato)); // se usa para la prueba
}

int init_suite(void) {
    tmp = tmpfile();
    return 0;
}

int clean_suite(void) {
    fclose(tmp);
    return 0;
}
/**
 * Recibe dos enteros y lo compara
 * @param entero1
 * @param entero2
 * @return si entero1 es mayor que entero2 retorna 1. si entero1 es menor que entero2 retorna -1. si son iguales retorna 0.
 */
int ordenar_int(void*, void*);

int ordenar_int(void *a_void, void *b_void) {
    int primero = *((int*) a_void);
    int segundo = *((int*) b_void);
    if (primero > segundo) {
        return 1;
    } else if (primero < segundo) {
        return -1;
    }
    return 0;
}

void test_nuevo_arbol_binario() {
    int dato = 10;
    ARBOL_BINARIO *nuevo = nuevo_arbol_binario(sizeof (int), &dato, ordenar_int);
    CU_ASSERT(nuevo != NULL);
    CU_ASSERT(nuevo->tamanio_dato == sizeof (int));
    CU_ASSERT(dato == *((int *) nuevo->dato));
    free(nuevo->dato);
    free(nuevo);
}

void test_insertar() {
    int dato = 10;
    int dato2 = 15;
    int dato3 = 5;
    int dato4 = 12;
    ARBOL_BINARIO *nuevo = nuevo_arbol_binario(sizeof (int), &dato, ordenar_int);
    insertar_arbol_binario(&dato2, nuevo);
    insertar_arbol_binario(&dato3, nuevo);
    insertar_arbol_binario(&dato4, nuevo);
    CU_ASSERT(nuevo->derecha != NULL);
    CU_ASSERT(dato2 == *((int *) nuevo->derecha->dato));
    CU_ASSERT(nuevo->izquierda != NULL);
    CU_ASSERT(dato3 == *((int *) nuevo->izquierda->dato));
    CU_ASSERT(dato4 == *((int *) nuevo->derecha->izquierda->dato));
    free(nuevo->derecha->izquierda->dato);
    free(nuevo->derecha->izquierda);
    free(nuevo->derecha->dato);
    free(nuevo->derecha);
    free(nuevo->izquierda->dato);
    free(nuevo->izquierda);
    free(nuevo->dato);
    free(nuevo);

}

void test_buscar_raiz() {
    int dato = 10;
    int dato2 = 15;
    int dato3 = 5;
    int dato4 = 12;
    ARBOL_BINARIO *nuevo = nuevo_arbol_binario(sizeof (int), &dato, ordenar_int);
    insertar_arbol_binario(&dato2, nuevo);
    insertar_arbol_binario(&dato3, nuevo);
    insertar_arbol_binario(&dato4, nuevo);
    ARBOL_BINARIO* raiz = buscar_raiz(nuevo);
    CU_ASSERT(raiz == nuevo);
    raiz = buscar_raiz(nuevo->derecha);
    CU_ASSERT(raiz == nuevo);
    raiz = buscar_raiz(nuevo->derecha->izquierda);
    CU_ASSERT(raiz == nuevo);
    raiz = buscar_raiz(nuevo->izquierda);
    CU_ASSERT(raiz == nuevo);
    free(nuevo->derecha->izquierda->dato);
    free(nuevo->derecha->izquierda);
    free(nuevo->derecha->dato);
    free(nuevo->derecha);
    free(nuevo->izquierda->dato);
    free(nuevo->izquierda);
    free(nuevo->dato);
    free(nuevo);
}

void test_primero_arbol_binario() {
    int dato = 10;
    int dato2 = 15;
    int dato3 = 5;
    ARBOL_BINARIO *nuevo = nuevo_arbol_binario(sizeof (int), &dato, ordenar_int);
    ARBOL_BINARIO* primero = primero_arbol_binario(nuevo);
    CU_ASSERT(nuevo == primero);


    insertar_arbol_binario(&dato3, nuevo);
    primero = primero_arbol_binario(nuevo);
    CU_ASSERT(nuevo->izquierda == primero);

    free(nuevo->izquierda->dato);
    free(nuevo->izquierda);
    free(nuevo->dato);
    free(nuevo);
}

void test_ultimo_arbol_binario() {
    int dato = 10;
    int dato2 = 15;
    int dato3 = 5;
    int dato4 = 20;
    ARBOL_BINARIO *nuevo = nuevo_arbol_binario(sizeof (int), &dato, ordenar_int);
    ARBOL_BINARIO* ultimo = ultimo_arbol_binario(nuevo);
    CU_ASSERT(nuevo == ultimo);
    insertar_arbol_binario(&dato2, nuevo);
    insertar_arbol_binario(&dato3, nuevo);
    insertar_arbol_binario(&dato4, nuevo);
    ultimo = ultimo_arbol_binario(nuevo);
    CU_ASSERT(nuevo->derecha->derecha == ultimo);
    free(nuevo->derecha->dato);
    free(nuevo->derecha);
    free(nuevo->dato);
    free(nuevo);
}

void test_busqueda_binaria_arbol_binario() {
    int dato = 10;
    int dato2 = 15;
    int dato3 = 5;
    int dato4 = 143;
    ARBOL_BINARIO *nuevo = nuevo_arbol_binario(sizeof (int), &dato, ordenar_int);
    insertar_arbol_binario(&dato2, nuevo);
    insertar_arbol_binario(&dato3, nuevo);
    ARBOL_BINARIO* encontrado = busqueda_binaria_arbol_binario(&dato, nuevo);
    CU_ASSERT(encontrado != NULL && dato == *((int *) encontrado->dato));
    encontrado = busqueda_binaria_arbol_binario(&dato2, nuevo);
    CU_ASSERT(encontrado != NULL && dato2 == *((int *) encontrado->dato));
    encontrado = busqueda_binaria_arbol_binario(&dato3, nuevo);
    CU_ASSERT(encontrado != NULL && dato3 == *((int *) encontrado->dato));
    encontrado = busqueda_binaria_arbol_binario(&dato4, nuevo);
    CU_ASSERT(encontrado == NULL);
}

void test_siguiente_arbol_binario() {
    int dato = 58;
    int dato2 = 43;
    int dato3 = 75;
    int dato4 = 85;
    ARBOL_BINARIO *nuevo = nuevo_arbol_binario(sizeof (int), &dato, ordenar_int);
    insertar_arbol_binario(&dato2, nuevo);
    insertar_arbol_binario(&dato3, nuevo);
    insertar_arbol_binario(&dato4, nuevo);

    ARBOL_BINARIO* siguiente = siguiente_arbol_binario(nuevo);
    CU_ASSERT(siguiente == nuevo->derecha);
    siguiente = siguiente_arbol_binario(nuevo->izquierda);
    CU_ASSERT(siguiente == nuevo);
    siguiente = siguiente_arbol_binario(nuevo->derecha);
    CU_ASSERT(siguiente == nuevo->derecha->derecha);
    siguiente = siguiente_arbol_binario(nuevo->derecha->derecha);
    CU_ASSERT(siguiente == NULL);
    free(nuevo->derecha->derecha->dato);
    free(nuevo->derecha->derecha);
    free(nuevo->derecha->dato);
    free(nuevo->derecha);
    free(nuevo->izquierda->dato);
    free(nuevo->izquierda);
    free(nuevo->dato);
    free(nuevo);
}

void test_anterior_arbol_binario() {
    int dato = 58;
    int dato2 = 43;
    int dato3 = 75;
    int dato4 = 85;
    ARBOL_BINARIO *nuevo = nuevo_arbol_binario(sizeof (int), &dato, ordenar_int);
    insertar_arbol_binario(&dato2, nuevo);
    insertar_arbol_binario(&dato3, nuevo);
    insertar_arbol_binario(&dato4, nuevo);
    ARBOL_BINARIO* anterior = anterior_arbol_binario(nuevo);
    CU_ASSERT(anterior == nuevo->izquierda);
    anterior = anterior_arbol_binario(nuevo->derecha);
    CU_ASSERT(anterior == nuevo);
    anterior = anterior_arbol_binario(nuevo->izquierda);
    CU_ASSERT(anterior == NULL);
    free(nuevo->derecha->derecha->dato);
    free(nuevo->derecha->derecha);
    free(nuevo->derecha->dato);
    free(nuevo->derecha);
    free(nuevo->izquierda->dato);
    free(nuevo->izquierda);
    free(nuevo->dato);
    free(nuevo);
}

void testGet_carnet() {
    char* carnet = get_carnet();
    printf("Examen parcial de \n ===============================\n%s\n ===============================\n", carnet);
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("prueba_arbol_binario", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "test_nuevo_arbol_binario", test_nuevo_arbol_binario)) ||
            (NULL == CU_add_test(pSuite, "test_insertar", test_insertar)) ||
            (NULL == CU_add_test(pSuite, "test_primero_arbol_binario", test_primero_arbol_binario)) ||
            (NULL == CU_add_test(pSuite, "test_ultimo_arbol_binario", test_ultimo_arbol_binario)) ||
            (NULL == CU_add_test(pSuite, "test_busqueda_binaria_arbol_binario", test_busqueda_binaria_arbol_binario)) ||
            (NULL == CU_add_test(pSuite, "test_siguiente_arbol_binario", test_siguiente_arbol_binario)) ||
            (NULL == CU_add_test(pSuite, "test_anterior_arbol_binario", test_anterior_arbol_binario)) ||
            (NULL == CU_add_test(pSuite, "testGet_carnet", testGet_carnet))
            ) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
