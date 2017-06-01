cmake_minimum_required(VERSION 3.6)
project(Wolf3d)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -lmlx -framework OpenGL -framework AppKit")

set(SOURCE_FILES wolf.h wolf3d.c key.c)

add_executable(Wolf3d ${SOURCE_FILES})
##target_link_libraries(wolf ${CMAKE_SOURCE_DIR}/libft/libft.a)
