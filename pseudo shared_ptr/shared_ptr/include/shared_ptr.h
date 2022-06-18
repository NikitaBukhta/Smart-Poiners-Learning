#ifndef SHARED_PTR_H
#define SHARED_PTR_H

typedef unsigned long long int ullong;

namespace smart_ptr{
    template <typename T>
    class SharedPtr{
    private:
        T *_ptr;
        ullong *_count;

    public:
        SharedPtr(T *ptr = nullptr);

        ~SharedPtr(void);

        SharedPtr(const SharedPtr<T> &other);

        SharedPtr(SharedPtr<T> &&other);

        void operator= (const SharedPtr<T> &other);

        void operator= (SharedPtr<T> &&other);

        T& operator* (void);

        T* get(void);

        ullong use_count(void);
    };
}

#endif // !SHARED_PTR_H