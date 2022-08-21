CC?=cc
CFLAGS?=-Os
PREFIX?=/usr/local

permafrost : permafrost.c
	$(CC) -o permafrost $(CFLAGS) -Wall permafrost.c

.PHONY: clean install
clean : 
	rm permafrost

install : permafrost
	install --mode 755 -D -t $(DESTDIR)$(PREFIX)/bin permafrost
