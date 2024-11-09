cmake_minimum_required(VERSION 3.29)
project(manage_system)

set(CMAKE_CXX_STANDARD 14)

add_executable(manage_system
    main.cpp
        work_manage.h
        work_manage.cpp
        worker.h
        employee.h
        employee.cpp
        manager.h
        manager.cpp
        Boss.h
        Boss.cpp
)
