add_executable(indicator_box_test indicator_box_test.c)
target_link_libraries (indicator_box_test proximal_functions_lib)
if(NOT MSVC) # Microsoft Visual studio doesn't like this
    target_link_libraries(indicator_box_test m) # link with the math lib, some toolchains need this
endif()