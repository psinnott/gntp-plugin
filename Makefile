mac : source/growl_plugin.c gntp.plugin/Contents/Resources/English.lproj gntp.plugin/Contents/MacOS  
	/Developer/Tools/Rez -o gntp.plugin/Contents/Resources/English.lproj/Localized.rsrc -useDF Localized.r
	cp Info.plist gntp.plugin/Contents/
	cp libGrowl.dylib gntp.plugin/Contents/MacOS/growl
	cp ../gntp-send/lib/libgrowl.so  gntp.plugin/Contents/MacOS/
	rm -rf /Library/Internet\ Plug-Ins/gntp.plugin/
	cp -r gntp.plugin/ /Library/Internet\ Plug-Ins/gntp.plugin/

clean :
	rm -f objs/* lib/* bin/* 
	rm -rf gntp.plugin/
	scons -c

gntp.plugin :
	mkdir $@

gntp.plugin/Contents : gntp.plugin
	mkdir $@

gntp.plugin/Contents/Resources : gntp.plugin/Contents
	mkdir $@

gntp.plugin/Contents/Resources/English.lproj : gntp.plugin/Contents/Resources/
	mkdir $@

gntp.plugin/Contents/MacOS : gntp.plugin/Contents
	mkdir $@
