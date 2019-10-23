cmake_minimum_required(VERSION 3.14)
project(eg C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
include_directories(libft)

add_executable(eg
        sources/ft_printf.h
        sources/ft_atoi.c
        sources/ft_bzero.c
        sources/ft_memchr.c
        sources/ft_memcpy.c
        sources/ft_memset.c
        sources/ft_pow.c
        sources/ft_strchr.c
        sources/ft_strchri.c
        sources/ft_strlen.c
        sources/ft_strncmp.c
        sources/ft_wcharlen.c
        sources/ft_wstrlen.c
        sources/libft.h
        sources/bonus_functions.c
        sources/ft_printf.c
        sources/handle_numbers.c
        sources/handle_strings.c
        sources/parse_arguments.c)
