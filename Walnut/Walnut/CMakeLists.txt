project(Walnut LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "./src/*.h" "./src/*.cpp")
add_library(Walnut STATIC ${SOURCES})
target_include_directories(Walnut PRIVATE
    "./src"
    ${IMGUI_INCLUDE}
    ${GLFW_INCLUDE}
    ${STBIMAGE_INCLUDE}
    ${VULKAN_SDK_INCLUDE}
    ${GLM_INCLUDE})
target_link_libraries(Walnut PRIVATE
    ImGui
    glfw
    ${VULKAN_SDK_LIB})
set_target_properties(Walnut PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${output_dir}/Walnut)

if(WIN32)
    target_compile_definitions(Walnut PRIVATE WL_PLATFORM_WINDOWS)
endif(WIN32)

target_compile_definitions(Walnut PRIVATE 
    $<$<CONFIG:Debug>:WL_DEBUG>
    $<$<CONFIG:Release>:WL_RELEASE>)