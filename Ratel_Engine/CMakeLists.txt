cmake_minimum_required(VERSION 3.15)
project(RatelEngine VERSION 1.0)

# C++ standart ayarları
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ana proje dizinleri
set(ENGINE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(ENGINE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Ana executable'ı oluştur
add_executable(RatelEngine
    ${ENGINE_SOURCE_DIR}/Core/Engine.cpp
    ${ENGINE_SOURCE_DIR}/main.cpp
)

# Include dizinlerini ayarla
target_include_directories(RatelEngine PUBLIC
    ${ENGINE_INCLUDE_DIR}
)

# Çıktı dizinlerini ayarla
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)