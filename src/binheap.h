#pragma once

#include "vec.h"

typedef struct {
  vec_t data;
  compare_fn comp;
} binheap_t;

void binheap_init(binheap_t* self, size_t cap, compare_fn comp, size_t elsz);

void binheap_build(binheap_t* self, const void* v, size_t n, compare_fn comp, size_t elsz);

void binheap_sort(vec_t data, compare_fn comp);

const void* binheap_peek(const binheap_t* self); 

size_t binheap_sift_up(binheap_t* self, size_t start, size_t pos);

void binheap_sift_down(binheap_t* self, size_t pos);

void binheap_push(binheap_t* self, const void* val);

void binheap_pop(binheap_t* self);

void binheap_del(binheap_t* self);
