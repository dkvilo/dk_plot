CC 							:= clang -std=c99 -Wno-deprecated
FRAMEWORK 			:= .
SANDBOX_SOURCE 	:= source
BUILD_DIR 			:= build
BIN 						:= dk_plot

FINAL_CFLAGS 		:= -I./$(FRAMEWORK)
OPT							:= -Ofast

prepare:
	mkdir build

clean_bin:
	rm $(BUILD_DIR)/$(BIN)

clean:
	# rmdir $(BUILD_DIR) /s /q
	rm -rf $(BUILD_DIR)

build:
	make prepare && $(CC) $(SANDBOX_SOURCE)/*.c $(FINAL_CFLAGS) $(OPT) -o $(BUILD_DIR)/$(BIN) -lm -lncurses

.PHONY:
	build clean
