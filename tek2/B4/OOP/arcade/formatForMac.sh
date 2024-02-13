#!/bin/zsh

# Changes all .so occurences to .dylib to make it work with MacOS
if [ ! -z $1 ]
then
    if [ $1 = "apple" ]
    then
        find . -type f -name "*.hpp" -exec sed -i '' 's/\.so/\.dylib/g' {} \;
        find . -type f -name "*.cpp" -exec sed -i '' 's/\.so/\.dylib/g' {} \;
        find ./src/arcade/graphicals/ -type f -name "CMakeLists.txt" -exec sed -i '' 's/add_subdirectory(sdl)/#/g' {} \;
        exit 0
    fi
    find . -type f -name "*.hpp" -exec sed -i '' 's/\.dylib/\.so/g' {} \;
    find . -type f -name "*.cpp" -exec sed -i '' 's/\.dylib/\.so/g' {} \;
    find ./src/arcade/graphicals/ -type f -name "CMakeLists.txt" -exec sed -i '' 's/#/add_subdirectory(sdl)/g' {} \;
fi