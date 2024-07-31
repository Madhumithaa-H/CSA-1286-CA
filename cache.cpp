#include <stdio.h>
#include <stdlib.h>
#define CACHE_SIZE 16       // Number of cache lines
#define BLOCK_SIZE 4        // Size of each cache block (in bytes)
#define MEMORY_SIZE 64      // Size of main memory (in bytes)
typedef struct {
    int valid;      // Valid bit
    int tag;        // Tag to identify if 
    unsigned char block[BLOCK_SIZE]; 
} CacheLine;

typedef struct {
    CacheLine lines[CACHE_SIZE];
} Cache;
void initialize_cache(Cache *cache) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache->lines[i].valid = 0;
        cache->lines[i].tag = -1;
    }
}
unsigned char read_from_memory(int address, unsigned char *memory) {
    return memory[address];
}
void write_to_memory(int address, unsigned char value, unsigned char *memory) {
    memory[address] = value;
}
unsigned char cache_access(Cache *cache, unsigned char *memory, int address, int is_write, unsigned char value) {
    int block_index = (address / BLOCK_SIZE) % CACHE_SIZE;
    int block_offset = address % BLOCK_SIZE;
    int tag = address / (BLOCK_SIZE * CACHE_SIZE);
    CacheLine *line = &cache->lines[block_index];
    if (!line->valid || line->tag != tag) {
        printf("Cache miss at address %d\n", address);
        for (int i = 0; i < BLOCK_SIZE; i++) {
            line->block[i] = read_from_memory(block_index * BLOCK_SIZE + i, memory);
        }
        line->valid = 1;
        line->tag = tag;
    } else {
        printf("Cache hit at address %d\n", address);
    }
    if (is_write) {
        line->block[block_offset] = value;
        write_to_memory(address, value, memory); // Update main memory as well
        printf("Wrote value %d to address %d\n", value, address);
    }
    return line->block[block_offset];
}
int main() {
    Cache cache;
    unsigned char memory[MEMORY_SIZE];
    initialize_cache(&cache);
    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory[i] = i; // Simple initialization
    }
    int address1 = 5;
    int address2 = 20;
    unsigned char value;
    value = cache_access(&cache, memory, address1, 0, 0);
    printf("Read value %d from address %d\n", value, address1);
    cache_access(&cache, memory, address2, 1, 99);
    value = cache_access(&cache, memory, address2, 0, 0);
    printf("Read value %d from address %d\n", value, address2);

    return 0;
}
