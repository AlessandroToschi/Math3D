CXX := clang++
CXX_FLAGS := -std=c++17 -g -Wall 
TEST_INCLUDES := -I . -I /opt/homebrew/include
TEST_LIBRARIES := -L /opt/homebrew/lib -l gtest
OUT_DIR := out

clean:
	rm -rf $(OUT_DIR)

out_dir: clean
	mkdir -p $(OUT_DIR)

%_test: out_dir
	$(CXX) $(CXX_FLAGS) -o $(OUT_DIR)/$@ $(TEST_INCLUDES) $(TEST_LIBRARIES) test/$@.cc


test: vector_3d_test vector_3d_neon_test
	for t in $^; do ./${OUT_DIR}/$$t; done

.PHONY: test