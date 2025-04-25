#pragma once

#include <vector>

namespace Ratel {

struct Particle {
    float x, y, z;        // position
    float vx, vy, vz;     // velocity
    float r, g, b, a;     // color
    float life;
    float size;
};

class ParticleSystem {
public:
    ParticleSystem();
    ~ParticleSystem();

    void Initialize(size_t maxParticles = 10000);
    void Shutdown();

    // Partikül yönetimi
    void Update(float deltaTime);
    void Emit(float x, float y, float z,
              float dx, float dy, float dz,
              float spread, float speed, float size,
              float r, float g, float b, float a,
              float lifetime, size_t count = 1);

    // Partikül efektleri
    void CreateExplosion(float x, float y, float z,
                        float radius, float r, float g, float b, float a,
                        size_t particleCount);
    void CreateFountain(float x, float y, float z,
                       float height, float r, float g, float b, float a,
                       size_t particleCount);

    // Getter metodları
    const std::vector<Particle>& GetParticles() const { return m_particles; }
    size_t GetActiveParticleCount() const { return m_activeParticles; }

private:
    std::vector<Particle> m_particles;
    size_t m_activeParticles;
    size_t m_maxParticles;
};

} // namespace Ratel