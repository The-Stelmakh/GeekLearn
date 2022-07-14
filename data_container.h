#pragma once

#include <cassert>
#include <iostream>
#include <vector>

class DataContainer 
{
    int* data;
    int size;
    int capacity;

public:
    DataContainer() : size(0), data(nullptr) {
        capacity = 0;
    }
    DataContainer(int _size) : size(_size) {
        if (_size == 0) {
            DataContainer();
        }
        else if (_size > 0) {
            data = new int[_size];
            capacity = 0;
        }
        else {
            printf("Bad things happened!\n");
            DataContainer();
        }
    }
    ~DataContainer() {
        delete[] data;
    }
    int& operator[](int idx) { return &data[idx]; }
    void setData(int idx, int value) {
        assert(idx >= 0 && idx < size);
        this->data[idx] = value;
    }
    int getData(int idx) const {
        assert(idx >= 0 && idx < size);
        return data[idx];
    }
    int capacity() {
        return this->capacity;
    }
    void resize(int newLength) {
        if (newLength == size) return;
        if (newLength <= 0) {
            erase();
            return;
        }

        int* newData = new int[newLength];
        int elementsToCopy = 0;
        if (size > 0) {
            elementsToCopy = (newLength > size) ? size : newLength;
            for (int idx = 0; idx < elementsToCopy; ++idx) 
                newData[idx] = data[idx];
        }
        delete[] data;

        data = newData;
        size = newLength;
        capacity = elementsToCopy;
    }
    void insertLast(int value) {
        resize(size + 1);
        setData(size - 1, value);
    }
    int returnLast() {
        return getData(size - 1);
    }
    int removeLast() {
        int tmp = getData(size - 1);
        resize(size - 1);
        return tmp;
    }
    int returnFirst() {
        return getData(0);
    }
    int removeFirst() {
        int tmp = getData(0);
        for (int idx = 1; idx < size; ++idx) 
            data[idx - 1] = data[idx];

        resize(size - 1);
        return tmp;
    }
    void print() {
        for (int idx = 0; idx < size; ++idx)
            std::cout << data[idx] << ", " << std::endl;
        std::cout << std::endl;
    }
    void sort() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - 1; j++) {
                if (data[i] > data[i + 1]) {
                    int t = data[i];
                    data[i] = data[i + 1];
                    data[i + 1] = t;
                }
            }
        }
    }
};