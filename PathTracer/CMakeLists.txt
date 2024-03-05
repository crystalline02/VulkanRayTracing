project(PathTracer LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES 
    "./src/PathTracerApp.cpp")
add_executable(PathTracer ${SOURCES})
target_include_directories(PathTracer PRIVATE
    ${IMGUI_INCLUDE}
    ${GLFW_INCLUDE}
    ${GLM_INCLUDE}
    ../Walnut/Walnut/src
    ${VULKAN_SDK_INCLUDE})
target_link_libraries(PathTracer PRIVATE
    Walnut)
set_target_properties(PathTracer PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${output_dir}/${PROJECT_NAME})

if(WIN32)
    target_compile_definitions(PathTracer PRIVATE WL_PLATFORM_WINDOWS)
endif(WIN32)

target_compile_definitions(PathTracer PRIVATE 
    $<$<CONFIG:Debug>:WL_DEBUG>
    $<$<CONFIG:Release>:WL_RELEASE>)


    
