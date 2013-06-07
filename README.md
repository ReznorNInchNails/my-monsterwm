my-monsterwm
============


Here you can find my config files for monsterwm. 
Any major changes will be updated. 
For now it includes only basic functions: bar, monsterwm, and some great keybindings.

To install: 

cd monsterwm-xcb

sudo make clean install

cd ..

cd monsterbar

sudo make clean install 

Then put monsterbar in your home directory, after that do:


nano ~/.xinitrc 

Add those lines

exec ~/.monsterbar

exec dbus-launch /usr/local/bin/monsterwm

