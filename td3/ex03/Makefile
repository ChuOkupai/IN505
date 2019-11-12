# COMPILATION
CXX			:= g++
CXXFLAGS	:= -Wall -Wextra -Werror
DFLAGS		= -MP -MMD -MF $(DEP_DIR)/$*.d -MT '$@'

# DIRECTORIES
SRC_PATH	:= src
TEST_PATH	:= test
BUILD		:= build
BIN_DIR 	:= $(BUILD)/bin
DEP_DIR		:= $(BUILD)/dep
OBJ_DIR 	:= $(BUILD)/obj
SUB_DIR		:= $(BIN_DIR) $(DEP_DIR) $(OBJ_DIR)

# FILES
SRC_BIN	:= $(notdir $(wildcard $(TEST_PATH)/*.cpp))
SRC		:= $(notdir $(wildcard $(SRC_PATH)/*.cpp))
BIN		:= $(SRC_BIN:%.cpp=$(BIN_DIR)/%.out)
DEP		:= $(SRC:%.cpp=$(DEP_DIR)/%.d)
OBJ		:= $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(BIN)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BUILD)

re: fclean all

$(BUILD):
	mkdir $@ $(SUB_DIR)

$(BIN_DIR)/%.out: $(TEST_PATH)/%.cpp inc/*.hpp | $(BUILD) $(OBJ)
	$(CXX) $(CXXFLAGS) -I./inc $(OBJ) $< -o $@

$(OBJ_DIR)/%.o: $(SRC_PATH)/%.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) $(DFLAGS) -I./inc -c $< -o $@

-include $(DEP)

.PHONY: all clean fclean re
