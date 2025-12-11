SUBDIRS = src

RU = ru/LC_MESSAGES

pkgdata_DATA = $(RU)/$(PACKAGE).mo



update_po: $(PACKAGE).pot

$(PACKAGE).pot: src/prog.c
	xgettext -k_ -c $< -o $@

compile_po: $(RU)/$(PACKAGE).mo

$(RU)/$(PACKAGE).mo: po/ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@	
po/ru.po: $(PACKAGE).pot
	msgmerge -U $@ $<

clean_locals:
	rm -rf ru
	rm -f $(PACKAGE).pot
