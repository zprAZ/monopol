#############################################################################
# Makefile for building: client
# Generated by qmake (2.01a) (Qt 4.8.6) on: Mon May 25 16:23:57 2015
# Project:  ../client/client.pro
# Template: app
# Command: /usr/lib64/qt4/bin/qmake -spec /usr/lib64/qt4/mkspecs/linux-g++ CONFIG+=debug -o Makefile ../client/client.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -std=c++11 -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/lib64/qt4/mkspecs/linux-g++ -I../client -I/usr/include/QtCore -I/usr/include/QtNetwork -I/usr/include/QtGui -I/usr/include -I. -I../client -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib64 -lQtGui -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib64/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = 
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = ../client/boardWidget.cpp \
		../client/cornerWidget.cpp \
		../client/cityWidget.cpp \
		../client/chanceWidget.cpp \
		../client/railwayWidget.cpp \
		../client/counterWidget.cpp \
		../client/taxWidget.cpp \
		../client/centralWidget.cpp \
		../client/mainWidget.cpp \
		../client/main.cpp \
		../client/mainWindow.cpp \
		../client/ip4Validator.cpp \
		../client/questionDialog.cpp \
		../client/ipsettingsDialog.cpp \
		../client/infoDialog.cpp \
		../client/ServerConnector.cpp moc_boardWidget.cpp \
		moc_cornerWidget.cpp \
		moc_cityWidget.cpp \
		moc_chanceWidget.cpp \
		moc_railwayWidget.cpp \
		moc_counterWidget.cpp \
		moc_taxWidget.cpp \
		moc_centralWidget.cpp \
		moc_mainWidget.cpp \
		moc_mainWindow.cpp \
		moc_questionDialog.cpp \
		moc_ipsettingsDialog.cpp \
		moc_infoDialog.cpp \
		moc_ServerConnector.cpp
OBJECTS       = boardWidget.o \
		cornerWidget.o \
		cityWidget.o \
		chanceWidget.o \
		railwayWidget.o \
		counterWidget.o \
		taxWidget.o \
		centralWidget.o \
		mainWidget.o \
		main.o \
		mainWindow.o \
		ip4Validator.o \
		questionDialog.o \
		ipsettingsDialog.o \
		infoDialog.o \
		ServerConnector.o \
		moc_boardWidget.o \
		moc_cornerWidget.o \
		moc_cityWidget.o \
		moc_chanceWidget.o \
		moc_railwayWidget.o \
		moc_counterWidget.o \
		moc_taxWidget.o \
		moc_centralWidget.o \
		moc_mainWidget.o \
		moc_mainWindow.o \
		moc_questionDialog.o \
		moc_ipsettingsDialog.o \
		moc_infoDialog.o \
		moc_ServerConnector.o
DIST          = /usr/lib64/qt4/mkspecs/common/unix.conf \
		/usr/lib64/qt4/mkspecs/common/linux.conf \
		/usr/lib64/qt4/mkspecs/common/gcc-base.conf \
		/usr/lib64/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/lib64/qt4/mkspecs/common/g++-base.conf \
		/usr/lib64/qt4/mkspecs/common/g++-unix.conf \
		/usr/lib64/qt4/mkspecs/qconfig.pri \
		/usr/lib64/qt4/mkspecs/modules/qt_webkit.pri \
		/usr/lib64/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt4/mkspecs/features/qt_config.prf \
		/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt4/mkspecs/features/default_pre.prf \
		/usr/lib64/qt4/mkspecs/features/debug.prf \
		/usr/lib64/qt4/mkspecs/features/default_post.prf \
		/usr/lib64/qt4/mkspecs/features/shared.prf \
		/usr/lib64/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/lib64/qt4/mkspecs/features/warn_on.prf \
		/usr/lib64/qt4/mkspecs/features/qt.prf \
		/usr/lib64/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt4/mkspecs/features/moc.prf \
		/usr/lib64/qt4/mkspecs/features/resources.prf \
		/usr/lib64/qt4/mkspecs/features/uic.prf \
		/usr/lib64/qt4/mkspecs/features/yacc.prf \
		/usr/lib64/qt4/mkspecs/features/lex.prf \
		/usr/lib64/qt4/mkspecs/features/include_source_dir.prf \
		../client/client.pro
QMAKE_TARGET  = client
DESTDIR       = 
TARGET        = client

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9][^0-9]*\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: ../client/client.pro  /usr/lib64/qt4/mkspecs/linux-g++/qmake.conf /usr/lib64/qt4/mkspecs/common/unix.conf \
		/usr/lib64/qt4/mkspecs/common/linux.conf \
		/usr/lib64/qt4/mkspecs/common/gcc-base.conf \
		/usr/lib64/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/lib64/qt4/mkspecs/common/g++-base.conf \
		/usr/lib64/qt4/mkspecs/common/g++-unix.conf \
		/usr/lib64/qt4/mkspecs/qconfig.pri \
		/usr/lib64/qt4/mkspecs/modules/qt_webkit.pri \
		/usr/lib64/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt4/mkspecs/features/qt_config.prf \
		/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt4/mkspecs/features/default_pre.prf \
		/usr/lib64/qt4/mkspecs/features/debug.prf \
		/usr/lib64/qt4/mkspecs/features/default_post.prf \
		/usr/lib64/qt4/mkspecs/features/shared.prf \
		/usr/lib64/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/lib64/qt4/mkspecs/features/warn_on.prf \
		/usr/lib64/qt4/mkspecs/features/qt.prf \
		/usr/lib64/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt4/mkspecs/features/moc.prf \
		/usr/lib64/qt4/mkspecs/features/resources.prf \
		/usr/lib64/qt4/mkspecs/features/uic.prf \
		/usr/lib64/qt4/mkspecs/features/yacc.prf \
		/usr/lib64/qt4/mkspecs/features/lex.prf \
		/usr/lib64/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib64/libQtGui.prl \
		/usr/lib64/libQtCore.prl \
		/usr/lib64/libQtNetwork.prl
	$(QMAKE) -spec /usr/lib64/qt4/mkspecs/linux-g++ CONFIG+=debug -o Makefile ../client/client.pro
/usr/lib64/qt4/mkspecs/common/unix.conf:
/usr/lib64/qt4/mkspecs/common/linux.conf:
/usr/lib64/qt4/mkspecs/common/gcc-base.conf:
/usr/lib64/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/lib64/qt4/mkspecs/common/g++-base.conf:
/usr/lib64/qt4/mkspecs/common/g++-unix.conf:
/usr/lib64/qt4/mkspecs/qconfig.pri:
/usr/lib64/qt4/mkspecs/modules/qt_webkit.pri:
/usr/lib64/qt4/mkspecs/features/qt_functions.prf:
/usr/lib64/qt4/mkspecs/features/qt_config.prf:
/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf:
/usr/lib64/qt4/mkspecs/features/default_pre.prf:
/usr/lib64/qt4/mkspecs/features/debug.prf:
/usr/lib64/qt4/mkspecs/features/default_post.prf:
/usr/lib64/qt4/mkspecs/features/shared.prf:
/usr/lib64/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/lib64/qt4/mkspecs/features/warn_on.prf:
/usr/lib64/qt4/mkspecs/features/qt.prf:
/usr/lib64/qt4/mkspecs/features/unix/thread.prf:
/usr/lib64/qt4/mkspecs/features/moc.prf:
/usr/lib64/qt4/mkspecs/features/resources.prf:
/usr/lib64/qt4/mkspecs/features/uic.prf:
/usr/lib64/qt4/mkspecs/features/yacc.prf:
/usr/lib64/qt4/mkspecs/features/lex.prf:
/usr/lib64/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib64/libQtGui.prl:
/usr/lib64/libQtCore.prl:
/usr/lib64/libQtNetwork.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/lib64/qt4/mkspecs/linux-g++ CONFIG+=debug -o Makefile ../client/client.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/client1.0.0 || $(MKDIR) .tmp/client1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/client1.0.0/ && $(COPY_FILE) --parents ../client/boardWidget.h ../client/cornerWidget.h ../client/cityWidget.h ../client/chanceWidget.h ../client/railwayWidget.h ../client/counterWidget.h ../client/taxWidget.h ../client/centralWidget.h ../client/mainWidget.h ../client/mainWindow.h ../client/ip4Validator.h ../client/questionDialog.h ../client/ipsettingsDialog.h ../client/infoDialog.h ../client/ServerConnector.h .tmp/client1.0.0/ && $(COPY_FILE) --parents ../client/boardWidget.cpp ../client/cornerWidget.cpp ../client/cityWidget.cpp ../client/chanceWidget.cpp ../client/railwayWidget.cpp ../client/counterWidget.cpp ../client/taxWidget.cpp ../client/centralWidget.cpp ../client/mainWidget.cpp ../client/main.cpp ../client/mainWindow.cpp ../client/ip4Validator.cpp ../client/questionDialog.cpp ../client/ipsettingsDialog.cpp ../client/infoDialog.cpp ../client/ServerConnector.cpp .tmp/client1.0.0/ && (cd `dirname .tmp/client1.0.0` && $(TAR) client1.0.0.tar client1.0.0 && $(COMPRESS) client1.0.0.tar) && $(MOVE) `dirname .tmp/client1.0.0`/client1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/client1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_boardWidget.cpp moc_cornerWidget.cpp moc_cityWidget.cpp moc_chanceWidget.cpp moc_railwayWidget.cpp moc_counterWidget.cpp moc_taxWidget.cpp moc_centralWidget.cpp moc_mainWidget.cpp moc_mainWindow.cpp moc_questionDialog.cpp moc_ipsettingsDialog.cpp moc_infoDialog.cpp moc_ServerConnector.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_boardWidget.cpp moc_cornerWidget.cpp moc_cityWidget.cpp moc_chanceWidget.cpp moc_railwayWidget.cpp moc_counterWidget.cpp moc_taxWidget.cpp moc_centralWidget.cpp moc_mainWidget.cpp moc_mainWindow.cpp moc_questionDialog.cpp moc_ipsettingsDialog.cpp moc_infoDialog.cpp moc_ServerConnector.cpp
moc_boardWidget.cpp: ../client/boardWidget.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) ../client/boardWidget.h -o moc_boardWidget.cpp

moc_cornerWidget.cpp: ../client/boardWidget.h \
		../client/cornerWidget.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) ../client/cornerWidget.h -o moc_cornerWidget.cpp

moc_cityWidget.cpp: ../client/boardWidget.h \
		../client/cityWidget.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) ../client/cityWidget.h -o moc_cityWidget.cpp

moc_chanceWidget.cpp: ../client/boardWidget.h \
		../client/chanceWidget.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) ../client/chanceWidget.h -o moc_chanceWidget.cpp

moc_railwayWidget.cpp: ../client/boardWidget.h \
		../client/railwayWidget.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) ../client/railwayWidget.h -o moc_railwayWidget.cpp

moc_counterWidget.cpp: ../client/boardWidget.h \
		../client/counterWidget.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) ../client/counterWidget.h -o moc_counterWidget.cpp

moc_taxWidget.cpp: ../client/boardWidget.h \
		../client/taxWidget.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) ../client/taxWidget.h -o moc_taxWidget.cpp

moc_centralWidget.cpp: ../client/centralWidget.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) ../client/centralWidget.h -o moc_centralWidget.cpp

moc_mainWidget.cpp: ../client/boardWidget.h \
		../client/centralWidget.h \
		../client/chanceWidget.h \
		../client/cityWidget.h \
		../client/cornerWidget.h \
		../client/railwayWidget.h \
		../client/taxWidget.h \
		../client/counterWidget.h \
		../client/mainWidget.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) ../client/mainWidget.h -o moc_mainWidget.cpp

moc_mainWindow.cpp: ../client/mainWindow.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) ../client/mainWindow.h -o moc_mainWindow.cpp

moc_questionDialog.cpp: ../client/questionDialog.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) ../client/questionDialog.h -o moc_questionDialog.cpp

moc_ipsettingsDialog.cpp: ../client/ipsettingsDialog.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) ../client/ipsettingsDialog.h -o moc_ipsettingsDialog.cpp

moc_infoDialog.cpp: ../client/infoDialog.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) ../client/infoDialog.h -o moc_infoDialog.cpp

moc_ServerConnector.cpp: ../client/ServerConnector.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) ../client/ServerConnector.h -o moc_ServerConnector.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

boardWidget.o: ../client/boardWidget.cpp ../client/boardWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o boardWidget.o ../client/boardWidget.cpp

cornerWidget.o: ../client/cornerWidget.cpp ../client/cornerWidget.h \
		../client/boardWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cornerWidget.o ../client/cornerWidget.cpp

cityWidget.o: ../client/cityWidget.cpp ../client/cityWidget.h \
		../client/boardWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cityWidget.o ../client/cityWidget.cpp

chanceWidget.o: ../client/chanceWidget.cpp ../client/chanceWidget.h \
		../client/boardWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o chanceWidget.o ../client/chanceWidget.cpp

railwayWidget.o: ../client/railwayWidget.cpp ../client/railwayWidget.h \
		../client/boardWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o railwayWidget.o ../client/railwayWidget.cpp

counterWidget.o: ../client/counterWidget.cpp ../client/counterWidget.h \
		../client/boardWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o counterWidget.o ../client/counterWidget.cpp

taxWidget.o: ../client/taxWidget.cpp ../client/taxWidget.h \
		../client/boardWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o taxWidget.o ../client/taxWidget.cpp

centralWidget.o: ../client/centralWidget.cpp ../client/centralWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o centralWidget.o ../client/centralWidget.cpp

mainWidget.o: ../client/mainWidget.cpp ../client/mainWidget.h \
		../client/boardWidget.h \
		../client/centralWidget.h \
		../client/chanceWidget.h \
		../client/cityWidget.h \
		../client/cornerWidget.h \
		../client/railwayWidget.h \
		../client/taxWidget.h \
		../client/counterWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainWidget.o ../client/mainWidget.cpp

main.o: ../client/main.cpp ../client/mainWindow.h \
		../client/ipsettingsDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o ../client/main.cpp

mainWindow.o: ../client/mainWindow.cpp ../client/mainWindow.h \
		../client/mainWidget.h \
		../client/boardWidget.h \
		../client/centralWidget.h \
		../client/chanceWidget.h \
		../client/cityWidget.h \
		../client/cornerWidget.h \
		../client/railwayWidget.h \
		../client/taxWidget.h \
		../client/counterWidget.h \
		../client/ipsettingsDialog.h \
		../client/questionDialog.h \
		../client/infoDialog.h \
		../client/ServerConnector.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainWindow.o ../client/mainWindow.cpp

ip4Validator.o: ../client/ip4Validator.cpp ../client/ip4Validator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ip4Validator.o ../client/ip4Validator.cpp

questionDialog.o: ../client/questionDialog.cpp ../client/questionDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o questionDialog.o ../client/questionDialog.cpp

ipsettingsDialog.o: ../client/ipsettingsDialog.cpp ../client/ipsettingsDialog.h \
		../client/ip4Validator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ipsettingsDialog.o ../client/ipsettingsDialog.cpp

infoDialog.o: ../client/infoDialog.cpp ../client/infoDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o infoDialog.o ../client/infoDialog.cpp

ServerConnector.o: ../client/ServerConnector.cpp ../client/ServerConnector.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ServerConnector.o ../client/ServerConnector.cpp

moc_boardWidget.o: moc_boardWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_boardWidget.o moc_boardWidget.cpp

moc_cornerWidget.o: moc_cornerWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_cornerWidget.o moc_cornerWidget.cpp

moc_cityWidget.o: moc_cityWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_cityWidget.o moc_cityWidget.cpp

moc_chanceWidget.o: moc_chanceWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_chanceWidget.o moc_chanceWidget.cpp

moc_railwayWidget.o: moc_railwayWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_railwayWidget.o moc_railwayWidget.cpp

moc_counterWidget.o: moc_counterWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_counterWidget.o moc_counterWidget.cpp

moc_taxWidget.o: moc_taxWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_taxWidget.o moc_taxWidget.cpp

moc_centralWidget.o: moc_centralWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_centralWidget.o moc_centralWidget.cpp

moc_mainWidget.o: moc_mainWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainWidget.o moc_mainWidget.cpp

moc_mainWindow.o: moc_mainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainWindow.o moc_mainWindow.cpp

moc_questionDialog.o: moc_questionDialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_questionDialog.o moc_questionDialog.cpp

moc_ipsettingsDialog.o: moc_ipsettingsDialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ipsettingsDialog.o moc_ipsettingsDialog.cpp

moc_infoDialog.o: moc_infoDialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_infoDialog.o moc_infoDialog.cpp

moc_ServerConnector.o: moc_ServerConnector.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ServerConnector.o moc_ServerConnector.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

