cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(mdldec)

add_executable(mdldec)

target_sources(mdldec
    PUBLIC
        class/hlsdk/activity.h
        class/hlsdk/mathlib.c
        class/hlsdk/mathlib.h
        class/hlsdk/studio.h
        class/bmp.cpp
        class/mdldec.cpp
        class/mdldec.h
        class/misc.cpp
        class/qc.cpp
        class/smd.cpp
        exe/main.cpp
)
