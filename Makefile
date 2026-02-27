C_TARGET = main_in_c
CPP_TARGET = main_in_cpp
all: $(C_TARGET) $(CPP_TARGET)
$(C_TARGET):
	gcc main.c -std=c99 -Wall -Werror -fsanitize=address -o $@
$(CPP_TARGET):
	g++ main.cpp -std=c++17 -Wall -Werror -fsanitize=address  -o $@ -I/usr/local/include/opencv4 -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs 
	#g++ main.cpp -o $@ $$(pkg-config --cflags --libs opencv4)

run: $(C_TARGET) $(CPP_TARGET)
	./$(C_TARGET)
	./$(CPP_TARGET)
runc: $(C_TARGET)
	./$(C_TARGET)
runcpp:$(CPP_TARGET)
	./$(CPP_TARGET)
clean:
	rm -f $(C_TARGET) $(CPP_TARGET)

