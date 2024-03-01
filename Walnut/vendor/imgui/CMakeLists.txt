project(ImGui LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(ImGui STATIC
    "imconfig.h"
    "imgui.h"
    "imgui.cpp"
    "imgui_draw.cpp"
    "imgui_internal.h"
    "imgui_tables.cpp"
    "imgui_widgets.cpp"
    "imstb_rectpack.h"
    "imstb_textedit.h"
    "imstb_truetype.h"
    "imgui_demo.cpp")

target_include_directories(ImGui PRIVATE 
    ./
    ${VULKAN_SDK_INCLUDE})
 
set_target_properties(ImGui PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${output_dir}/ImGui)

