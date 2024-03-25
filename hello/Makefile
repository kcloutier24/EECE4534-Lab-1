CFLAGS=-g
TARGET=main
SOURCE=main.c
ESL_ZEDBOARD_IP ?= qemu
BIN_DEST=/home/root
DEBUG_PORT=1234

$(TARGET): $(SOURCE)
		$(CC) $(CFLAGS) -o $@ $^

kill:
		@ssh -q root@$(ESL_ZEDBOARD_IP) pkill -9 -f $(TARGET) || true

all: $(TARGET)

upload: $(TARGET)
		@scp -q $^ root@$(ESL_ZEDBOARD_IP):$(BIN_DEST)

run: upload
		@ssh -q root@$(ESL_ZEDBOARD_IP) $(BIN_DEST)/$(TARGET)

clean:
		rm -rf *.o $(TARGET)

debug-remote: upload
		@ssh -q -f root@$(ESL_ZEDBOARD_IP) "bash -c 'nohup gdbserver --once :$(DEBUG_PORT) $(BIN_DEST)/$(TARGET) &> /dev/null < /dev/null &'"

debug: debug-remote
		$(GDB) -iex "target remote $(ESL_ZEDBOARD_IP):$(DEBUG_PORT)" $(TARGET)

.PHONY: clean upload run kill
