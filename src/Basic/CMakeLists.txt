file(GLOB_RECURSE BASIC_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE BASIC_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(basic-engine SHARED ${BASIC_SOURCES} ${BASIC_HEADERS})
target_link_libraries(basic-engine PUBLIC ${EXTERN_LIBRARIES})
target_precompile_headers(basic-engine PUBLIC Basic.pch)