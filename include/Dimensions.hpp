#pragma once

template <class T>
class Dim2D{
    public:
    T X;
    T Y;

    Dim2D(T X = 0, T Y = 0) : X(X), Y(Y) {}
};