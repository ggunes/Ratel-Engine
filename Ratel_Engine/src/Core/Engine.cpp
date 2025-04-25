#include "Core/Engine.h"
#include "Renderer/Renderer.h"
#include "Physics/PhysicsSystem.h"
#include "Particles/ParticleSystem.h"

#include <chrono>
#include <thread>

namespace Ratel {

Engine::Engine()
    : m_isRunning(false) {
}

Engine::~Engine() {
    Shutdown();
}

bool Engine::Initialize(const std::string& windowTitle, int width, int height) {
    // Alt sistemleri oluştur
    m_renderer = std::make_unique<Renderer>();
    m_physicsSystem = std::make_unique<PhysicsSystem>();
    m_particleSystem = std::make_unique<ParticleSystem>();

    // Alt sistemleri başlat
    if (!m_renderer->Initialize(windowTitle, width, height)) {
        return false;
    }

    if (!m_physicsSystem->Initialize()) {
        return false;
    }

    m_particleSystem->Initialize();

    m_isRunning = true;
    return true;
}

void Engine::Shutdown() {
    if (m_particleSystem) {
        m_particleSystem->Shutdown();
    }
    if (m_physicsSystem) {
        m_physicsSystem->Shutdown();
    }
    if (m_renderer) {
        m_renderer->Shutdown();
    }
}

void Engine::Run() {
    auto lastTime = std::chrono::high_resolution_clock::now();

    while (m_isRunning && !m_renderer->ShouldClose()) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        float deltaTime = std::chrono::duration<float>(currentTime - lastTime).count();
        lastTime = currentTime;

        Update(deltaTime);
        Render();

        // FPS sınırlaması (60 FPS)
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}

void Engine::Update(float deltaTime) {
    m_physicsSystem->Update(deltaTime);
    m_particleSystem->Update(deltaTime);
    m_renderer->PollEvents();
}

void Engine::Render() {
    m_renderer->BeginFrame();
    m_renderer->Clear();

    // Partikülleri çiz
    const auto& particles = m_particleSystem->GetParticles();
    for (size_t i = 0; i < m_particleSystem->GetActiveParticleCount(); ++i) {
        const auto& p = particles[i];
        m_renderer->DrawRect(static_cast<int>(p.x), static_cast<int>(p.y),
                           static_cast<int>(p.size), static_cast<int>(p.size),
                           RGB(static_cast<int>(p.r * 255),
                               static_cast<int>(p.g * 255),
                               static_cast<int>(p.b * 255)));
    }

    m_renderer->EndFrame();
    m_renderer->SwapBuffers();
}

} // namespace Ratel