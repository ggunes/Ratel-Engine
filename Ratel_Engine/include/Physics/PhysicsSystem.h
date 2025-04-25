#pragma once

#include <memory>
#include <vector>
#include <windows.h>

namespace Ratel {

class PhysicsSystem {
public:
    PhysicsSystem();
    ~PhysicsSystem();

    bool Initialize();
    void Shutdown();

    void Update(float deltaTime);

    // Fizik nesnesi oluşturma
    // Fizik dünyası kontrolü
    void SetGravity(float gravity) { m_gravity = gravity; }
    float GetGravity() const { return m_gravity; }

private:
    float m_gravity = 9.81f;
};

} // namespace Ratel