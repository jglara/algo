CXXFLAGS =	-O0 -g -Wall -fmessage-length=0 -std=c++11

OBJS =		main.o

LIBS =

TARGET =	mysort

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
