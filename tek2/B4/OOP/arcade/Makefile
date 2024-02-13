##
## EPITECH PROJECT, 2022
## All projects
## File description:
## Makefile
##

TARGET := arcade

BUILD_DIR := build
BUILD_DIR_RELEASE := $(BUILD_DIR)/release
BUILD_DIR_DEBUG := $(BUILD_DIR)/debug

BUILD_PART_FLAGS := -DBUILD_CORE=FALSE -DBUILD_GAMES=FALSE -DBUILD_GRAPHICALS=FALSE
BUILD_ALL := -DBUILD_CORE=TRUE -DBUILD_GAMES=TRUE -DBUILD_GRAPHICALS=TRUE
CONFIG_FLAGS := ./src -G"Unix Makefiles" $(BUILD_PART_FLAGS)
DOC_PATH := doc
LIB_PATH := lib

CONFIG_FLAGS_RELEASE := \
	-DCMAKE_BUILD_TYPE=Release \
	$(CONFIG_FLAGS) -B$(BUILD_DIR_RELEASE) \

CONFIG_FLAGS_DEBUG := \
	-DCMAKE_BUILD_TYPE=Debug \
	$(CONFIG_FLAGS) -B$(BUILD_DIR_DEBUG) \

BUILD_FLAGS_RELEASE := --build $(BUILD_DIR_RELEASE) --config Release
BUILD_FLAGS_DEBUG := --build $(BUILD_DIR_DEBUG) --config Debug

# Build Targets
all: $(TARGET)
$(TARGET): $(LIB_PATH)
	cmake $(CONFIG_FLAGS_RELEASE) $(BUILD_ALL)
	cmake $(BUILD_FLAGS_RELEASE)

core:
	cmake $(CONFIG_FLAGS_RELEASE) -DBUILD_CORE=TRUE
	cmake $(BUILD_FLAGS_RELEASE)

games: $(LIB_PATH)
	cmake $(CONFIG_FLAGS_RELEASE) -DBUILD_GAMES=TRUE
	cmake $(BUILD_FLAGS_RELEASE)

graphicals: $(LIB_PATH)
	cmake $(CONFIG_FLAGS_RELEASE) -DBUILD_GRAPHICALS=TRUE
	cmake $(BUILD_FLAGS_RELEASE)

# Debug Target
debug: $(LIB_PATH)
	cmake $(CONFIG_FLAGS_DEBUG) $(BUILD_ALL)
	cmake $(BUILD_FLAGS_DEBUG)

$(LIB_PATH):
	mkdir $@

$(DOC_PATH):
	mkdir $@

generate_doc: $(DOC_PATH)
	doxygen Doxyfile
	./verify_doc.sh

generate_pdf_doc: generate_doc
	make -C ${DOC_PATH}/output/latex
	cp ${DOC_PATH}/output/latex/refman.pdf ${DOC_PATH}/doc.pdf

open_doc: generate_doc
	xdg-open ${DOC_PATH}/output/html/index.html

# Remove Target's Build Files
clean:
	rm -rf $(BUILD_DIR_RELEASE)/CMakeFiles $(BUILD_DIR_RELEASE)/src/CMakeFiles
	rm -rf $(BUILD_DIR_DEBUG)/CMakeFiles $(BUILD_DIR_DEBUG)/src/CMakeFiles

# Remove Target
fclean:
	rm -rf $(BUILD_DIR)
	rm -f $(TARGET)
	rm -rf ${LIB_PATH}

# Recompile all
re: fclean all

valgrind: debug
	cd tests && valgrind --trace-children=yes --leak-check=full ../build/debug/tests/unit_test 2> vg_out.txt && cd -

update_interfaces:
	git submodule update --init --recursive
	make copy_interfaces

copy_interfaces:
	rm -rf include/arcade/*
	cp -rf ArcadeInterfaces/include/arcade/* ./include/arcade/

# Run Target
tests:
	cmake  -DBUILD_TEST_SUITE=TRUE -DUSE_GCOV=TRUE $(CONFIG_FLAGS_DEBUG)
	cmake $(BUILD_FLAGS_DEBUG)
	(cd $(BUILD_DIR_DEBUG) && ctest --verbose) || true
	rm -rf `find . -wholename "./$(BUILD_DIR_DEBUG)/tests/CMakeFiles/unit_test.dir/**/*.cpp.gc*"`

# Display Code Coverage
coverage:
	gcovr --branch .
	gcovr .

.PHONY: \
	all $(TARGET) \
	clean fclean re \
	debug valgrind \
	tests coverage \
	update_interfaces copy_interfaces \
	generate_doc open_doc generate_pdf_doc
