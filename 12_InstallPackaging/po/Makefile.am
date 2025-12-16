RU = share/locale/ru/LC_MESSAGES
#pkgdata_DATA = $(RU)/$(PACKAGE).mo

all-local: compile_po

update_po: $(PACKAGE).pot 

$(PACKAGE).pot: ../src/prog.c 
	xgettext -k_ -c $< -o $@ 
compile_po: $(RU)/$(PACKAGE).mo 

$(RU)/$(PACKAGE).mo: ../po/ru.po $(PACKAGE).pot 
	msgmerge -U ../po/ru.po $(PACKAGE).pot 
	mkdir -p $(dir $@) 
	msgfmt ../po/ru.po -o $@ 

install-data-local: compile_po
	mkdir -p $(prefix)/$(RU)
	install -m 644 $(RU)/$(PACKAGE).mo $(prefix)/$(RU)/$(PACKAGE).mo
uninstall-local:
	rm -f $(prefix)/$(RU)/$(PACKAGE).mo

clean_local: 
	rm -rf $(RU) 
	rm -f $(PACKAGE).pot
