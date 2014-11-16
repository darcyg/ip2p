TALK_INC_DIR = ./deps/libjingle

AR = ar
CXX = g++
CXXFLAGS = -Wall -fno-rtti -fno-exceptions -fvisibility=hidden -ffunction-sections -fdata-sections -gdwarf-2 -g3 -O0 -DHAMMER_TIME=1 -DLOGGING=1 -DFEATURE_ENABLE_SSL -DHASHNAMESPACE=__gnu_cxx -DPOSIX -DDISABLE_DYNAMIC_CAST -DHAVE_OPENSSL_SSL_H=1 -D_REENTRANT -DOSX -D_DEBUG -DEXPAT_RELATIVE_PATH -I$(TALK_INC_DIR) 
LDFLAGS = -lexpat -lssl -lcrypto -framework CoreFoundation -framework Carbon -framework Security -framework SystemConfiguration 

OBJS_DIR = build
LIB_SRCS =
include $(MAKE_DIR)/libjingle_build.mk
LIB_OBJS = ${LIB_SRCS:%.cc=$(OBJS_DIR)/%.o}


APP_SRCS =
include $(MAKE_DIR)/app_build.mk
APP_OBJS = ${APP_SRCS:%.cc=$(OBJS_DIR)/%.o}

LIB = $(OBJS_DIR)/libjingle.a

TARGET = neble
RELAYSERVER_APP = relayserver 
STUNSERVER_APP = stunserver

all: $(TARGET) $(RELAYSERVER_APP) $(STUNSERVER_APP)
 

$(OBJS_DIR)/%.o : %.c
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJS_DIR)/%.o : %.cc
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJS_DIR)/%.o : %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(LIB): $(LIB_OBJS)
	$(AR) -cr $@ $(LIB_OBJS)

$(TARGET): $(LIB) $(APP_OBJS)
	$(CCX) -o $@ $(APP_OBJS) $(LIB) $(LDFLAGS)
	
$(RELAYSERVER_APP): $(LIB)
	$(CXX) -o $@ $(OBJS_DIR)/deps/libjingle/talk/p2p/base/relayserver_main.o $(LIB) $(LDFLAGS)

$(STUNSERVER_APP): $(LIB)
	$(CXX) -o $@ $(OBJS_DIR)/deps/libjingle/talk/p2p/base/stunserver_main.o $(LIB) $(LDFLAGS)
	
.PHONY: clean all

clean:
	rm -f $(TARGET)
	rm -f $(LIB)
	rm -rf $(OBJS_DIR)
	rm -rf $(STUNSERVER_APP)
	rm -rf $(RELAYSERVER_APP)
