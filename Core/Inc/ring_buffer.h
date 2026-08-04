#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

// Definisanje veličine bafera (mora biti jednako kao u ring_buffer.c)
#define BUFFER_SIZE 50
typedef struct {
    volatile uint16_t buffer[BUFFER_SIZE];
    volatile uint16_t head;
    volatile uint16_t tail;
    volatile uint8_t count;
} RingBuffer;

// Deklaracije (prototipovi) funkcija
void Init_buffer(RingBuffer *rb);
void Push(RingBuffer *rb, uint16_t data);
void Pop(RingBuffer *rb, uint16_t *data);

uint8_t RingBuffer_Count(RingBuffer *rb);
bool RingBuffer_is_empty(RingBuffer *rb);
bool RingBuffer_is_full(RingBuffer *rb);

#endif /* RING_BUFFER_H */