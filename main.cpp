#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include "perlin.h"

const int WIDTH = 50;
const int HEIGHT = 50;

// Parámetros a modificar
float scale = 50.0f;
int octaves = 5;
float persistence = 0.5f;
float lacunarity = 2.0f;

char getSymbol(float value) {
    if (value < 0.33f) return '.';
    else if (value < 0.66f) return '#';
    else return '^';
}

int main() {
    PerlinNoise perlin;

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            float amplitude = 1.0f;
            float frequency = 1.0f;
            float noiseHeight = 0.0f;

            for (int i = 0; i < octaves; ++i) {
                float sampleX = x / scale * frequency;
                float sampleY = y / scale * frequency;

                float perlinValue = perlin.noise(sampleX, sampleY);
                noiseHeight += perlinValue * amplitude;

                amplitude *= persistence;
                frequency *= lacunarity;
            }

            float normalized = (noiseHeight + 1.0f) / 2.0f;
            std::cout << getSymbol(normalized);
        }
        std::cout << '\n';
    }

    return 0;
}