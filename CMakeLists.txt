cmake_minimum_required(VERSION 3.23)
project(ADS_Structures C)

set(CMAKE_C_STANDARD 23)

add_executable(ADS_Structures main.c )

add_library(SLLL
            singleLinkedLinearList/singleLinkedLinearList.h
            singleLinkedLinearList/singleLinkedLinearList.c
            stackArray/stackArray.h stackArray/stackArray.c
            stackList/stackList.h stackList/stackList.c
            queueList/queueList.h queueList/queueList.c
            queueArray/queueArray.h queueArray/queueArray.c
            doubleLinkedList/doubleLinkedList.h
            doubleLinkedList/doubleLinkedList.c
            deque/deque.h deque/deque.c)

target_link_libraries(ADS_Structures SLLL)
