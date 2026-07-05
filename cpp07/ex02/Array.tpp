template <typename T>
Array<T>::Array() : arr(NULL), len(0) {}

template <typename T>
Array<T>::Array(unsigned int n)
{
    len = n;
    arr = new T[len];
    for (unsigned int i = 0; i < len; i++)
        arr[i] = T();
}

template <typename T>
Array<T>::Array(const Array &x) : arr(NULL) , len(0)
{
    *this = x;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &x)
{
    if (this != &x)
    {
        delete [] arr;
        len = x.len;
        if (len > 0)
        {
            arr = new T[len];
            for (unsigned int i = 0; i < len; i++)
                arr[i] = x.arr[i];
        }
        else 
            arr = NULL;
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= len)
        throw CheckIndex();
    return arr[index];
}

template <typename T>
unsigned int Array<T>::size(void) const
{
    return len;
}

template <typename T>
Array<T>::~Array()
{
    delete [] arr;
}