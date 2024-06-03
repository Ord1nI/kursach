##
# Project Title
#
# @file
# @version 0.1
debug:
	clang++ ui.cpp BookSelectFrame.cpp Linked_list.cpp -O2 `wx-config --libs --cxxflags` -std=c++17 -fsanitize=address,leak -o lib.out VirtualList.cpp tinyxml2.cpp
run:
	clang++ ui.cpp BookSelectFrame.cpp Linked_list.cpp -O2 `wx-config --libs --cxxflags` -std=c++17 -fsanitize=address,leak -o lib.out VirtualList.cpp tinyxml2.cpp
	./lib.out
build:
	clang++ ui.cpp BookSelectFrame.cpp Linked_list.cpp `wx-config --libs --cxxflags` -std=c++17  -o lib.out VirtualList.cpp tinyxml2.cpp


# end
