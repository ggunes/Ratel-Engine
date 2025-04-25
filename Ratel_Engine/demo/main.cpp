#include "Core/Engine.h"
#include "Physics/PhysicsSystem.h"
#include "Particles/ParticleSystem.h"

#include <iostream>

int main() {
    Ratel::Engine engine;

    // Motoru başlat
    if (!engine.Initialize("Ratel Engine Demo", 1280, 720)) {
        std::cerr << "Motor başlatılamadı!" << std::endl;
        return -1;
    }

    // Fizik dünyasını ayarla
    auto* physics = engine.GetPhysicsSystem();
    physics->SetGravity(glm::vec3(0.0f, -9.81f, 0.0f));

    // Zemin oluştur
    physics->CreateBox(glm::vec3(0.0f, -5.0f, 0.0f), glm::vec3(10.0f, 0.5f, 10.0f), 0.0f);

    // Düşen küre oluştur
    physics->CreateSphere(glm::vec3(0.0f, 5.0f, 0.0f), 0.5f, 1.0f);

    // Partikül efektleri oluştur
    auto* particles = engine.GetParticleSystem();
    
    // Çeşme efekti
    particles->CreateFountain(
        glm::vec3(-2.0f, 0.0f, 0.0f),  // pozisyon
        5.0f,                           // yükseklik
        glm::vec4(0.0f, 0.5f, 1.0f, 1.0f), // mavi renk
        1000                            // partikül sayısı
    );

    // Patlama efekti
    particles->CreateExplosion(
        glm::vec3(2.0f, 0.0f, 0.0f),    // pozisyon
        3.0f,                            // yarıçap
        glm::vec4(1.0f, 0.5f, 0.0f, 1.0f), // turuncu renk
        500                              // partikül sayısı
    );

    // Ana döngüyü başlat
    engine.Run();

    return 0;
}