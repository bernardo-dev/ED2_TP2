# Especifica a versão mínima do CMake necessária para compilar o projeto
cmake_minimum_required(VERSION 3.10)

# Define o nome do projeto
project(UnitTests C)

# Define o padrão de C
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED False)

# Define as tags de compilação
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

# Define o tipo de build como Debug
set(CMAKE_BUILD_TYPE Debug)

# Define o diretório fonte
set(SRC_DIR ../../src)
set(TEST_DIR .)

# Define o diretório de saída
set(BIN_DIR ../../bin)

# Define o diretório de saída do executável
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../${BIN_DIR}/${CMAKE_BUILD_TYPE})

# Especifica os arquivos fonte para os testes unitários
set(TEST_FILES
    ${TEST_DIR}/main.c
    ${TEST_DIR}/unit_util.c
    ${SRC_DIR}/util.c
)

# Adiciona o executável para os testes unitários
add_executable(unit_tests ${TEST_FILES})

# Adiciona a flag de debug
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")

# Inclui o diretório de cabeçalhos
include_directories(${SRC_DIR})