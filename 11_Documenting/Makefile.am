SUBDIRS = src

@DX_RULES@

all-local: doxygen-doc

doxygen-doc/man/man1/prog.1:	doxygen-doc

man1_MANS = doxygen-doc/man/man1/prog.1

install-data-local:
	mkdir -p $(DESTDIR)/$(docdir)
	cp -a doxygen-doc/html $(DESTDIR)/$(docdir)

RU = ru/LC_MESSAGES

pkgdata_DATA = $(RU)/$(PACKAGE).mo

http: doxygen-doc
	python3 -m http.server --directory $</html

update_po: $(PACKAGE).pot

$(PACKAGE).pot: src/prog.c
	xgettext -k_ -c $< -o $@

compile_po: $(RU)/$(PACKAGE).mo

$(RU)/$(PACKAGE).mo: po/ru.po $(PACKAGE).pot
	msgmerge -U po/ru.po $(PACKAGE).pot
	mkdir -p `dirname $@`
	msgfmt po/ru.po -o $@	

clean_locals:
	rm -rf ru
	rm -f $(PACKAGE).pot

