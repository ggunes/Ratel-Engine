# Demo uygulaması için CMake yapılandırması

add_executable(RatelDemo
    main.cpp
)

target_link_libraries(RatelDemo PRIVATE
    RatelEngine
)

# Demo uygulamasının çalışma dizinini ayarla
set_target_properties(RatelDemo PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
)