# Especifica a versão mínima do CMake necessária para compilar o projeto
cmake_minimum_required(VERSION 3.10)

# Define o nome do projeto
project(OrdenacaoExterna C)

# Define o padrao de C
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED False)

# Define as tags de compilacao
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

# Define o diretorio fonte
set(SRC_DIR src)

# Define o diretorio de saida
set(BIN_DIR bin)

# Define o diretorio de saida do executavel
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../${BIN_DIR}/${CMAKE_BUILD_TYPE})

# Especifica os arquivos fonte para executavel principal
set(SOURCE_FILES
    ${SRC_DIR}/main.c
    ${SRC_DIR}/util.c
    ${SRC_DIR}/util.h
)

# Adiciona o executavel
add_executable(ordena ${SOURCE_FILES})

# Adiciona a flag de debug
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")