all:blur showImg
showImg:com/gmq/showImg.java
	javac -cp ./lib/opencv-410.jar com/gmq/showImg.java
	java -cp ./lib/opencv-410.jar:. com/gmq/showImg
blur:com/gmq/blur.java
	javac -cp ./lib/opencv-410.jar com/gmq/blur.java
	java -cp ./lib/opencv-410.jar:. com/gmq/blur
drawShape:com/gmq/drawShape.java
	javac -cp ./lib/opencv-410.jar com/gmq/drawShape.java
	java -cp ./lib/opencv-410.jar:. com/gmq/drawShape
video:com/gmq/video.java
	javac -cp ./lib/opencv-410.jar com/gmq/video.java
	java -cp ./lib/opencv-410.jar:. com/gmq/video

.PHONY:
clean:
	-rm com/gmq/*.class