TALK_INC_DIR = ./deps/libjingle
EXPAT_INC_DIR = /usr/include
SSL_INC_DIR =  /usr/include/openssl
OBJS_DIR = ./obj

AR = ar
CC = g++

CFLAGS = -Wall -fno-rtti -fno-exceptions -fvisibility=hidden -ffunction-sections -fdata-sections\
         -gdwarf-2 -g3 -O0 -DHAMMER_TIME=1 -DLOGGING=1 -DFEATURE_ENABLE_SSL -DHASHNAMESPACE=__gnu_cxx\
         -DPOSIX -DDISABLE_DYNAMIC_CAST -DHAVE_OPENSSL_SSL_H=1 -D_REENTRANT -DPOSOIX -D_DEBUG -DEXPAT_RELATIVE_PATH\
         -DLINUX -I$(TALK_INC_DIR) -I$(EXPAT_INC_DIR) -I$(SSL_INC_DIR)         
LDFLAGS = -lexpat -lssl -lcrypto -lpthread -lrt

LIB_SRCS =
include $(MAKE_DIR)/libjingle_build.mk
LIB_OBJS = ${LIB_SRCS:%.cc=$(OBJS_DIR)/%.o}
LIB = $(OBJS_DIR)/libjingle.a

APP_SRCS =
include $(MAKE_DIR)/app_build.mk
APP_OBJS = ${APP_SRCS:%.cc=$(OBJS_DIR)/%.o}
TARGET = neble

RELAYSERVER_SRCS += src/relayserver/relayserver_main.cc \
		    src/relayserver/relayserver.cc
RELAYSERVER_OBJS = ${RELAYSERVER_SRCS:%.cc=$(OBJS_DIR)/%.o}
RELAYSERVER_APP = relayserver 

RELAYCLIENT_SRCS += src/peer/relayclient.cc
RELAYCLIENT_OBJS = ${RELAYCLIENT_SRCS:%.cc=$(OBJS_DIR)/%.o}
RELAYCLIENT_APP = relayclient

STUNSERVER_APP = stunserver


all: $(TARGET) $(RELAYSERVER_APP) $(RELAYCLIENT_APP)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS_DIR)/%.o: %.cc
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIB): $(LIB_OBJS)
	$(AR) -cr $@ $(LIB_OBJS)

$(TARGET): $(LIB) $(APP_OBJS)
	$(CC) -o $@ $(APP_OBJS) $(LIB) $(LDFLAGS)
	
	
$(RELAYSERVER_APP): $(LIB) $(RELAYSERVER_OBJS)
	$(CC) -o $@ $(RELAYSERVER_OBJS) $(LIB) $(LDFLAGS)	
	
$(RELAYCLIENT_APP): $(LIB) $(RELAYCLIENT_OBJS)
	$(CC) -o $@ $(RELAYCLIENT_OBJS) $(LIB) $(LDFLAGS)
	
$(STUNSERVER_APP): $(LIB)
	$(CC) -o $@ $(OBJS_DIR)/deps/libjingle/talk/p2p/base/stunserver_main.o $(LIB) $(LDFLAGS)


.PHONY: clean all

clean:
	rm -f $(TARGET)
	rm -f $(LIB)
	rm -rf $(OBJS_DIR)
	rm -rf $(STUNSERVER_APP)
	rm -rf $(RELAYSERVER_APP)
	rm -rf $(RELAYCLIENT_APP)
