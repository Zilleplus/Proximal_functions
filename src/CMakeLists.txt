file(GLOB PROXIMAL_FUNCTIONS_SRC
    "*.c"
)
add_library(proximal_functions_lib STATIC ${PROXIMAL_FUNCTIONS_SRC})
set_property(TARGET proximal_functions_lib PROPERTY C_STANDARD 90)