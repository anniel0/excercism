#include "rna_transcription.h"

char *to_rna(const char *dna) {
    size_t size = strlen(dna);
    char *res = (char*)malloc(size*sizeof(char)); 
    if( size == 0 ) {
        return res;
    }
    for( size_t i = 0; i < size ;i++ ){
        if( dna[i] == 'G' ) {
            res[i] = 'C';
        } else if( dna[i] == 'C' ) {
            res[i] = 'G';
        } else if( dna[i] == 'T' ) {
            res[i] = 'A';
        } else if( dna[i] == 'A' ) {
            res[i] = 'U';
        } 
    }
    return res;
}