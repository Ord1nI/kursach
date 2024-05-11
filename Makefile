##
# Project Title
#
# @file
# @version 0.1
debug:
	clang++ ui.cpp BookSelectFrame.cpp Linked_list.cpp -O2 `wx-config --libs --cxxflags` -std=c++17 -fsanitize=address,leak -o hueta.out VirtualList.cpp
run:
	clang++ ui.cpp BookSelectFrame.cpp Linked_list.cpp -O2 `wx-config --libs --cxxflags` -std=c++17 -fsanitize=address,leak -o hueta.out VirtualList.cpp
	./hueta.out
build:
	clang++ ui.cpp BookSelectFrame.cpp Linked_list.cpp `wx-config --libs --cxxflags` -std=c++17  -o hueta.out VirtualList.cpp


# end
