SUBDIRS = src po tests

@DX_RULES@

all-local: doxygen-doc

doxygen-doc/man/man1/prog.1:	doxygen-doc

man1_MANS = doxygen-doc/man/man1/prog.1

install-data-local:
	mkdir -p $(DESTDIR)/$(docdir)
	cp -a doxygen-doc/html $(DESTDIR)/$(docdir)

uninstall-local:
	rm -rf $(DESTDIR)/$(docdir)/html

http: doxygen-doc
	python3 -m http.server --directory $</html


