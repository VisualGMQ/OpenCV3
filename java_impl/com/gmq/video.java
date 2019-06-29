package com.gmq;

import java.io.*;
import org.opencv.core.*;
import org.opencv.highgui.*;
import org.opencv.imgproc.Imgproc;
import org.opencv.videoio.VideoCapture;

public class video {
    public static void main(String[] args) {
        System.load(new File("./lib/libopencv_java410.dylib").getAbsolutePath());
        // open video
        VideoCapture camera = new VideoCapture(0);
        Mat img = new Mat();
        if (!camera.isOpened()) {
            System.out.println("no camera");
            return;
        }

        HighGui.namedWindow("camera");
        while (camera.read(img)) {
            HighGui.imshow("camera", img);
            // you can do some operator on img.
            HighGui.waitKey(300);
        }
        System.exit(0);
    }
}