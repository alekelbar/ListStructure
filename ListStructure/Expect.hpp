#pragma once
#include <iostream>
#include <string>

template<typename T>
class Expect {
    T actual;

public:
    Expect(T value) : actual(value) {}

    // Asegura que el valor sea igual al valor esperado
    void toEqual(T expected, const std::string& message = "") {
        if (actual != expected) {
            throw std::runtime_error("Expected: " + std::to_string(expected) + ", Actual: " + std::to_string(actual) + " - " + message);
        }
    }

    // Asegura que el valor sea diferente al valor esperado
    void toNotEqual(T expected, const std::string& message = "") {
        if (actual == expected) {
            throw std::runtime_error("Expected not equal to: " + std::to_string(expected) + " - " + message);
        }
    }

    // Sobrecarga de operador para facilitar la comparación
    void operator==(T expected) {
        toEqual(expected);
    }

    void operator!=(T expected) {
        toNotEqual(expected);
    }
};
