cmake_minimum_required(VERSION 3.21)
project(self_organising_list_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(self_organising_list_cpp main.cpp SelfOrganisingList.h Node.h Node.tpp SelfOrganisingList.tpp SkipList.tpp SkipList.h)
