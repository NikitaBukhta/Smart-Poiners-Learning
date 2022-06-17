#ifndef SHARED_PTR_H
#define SHARED_PTR_H

namespace smart_ptr{
    template <typename T>
    class SharedPtr{
    private:
        T *_ptr;

    public:
        SharedPtr(T *ptr = nullptr);

        ~SharedPtr(void);

        int* get(void);
    };
}

#endif // !SHARED_PTR_H