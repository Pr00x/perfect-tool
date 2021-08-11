CC=gcc

install:
	$(CC) perfect.c -o /usr/bin/perfect
	cp -r components /opt/components/
	sudo apt-get install python python-pip
	pip install youtube_dl
clean:
	rm /usr/bin/perfect
	rm -rf /opt/components/
