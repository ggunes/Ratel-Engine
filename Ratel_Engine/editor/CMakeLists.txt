# Editör uygulaması için CMake yapılandırması

# Editör hedefini oluştur
add_executable(RatelEditor
    main.cpp
)

# Motor kütüphanesini bağla
target_link_libraries(RatelEditor PRIVATE
    RatelEngine
)

# Windows için özel ayarlar
if(WIN32)
    # Windows'ta konsol penceresini gizle
    set_target_properties(RatelEditor PROPERTIES
        WIN32_EXECUTABLE TRUE
    )
    
    # Çalışma dizinini ayarla
    set_target_properties(RatelEditor PROPERTIES
        VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
    )
endif()