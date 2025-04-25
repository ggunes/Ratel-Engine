#pragma once

#include <memory>
#include <string>

namespace Ratel {

class Renderer;
class PhysicsSystem;
class ParticleSystem;

class Engine {
public:
    Engine();
    ~Engine();

    // Motor başlatma ve kapatma
    bool Initialize(const std::string& windowTitle = "Ratel Engine", int width = 1280, int height = 720);
    void Shutdown();

    // Ana döngü
    void Run();
    void Update(float deltaTime);
    void Render();

    // Alt sistemlere erişim
    Renderer* GetRenderer() const { return m_renderer.get(); }
    PhysicsSystem* GetPhysicsSystem() const { return m_physicsSystem.get(); }
    ParticleSystem* GetParticleSystem() const { return m_particleSystem.get(); }

    // Pencere kontrolü
    bool IsRunning() const { return m_isRunning; }
    void Stop() { m_isRunning = false; }

private:
    std::unique_ptr<Renderer> m_renderer;
    std::unique_ptr<PhysicsSystem> m_physicsSystem;
    std::unique_ptr<ParticleSystem> m_particleSystem;

    bool m_isRunning;
};

} // namespace Ratel