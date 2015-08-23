## Process this file with automake to produce Makefile.in

## Created by Anjuta



AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(LTERM_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = lterm

lterm_SOURCES = \
	main.c \
	lterm.h \
	lterm.c	


lterm_LDFLAGS =

lterm_LDADD = $(LTERM_LIBS)


if PLATFORM_WIN32
lterm_LDFLAGS += -Wl,--export-all-symbols
else
lterm_LDFLAGS += -Wl,--export-dynamic
endif

if NATIVE_WIN32
lterm_LDFLAGS += -mwindows
endif


