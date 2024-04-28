cmake_minimum_required(VERSION 3.26)
project(lab4a C)

set(CMAKE_C_STANDARD 17)

add_executable(lab4a
        BinaryTree.h
        BinaryTree.c
        Boolean.h
        IOUtils.c
        IOUtils.h
        main2.c
        mainWithDialog.c
        DotIntegration.h
        DotIntegration.c
        mainWithDialog.c)
