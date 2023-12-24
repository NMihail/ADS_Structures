cmake_minimum_required(VERSION 3.23)
project(ADS_Structures C)

set(CMAKE_C_STANDARD 23)

add_executable(ADS_Structures main.c)

add_library(SLLL
            singleLinkedLinearList/singleLinkedLinearList.c
            singleLinkedLinearList/singleLinkedLinearList.h
            stackArray/stackArray.c stackArray/stackArray.h
            stackList/stackList.c stackList/stackList.h
            queueList/queueList.c queueList/queueList.h
            queueArray/queueArray.c queueArray/queueArray.h
            doubleLinkedList/doubleLinkedList.c
            doubleLinkedList/doubleLinkedList.h
            deque/deque.c deque/deque.h
            fileQueue/fileQueue.c fileQueue/fileQueue.h
            singleLinkedLinearListCycled/singleLinkedLinearListCycled.c
            singleLinkedLinearListCycled/singleLinkedLinearListCycled.h)

target_link_libraries(ADS_Structures SLLL)
