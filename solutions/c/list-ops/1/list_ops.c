#include "list_ops.h"

// constructs a new list
list_t *new_list(size_t length, list_element_t elements[]) {
    // Asignar memoria para la estructura y el array flexible
    list_t *list = (list_t*)malloc(sizeof(list_t) + length * sizeof(list_element_t));
    if (list == NULL) return NULL;
    
    list->length = length;
    
    if (elements != NULL && length > 0) {
        memcpy(list->elements, elements, length * sizeof(list_element_t));
    }
    
    return list;
}

// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2) {
    if (list1 == NULL && list2 == NULL) return new_list(0, NULL);
    if (list1 == NULL) return new_list(list2->length, list2->elements);
    if (list2 == NULL) return new_list(list1->length, list1->elements);
    
    size_t new_length = list1->length + list2->length;
    list_t *new_list_ptr = (list_t*)malloc(sizeof(list_t) + new_length * sizeof(list_element_t));
    if (new_list_ptr == NULL) return NULL;
    
    new_list_ptr->length = new_length;
    
    // Copiar elementos de list1
    if (list1->length > 0) {
        memcpy(new_list_ptr->elements, list1->elements, list1->length * sizeof(list_element_t));
    }
    
    // Copiar elementos de list2
    if (list2->length > 0) {
        memcpy(new_list_ptr->elements + list1->length, list2->elements, list2->length * sizeof(list_element_t));
    }
    
    return new_list_ptr;
}

// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
    if (list == NULL || filter == NULL) return new_list(0, NULL);
    
    // Primero contar cuántos elementos pasan el filtro
    size_t count = 0;
    for (size_t i = 0; i < list->length; i++) {
        if (filter(list->elements[i])) {
            count++;
        }
    }
    
    // Crear nueva lista con los elementos filtrados
    list_t *result = (list_t*)malloc(sizeof(list_t) + count * sizeof(list_element_t));
    if (result == NULL) return NULL;
    
    result->length = count;
    
    // Copiar elementos que pasan el filtro
    if (count > 0) {
        size_t index = 0;
        for (size_t i = 0; i < list->length; i++) {
            if (filter(list->elements[i])) {
                result->elements[index++] = list->elements[i];
            }
        }
    }
    
    return result;
}

// returns the length of the list
size_t length_list(list_t *list) {
    return list ? list->length : 0;
}

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
    if (list == NULL || map == NULL) return new_list(0, NULL);
    
    list_t *result = (list_t*)malloc(sizeof(list_t) + list->length * sizeof(list_element_t));
    if (result == NULL) return NULL;
    
    result->length = list->length;
    
    for (size_t i = 0; i < list->length; i++) {
        result->elements[i] = map(list->elements[i]);
    }
    
    return result;
}

// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)) {
    if (list == NULL || foldl == NULL) return initial;
    
    list_element_t result = initial;
    for (size_t i = 0; i < list->length; i++) {
        result = foldl(result, list->elements[i]);
    }
    return result;
}

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)) {
    if (list == NULL || foldr == NULL) return initial;
    
    list_element_t result = initial;
    for (size_t i = list->length; i > 0; i--) {
        result = foldr(list->elements[i - 1], result);
    }
    return result;
}

// reverse the elements of the list
list_t *reverse_list(list_t *list) {
    if (list == NULL) return new_list(0, NULL);
    
    list_t *result = (list_t*)malloc(sizeof(list_t) + list->length * sizeof(list_element_t));
    if (result == NULL) return NULL;
    
    result->length = list->length;
    
    for (size_t i = 0; i < list->length; i++) {
        result->elements[i] = list->elements[list->length - 1 - i];
    }
    
    return result;
}

// destroy the entire list
void delete_list(list_t *list) {
    free(list);
}