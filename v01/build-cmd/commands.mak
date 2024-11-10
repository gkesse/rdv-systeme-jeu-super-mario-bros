SRC_DIR = ..
BUILD_DIR = ../build
TARGET_NAME = ReadyMario
SETUP_NAME = $(BUILD_DIR)/$(TARGET_NAME)

all: clean_exe cmake compile run

cmake:
	@echo
	@cmake -B $(BUILD_DIR) -S $(SRC_DIR)
compile:
	@echo
	@make -C $(BUILD_DIR)
clean_exe:
	@echo
	@rm -f $(SETUP_NAME)
clean: clean_exe
	@echo
	@make -C $(BUILD_DIR) clean
clean_all:
	@echo
	@rm -rf $(BUILD_DIR)/*
run:
	@echo
	@./envs.sh && $(SETUP_NAME) $(ARGS)
