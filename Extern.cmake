#Loading External dependencies

#These following dependencies are not included in the project, install them using a package-manager
find_package(PkgConfig)
pkg_search_module(GLEW REQUIRED glew)
pkg_search_module(GLFW REQUIRED glfw3)
pkg_search_module(GLM REQUIRED glm)
pkg_search_module(ASSIMP REQUIRED assimp)

set(EXTERN_INCLUDES ${GLEW_INCLUDE_DIRS}
                    ${GLFW_INCLUDE_DIRS}
                    ${GLM_INCLUDE_DIRS}
                    ${ASSIMP_INCLUDE_DIRS})

set(EXTERN_LIBRARIES ${GLEW_LIBRARIES}
                     ${GLFW_LIBRARIES}
                     ${GLM_LIBRARIES}
                     ${ASSIMP_LIBRARIES})

include_directories(${EXTERN_INCLUDES} extern/spdlog/include extern/stb/)