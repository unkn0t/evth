#pragma once

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) < (b) ? (a) : (b)
#define gen_swap(x, y, T) do { T tmp = *x; *x = *y; *y = tmp; } while (0)

typedef int (*compare_fn)(const void*, const void*);

void* safe_realloc(void* ptr, size_t nmemb, size_t size) {
  size_t final_size = nmemb * size;
  assert(!(nmemb != 0 && final_size / nmemb != size));
  return realloc(ptr, nmemb * size);
}

void safe_memcpy(void* dest, const void* src, size_t n, size_t size) {
  memcpy(dest, src, n * size);
}

void* ptr_add(void* ptr, size_t n, size_t elsz) {
  return (char*)ptr + n * elsz;
}

void swap(void* obj1, void* obj2, size_t size, void* slot) {
  memcpy(slot, obj1, size);
  memcpy(obj1, obj2, size);
  memcpy(obj2, slot, size);
}