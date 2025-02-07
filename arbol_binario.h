/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   arbol_binario.h
 * Author: jcpenya
 *
 * Created on 26 de noviembre de 2024, 17:07
 */

#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif

typedef struct arbol_binario {
    struct arbol_binario* izquierda;
    struct arbol_binario* derecha;
    struct arbol_binario* padre;
    void* dato;
    int tamanio_dato;
    int(*funcion_ordenar)(void*, void*);
} ARBOL_BINARIO;
/**
 * Crea un arbol, con un unico elemento como raiz.
 * @param  Tamaño en bytes del dato a almacenar en el nodo
 * @param  Dato a almacenar en el nodo
 * @param funcion_ordenar Funcion encargada de comparar dos datos: retorna 0 si son iguales, 1 si el primer dato es mayor, -1 si el segundo dato es menor
 * @return el nodo raiz recien creado
 */
ARBOL_BINARIO* nuevo_arbol_binario(int, void*, int(*funcion_ordenar)(void*, void*));
/**
 * Obtiene el primer elemento en orden IN-ORDER de un subarbol binario
 * @param Nodo a partir del cual se buscara el primer elemento
 * @return El primer elemento del subarbol
 */
ARBOL_BINARIO* primero_arbol_binario(ARBOL_BINARIO*);
/**
 * Obtiene el ultimo elemento en orden IN-ORDER de un subarbol binario
 * @param Nodo a partir del cual se buscara el ultimo elemento
 * @return El ultimo elemento del subarbol
 */
ARBOL_BINARIO* ultimo_arbol_binario(ARBOL_BINARIO*);
/**
 * Inserta un elemento en orden IN-ORDER en un subarbol binario
 * @param Dato a insertar. Si el dato ya existe en el subarbol se ignora la insercion.
 * @param Subarbol donde se insertara el nodo.
 */
void insertar_arbol_binario(void*, ARBOL_BINARIO*);
/**
 * Encuentra el siguiente elemento en orden IN-ORDER en un arbol binario.
 * @param Nodo del que se desea conocer cual es el nodo siguiente
 * @return Nodo siguiente o NULL si es el ultimo nodo en el arbol.
 */
ARBOL_BINARIO* siguiente_arbol_binario(ARBOL_BINARIO*);
/**
 * Encuentra el elemento anterior en orden IN-ORDER en un arbol binario
 * @param Nodo del que se desea conocer cual es el nodo anterior
 * @return Nodo anterior o NULL si es el primer nodo en el arbol
 */
ARBOL_BINARIO* anterior_arbol_binario(ARBOL_BINARIO*);
/**
 * Busca un elemento dentro de un arbol binario
 * @param Dato a ser buscado
 * @param Nodo raiz a partir del cual se buscara el dato
 * @return El nodo donde se encuentra el dato o NULL si no esta presente.
 */
ARBOL_BINARIO* busqueda_binaria_arbol_binario(void*, ARBOL_BINARIO*);
/**
 * Dado un elemento de un arbol, retorna su raiz
 * @param Nodo perteneciente al arbol que desea encontrarse la raiz
 * @return Nodo raiz del arbol
 */
ARBOL_BINARIO* buscar_raiz(ARBOL_BINARIO*);
/**
 * Ejecuta la funcion indicada para cada nodo del arbol
 * @param Arbol para cuyos nodos se invocara la funcion indicada
 * @param Funcion que recibe un dato como argumento y que sera invocada para cada nodo del arbol
 */
void iterar_arbol_binario(ARBOL_BINARIO*, void(*)(void*));

/**
 * Obtiene el carnet para asignar nota
 */
char* get_carnet();


#endif /* ARBOL_BINARIO_H */