CC = "gcc"
PROJECT = light
SRC = light.c
LIBS  = -lwiringPi -lwiringPiDev

$(PROJECT) : $(SRC)
	$(CC) -o $(PROJECT) $(SRC) $(LIBS)
run: 
	./$(PROJECT)
php: 
	php g1.php > g1.png
html:
	midori light.html	
clean:
	 rm  $(PROJECT) *.png
