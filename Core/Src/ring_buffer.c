#include "ring_buffer.h"


//RingBuffer distance count
uint8_t RingBuffer_Count(RingBuffer *rb){
    uint8_t count = (rb->head - rb->tail + BUFFER_SIZE) % BUFFER_SIZE;
    return count;
}

//Is_empty, function that is true if ringbuffer is currently empty.
bool RingBuffer_is_empty ( RingBuffer *rb) {
    if ( RingBuffer_Count(rb) == 0){ 
        return true;}
    else{
        return false;
    }
}

//Is_full, function that is true if ringbuffer is currently full.
bool RingBuffer_is_full ( RingBuffer *rb){
    if (RingBuffer_Count(rb) == BUFFER_SIZE - 1 ){
        return true;}
    else {
        return false;
    }
}

//Initialisation of the ring buffer
void Init_buffer( RingBuffer *rb) {
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}


//Push, for adding data to the buffer
void Push(RingBuffer *rb, uint16_t data) {
    if(!RingBuffer_is_full(rb)){
        rb->buffer[rb->head] = data;
        rb->head = (rb->head + 1) % BUFFER_SIZE;
    }
    else {
        rb->buffer[rb->head] = data;
        rb->head = (rb->head + 1) % BUFFER_SIZE;
        rb->tail = (rb->tail + 1) % BUFFER_SIZE;
    }
}

//Pop, for removing data from the buffer
void Pop(RingBuffer *rb, uint16_t *data){
    if(!RingBuffer_is_empty(rb)){
        *data = rb->buffer[rb->tail];
        rb->tail = (rb->tail + 1) % BUFFER_SIZE;
    }
    else {
        //Buffer is empty.
    }
}