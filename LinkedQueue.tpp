template <typename T>
LinkedQueue<T>::LinkedQueue() {
    this->length =0;
    head = nullptr;
    last = nullptr;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    // TODO
    if (this->length <=0)
    {
        throw string("invalid length");
    }
    return last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    // TODO
    if (isEmpty()) return;
    Node* curr = head;
    while(curr)
    {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;
    last = nullptr;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // TODO
    this->length =0;
    this->head = nullptr;
    this->last =nullptr;

    if(copyObj.head ==nullptr)
    return;

    this->head = new Node(copyObj.head->value);
    this->length++;

    Node* sourHead = copyObj.head->next;
    Node* destHead = this->head;
    while (sourHead != nullptr)
    {
        Node* newNode = new Node(sourHead->value);
        destHead->next = newNode;
        sourHead = sourHead->next;
        destHead = destHead->next;
        this->length++;
    }
    last = destHead;
    destHead->next = nullptr;

}

template <typename T>
void LinkedQueue<T>::dequeue() {
    // TODO
    if (head == nullptr)
        throw string("The queue is empty!\n");
    Node* temp = head;
    head = head->next;
    delete temp;
    temp = nullptr;
    this->length--;

}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    // TODO
    Node* newNode = new Node(elem);
    if (this->length ==0 )
    {
        head = newNode;
        last = newNode;
        this->length++;
        return;
    }
    last->next = newNode;
    newNode->next = nullptr;
    last = newNode;
    
    this->length++;


}

template <typename T>
T LinkedQueue<T>::front() const {
    // TODO
    if(head==nullptr)
        throw string("The queue is empty");
    return head->value;

}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool LinkedQueue<T>::isFull() const {
    return true;
}
