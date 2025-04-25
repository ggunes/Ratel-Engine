#include "Core/Engine.h"

int main() {
    Ratel::Engine engine;

    // Motoru başlat
    if (!engine.Initialize("Ratel Engine Demo", 1280, 720)) {
        return -1;
    }

    // Ana döngüyü çalıştır
    engine.Run();

    return 0;
}