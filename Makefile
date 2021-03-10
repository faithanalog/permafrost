permafrost : permafrost.c
	cc -o permafrost -Os -Wall permafrost.c

.PHONY: clean install
clean : 
	rm permafrost

install : permafrost
	install --mode 755 -D -t /usr/local/bin permafrost
