#include "linked_list.h"
#include <stdlib.h>  // Necesario para malloc y free

struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list {
   struct list_node *first, *last;
};

// constructs a new (empty) list
struct list *list_create(void) {
    struct list* l = (struct list*)malloc(sizeof(struct list));
    if (l == NULL) return NULL;  // Verificar asignación de memoria
    l->first = NULL;
    l->last = NULL;
    return l;
}

// counts the items on a list
size_t list_count(const struct list *list) {
    if (list == NULL) return 0;
    
    struct list_node *aux = list->first;
    size_t count = 0;
    while(aux != NULL) {
        count++;
        aux = aux->next;
    }
    return count;
}

// inserts item at back of a list
void list_push(struct list *list, ll_data_t item_data) {
    if (list == NULL) return;
    
    struct list_node *nuevo = (struct list_node *)malloc(sizeof(struct list_node));
    if (nuevo == NULL) return;  // Fallo de asignación
    
    nuevo->data = item_data;
    nuevo->next = NULL;
    nuevo->prev = list->last;
    
    if (list->last == NULL) {  // Lista vacía
        list->first = nuevo;
        list->last = nuevo;
    } else {
        list->last->next = nuevo;
        list->last = nuevo;
    }
}

// removes item from back of a list
ll_data_t list_pop(struct list *list) {
    if (list == NULL || list->last == NULL) {
        // Manejar error - lista vacía
        return 0;  
    }
    
    ll_data_t res = list->last->data;
    struct list_node *temp = list->last;
    
    if (list->first == list->last) {  // Solo un elemento
        list->first = NULL;
        list->last = NULL;
    } else {
        list->last = list->last->prev;
        list->last->next = NULL;
    }
    
    free(temp);
    return res;
}

// inserts item at front of a list
void list_unshift(struct list *list, ll_data_t item_data) {
    if (list == NULL) return;
    
    struct list_node *nuevo = (struct list_node *)malloc(sizeof(struct list_node));
    if (nuevo == NULL) return;
    
    nuevo->data = item_data;
    nuevo->prev = NULL;
    nuevo->next = list->first;
    
    if (list->first == NULL) {  // Lista vacía
        list->first = nuevo;
        list->last = nuevo;
    } else {
        list->first->prev = nuevo;
        list->first = nuevo;
    }
}

// removes item from front of a list
ll_data_t list_shift(struct list *list) {
    if (list == NULL || list->first == NULL) {
        return 0;  // Manejar error - lista vacia
    }
    
    ll_data_t res = list->first->data;
    struct list_node *temp = list->first;
    
    if (list->first == list->last) {  // Solo un elemento
        list->first = NULL;
        list->last = NULL;
    } else {
        list->first = list->first->next;
        list->first->prev = NULL;
    }
    
    free(temp);
    return res;
}

// deletes a node that holds the matching data (only the first occurrence)
void list_delete(struct list *list, ll_data_t data) {
    if (list == NULL || list->first == NULL) return;
    
    struct list_node *current = list->first;
    
    while (current != NULL) {
        if (current->data == data) {
            // Ajustar punteros de los nodos vecinos
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {  // Es el primer nodo
                list->first = current->next;
            }
            
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {  // Es el último nodo
                list->last = current->prev;
            }
            
            // Liberar el nodo actual
            free(current);
            
            // SALIR después de eliminar la primera ocurrencia
            return;
        }
        
        current = current->next;
    }
}

// destroys an entire list
void list_destroy(struct list *list) {
    if (list == NULL) return;
    
    // Liberar todos los nodos
    struct list_node *current = list->first;
    while (current != NULL) {
        struct list_node *temp = current;
        current = current->next;
        free(temp);
    }
    
    // Liberar la estructura de la lista
    free(list);
}