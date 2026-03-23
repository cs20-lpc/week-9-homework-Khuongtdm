template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    // TODO
    maxSize = i;
    this->length = 0;
    frontIndex = 0;
    backIndex = maxSize-1;
    buffer = new T[maxSize];
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const {
    // TODO
    if(isEmpty())
        throw string("error, queue is empty, cannot access the back");
    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    // TODO
    delete[] buffer;
    buffer = nullptr;
    this->length =0;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    // TODO
    this->maxSize = copyObj.maxSize;
    this->length = copyObj.length;
    this->frontIndex = copyObj.frontIndex;
    this->backIndex = copyObj.backIndex;
    this->buffer = new T[maxSize];


    for (int i = 0; i < maxSize; i++) {
        this->buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    // TODO
    if(isEmpty())
        throw string("error, queue is empty, cannot dequeue");
    frontIndex = (frontIndex+1)%maxSize;
    this->length--;
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    // TODO
    if(this->length == maxSize)
        throw string("error, queue is full, cannot enqueue");
    backIndex = (backIndex+1)%maxSize;
    buffer[backIndex] = elem;
    
    this->length++;
}

template <typename T>
T ArrayQueue<T>::front() const {
    // TODO
    if(isEmpty())
        throw string("error, queue is empty, cannot access the front");
    return buffer[frontIndex];
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
