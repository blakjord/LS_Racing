cmake_minimum_required(VERSION 3.15)
project(LS_Racing C)

set(CMAKE_C_STANDARD 11)
set(ALLEGRO_DIR "C:||MinGW")
include_directories(${ALLEGRO_DIR}/include)
include_directories(${ALLEGRO_DIR}/lib)

add_executable(LS_Racing main.c LS_allegro.c LS_allegro.h lectura.c lectura.h configuracion.c configuracion.h carrera.c carrera.h clasificacion.c clasificacion.h lista.c lista.h grafico.c grafico.h)

target_link_libraries(LS_Racing -lmingw32 -lallegro-5.0.10-monolith-md-debug)