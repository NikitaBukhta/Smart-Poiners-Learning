set(
    LIB_NAME
    shared_ptr_lib
)

set(
    SRC
    src/shared_ptr.cpp
)

set(
    HEADERS_DIR
    include;
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(
    ${LIB_NAME}
    ${SRC}
)

target_include_directories(
    ${LIB_NAME}
    PUBLIC
    ${HEADERS_DIR}
)