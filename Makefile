CXX := clang++
CXX_FLAGS := -std=c++17 -g
INCLUDES := -I . -I /opt/homebrew/include
LIBRARIES := -L /opt/homebrew/lib -l gtest
OUT_DIR := out

out_dir:
	mkdir -p $(OUT_DIR)

test: out_dir
	$(CXX) $(CXX_FLAGS) -o $(OUT_DIR)/vector_3d_test $(INCLUDES) $(LIBRARIES) test/vector_3d_test.cc
	$(CXX) $(CXX_FLAGS) -o $(OUT_DIR)/vector_3d_neon_test $(INCLUDES) $(LIBRARIES) test/vector_3d_neon_test.cc

	./$(OUT_DIR)/vector_3d_test
	./$(OUT_DIR)/vector_3d_neon_test

.PHONY: test