set(
    LIB_NAME
    test_class_lib
)

set(
    SRC
    src/test_class.cpp
)

set(
    HEADERS_DIR
    include;
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