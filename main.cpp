#include <iostream>
#include <windows.h>


typedef char ALIGN[16];
union header{
struct {
    size_t size;
    unsigned is_free;
    union header *next;
 } s;
ALIGN stub;
};
typedef union header header_t;


header_t *head = nullptr, *tail = nullptr;
pthread_mutex_t global_malloc_lock;


void *malloc(size_t size)
{
    void *block = VirtualAlloc(nullptr, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if(!block)
    {
        std::cerr << "Allocation failed";
        return nullptr;
    }
    return block;
}
int main() {

}
