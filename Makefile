##
# Project Title
#
# @file
# @version 0.1
build:
	clang++ ui.cpp Linked_list.cpp `wx-config --libs --cxxflags` -std=c++17 -o hueta.out VirtualList.cpp


# end
