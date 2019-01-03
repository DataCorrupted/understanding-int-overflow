PROJ_NAME = understanding-int-overflow
CC = clang
CFLAGS_O0 = -O0
CFLAGS_O2 = -O2

all: \
	${PROJ_NAME}.O0.bin \
	${PROJ_NAME}.O2.bin \
	clean \
	execute

${PROJ_NAME}.O0.bin: ${PROJ_NAME}.c
	$(CC) $(CFLAGS_O0) $< -o $@
	$(CC) $(CFLAGS_O0) $< -o ${PROJ_NAME}.O0.ll -S -emit-llvm
	@echo "Compile O0 complete."
	@echo ""

${PROJ_NAME}.O2.bin: ${PROJ_NAME}.c
	$(CC) $(CFLAGS_O2) $< -o $@
	$(CC) $(CFLAGS_O2) $< -o ${PROJ_NAME}.O2.ll -S -emit-llvm
	@echo "Compile O2 complete."
	@echo ""

clean:
	mv *.ll ../bc
	mv *.bin ../bin
	@echo "Moving binary complete."
	@echo ""
execute:
	@echo "Execuiting compiled binary..."
	@echo ""
	@echo "O0:"
	@../bin/${PROJ_NAME}.O0.bin
	@echo " "
	@echo "O2:"
	@../bin/${PROJ_NAME}.O2.bin
	@echo " "