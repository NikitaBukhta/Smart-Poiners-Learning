#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

namespace smart_ptr{
    template <typename T>
    class UniquePtr{
    private:
        T *_ptr;
    public:
        UniquePtr(T *ptr = nullptr);

        ~UniquePtr(void);

        UniquePtr(const UniquePtr<T> &other) = delete;

        UniquePtr(UniquePtr<T> &&other);

        void operator= (const UniquePtr<T> &other) = delete;

        void operator= ( UniquePtr<T> &&other);

        bool operator== (const UniquePtr<T> &other) const noexcept;

        bool operator== (const T &other) const noexcept;

        bool operator!= (const UniquePtr<T> &other) const noexcept;

        bool operator!= (const T &other) const noexcept;

        T& operator* (void) const noexcept;

        T* operator-> (void) const noexcept;

        T* get(void) const noexcept;

        void reset(T *ptr = nullptr) noexcept;
    };
}

#endif // !UNIQUE_PTR_H